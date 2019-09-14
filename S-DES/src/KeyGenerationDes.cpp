/**
 * @file KeyGenerationDes.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos para a class KeyGenerationDes
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "KeyGenerationDes.h"

#include <bitset>  // std::bitset

/**
 * @brief Construct a new Key Generation Des:: Key Generation Des object
 *
 * @param key_master Chave principal
 */
KeyGenerationDes::KeyGenerationDes(std::string key_master) {
  if (key_master.size() != 10) {
    throw "Tamanho da chave principal não é compatível para criação de sub chaves";
  }
  key_master = getPermutation(key_master, P10);
  key_master =
      getLS(getKeyLeft(key_master), 1) + getLS(getKeyRight(key_master), 1);
  keys.push_back(static_cast<char>(
      std::bitset<8>(getPermutation(key_master, P8)).to_ulong()));
  key_master =
      getLS(getKeyLeft(key_master), 2) + getLS(getKeyRight(key_master), 2);
  keys.push_back(static_cast<char>(
      std::bitset<8>(getPermutation(key_master, P8)).to_ulong()));
}

/**
 * @brief Destroy the Key Generation Des:: Key Generation Des object
 *
 */
KeyGenerationDes::~KeyGenerationDes(void) {}

/**
 * @brief Set the Sub Key object
 *
 * @param sub_key Sub chave
 */
void KeyGenerationDes::setSubKey(char sub_key) { keys.push_back(sub_key); }

/**
 * @brief Permutar a chave
 *
 * @param key Chave
 * @param feistel Sequência de permutação
 * @return std::string Chave permutada
 */
std::string KeyGenerationDes::getPermutation(
    std::string key, std::vector<unsigned int> feistel) {
  for (unsigned int i = 0; i < feistel.size(); ++i) {
    if (feistel[i] > 8) {
      throw "Vetor Feistel contem elemento maior que tamanho da chave";
    }
    if (feistel[i] == 0) {
      throw "Vetor Feistel contem elemento fora da chave";
    }
  }
  std::string final_Key;
  for (unsigned int position : feistel) {
    final_Key.push_back(key[position - 1]);
  }
  return final_Key;
}

/**
 * @brief Mover chave a esquerda
 *
 * @param key Chave de entrada
 * @param repetition Quantidade de movimentações
 * @return std::string Chave final
 */
std::string KeyGenerationDes::getLS(std::string key, unsigned int repetition) {
  if (key.size() == 0) {
    throw "Insira uma chave com no mínimo um bit para operação LS";
  }
  for (auto i(0u); i < repetition; ++i) {
    std::string last(1, key.back());  // char para string
    key.insert(0, last);
    key.pop_back();
  }
  return key;
}

/**
 * @brief Obter lado direito da chave
 *
 * @param key Chave de entrada
 * @return std::string Lado direito da chave
 */
std::string KeyGenerationDes::getKeyRight(std::string key) {
  std::string finalKey;
  for (auto i(key.size() / 2); i < key.size(); ++i) {
    finalKey.push_back(key[i]);
  }
  return finalKey;
}

/**
 * @brief Obter lado esquerdo da chave
 *
 * @param key Chave de entrada
 * @return std::string Lado direito da chave
 */
std::string KeyGenerationDes::getKeyRight(std::string key) {
  std::string key_string = std::bitset<8>(key).to_string();
  std::string finalKey;
  for (auto i(0u); i < (key_string.size() / 2); ++i) {
    finalKey.push_back(key_string[i]);
  }
  return finalKey;
}

/**
 * @brief Get the Sub Key object
 *
 * @param number_key Número da chave
 * @return char Chave
 */
char KeyGenerationDes::getSubKey(unsigned int number_key) {
  if ((number_key != 1) and (number_key != 2)) {
    throw "Sub chave indisponível";
  }
  return keys[number_key - 1];
}