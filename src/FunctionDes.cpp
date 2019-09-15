/**
 * @file FunctionDes.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos para class FunctionDes
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "FunctionDes.h"
#include <bitset>  // std::bitset

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
 * @brief Permutar a chave
 *
 * @param key Chave
 * @param feistel Sequência de permutação
 * @return std::string Chave permutada
 */
#include <iostream>
std::string FunctionDes::getPermutation(std::string key,
                                        std::vector<unsigned int> feistel) {
  for (unsigned int i = 0; i < feistel.size(); ++i) {
    if (feistel[i] > key.size()) {
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
std::string FunctionDes::getLS(std::string key, unsigned int repetition) {
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
std::string FunctionDes::getKeyRight(std::string key) {
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
std::string FunctionDes::getKeyLeft(std::string key) {
  std::string finalKey;
  for (auto i(0u); i < (key.size() / 2); ++i) {
    finalKey.push_back(key[i]);
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
std::string FunctionDes::getXorOperation(std::string epKey,
                                         std::string subKey) {
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

/**
 * @brief Obter o sistema sBox na chave
 *
 * @param key Chave inical
 * @param sBox
 * @return std::string
 */
std::string FunctionDes::getSBox(std::string key,
                                 std::vector<std::vector<unsigned int>> sBox) {
  if (key.size() != 4) {
    throw "Tamanho da chave é incompatível com a operação";
  } else {
    std::string lineSBOX = getKeyLeft(key);
    unsigned int numberLine;
    std::string colSBOX = getKeyRight(key);
    unsigned int numberCol;
    if (lineSBOX == "00") {
      numberLine = 0;
    } else {
      if (lineSBOX == "01") {
        numberLine = 1;
      } else {
        if (lineSBOX == "10") {
          numberLine = 2;
        } else {
          if (lineSBOX == "11") {
            numberLine = 3;
          } else {
            throw "Erro ao tentar achar o par no sBox";
          }
        }
      }
    }
    if (colSBOX == "00") {
      numberCol = 0;
    } else {
      if (colSBOX == "01") {
        numberCol = 1;
      } else {
        if (colSBOX == "10") {
          numberCol = 2;
        } else {
          if (colSBOX == "11") {
            numberCol = 3;
          } else {
            throw "Erro ao tentar achar o par no sBox";
          }
        }
      }
    }
    unsigned int numberSBox = sBox[numberLine][numberCol];
    if (numberSBox == 0) {
      return "00";
    } else {
      if (numberSBox == 1) {
        return "01";
      } else {
        if (numberSBox == 2) {
          return "10";
        } else {
          if (numberSBox == 3) {
            return "11";
          } else {
            throw "Erro ao tentar achar o par no sBox";
          }
        }
      }
    }
  }
}