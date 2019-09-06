//**
 * @file RC4.cpp
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief 
 * @version 0.1
 * @date 2019-09-06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "RC4.h"
#include <iostream>
#include <string>

RC4::RC4(unsigned char* pChave, unsigned int tamanhoChave) {
  iniciarRC4(pChave, tamanhoChave);
}

RC4::~RC4() {}

void
RC4::iniciarRC4(unsigned char* pChave, unsigned int tamanhoChave) {
  j = 0;

  for (i = 0; i < 256; i++) {
    m_sBox[i] = i;
  }

  for (i = 0; i < 256; i++) {
    j = (j + m_sBox[i] + pChave[i % lenKey]) % 256;
    troca = m_sBox[i];
    m_sBox[i] = m_sBox[j];
    m_sBox[i] = troca;
  }
}

void 
RC4::cifrarRC4(unsigned char pDado[], unsigned long tamanhoDado) {
  int sBox[256];
  int a = 0, b = 0;
  long deslocamento;

  // Armazenando uma cópia da nossa caixa de substituição direto da memória.
  memcpy(sBox, m_sBox, 256 * sizeof(int));

  // Encriptando o dado.
  for (deslocamento = 0; deslocamento < tamanhoDado; deslocamento++) {
    a = (a + 1) % 256;
    b = (b + sBox[a]) % 256;
    troca = sBox[a];
    sBox[a] = sBox[b];
    sBox[b] = troca;
    // ^ = operador "ou" exclusivo bit a bit (XOR).
    pDado[deslocamento] ^= sBox[(sBox[a] + sBox[b]) % 256];
  }
}

// Salva o dado em uma string separada.
string 
RC4::bkpString(unsigned char* pDadoDeEntrada, unsigned long tamanhoDoDado) {
  string sEntradaSaidaDeDado((char*)pDadoDeEntrada, tamanhoDoDado);
  RC4((unsigned char*)sEntradaSaidaDeDado.c_str(), tamanhoDoDado);
  return sEntradaSaidaDeDado;
}