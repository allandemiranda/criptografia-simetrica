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

#include <omp.h>
#include <iostream>

#include "Socket.h"

/**
 * @brief Função menu
 *
 * @param argc Quantidade de parãmetros recebidos
 * @param argv Parâmetros recebidos
 * @return int 0 SUCCESS
 */
int main(int argc, char const *argv[]) {
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
