/**
 * @file OpenFile.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da class OpenFile
 * @version 0.1
 * @date 13-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "OpenFile.h"
#include <fstream>   // std::ifstream
#include <iostream>  // std::cerr

/**
 * @brief Construct a new Open File:: Open File object
 *
 * @param file_name Nome do arquivo a ser lido
 */
OpenFile::OpenFile(std::string file_name) { setText(getFile(file_name)); }

/**
 * @brief Destroy the Open File:: Open File object
 *
 */
OpenFile::~OpenFile() {}

/**
 * @brief Set the Text object
 *
 * @param text_ Texto a ser adicionado ao texto final
 */
void OpenFile::setText(std::vector<char> text_) {
  for (char c : text_) {
    text.push_back(c);
  }
}

/**
 * @brief Get the File object
 *
 * @param file_name Nome do arquivo
 * @return std::vector<char> Texto obtido do arquivo
 */
std::vector<char> OpenFile::getFile(std::string file_name) {
  std::vector<char> text_f;
  try {
    std::ifstream file(file_name);
    char c;
    while (file.get(c)) {
      text_f.push_back(c);
    }
    file.close();
  } catch (const std::ios_base::failure& e) {
    std::cerr << "Erro ao abrir arquivo de texto" << std::endl;
  }
  return text_f;
}

/**
 * @brief Get the Text object
 *
 * @return std::vector<char> Texto final
 */
std::vector<char> OpenFile::getText(void) { return text; }