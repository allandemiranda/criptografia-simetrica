/**
 * @file RC4.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos 
 * @brief 
 * @version 0.1
 * @date 14-09-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "RC4.h"

RC4::RC4(unsigned char* pChave, unsigned int tamanhoChave) {
  iniciarKSA(pChave, tamanhoChave);
}
RC4::RC4() {}

/**
 * @brief Inicializa da caixa de substituição, baseando-se na chave
 * fornecida. Retorna a caixa S com valores alterados, conforme a 
 * chave.
 * 
 */
void
RC4::iniciarKSA(unsigned char* pChave, unsigned int tamanhoChave) {
  j = 0;
  /**
   * @brief Gera uma caixa com valores inteiros sequenciais de  a 255.
   * 
   */
  for (i = 0; i < 256; i++) {
    sBox_m[i] = i;
  }
  /**
   * @brief Os valores da caixa S serão trocados, um a um, de acordo o
   * a chave.
   * 
   */
  for (i = 0; i < 256; i++) {
    /**
     * @brief Algoritmo de troca de valores da caixa S. A chave pode ter,
     * no máximo 256 bytes, ou seja, pode ser uma outra caixa (vetor) com
     * até 256 caracteres.
     * 
     */
    j = (j + sBox_m[i] + sBox_m[i % tamanhoChave]) % 256;
    troca = sBox_m[i];
    sBox_m[i] = sBox_m[j];
    sBox_m[i] = troca;
  }
}

void 
RC4::cifrarRC4(unsigned char pMensagem[], unsigned long tamanhoMensagem) {
  int sBox[256];
  int i = 0, j = 0;
  long deslocamento;

  /**
   * @brief Armazenando uma cópia da nossa caixa de substituição direto da memória,
   * a fim de evitar recriar a caixa S toda vez que for cifrar/decifrar.
   * 
   */
  memcpy(sBox, sBox_m, 256 * sizeof(int));

  /**
   * @brief Encriptando o dado, ao gerar um fluxo pseudoaleatório que permite 
   * cifrar uma mensagem por meio de uma operação XOR.
   * 
   */
  for (deslocamento = 0; deslocamento < tamanhoMensagem; deslocamento++) {
    i = (i + 1) % 256;
    j = (j + sBox[i]) % 256;
    troca = sBox[i];
    sBox[i] = sBox[j];
    sBox[j] = troca;
    /**
     * @brief ^ = operador "ou exclusivo" bit a bit (XOR).
     * 
     */
    pMensagem[deslocamento] ^= sBox[(sBox[i] + sBox[j]) % 256];
  }
}

/**
 * @brief Salva a mensagem separadamente, com intuito de não sobrescrever a existente.
 * 
 */
string
RC4::bkpString(unsigned char* pDadoDeEntrada, unsigned long tamanhoDoDado) {

  string sEntradaSaidaDeDado((char*)pDadoDeEntrada, tamanhoDoDado);
  RC4((unsigned char*)sEntradaSaidaDeDado.c_str(), tamanhoDoDado);
  return sEntradaSaidaDeDado;

}