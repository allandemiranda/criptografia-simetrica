/**
 * @file RC4.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos para class RC4
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "RC4.h"
#include <bitset>    // std::bitset
#include <iostream>  // std::cout, std::endl
#include "KSA.h"
#include "OpenFile.h"
#include "PRGA.h"
#include "SaveBinaryFile.h"

/**
 * @brief Construct a new RC4::RC4 object
 *
 * @param fileOpen Arquivo para abrir
 * @param fileSave Arquivo para salvar
 * @param key Chave principal
 */
RC4::RC4(std::string fileOpen, std::string fileSave, std::string key) {
  OpenFile arquivoTexto(fileOpen);
  KSA one_step(key);
  PRGA second_step(one_step.getS(), arquivoTexto.getText());
  std::vector<char> textoCodficado = arrayInt_Char(second_step.getText());
  SaveBinaryFile salvarBinario(textoCodficado, fileSave);
}

/**
 * @brief Construct a new RC4::RC4 object
 *
 * @param fileOpen Arquivo para abrir
 * @param key Chave principal
 */
RC4::RC4(std::string fileOpen, std::string key) {
  OpenFile arquivoTexto(fileOpen);
  KSA one_step(key);
  PRGA second_step(one_step.getS(), arquivoTexto.getText());
  std::vector<char> textoCodficado = arrayInt_Char(second_step.getText());
  std::cout << std::endl;
  for (char c : textoCodficado) {
    std::cout << c;
  }
  std::cout << std::endl;
  std::cout << std::endl;
}

/**
 * @brief Construct a new RC4::RC4 object
 *
 * @param arquivoTexto Texto do chat
 * @param key Chave do chat
 */
RC4::RC4(std::vector<char> arquivoTexto, std::string key) {
  KSA one_step(key);
  PRGA second_step(one_step.getS(), arquivoTexto);
  chatTxt = arrayInt_Char(second_step.getText());
}

/**
 * @brief Destroy the RC4::RC4 object
 *
 */
RC4::~RC4(void) {}

/**
 * @brief Obter um vetor de char de um vetor de int
 *
 * @param arrayNum Vetor de inteniros
 * @return std::vector<char> Vetor de char
 */
std::vector<char> RC4::arrayInt_Char(std::vector<unsigned int> arrayNum) {
  std::vector<char> text;
  for (unsigned int num : arrayNum) {
    text.push_back(static_cast<char>(num));
  }
  return text;
}

/**
 * @brief Get the Chat Txt object
 *
 * @return std::vector<char> Chat do texto
 */
std::vector<char> RC4::getChatTxt(void) { return chatTxt; }