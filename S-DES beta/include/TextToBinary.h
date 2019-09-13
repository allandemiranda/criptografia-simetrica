/**
 * @file TextToBinary.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para trasformar um vetor de texto em uma string binária
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef TEXTTOBINARY_H_
#define TEXTTOBINARY_H_

#include <string>  // std::string
#include <vector>  // std::vector

class TextToBinary {
 private:
  void convertToBinary(std::string);  // Converter texto em binário
  std::string textBinary;             // Texto converrtido para binário
  std::string lineFeed = "00001010";  // Fim de linha "/n"

 public:
  std::string getBinary(void);  // Obter o texto em binário
  TextToBinary(std::string);
  ~TextToBinary(void);
};

#endif