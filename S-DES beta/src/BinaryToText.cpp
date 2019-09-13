/**
 * @file BinaryToText.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da classe BinaryToText
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "BinaryToText.h"

#include <bitset>  //std::bitset
#include <string>  // std::string
#include <vector>  // std::vector

/**
 * @brief Construct a new Binary To Text:: Binary To Text object
 *
 * @param textBinary Texto em binário
 */
BinaryToText::BinaryToText(std::string textBinary) {
  convertToText(textBinary);
}

/**
 * @brief Destroy the Binary To Text:: Binary To Text object
 *
 */
BinaryToText::~BinaryToText(void) {}

/**
 * @brief Obter linha do texto
 *
 * @param lineNumber Número da linha (inicia em 1)
 * @return std::string Texto da linha
 */
std::string BinaryToText::getLine(unsigned long lineNumber) {
  if ((lineNumber == 0) or (lineNumber > text.size())) {
    throw "Linha solicitado está fora do tamanho do texto";
  } else {
    return text[lineNumber - 1];
  }
}

/**
 * @brief Obter tamanho do texto convertido
 *
 * @return unsigned long Tamanho do texto
 */
unsigned long BinaryToText::getSizeText(void) { return text.size(); }

/**
 * @brief Converter o texto binário para texto normal
 *
 * @param binaryText Texto binário
 */
void BinaryToText::convertToText(std::string binaryText) {
  std::vector<std::string> character;
  for (auto i(0u); i < (binaryText.size() / 8); ++i) {
    std::string newCharacter;
    for (auto j(0u); j < 8; ++j) {
      newCharacter += binaryText[(i * 8) + j];
    }
    character.push_back(newCharacter);
  }
  std::string finalLine;
  for (std::string characterBinary : character) {
    if (characterBinary == lineFeed) {
      text.push_back(finalLine);
      finalLine.erase();
    } else {
      unsigned char c = static_cast<unsigned char>(
          std::bitset<8>(characterBinary).to_ulong());
      finalLine.push_back(c);
    }
  }
}