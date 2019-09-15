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

#include "FunctionDes.h"
#include <string>  // std::string
#include <vector>  // std::vector

class KeyGenerationDes : public FunctionDes{
 private:
  std::vector<char> keys;  // Chaves geradas
  void setSubKey(char);    // Definir sub chave  

 public:
  char getSubKey(unsigned int);  // Ober sub chave
  KeyGenerationDes(std::string);
  ~KeyGenerationDes(void);
};

#endif