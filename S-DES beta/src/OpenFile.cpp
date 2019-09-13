/**
 * @file OpenFile.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da classe OpenFile
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "OpenFile.h"

#include <fstream>   // std::ifstream
#include <iostream>  // std::cerr
#include <string>    // std::string
#include <vector>    // std::vector

/**
 * @brief Construct a new Open File:: Open File object
 *
 * @param fileName Caminho do arquivo
 */
OpenFile::OpenFile(std::string fileName) { getText(fileName); }

/**
 * @brief Destroy the Open File:: Open File object
 *
 */
OpenFile::~OpenFile(void) {}

/**
 * @brief Obter linha do texto
 *
 * @param lineNumber Número da linha (inicia em 1)
 * @return std::string Texto contido na linha solicitada
 */
std::string OpenFile::getLine(unsigned long lineNumber) {
  if ((lineNumber == 0) or (lineNumber > getSizeText())) {
    throw "Linha solicitada está fora do tamanho do texto";
  } else {
    return text[lineNumber - 1];
  }
}

/**
 * @brief Obter tamanho do texto
 *
 * @return unsigned long Tamanho do texto
 */
unsigned long OpenFile::getSizeText(void) {
  if (text.size() == 0) {
    throw "Não exstem linhas no texto";
  } else {
    return text.size();
  }
}

/**
 * @brief Obter texto do aquivo
 *
 * @param fileName Caminho do arquivo
 */
void OpenFile::getText(std::string fileName) {
  try {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
      text.push_back(line);
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << "Erro ao abrir arquivo de texto" << std::endl;
  }
}