/**
 * @file SaveBinaryFile.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da class SaveBinaryFile
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "SaveBinaryFile.h"
#include <fstream>   // std::ofstream
#include <iostream>  // std::cerr & std::endl

/**
 * @brief Construct a new Save Binary File:: Save Binary File object
 *
 * @param binaryText Texto para ser gravado
 * @param folder Destino do arquivo
 */
SaveBinaryFile::SaveBinaryFile(std::vector<char> binaryText,
                               std::string folder) {
  std::ofstream newFile;
  newFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    newFile.open(folder, std::ios::trunc);
    for (char c : binaryText) {
      newFile << c;
    }
    newFile.close();
  } catch (std::ifstream::failure e) {
    std::cerr << "Erro ao criar arquivo " << folder << std::endl;
  }
}

/**
 * @brief Destroy the Save Binary File:: Save Binary File object
 *
 */
SaveBinaryFile::~SaveBinaryFile(void) {}