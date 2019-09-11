/**
 * @file SaveBinaryFile.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da classe SaveBinaryFile
 * @version 0.1
 * @date 10-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "SaveBinaryFile.h"

#include <fstream>   // std::ofstream
#include <iostream>  // std::cerr & std::endl

/**
 * @brief Construct a new Save Text File:: Save Text File object
 *
 * @param binaryText Texto no formáto binário
 */
SaveBinaryFile::SaveBinaryFile(std::string binaryText) {
  std::ofstream newFile;
  newFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    newFile.open(folder, std::ios::trunc);
    for (char n : binaryText) {
      newFile << n;
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