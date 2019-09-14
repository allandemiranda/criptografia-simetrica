/**
 * @file EncodeDes.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para codificar texto recebido
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef ENCODEDES_H_
#define ENCODEDES_H_

#include "FunctionDes.h"

class EncodeDes : public FunctionDes {
 private:
  char finalPlaintext;  // Texto criptografado

 public:
  char getFinalPlaintext(void);  // Obter texto criptografado
  EncodeDes(char, char, char);
  ~EncodeDes(void);
};

#endif