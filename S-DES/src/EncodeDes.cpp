/**
 * @file EncodeDes.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da class EncodeDes
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "EncodeDes.h"
#include <bitset>  // std::bitset
#include <string>  // std::string

/**
 * @brief Construct a new EncodeDes:: EncodeDes object
 *
 * @param plaintext Texto binário de entrada de 8-bit
 * @param keyOne Sub chave um
 * @param keyTwo Sub chave dois
 */
EncodeDes::EncodeDes(char plaintext, char keyOne, char keyTwo) {
  std::string textBinary = std::bitset<8>(plaintext).to_string();
  std::string keyOne_s = std::bitset<8>(keyOne).to_string();
  std::string keyTwo_s = std::bitset<8>(keyTwo).to_string();

  textBinary = getPermutation(textBinary, IP);

  std::string half = getKeyRight(textBinary);
  half = getPermutation(half, EP);                                        // (1)
  half = getXorOperation(half, keyOne_s);                                 // (2)
  half = getSBox(getKeyLeft(half), S0) + getSBox(getKeyRight(half), S1);  // (3)
  half = getPermutation(half, P4);                                        // (4)

  textBinary = getKeyRight(textBinary) +
               getXorOperation(half, getKeyLeft(textBinary));  // (5) (6) (7)

  std::string halfSecond = getKeyRight(textBinary);
  halfSecond = getPermutation(halfSecond, EP);         // (1)
  halfSecond = getXorOperation(halfSecond, keyTwo_s);  // (2)
  halfSecond = getSBox(getKeyLeft(halfSecond), S0) +
               getSBox(getKeyRight(halfSecond), S1);  // (3)
  halfSecond = getPermutation(halfSecond, P4);        // (4)

  textBinary = getXorOperation(halfSecond, getKeyLeft(textBinary)) +
               getKeyRight(textBinary);  // (5) (6) (7)

  textBinary = getPermutation(textBinary, IP1);  // (8)

  finalPlaintext = static_cast<char>(std::bitset<8>(textBinary).to_ulong());
}

/**
 * @brief Destroy the Encode Des:: Encode Des object
 *
 */
EncodeDes::~EncodeDes(void) {}

/**
 * @brief Get the Final Plaintext object
 *
 * @return char Binário criptografado
 */
char EncodeDes::getFinalPlaintext(void) { return finalPlaintext; }