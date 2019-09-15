/**
 * @file KSA.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da class KSA
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "KSA.h"
#include <bitset>  // std::bitset

/**
 * @brief Construct a new KSA::KSA object
 *
 * @param key Chave inicial
 */
KSA::KSA(std::string key) {
  S = setPermutatio(setOrdenation(), setT(setK(key)));
}

/**
 * @brief Destroy the KSA::KSA object
 *
 */
KSA::~KSA(void) {}

/**
 * @brief Set the Permutatio object
 *
 * @param S_temp Vetor S
 * @param T_temp Vetor T
 * @return std::vector<unsigned int> Vetor S final
 */
std::vector<unsigned int> KSA::setPermutatio(std::vector<unsigned int> S_temp,
                                             std::vector<unsigned int> T_temp) {
  for (unsigned int i(0), j(0); i < 256; ++i) {
    j = (j + S_temp[i] + T_temp[i]) % 256;
    unsigned int temp = S_temp[i];
    S_temp[i] = S_temp[j];
    S_temp[j] = temp;
  }
  return S_temp;
}

/**
 * @brief Definir vetor T
 *
 * @param temp_K Vetor K
 * @return std::vector<unsigned int> Vetor T
 */
std::vector<unsigned int> KSA::setT(std::vector<unsigned int> temp_K) {
  std::vector<unsigned int> temp_T;
  for (unsigned int i(0); i < 256; ++i) {
    temp_T.push_back(temp_K[i % temp_K.size()]);
  }
  return temp_T;
}

/**
 * @brief Definir vetor K
 *
 * @param key Chave inicial
 * @return std::vector<unsigned int>  Vetor final
 */
std::vector<unsigned int> KSA::setK(std::string key) {
  std::vector<unsigned int> temp_K;
  for (auto i(0u); i < key.size(); ++i) {
    temp_K.push_back(std::bitset<8>(key[i]).to_ulong());
  }
  return temp_K;
}

/**
 * @brief Set the Ordenation object
 *
 * @return std::vector<unsigned int> Vetor de números ordenados
 */
std::vector<unsigned int> KSA::setOrdenation(void) {
  std::vector<unsigned int> temp;
  for (unsigned int i(0); i < 256; ++i) {
    temp.push_back(i);
  }
  return temp;
}

/**
 * @brief Obter vetor S
 *
 * @return std::vector<unsigned int> Vetor S
 */
std::vector<unsigned int> KSA::getS(void) { return S; }