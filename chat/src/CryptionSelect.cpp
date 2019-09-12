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

#include "CryptionSelect.h"

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
std::vector<std::string> explode(const std::string& P) {
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
 * @brief Função para verificar se mensagem redebida contem informação de nova
 * criptografia
 *
 * @param message mensagem redcebida
 * @return true Contem informação e foi setado as novas configurações
 * @return false Não contem informações
 */
bool CryptionSelect::analyzeMsgReceive(std::string message) {
  std::vector<std::string> info = explode(message);
  if ((info[0] == "MODIFICAR") or (info[0] == "MODIFICADO")) {
    if (info[1] == "OFF") {
      encryptionType = "";
      key = "";
      return true;
    }
    if (info[1] == "S-DES") {
      if (rulesDes(info[2])) {
        encryptionType = info[1];
        key = info[2];
        return true;
      }
    }
  }
  return false;
}
