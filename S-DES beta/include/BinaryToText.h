/**
 * @file BinaryToText.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para converter de binário para texto
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BINARYTOTEXT_H_
#define BINARYTOTEXT_H_

#include <string>  // std::string
#include <vector>  // std::vector

class BinaryToText {
 private:
  void convertToText(std::string);    // Converter de binário para texto
  std::vector<std::string> text;      // Texto normal
  std::string lineFeed = "00001010";  // Fim de linha "/n"

 public:
  unsigned long getSizeText(void);     // Obter o tamanho do texto em linhas
  std::string getLine(unsigned long);  // Obter linha do texto
  BinaryToText(std::string);
  ~BinaryToText(void);
};

#endif