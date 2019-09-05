/**
 * @file SubKeyGenerate.h
 * @author Allan de Miranda
 * @brief Gerador de sub chaves
 * @version 0.1
 * @date 2019-08-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SUBKEYGENERATE_H_
#define SUBKEYGENERATE_H_

#include <string>
#include <vector>

class SubKeyGenerate {
 private:
  std::string masterKeyPath = "data/key.sdes";
  std::string getMasterKey(std::string);
  std::string masterKey;
  void setSubKeys(unsigned long);
  unsigned long numberOfNodes = 2;
  std::string PMaster = "3 5 2 7 4 10 1 9 8 6";
  std::string PSecond = "6 3 7 4 8 5 10 9";
  std::vector<unsigned long> PMasterVector;
  std::vector<unsigned long> PSecondVector;
  const std::vector<unsigned long> explode(const std::string&);
  bool checkPVector(unsigned long, std::vector<unsigned long>&);
  std::string manipulateP(std::string&, std::vector<unsigned long>&);
  std::string keyLeft(std::string);
  std::string keyRight(std::string);
  std::string LS(unsigned long, std::string);

 public:
  std::vector<std::string> subKeys;  // Sub chaves finais ordenadas
  SubKeyGenerate(std::string, unsigned long, std::string, std::string);
  ~SubKeyGenerate(void);
};

#endif /* SUBKEYGENERATE_H_ */