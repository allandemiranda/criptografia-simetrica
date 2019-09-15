/**
 * @file DecodeDes.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class para decriptar chaves
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef DECODEDES_H_
#define DECODEDES_H_

#include "FunctionDes.h"

class DecodeDes : public FunctionDes {
 private:
  char finalPlaintext;  // Texto decriptado

 public:
  char getFinalPlaintext(void);  // Obter código decodificado
  DecodeDes(char, char, char);
  ~DecodeDes(void);
};

#endif