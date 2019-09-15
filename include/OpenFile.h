/**
 * @file OpenFile.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para abrir qualquer arquivo de texto
 * @version 0.1
 * @date 13-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef OPENFILE_H_
#define OPENFILE_H_

#include <string>    // std::string
#include <vector>    // std::vector

class OpenFile {
 private:
  std::vector<char> text;                  // Texto final
  void setText(std::vector<char>);         // Definir textoo
  std::vector<char> getFile(std::string);  // Obter arquivo

 public:
  std::vector<char> getText(void);  // Ober texto
  OpenFile(std::string);
  ~OpenFile(void);
};

#endif