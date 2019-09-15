/**
 * @file SDES.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da class SDES
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "SDES.h"
#include <bitset>    // std::bitset
#include <iostream>  // std::cout, std::endl
#include <vector>    // std::vector
#include "DecodeDes.h"
#include "EncodeDes.h"
#include "KeyGenerationDes.h"
#include "OpenFile.h"
#include "SaveBinaryFile.h"

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
  std::cout << std::endl;
}

/**
 * @brief Destroy the SDES::SDES object
 *
 */
SDES::~SDES(void) {}

/**
 * @brief Construct a new SDES::SDES object
 *
 * @param arquivoTexto Texto
 * @param key Chave
 * @param type TRUE Codificar
 * @param type FALSE Decodificar
 */
SDES::SDES(std::vector<char> arquivoTexto, std::string key, bool type) {
  KeyGenerationDes subChaves(key);
  if (type) {
    for (auto i(0u); i < arquivoTexto.size(); ++i) {
      EncodeDes codificado(arquivoTexto[i], subChaves.getSubKey(1),
                           subChaves.getSubKey(2));
      chatTxt.push_back(codificado.getFinalPlaintext());
    }
  } else {
    for (auto i(0u); i < arquivoTexto.size(); ++i) {
      DecodeDes decodificado(arquivoTexto[i], subChaves.getSubKey(1),
                           subChaves.getSubKey(2));
      chatTxt.push_back(decodificado.getFinalPlaintext());
    }
  }
}

/**
 * @brief Get the Chat Txt object
 *
 * @return std::vector<char> Texto do chat
 */
std::vector<char> SDES::getChatTxt(void) { return chatTxt; }