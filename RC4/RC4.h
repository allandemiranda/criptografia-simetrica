/**
 * @file RC4.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos 
 * @brief 
 * @version 0.1
 * @date 14-09-2019
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
    int sBox_m[256];
    unsigned char troca;
    int i, j;

  public:
    RC4(unsigned char* pChave, unsigned int tamanhoChave);  
    RC4();
    void cifrarRC4(unsigned char pDado[], unsigned long tamanhoDado);
    string bkpString(unsigned char* pDadoDeEntrada, unsigned long tamanhoDoDado);
    void iniciarKSA(unsigned char* pChave, unsigned int tamanhoChave);
};

#endif  //_RC4_H_