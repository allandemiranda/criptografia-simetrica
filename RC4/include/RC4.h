//**
 * @file RC4.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief 
 * @version 0.1
 * @date 2019-09-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef _RC4_H_
#define _RC4_H_

#include <string>
using namespace std;

class RC4 {
 private:
  int m_sBox[256];
  unsigned char troca;
  int i, j;

 public:
  RC4(unsigned char* pChave, unsigned int tamanhoChave);
  ~RC4();

  void cifrarRC4(unsigned char pDado[], unsigned long tamanhoDado);
  string bkpString(unsigned char* pDadoDeEntrada, unsigned long tamanhoDoDado);
  void cifrar(unsigned char* pChave, unsigned int tamanhoChave);
};

#endif  //_RC4_H_