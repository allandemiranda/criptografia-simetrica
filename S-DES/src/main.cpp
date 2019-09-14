/**
 * @file s-des-encode.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Programa para codificar texto pelo S-DES
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>  // std::cout, std::endl;
#include <string>    // std::string
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
  if (argc == 4) {
    // Codificador
    std::string masterKey = "1010011101";
    std::string openfile = argv[1];
    std::string saveFile = argv[2];
    try {
      SDES codificar(openfile, saveFile, masterKey);
    } catch (const char* msg) {
      std::cerr << msg << std::endl;
    }
  } else {
    if (argc == 3) {
      // Decodificador
      std::string masterKey = "1010011101";
      std::string openfile = argv[1];
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
  return 0;
}
