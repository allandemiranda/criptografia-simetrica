/**
 * @file main.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "BinaryToText.h"
#include "Decode.h"
#include "Encode.h"
#include "KeyGeneration.h"
#include "OpenFile.h"
#include "SaveBinaryFile.h"
#include "TextToBinary.h"

#include <iostream>  // std::cout , std::endl
#include <string>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

void codificar(std::string);    // Codifiar texto
void decodificar(std::string);  // Decodificar texto binário

/**
 * @brief Função menu
 *
 * @param argc Quantidade de parâmetros recebidos
 * @param argv Parâmetros recebidos
 * @return int
 */
int main(int argc, char const *argv[]) {
#pragma omp parallel
  {
#pragma omp sections
    {
#pragma omp section
      {
        while (true) {
          int sock = 0, valread;
          struct sockaddr_in serv_addr;
          // char *hello = "Hello from client";
          char buffer[1024] = {0};
          if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("\n Socket creation error \n");
            // return -1;
          }

          serv_addr.sin_family = AF_INET;
          serv_addr.sin_port = htons(PORT);

          // Convert IPv4 and IPv6 addresses from text to binary form
          if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
            printf("\nInvalid address/ Address not supported \n");
            // return -1;
          }

          while (connect(sock, (struct sockaddr *)&serv_addr,
                         sizeof(serv_addr)) < 0) {
            // printf("\nConnection Failed \n");
            // return -1;
          }
          std::string aaa;
          std::cin >> aaa;
          const char *hello = aaa.c_str();
          send(sock, hello, strlen(hello), 0);
        }
      }
#pragma omp section
      {
        while (true) {
          int server_fd, new_socket, valread;
          struct sockaddr_in address;
          int opt = 1;
          int addrlen = sizeof(address);
          char buffer[1024] = {0};

          // Creating socket file descriptor
          if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
          }

          // Forcefully attaching socket to the port 8080
          if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                         &opt, sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
          }
          address.sin_family = AF_INET;
          address.sin_addr.s_addr = INADDR_ANY;
          address.sin_port = htons(PORT);

          // Forcefully attaching socket to the port 8080
          if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) <
              0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
          }
          if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
          }
          if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                   (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
          }
          std::cout  << "aqui" << std::endl;
          valread = read(new_socket, buffer, 1024);
          printf("%s\n", buffer);
        }
      }
    }
  }
  return 0;
}

/**
 * @brief Função para codificar texto de um arquivo
 *
 * @param caminho Caminho do arquivo com o texto
 * @return std::string Texto codificado
 */
void codificar(std::string caminho) {
  OpenFile chavePrincipal("data/key.des");
  KeyGeneration subChaves(chavePrincipal.getLine(1));

  OpenFile arquivoTexto(caminho);
  std::string textoEmBinario;
  for (auto i(0u); i < arquivoTexto.getSizeText(); ++i) {
    TextToBinary paraBinario(arquivoTexto.getLine(i + 1));
    textoEmBinario += paraBinario.getBinary();
  }

  std::string textoCodficado;
  for (auto i(0u); i < (textoEmBinario.size() / 8); ++i) {
    std::string tempBinario;
    for (auto j(0u); j < 8; ++j) {
      tempBinario.push_back(textoEmBinario[(i * 8) + j]);
    }
    Encode codificado(tempBinario, subChaves.getKey(1), subChaves.getKey(2));
    textoCodficado += codificado.getFinalPlaintext();
  }

  SaveBinaryFile salvarBinario(textoCodficado);
}

/**
 * @brief Função para decodificar texto de um arquivo
 *
 * @param caminho Caminho do arquivo codificado
 */
void decodificar(std::string caminho) {
  OpenFile chavePrincipal("data/key.des");
  KeyGeneration subChaves(chavePrincipal.getLine(1));

  OpenFile arquivoBinario(caminho);
  std::string arquivoBinarioDecodificado;
  for (auto i(0u); i < (arquivoBinario.getLine(1).size() / 8); ++i) {
    std::string tempBinario;
    for (auto j(0u); j < 8; ++j) {
      tempBinario.push_back(arquivoBinario.getLine(1)[(i * 8) + j]);
    }
    Decode decodificado(tempBinario, subChaves.getKey(1), subChaves.getKey(2));
    arquivoBinarioDecodificado += decodificado.getFinalPlaintext();
  }

  BinaryToText textoFinal(arquivoBinarioDecodificado);
  for (auto i(0u); i < textoFinal.getSizeText(); ++i) {
    std::cout << textoFinal.getLine(i + 1) << std::endl;
  }
}