/**
 * @file Socket.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da classe Socket
 * @version 0.1
 * @date 12-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Socket.h"

#include <arpa/inet.h>   // socket
#include <netinet/in.h>  // socket
#include <stdio.h>       // socket
#include <stdlib.h>      // socket
#include <string.h>      // socket
#include <sys/socket.h>  // socket
#include <unistd.h>      // socket
#include <bitset>        // std::bitset
#include <iostream>      // std::cout, std::endl;
#include <string>        // std::string
#include <vector>        // std::vector

/**
 * @brief Construct a new Socket:: Socket object
 *
 * @param port Porta de comunicação
 */
Socket::Socket(unsigned long port) { PORT = port; }

/**
 * @brief Destroy the Socket:: Socket object
 *
 */
Socket::~Socket() {}

/**
 * @brief Função para abrir a porta e receber as mensagens
 *
 */
void Socket::startReceive(void) {
  if ((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
    throw "socket failed";
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    throw "setsockopt";
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    throw "bind failed";
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 3) < 0) {
    throw "listen";
    perror("listen");
    exit(EXIT_FAILURE);
  }
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                           (socklen_t *)&addrlen)) < 0) {
    throw "accept";
    perror("accept");
    exit(EXIT_FAILURE);
  }
  statusReceiverNow = "on";
}

/**
 * @brief Função para receber mensagens
 *
 * @return std::vector<char> Mensagem recebida
 */
std::vector<char> Socket::receive(void) {
  char buffer[1024] = {0};
  valread = recv(new_socket, buffer, 1024, 0);
  if (valread == 0) {
    statusReceiverNow = "off";
  }
  std::vector<char> strBuffer;
  for (char c : buffer) {
    if (std::bitset<8>(c).to_ulong() == 0) {
      break;
    }
    strBuffer.push_back(c);
  }
  return strBuffer;
}

/**
 * @brief Verificador de status do receptor de mensagens
 *
 * @return std::string on parceiro online
 * @return std::string off parceiro offline
 */
std::string Socket::getStatusReceive(void) { return statusReceiverNow; }

/**
 * @brief Função para abrir a porta e enviar as mensagens
 *
 * @param ipAdr endereço ip do destinatário
 */
void Socket::startSubmit(char const *ipAdr) {
  if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
    throw "Socket creation error";
    printf("\n Socket creation error \n");
  }
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  std::cout << "Estabelecendo conexão com outro usuário de ip " << ipAdr << ":"
            << PORT << std::endl;
  if (inet_pton(AF_INET, ipAdr, &serv_addr.sin_addr) <= 0) {
    throw "Invalid address/ Address not supported";
    printf("\nInvalid address/ Address not supported \n");
  }
  while (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    // Aguardando outro usuário
  }
  std::cout << "Usuário parceiro Online!" << std::endl;
}

/**
 * @brief Função para enviar mensagem
 *
 * @param msg Mensagem
 */
void Socket::submit(std::vector<char> msg) {
  if (msg.size() > 1024) {
    throw "ERRO! Tentando enviar mensagem maior do que 1024-bit";
  }
  char buffer[1024];
  for (auto i(0u); i < msg.size(); ++i) {
    buffer[i] = msg[i];
  }
  send(sock, buffer, msg.size(), 0);
}