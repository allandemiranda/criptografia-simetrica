/**
 * @file SaveBinaryFile.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para salvar texto binário em um arquivo
 * @version 0.1
 * @date 10-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SAVEBINARYFILE_H_
#define SAVEBINARYFILE_H_

#include <string>    // std::string

class SaveBinaryFile {
 private:
  std::string folder = "out/TextoCodificado.txt";

 public:
  SaveBinaryFile(std::string);
  ~SaveBinaryFile(void);
};

#endif