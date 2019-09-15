/**
 * @file FunctionDes.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class para gerenciar funções principais do S-DES
 * @version 0.1
 * @date 14-09-2019
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
  std::vector<unsigned int> IP = {2, 6, 3, 1, 4, 8, 5, 7};   // IP
  std::vector<unsigned int> IP1 = {4, 1, 3, 5, 7, 2, 8, 6};  // IP-1
  std::vector<unsigned int> EP = {4, 1, 2, 3, 2, 3, 4, 1};   // EP
  std::vector<unsigned int> P4 = {2, 4, 3, 1};               // P4
  std::vector<std::vector<unsigned int>> S0 = {
      {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};  // S0
  std::vector<std::vector<unsigned int>> S1 = {
      {1, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};  // S1
  std::string getXorOperation(std::string, std::string);  // Operação xor
  std::string getSBox(
      std::string,
      std::vector<std::vector<unsigned int>>);  // Permutação sBox
  // from key generation
  std::vector<unsigned int> P10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};  // P10
  std::vector<unsigned int> P8 = {6, 3, 7, 4, 8, 5, 10, 9};         // P8
  std::string getPermutation(std::string,
                             std::vector<unsigned int>);  // Permutação de chave
  std::string getLS(std::string, unsigned int);           // LS
  std::string getKeyRight(std::string);  // Parte direita da chave em string
  std::string getKeyLeft(std::string);   // Parte esquerda da chave em string

 public:
  FunctionDes(void);
  ~FunctionDes(void);
};

#endif