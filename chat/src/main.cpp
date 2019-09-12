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

#include <omp.h>     // omp parallel
#include <iostream>  // std::cin, std::endl, std::cout
#include <string>    // std::string

#include "CryptionSelect.h"
#include "Socket.h"

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
  //CryptionSelect emUso(void);
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
          // if(emUso().analyzeMsgReceive(novaMsg)){
          //   if(emUso().setType(novaMsg)){
          //     novoSocket.submit(mensagem);
          //   }
          // }
        }
        std::cout << "Chat fechado pelo Parceiro" << std::endl;
        std::cout << "Digite qualquer tecla apra sair..." << std::endl;
      }
#pragma omp section
      {
        // Envia a mensagem
        novoSocket.startSubmit(argv[1]);
        while (novoSocket.getStatusReceive() == "on") {
          std::string mensagem;
          std::getline(std::cin, mensagem);
          novoSocket.submit(mensagem);
        }
      }
    }
  }
  return 0;
}
