/**
 * @file Encode.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da classe Encode
 * @version 0.1
 * @date 10-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Encode.h"

#include <string>  // std::string

/**
 * @brief Construct a new Encode:: Encode object
 *
 * @param plaintext Texto binário de entrada de 8-bit
 * @param keyOne Sub chave um
 * @param keyTwo Sub chave dois
 */
Encode::Encode(std::string plaintext, std::string keyOne, std::string keyTwo) {
  if (keyOne.size() != 8) {
    throw "Tamanho da chave um de criptografia incompatível";
  }
  if (keyTwo.size() != 8) {
    throw "Tamanho da chave dois de criptografia incompatível";
  }
  if (plaintext.size() != 8) {
    throw "Tamanho da chave de codificação incompatível";
  }
  process(plaintext, keyOne, keyTwo);
}

/**
 * @brief Destroy the Encode:: Encode object
 *
 */
Encode::~Encode(void) {}

/**
 * @brief Obter código codificado
 *
 * @return std::string Código codificado
 */
std::string Encode::getFinalPlaintext(void) { return finalPlaintext; }

/**
 * @brief Processamento de codificação S-DES
 *
 * @param textBinary Texto de entrada para codificação
 */
void Encode::process(std::string textBinary, std::string keyOne,
                     std::string keyTwo) {
  textBinary = permutation(textBinary, IP);

  std::string half = keyRight(textBinary);
  half = permutation(half, EP);                               // (1)
  half = xorOperation(half, keyOne);                          // (2)
  half = sBox(keyLeft(half), S0) + sBox(keyRight(half), S1);  // (3)
  half = permutation(half, P4);                               // (4)

  textBinary = keyRight(textBinary) +
               xorOperation(half, keyLeft(textBinary));  // (5) (6) (7)

  std::string halfSecond = keyRight(textBinary);
  halfSecond = permutation(halfSecond, EP);       // (1)
  halfSecond = xorOperation(halfSecond, keyTwo);  // (2)
  halfSecond =
      sBox(keyLeft(halfSecond), S0) + sBox(keyRight(halfSecond), S1);  // (3)
  halfSecond = permutation(halfSecond, P4);                            // (4)

  textBinary = xorOperation(halfSecond, keyLeft(textBinary)) +
               keyRight(textBinary);  // (5) (6) (7)

  textBinary = permutation(textBinary, IP1);  // (8)

  finalPlaintext = textBinary;
}