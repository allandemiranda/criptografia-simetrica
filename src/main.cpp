/**
 * @file s-des-encode.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Programa
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>  // std::cout, std::endl;
#include <string>    // std::string
#include "Chat.h"
#include "ChatDH.h"
#include "RC4.h"
#include "SDES.h"

/**
 * @brief Codificar texto
 *
 * @param argc Quantidade de parãmetros recebidos
 * @param argv Parâmetros recebidos
 * @return int 0 SUCCESS Arquivo codificado
 * @return int 1 ERROR Argumntos não digitados corretamente
 */
int main(int argc, char const* argv[]) {
  std::string opition = argv[1];
  if (opition == "sdes") {
    if (argc == 5) {
      // Codificador
      std::string openfile = argv[2];
      std::string saveFile = argv[3];
      std::string masterKey = argv[4];
      try {
        SDES codificar(openfile, saveFile, masterKey);
      } catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
    } else {
      if (argc == 4) {
        // Decodificador
        std::string openfile = argv[2];
        std::string masterKey = argv[3];
        try {
          SDES decodificar(openfile, masterKey);
        } catch (const char* msg) {
          std::cerr << msg << std::endl;
        }
      } else {
        std::cout << "Erro! Digitar os argumentos corretamente." << std::endl;
        return 1;
      }
    }
  } else {
    if (opition == "rc4") {
      if (argc == 5) {
        std::string openfile = argv[2];
        std::string saveFile = argv[3];
        std::string masterKey = argv[4];
        try {
          RC4 codificar(openfile, saveFile, masterKey);
        } catch (const char* msg) {
          std::cerr << msg << std::endl;
        }
      } else {
        if (argc == 4) {
          std::string openfile = argv[2];
          std::string masterKey = argv[3];
          try {
            RC4 decodificar(openfile, masterKey);
          } catch (const char* msg) {
            std::cerr << msg << std::endl;
          }
        } else {
          std::cout << "Erro! Digitar os argumentos corretamente." << std::endl;
          return 1;
        }
      }
    } else {
      if (opition == "chat") {
        if (argc == 3) {
          try {
            Chat newchat(argv[2]);
          } catch (const char* msg) {
            std::cerr << msg << std::endl;
          }
        } else {
          std::cout << "Erro! Digitar os argumentos corretamente." << std::endl;
          return 1;
        }
      } else {
        if (opition == "chatDH") {
          try {
            ChatDH newchatDH(argv[2]);
          } catch (const char* msg) {
            std::cerr << msg << std::endl;
          }
        } else {
          std::cout << "Erro! Digitar os argumentos corretamente." << std::endl;
          return 1;
        }
      }
    }
  }
  return 0;
}
