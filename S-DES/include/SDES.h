/**
 * @file SDES.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class com funcinalidades do S-DES
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SDES_H_
#define SDES_H_

#include <bitset>    // std::bitset
#include <iostream>  // std::cout, std::endl
#include <string>    // std::string
#include <vector>    // std::vector
#include "DecodeDes.h"
#include "EncodeDes.h"
#include "KeyGenerationDes.h"
#include "OpenFile.h"
#include "SaveBinaryFile.h"

class SDES {
 public:
  SDES(std::string, std::string, std::string);
  SDES(std::string, std::string);
  ~SDES(void);
};

/**
 * @brief Construct a new SDES::SDES object
 *
 * @param fileOpen Arquivo para abrir
 * @param fileDestination Arquivo para salvar
 * @param key Chave principal
 */
SDES::SDES(std::string fileOpen, std::string fileDestination, std::string key) {
  KeyGenerationDes subChaves(key);
  OpenFile arquivoTexto(fileOpen);
  std::vector<char> textoCodficado;
  for (auto i(0u); i < arquivoTexto.getText().size(); ++i) {
    EncodeDes codificado(arquivoTexto.getText()[i], subChaves.getSubKey(1),
                         subChaves.getSubKey(2));
    textoCodficado.push_back(codificado.getFinalPlaintext());
  }
  SaveBinaryFile salvarBinario(textoCodficado, fileDestination);
}

/**
 * @brief Construct a new SDES::SDES object
 *
 * @param fileOpen Arquivo para abrir
 * @param key Chave principal
 */
SDES::SDES(std::string fileOpen, std::string key) {
  KeyGenerationDes subChaves(key);
  OpenFile arquivoTexto(fileOpen);
  std::vector<char> textoDecodficado;
  for (auto i(0u); i < arquivoTexto.getText().size(); ++i) {
    DecodeDes decodificado(arquivoTexto.getText()[i], subChaves.getSubKey(1),
                           subChaves.getSubKey(2));
    textoDecodficado.push_back(decodificado.getFinalPlaintext());
  }
  std::cout << std::endl;
  for (char c : textoDecodficado) {
    std::cout << c;
  }
  std::cout << std::endl;
}

/**
 * @brief Destroy the SDES::SDES object
 *
 */
SDES::~SDES(void) {}

#endif