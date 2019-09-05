/**
 * @file SubKeyGenerate.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "SubKeyGenerate.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Construct a new Sub Key Generate:: Sub Key Generate object
 *
 * @param keyMaster Chave principal
 */
SubKeyGenerate::SubKeyGenerate(std::string keyPath, unsigned long nodes,
                               std::string pMaster, std::string pSecond) {
  if (keyPath != "") {
    masterKeyPath = keyPath;
  }
  if (nodes != 0) {
    numberOfNodes = nodes;
  }
  if (pMaster != "") {
    PMaster = pMaster;
  }
  if (pSecond != "") {
    PSecond = pSecond;
  }
  masterKey = getMasterKey(masterKeyPath);
  PMasterVector = explode(PMaster);
  PSecondVector = explode(PSecond);
  if (!checkPVector(masterKey.size(), PMasterVector)) {
    throw "Incompatibilidade entre o tamanho da chave e a configuração de criação";
  }
  if (!checkPVector(masterKey.size(), PSecondVector)) {
    throw "Incompatibilidade entre o tamanho da chave e a configuração de criação";
  }
  masterKey = manipulateP(masterKey, PMasterVector);
  for (auto i(0u); i < numberOfNodes; ++i) {
    masterKey =
        LS((i + 1), keyLeft(masterKey)) + LS((i + 1), keyRight(masterKey));
    subKeys.push_back(manipulateP(masterKey, PSecondVector));
  }
}

/**
 * @brief Destroy the Sub Key Generate:: Sub Key Generate object
 *
 */
SubKeyGenerate::~SubKeyGenerate() {}

/**
 * @brief Função para abrir ler arquivo da chave principal
 *
 * @param keyPath Caminho da chave
 * @return std::string Chave principal
 */
std::string SubKeyGenerate::getMasterKey(std::string keyPath) {
  std::string key;
  try {
    std::ifstream file(keyPath);
    std::string line;
    while (std::getline(file, line)) {
      key = line;
      break;
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << "Erro ao abrir a chave" << std::endl;
  }
  return key;
}

/**
 * @brief Função para converter a string em um vetor de números
 *
 * @param P String com a sequência de manipulação
 * @return const std::vector<std::string>
 */
const std::vector<unsigned long> SubKeyGenerate::explode(const std::string& P) {
  char c = ' ';
  std::string buff{""};
  std::vector<unsigned long> v;

  for (auto n : P) {
    if (n != c) {
      buff += n;
    } else if (n == c && buff != "") {
      v.push_back(std::stoi(buff));
      buff = "";
    }
  }
  if (buff != "") {
    v.push_back(std::stoi(buff));
  }

  return v;
}

/**
 * @brief Verificador de consistência de configurações para geração de chave
 *
 * @param nSize Tamanho da chave principal
 * @param Pvector Vetor com refências de permutação de posições
 * @return true Posições compatíveis
 * @return false Posições não compatíveis
 */
bool SubKeyGenerate::checkPVector(unsigned long nSize,
                                  std::vector<unsigned long>& Pvector) {
  for (unsigned long i = 0; i < Pvector.size(); ++i) {
    if (Pvector[i] > nSize) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Função para fazer a manitupação da chave
 *
 * @param key Chave inicial
 * @param P Vetor com a sequência de manipulação
 * @return std::string Chave final manipulada
 */
std::string SubKeyGenerate::manipulateP(std::string& key,
                                        std::vector<unsigned long>& P) {
  std::string newKey;
  for (unsigned long n : P) {
    newKey.push_back(key[n - 1]);
  }
  return newKey;
}

/**
 * @brief Função para dividir a Chave do lado esquerdo
 *
 * @param key Chave principal
 * @return std::string Chave do lado esquerdo
 */
std::string SubKeyGenerate::keyLeft(std::string key) {
  std::string newKeyLeft;
  for (auto i(0u); i < (key.size() / 2); ++i) {
    newKeyLeft.push_back(key[i]);
  }
  return newKeyLeft;
}

/**
 * @brief Função para dividir a chave do lado direito
 *
 * @param key Chave princial
 * @return std::string Chave do lado direito
 */
std::string SubKeyGenerate::keyRight(std::string key) {
  std::string newKeyRight;
  for (auto i(key.size() / 2); i < key.size(); ++i) {
    newKeyRight.push_back(key[i]);
  }
  return newKeyRight;
}

/**
 * @brief Função para mover o código para esquerda
 *
 * @param repetition Quantridade de trocas
 * @param key Chave de entrada
 * @return std::string Chave de saída
 */
std::string SubKeyGenerate::LS(unsigned long repetition, std::string key) {
  std::string newKey = key;
  for (auto i(0u); i < repetition; ++i) {
    std::string lastW(1, newKey.back());
    newKey.insert(0, lastW);
    newKey.pop_back();
  }
  return newKey;
}