/**
 * @file Encode.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Clase para codificar string binária
 * @version 0.1
 * @date 10-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef ENCODE_H_
#define ENCODE_H_

#include "FunctionDes.h"

#include <string>  // std::string
#include <vector>  // std::vector

class Encode : public FunctionDes {
 private:
  void process(std::string);   // Processamento de codificação
  std::string finalPlaintext;  // Código de 8-bit codificado
 public:
  std::string getFinalPlaintext(void);  // Obter código codificado
  Encode(std::string);
  ~Encode(void);
};

#endif