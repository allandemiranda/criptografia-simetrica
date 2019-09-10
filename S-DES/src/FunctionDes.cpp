/**
 * @file FunctionDes.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da classe FunctionDes
 * @version 0.1
 * @date 10-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "FunctionDes.h"

#include <string>  // std::string
#include <vector>  // std::vector

/**
 * @brief Construct a new Function Des:: Function Des object
 *
 */
FunctionDes::FunctionDes(void) {}

/**
 * @brief Destroy the Function Des:: Function Des object
 *
 */
FunctionDes::~FunctionDes(void) {}

/**
 * @brief Obter lado esquerdo da chave
 *
 * @param key Chave inicial
 * @return std::string Lado esquerdo da chave inicial
 */
std::string FunctionDes::keyLeft(std::string key) {
  std::string finalKey;
  for (auto i(0u); i < 5; ++i) {
    finalKey.push_back(key[i]);
  }
  return finalKey;
}

/**
 * @brief Obter lado direito da chave
 *
 * @param key Chave inicial
 * @return std::string Lado direito da chave inicial
 */
std::string FunctionDes::keyRight(std::string key) {
  std::string finalKey;
  for (auto i(5u); i < 10; ++i) {
    finalKey.push_back(key[i]);
  }
  return finalKey;
}

/**
 * @brief Permutação de Feistel
 *
 * @param key Chave inicial
 * @param feistel Sequência de Feistel
 * @return std::string Chave final
 */
std::string FunctionDes::permutation(std::string key,
                                     std::vector<unsigned int> feistel) {
  std::string finalKey;
  for (unsigned int position : feistel) {
    finalKey.push_back(key[position - 1]);
  }
  return finalKey;
}

/**
 * @brief Operação xor
 *
 * @param epKey Chave do processo ep
 * @param subKey Sub chave gerada
 * @return std::string
 */
std::string FunctionDes::xorOperation(std::string epKey, std::string subKey) {
  if (epKey.size() != subKey.size()) {
    throw "Tamanho das chaves diferentes para operação xor";
  } else {
    std::string finalXor;
    for (auto i(0u); i < epKey.size(); ++i) {
      if (epKey[i] == subKey[i]) {
        finalXor.push_back('0');
      } else {
        finalXor.push_back('1');
      }
    }
    return finalXor;
  }
}