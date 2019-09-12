/**
 * @file EncodeDes.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Clase para codificar string binária
 * @version 0.1
 * @date 10-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef ENCODEDES_H_
#define ENCODEDES_H_

#include "FunctionDes.h"

#include <string>  // std::string

class EncodeDes : public FunctionDes {
 private:
  void process(std::string, std::string,
               std::string);   // Processamento de codificação
  std::string finalPlaintext;  // Código de 8-bit codificado
 public:
  std::string getFinalPlaintext(void);  // Obter código codificado
  EncodeDes(std::string, std::string, std::string);
  ~EncodeDes(void);
};

#endif