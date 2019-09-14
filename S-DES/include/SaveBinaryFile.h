/**
 * @file SaveBinaryFile.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class para salvar arquivo binário gerado
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SAVEBINARYFILE_H_
#define SAVEBINARYFILE_H_

#include <string>  // std::string
#include <vector>  // std::vector

class SaveBinaryFile {
 private:
  std::string folder = "out/TextoCodificado.txt";  // Destino do arquivo

 public:
  SaveBinaryFile(std::vector<char>);
  ~SaveBinaryFile(void);
};

#endif