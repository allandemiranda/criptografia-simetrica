/**
 * @file KeyGeneration.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da class KeyGeneration
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "KeyGeneration.h"

#include <string>  // std::string
#include <vector>  // std::vector

/**
 * @brief Construct a new Key Generation:: Key Generation object
 *
 * @param key Chave principal 10-bit
 */
KeyGeneration::KeyGeneration(std::string key) {
  if (key.size() != 10) {
    throw "Tamanho da chave principal não é compatível";
  }
  key = permutation(key, P10);
  key = LS(keyLeft(key), 1) + LS(keyRight(key), 1);
  keys.push_back(permutation(key, P8));
  key = LS(keyLeft(key), 2) + LS(keyRight(key), 2);
  keys.push_back(permutation(key, P8));
}

/**
 * @brief Destroy the Key Generation:: Key Generation object
 *
 */
KeyGeneration::~KeyGeneration(void) {}

/**
 * @brief Permutação de Feistel
 *
 * @param key Chave inicial
 * @param feistel Sequência de Feistel
 * @return std::string Chave final
 */
std::string KeyGeneration::permutation(std::string key,
                                       std::vector<unsigned int> feistel) {
  for (auto i(0u); i < feistel.size(); ++i) {
    if (feistel[i] > key.size()) {
      throw "Vetor Feistel contem elemento maior que tamanho da chave";
    }
    if (feistel[i] == 0) {
      throw "Vetor Feistel contem elemento menor que tamanho da chave";
    }
  }
  std::string finalKey;
  for (unsigned int position : feistel) {
    finalKey.push_back(key[position - 1]);
  }
  return finalKey;
}

/**
 * @brief Deslocar para a esquerda
 *
 * @param key Chave inicial
 * @param time Quantidade de deslocamentos
 * @return std::string Chave final
 */
std::string KeyGeneration::LS(std::string key, unsigned int time) {
  if (time == 0) {
    throw "A quantidade de operações de deslocamento deve ser maior que zero";
  } else {
    for (auto i(0u); i < time; ++i) {
      std::string last(1, key.back());  // char para string
      key.insert(0, last);
      key.pop_back();
    }
    return key;
  }
}

/**
 * @brief Obter lado esquerdo da chave
 *
 * @param key Chave inicial
 * @return std::string Lado esquerdo da chave inicial
 */
std::string KeyGeneration::keyLeft(std::string key) {
  unsigned int sizeKey = key.size();
  std::string finalKey;
  for (auto i(0u); i < (sizeKey / 2); ++i) {
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
std::string KeyGeneration::keyRight(std::string key) {
  unsigned int sizeKey = key.size();
  std::string finalKey;
  for (auto i(sizeKey / 2); i < sizeKey; ++i) {
    finalKey.push_back(key[i]);
  }
  return finalKey;
}

/**
 * @brief Obter chave gerada
 *
 * @param number Número da chave (1 ou 2)
 * @return std::string Chave gerada
 */
std::string KeyGeneration::getKey(unsigned int number) {
  if ((number == 0) or (number > 2)) {
    throw "Número de chave solicitada inválida";
  } else {
    return keys[number - 1];
  }
}