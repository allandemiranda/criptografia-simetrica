/**
 * @file KeyGenerationDes.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class para a geração de chaves do S-DES
 * @version 0.1
 * @date 13-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef KEYGENERATIONDES_H_
#define KEYGENERATIONDES_H_

#include <string>  // std::string
#include <vector>  // std::vector

class KeyGenerationDes {
 private:
  std::string keyMaster;   // Chave principal
  std::vector<char> keys;  // Chaves geradas
  void setSubKey(char);    // Definir sub chave
  std::string getPermutation(std::string,
                             std::vector<unsigned int>);  // Permutação de chave
  std::vector<unsigned int> P10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};  // P10
  std::vector<unsigned int> P8 = {6, 3, 7, 4, 8, 5, 10, 9};         // P8
  std::string getLS(std::string, unsigned int);                     // LS
  std::string getKeyRight(std::string);  // Parte direita da chave em string
  std::string getKeyLeft(std::string);   // Parte esquerda da chave em string

 public:
  char getSubKey(unsigned int);  // Ober sub chave
  KeyGenerationDes(std::string);
  ~KeyGenerationDes(void);
};

#endif