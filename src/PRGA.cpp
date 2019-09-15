/**
 * @file PRGA.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Método da class PRGA
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "PRGA.h"
#include <bitset>  // std::bitset

/**
 * @brief Construct a new PRGA::PRGA object
 *
 * @param S Vetor S
 * @param text Texto de entrada
 */
PRGA::PRGA(std::vector<unsigned int> S, std::vector<char> text) {
  int size = text.size();
  for (int i(0), j(0), k(0); k < size; ++k) {
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    int temp = S[i];
    S[i] = S[j];
    S[j] = temp;
    textF.push_back(getXor(S[(S[i] + S[j]) % 256], text[k]));
  }
}

/**
 * @brief obter operação xor
 *
 * @param num Número
 * @param c Caracter
 * @return int Valor final
 */
int PRGA::getXor(int num, char c) {
  int new_c = std::bitset<8>(c).to_ulong();
  return num ^ new_c;
}

/**
 * @brief Destroy the PRGA::PRGA object
 *
 */
PRGA::~PRGA(void) {}

/**
 * @brief Get the Text object
 *
 * @return std::vector<unsigned int> Numeric vector text
 */
std::vector<unsigned int> PRGA::getText(void) { return textF; }