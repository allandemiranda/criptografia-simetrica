/**
 * @file main.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos 
 * @brief 
 * @version 0.1
 * @date 05-09-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "KeyGenerate.h"
#include "SubKeyGenerate.h"
#include "TextEncoder.h"

#include <iostream>
#include <string>

int main(int argc, char const* argv[]) {
  // Opção para o gerador de chave
  if (argc == 3) {
    std::string option = argv[1];
    if (option == "newKey") {
      unsigned long keySize = atoi(argv[2]);
      try {
        KeyGenerate novaChave(keySize, "");
        std::cout << "Chave criada com sucesso" << std::endl;
      } catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
    }
  }
  if (argc == 4) {
    std::string option = argv[1];
    if (option == "newKey") {
      unsigned long keySize = atoi(argv[2]);
      std::string pach = argv[3];
      try {
        KeyGenerate novaChave(keySize, pach);
        std::cout << "Chave criada com sucesso" << std::endl;
      } catch (const char* msg) {
        std::cerr << msg << std::endl;
      }
    }
  }

  // Configurações S-DES
  std::string keyPath = "";  // Ex: "/home/user/keys/key.sdes" -- Default: ""
  unsigned long nodes = 0;   // Ex: 5 -- Default: 0
  std::string pMaster = "";  // Ex: "3 5 2 7 4 10 1 9 8 6" -- Defalt: ""
  std::string pSecond = "";  // Ex: "3 5 2 7 4 10 1 9 8 6" -- Defalt: ""
  std::string initialPermutation =
      "";  // Ex: "3 5 2 7 4 10 1 9 8 6" -- Defalt: ""
  std::string finalPermutation =
      "";  // Ex: "3 5 2 7 4 10 1 9 8 6" -- Defalt: ""

  // Opções para codificador
  // try {
  //   SubKeyGenerate novo("", 0, "", "");
  // } catch (const char* msg) {
  //   std::cerr << msg << std::endl;
  // }
std::vector<std::string> a;
  //TextEncoder novo(a, "", "", "");

      // Opções para decodificador

      return 0;
}
