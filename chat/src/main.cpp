/**
 * @file main.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief
 * @version 0.1
 * @date 12-09-2019
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
#include "Socket.h"
#include "TextToBinary.h"

#include <omp.h>     // omp parallel
#include <iostream>  // std::cin, std::endl, std::cout
#include <string>    // std::string

/**
 * @brief Função menu
 *
 * @param argc Quantidade de parãmetros recebidos
 * @param argv Parâmetros recebidos
 * @return int 0 SUCCESS
 * @return int 1 ERROR Argumntos não digitados corretamente
 */
int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cout << "Erro! Digitar os argumentos corretamente." << std::endl;
    return 1;
  }
  Socket novoSocket(5354);
#pragma omp parallel
  {
#pragma omp sections
    {
#pragma omp section
      {
        // Receber mensagem
        novoSocket.startReceive();
        while (novoSocket.getStatusReceive() == "on") {
          std::string novaMsg = novoSocket.receive();
          std::cout << "Parceiro: " << novaMsg << std::endl;
        }
        std::cout << "Chat fechado pelo Parceiro" << std::endl;
      }
#pragma omp section
      {
        // Envia a mensagem
        novoSocket.startSubmit(argv[1]);
        while (true) {
          if (novoSocket.getStatusReceive() == "off") {
            break;
          }
          std::string mensagem;
          std::getline(std::cin, mensagem);
          novoSocket.submit(mensagem);
        }
      }
    }
  }
  return 0;
}
