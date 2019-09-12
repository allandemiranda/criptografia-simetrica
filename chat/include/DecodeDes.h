/**
 * @file DecodeDes.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para decodificar texto em binário
 * @version 0.1
 * @date 10-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef DECODEDES_H_
#define DECODEDES_H_

#include "FunctionDes.h"

#include <string>  // std::string

class DecodeDes : public FunctionDes {
 private:
  void process(std::string, std::string,
               std::string);   // Processamento de decodificação
  std::string finalPlaintext;  // Código de 8-bit decodificado
 public:
  std::string getFinalPlaintext(void);  // Obter código decodificado
  DecodeDes(std::string, std::string, std::string);
  ~DecodeDes(void);
};

#endif