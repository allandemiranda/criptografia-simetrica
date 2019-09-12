/**
 * @file KeyGeneration.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para gerar as sub chaves usadas no S-DES
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef KEYGENERATION_H_
#define KEYGENERATION_H_

#include <string>  // std::string
#include <vector>  // std::vector

class KeyGeneration {
 private:
  std::string permutation(std::string,
                          std::vector<unsigned int>);  // Permutação da chave
  std::vector<unsigned int> P10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};  // P10
  std::vector<unsigned int> P8 = {6, 3, 7, 4, 8, 5, 10, 9};         // P8
  std::string LS(std::string, unsigned int);                        // LS
  std::string keyRight(std::string);  // Parte direita da chave
  std::string keyLeft(std::string);   // Parte esquerda da chave
  std::vector<std::string> keys;

 public:
  std::string getKey(unsigned int);  // Obter chave
  KeyGeneration(std::string);
  ~KeyGeneration(void);
};

#endif