/**
 * @file FunctionDes.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Função principal do S-DES
 * @version 0.1
 * @date 10-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef FUNCTIONDES_H_
#define FUNCTIONDES_H_

#include <string>  // std::string
#include <vector>  // std::vector

class FunctionDes {
 protected:
  std::vector<unsigned int> IP = {2, 6, 3, 1, 4, 8, 5, 7};
  std::vector<unsigned int> IP1 = {4, 1, 3, 5, 7, 2, 8, 6};
  std::vector<unsigned int> EP = {4, 1, 2, 3, 2, 3, 4, 1};
  std::vector<unsigned int> P4 = {2, 4, 3, 1};
  std::vector<std::vector<unsigned int>> S0 = {
      {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
  std::vector<std::vector<unsigned int>> S1 = {
      {1, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};
  std::string permutation(std::string,
                          std::vector<unsigned int>);  // Permutação da chave
  std::string xorOperation(std::string, std::string);  // Operação xor
  std::string keyRight(std::string);                   // Parte direita da chave
  std::string keyLeft(std::string);  // Parte esquerda da chave
  std::string sBox(std::string,
                   std::vector<std::vector<unsigned int>>);  // Permutação sBox

 public:
  FunctionDes(void);
  ~FunctionDes(void);
};

#endif