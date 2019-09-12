/**
 * @file CryptionSelect.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para criptografar a mensagem no tipo correto
 * @version 0.1
 * @date 12-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef CRYPTIONSELECT_H_
#define CRYPTIONSELECT_H_

#include <string>  // std::string
#include <vector>  // std::vector

class CryptionSelect {
 private:
  std::string encryptionType;
  std::string key;
  std::vector<std::string> explode(const std::string&);
  bool binaryOnly(std::string);
  bool rulesDes(std::string);

 public:
  std::string encode(std::string);
  std::string decode(std::string);
  bool analyzeMsgReceive(std::string);
  bool setType(std::string);
  CryptionSelect(void);
  ~CryptionSelect(void);
};

#endif