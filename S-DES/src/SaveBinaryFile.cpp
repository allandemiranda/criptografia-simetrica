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

#include <bitset>    // std::bitset
#include <fstream>   // std::ofstream
#include <iostream>  // std::cerr & std::endl
#include <string>    // std::string

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
    for (auto i(0u); i < (binaryText.size() / 8); ++i) {
      std::string tempString;
      for (auto j(0u); j < 8; ++j) {
        tempString.push_back(binaryText[(i * 8) + j]);
      }
      newFile << static_cast<char>(std::bitset<8>(tempString).to_ulong());
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