/**
 * @file CryptionSelect.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos da classe CryptionSelect
 * @version 0.1
 * @date 12-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "BinaryToText.h"
#include "DecodeDes.h"
#include "EncodeDes.h"
#include "KeyGenerationDes.h"
#include "TextToBinary.h"

#include "CryptionSelect.h"

#include <string>
#include <vector>

/**
 * @brief Construct a new Cripto Select:: Cripto Select object
 *
 */
CryptionSelect::CryptionSelect(void) {
  encryptionType = "";
  key = "";
}

/**
 * @brief Destroy the Cripto Select:: Cripto Select object
 *
 */
CryptionSelect::~CryptionSelect(void) {}

/**
 * @brief Função para converter a string em um vetor de informações
 *
 * @param P String com a sequência de texto
 * @return std::vector<std::string> Texto separado por informação
 */
std::vector<std::string> CryptionSelect::explode(const std::string& P) {
  char c = '/';
  std::string buff{""};
  std::vector<std::string> v;

  for (auto n : P) {
    if (n != c) {
      buff += n;
    } else if (n == c && buff != "") {
      v.push_back(buff);
      buff = "";
    }
  }
  if (buff != "") {
    v.push_back(buff);
  }

  return v;
}

/**
 * @brief Funçao para verificar se a string é um binário
 *
 * @param binary String binária
 * @return true É uma string binária
 * @return false Não é uma string binária
 */
bool CryptionSelect::binaryOnly(std::string binary) {
  for (char caractere : binary) {
    if ((caractere != '0') and (caractere != '1')) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Função apra verificar se achave é válida
 *
 * @param key Chave de entrada
 * @return true É uma chave válida
 * @return false Não é uma chave válida
 */
bool CryptionSelect::rulesDes(std::string key) {
  if (key.size() != 10) {
    return false;
  }
  if (!binaryOnly(key)) {
    return false;
  }
  return true;
}

/**
 * @brief Função para setar novas configurações de criptografia
 *
 * @param message Mensagem recebida
 * @return true Precisa retornar confirmação de modificação
 * @return false Não precisa retornar confirmação de modificação
 */
bool CryptionSelect::setType(std::string message) {
  std::vector<std::string> info = explode(message);
  if ((info[0] == "MODIFICAR") or (info[0] == "MODIFICADO")) {
    if (info[1] == "OFF") {
      encryptionType = "";
      key = "";
    }
    if (info[1] == "S-DES") {
      if (rulesDes(info[2])) {
        encryptionType = info[1];
        key = info[2];
      }
    }
    if (info[1] == "RC4") {
      encryptionType = "";
      key = "";
    }
  }
  if (info[0] == "MODIFICAR") {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Função para verificar se mensagem redebida contem informação de nova
 * criptografia
 *
 * @param message mensagem redcebida
 * @return true Contem informação
 * @return false Não contem informações
 */
bool CryptionSelect::analyzeMsgReceive(std::string message) {
  std::vector<std::string> info = explode(message);
  if ((info[0] == "MODIFICAR") or (info[0] == "MODIFICADO")) {
    if (info[1] == "OFF") {
      return true;
    }
    if (info[1] == "S-DES") {
      if (rulesDes(info[2])) {
        return true;
      }
    }
    if (info[1] == "RC4") {
      return true;
    }
  }
  return false;
}

/**
 * @brief Função de codificação de mensagem
 *
 * @param msg Mensagem normal para enviar
 * @return std::string Mensagem codificada para enviar
 */
std::string CryptionSelect::encode(std::string msg) {
  if (encryptionType == "OFF") {
    return msg;
  }
  if (encryptionType == "S-DES") {
    KeyGenerationDes subChaves(msg);

    std::string textoEmBinario;
    TextToBinary paraBinario(msg);
    textoEmBinario += paraBinario.getBinary();

    std::string textoCodficado;
    for (auto i(0u); i < (textoEmBinario.size() / 8); ++i) {
      std::string tempBinario;
      for (auto j(0u); j < 8; ++j) {
        tempBinario.push_back(textoEmBinario[(i * 8) + j]);
      }
      EncodeDes codificado(tempBinario, subChaves.getKey(1),
                           subChaves.getKey(2));
      textoCodficado += codificado.getFinalPlaintext();
    }

    return textoCodficado;
  }
  if (encryptionType == "RC4") {
    // ADICIONAR AQUI RC4
    return msg;
  }
  return msg;
}

/**
 * @brief Função de codificação de mensagem
 *
 * @param msg
 * @return std::string
 */
std::string CryptionSelect::decode(std::string msg) {
  if (encryptionType == "OFF") {
    return msg;
  }
  if (encryptionType == "S-DES") {
    KeyGenerationDes subChaves(key);

    std::string arquivoBinarioDecodificado;
    for (auto i(0u); i < (msg.size() / 8); ++i) {
      std::string tempBinario;
      for (auto j(0u); j < 8; ++j) {
        tempBinario.push_back(msg[(i * 8) + j]);
      }
      DecodeDes decodificado(tempBinario, subChaves.getKey(1),
                             subChaves.getKey(2));
      arquivoBinarioDecodificado += decodificado.getFinalPlaintext();
    }

    BinaryToText textoFinal(arquivoBinarioDecodificado);
    return textoFinal.getLine(1);
  }
  if (encryptionType == "RC4") {
    // ADICIONAR AQUI RC4
    return msg;
  }
  return msg;
}