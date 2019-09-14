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