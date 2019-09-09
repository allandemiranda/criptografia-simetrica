/**
 * @file OpenFile.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para abrir um arquivo de texto
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef OPENFILE_H_
#define OPENFILE_H_

#include <string>  // std::string
#include <vector>  // std::vector

class OpenFile {
 private:
  void getText(std::string);  // Obter texto do arquivo e salvar no vetor text
  std::vector<std::string> text;  // Texto do arquivo
 public:
  unsigned long getSizeText(void);     // Obter o tamanho do texto em linhas
  std::string getLine(unsigned long);  // Obter linha do texto
  OpenFile(std::string);
  ~OpenFile(void);
};

#endif