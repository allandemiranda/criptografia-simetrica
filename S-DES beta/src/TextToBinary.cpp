/**
 * @file TextToBinary.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da classe TextToBinary
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "TextToBinary.h"

#include <bitset>  // std::bitset
#include <string>  // std::string
#include <vector>  // std::vector

/**
 * @brief Construct a new Text To Binary:: Text To Binary object
 *
 * @param lineText Linha do texto
 */
TextToBinary::TextToBinary(std::string lineText) { convertToBinary(lineText); }

/**
 * @brief Destroy the Text To Binary:: Text To Binary object
 *
 */
TextToBinary::~TextToBinary() {}

/**
 * @brief Obter texto convertido
 *
 * @return std::string Texto em binário
 */
std::string TextToBinary::getBinary(void) { return textBinary; }

/**
 * @brief Converter texto em binário
 *
 * @param text Linha do texto
 */
void TextToBinary::convertToBinary(std::string text) {
  for (char character : text) {
    textBinary += std::bitset<8>(character).to_string();
  }
  textBinary += lineFeed;
}