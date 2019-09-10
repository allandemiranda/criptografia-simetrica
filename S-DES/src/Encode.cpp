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

/**
 * @brief Construct a new Encode:: Encode object
 *
 * @param plaintext Texto binário de entrada de 8-bit
 */
Encode::Encode(std::string plaintext) { process(plaintext); }

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
void Encode::process(std::string textBinary) {
  if (textBinary.size() != 8) {
    throw "Tamanho do texto de entrada para codificação é incompatível";
  } else {
    textBinary = permutation(textBinary, IP);
    // CONTINUAR AQUI
  }
}