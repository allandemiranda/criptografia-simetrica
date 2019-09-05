/**
 * @file TextEncoder.cpp
 * @author Allan de Miranda
 * @brief
 * @version 0.1
 * @date 2019-09-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "TextEncoder.h"

#include <bitset>
#include <fstream>
#include <iostream>
#include <string>

TextEncoder::TextEncoder(std::vector<std::string> keys, std::string path,
                         std::string newInitialPermutation,
                         std::string newFinalPermutation, std::string newEP) {
  if (newInitialPermutation != "") {
    initialPermutation = newInitialPermutation;
  }
  if (newFinalPermutation != "") {
    finalPermutation = newFinalPermutation;
  }
  if (newEP != "") {
    EP = newEP;
  }
  std::string binaryText = getText(path);
  initialPermutationVector = explode(initialPermutation);
  finalPermutationVector = explode(finalPermutation);
  if (!checkPermutationVector(keys[0].size(), initialPermutationVector)) {
    throw "Incompatibilidade entre o tamanho da chave e a configuração de criação";
  }
  if (!checkPermutationVector(keys[0].size(), finalPermutationVector)) {
    throw "Incompatibilidade entre o tamanho da chave e a configuração de criação";
  }

  std::string finalBinaryText;
  for (auto i(0u); i < (binaryText.size() / keys[0].size()); ++i) {
    std::string tempBinaryText;
    for (auto j(0u); j < keys[0].size(); ++j) {
      tempBinaryText.push_back(binaryText[(i * keys[0].size()) + j]);
    }
    tempBinaryText = manipulateP(tempBinaryText, initialPermutationVector);
    for(auto j(0u); j<keys.size(); ++j){

    }
  }
}

TextEncoder::~TextEncoder() {}

/**
 * @brief Função para abrir aquivo de texto
 *
 * @param path Caminho do arquivo
 * @return std::string Texto
 */
std::string TextEncoder::getText(std::string path) {
  std::string text;
  try {
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
      for (auto i(0u); i < line.size(); ++i) {
        text += std::bitset<8>(line[i]).to_string();
      }
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << "Erro ao abrir arquivo de texto" << std::endl;
  }
  return text;
}

/**
 * @brief Função para converter a string em um vetor de números
 *
 * @param P String com a sequência de manipulação
 * @return const std::vector<std::string>
 */
const std::vector<unsigned long> TextEncoder::explode(const std::string& P) {
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
 * @brief Verificador de consistência de configurações para permutação
 *
 * @param nSize Tamanho da chave principal
 * @param Pvector Vetor com refências de permutação de posições
 * @return true Posições compatíveis
 * @return false Posições não compatíveis
 */
bool TextEncoder::checkPermutationVector(unsigned long nSize,
                                         std::vector<unsigned long>& Pvector) {
  for (unsigned long i = 0; i < Pvector.size(); ++i) {
    if (Pvector[i] > nSize) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Função para fazer a manitupação
 *
 * @param key Chave inicial
 * @param P Vetor com a sequência de manipulação
 * @return std::string Chave final manipulada
 */
std::string TextEncoder::manipulateP(std::string& key,
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
std::string TextEncoder::txtLeft(std::string key) {
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
std::string TextEncoder::txtRight(std::string key) {
  std::string newKeyRight;
  for (auto i(key.size() / 2); i < key.size(); ++i) {
    newKeyRight.push_back(key[i]);
  }
  return newKeyRight;
}

std::string TextEncoder::operationXor(std::string text, std::string key){
    
}