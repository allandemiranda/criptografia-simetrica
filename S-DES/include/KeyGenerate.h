/**
 * @file KeyGenerate.h
 * @author Allan de Miranda
 * @brief Classe para geração das chaves usadas
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef KEYGENERATE_H_
#define KEYGENERATE_H_

#include <string>

class KeyGenerate {
 private:
  std::string keySavePath = "data";  // Caminho para salvar a chave
  bool checkKeySize(unsigned long);
  std::string createKeyMaster(unsigned long);
  void createKeyFile(std::string, std::string);

 public:
  KeyGenerate(unsigned long, std::string);
  ~KeyGenerate(void);
};

#endif /* KEYGENERATE_H_ */
