/**
 * @file KeyGenerate.cpp
 * @author Allan de Miranda
 * @brief Métodos da classe KeyGenerate
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "KeyGenerate.h"

#include <bitset>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Construct a new Key Generate:: Key Generate object
 *
 * @param keySize Tamanho da chake em bit's a ser gerada
 * @param optionPath Configuração avançada de local para salvar chave gerada
 */
KeyGenerate::KeyGenerate(unsigned long keySize, std::string optionPath) {
  if (optionPath != "") {
    keySavePath = optionPath;
  }
  createKeyFile(createKeyMaster(keySize), keySavePath);
}

/**
 * @brief Destroy the Key Generate:: Key Generate object
 *
 */
KeyGenerate::~KeyGenerate() {}

/**
 * @brief função para verficar se a chave solicitada está no tamanho correto
 *
 * @param newkeySize Tamanho da chave solicitada
 * @return true Tamanho correto
 * @return false Tamanho errado
 */
bool KeyGenerate::checkKeySize(unsigned long newKeySize) {
  if (newKeySize % 2 != 0) {
    return false;
  } else {
    return true;
  }
}

/**
 * @brief Função de criação da chave principal
 *
 * @param newKeySize Tamanho da chave
 * @return std::string
 */
std::string KeyGenerate::createKeyMaster(unsigned long newKeySize) {
  if (!checkKeySize(newKeySize)) {
    throw "O tamanho da chave deve sempre ser um número par";
  }
  std::time_t time = std::time(NULL);  // Hora do sistema
  std::string timeString =
      std::asctime(std::localtime(&time));  // Transformar data em string
  unsigned long timeStringSize =
      timeString.size();  // Tamanho da string da data
  std::string key;        // Chave final
  std::srand(std::time(nullptr));
  for (auto i(0u); i < newKeySize; ++i) {
    unsigned long positionDate =
        std::rand() / ((RAND_MAX + 1u) /
                       timeStringSize);  // Pegar uma posição aleatória da data
    unsigned int positionBit =
        std::rand() /
        ((RAND_MAX + 1u) / 8);  // Pegar uma posição aleatória de 8 bits
    key.push_back(
        std::bitset<8>(timeString[positionDate]).to_string()[positionBit]);
  }
  return key;
}

/**
 * @brief Função para criar arquivo com a chave principal
 *
 * @param keyMaster Chave principal
 * @param keyPath Local onde salvar chave
 */
void KeyGenerate::createKeyFile(std::string keyMaster, std::string keyPath) {
  std::ofstream newFile;
  keyPath += "/key.sdes";
  newFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    newFile.open(keyPath, std::ios::trunc);
    for (char n : keyMaster) {
      newFile << n;
    }
    newFile.close();
  } catch (std::ifstream::failure e) {
    std::cerr << "Erro ao criar arquivo da chave --> " <<  keyPath << std::endl;
  }
}