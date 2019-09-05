/**
 * @file TextEncoder.h
 * @author Allan de Miranda
 * @brief Codificador de textos
 * @version 0.1
 * @date 2019-09-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef TEXTENCODER_H_
#define TEXTENCODER_H_

#include "SubKeyGenerate.h"

#include <string>
#include <vector>

class TextEncoder {
 private:
  std::string getText(std::string);
  std::string EP = "4 1 2 3 2 3 4 1";
  std::string initialPermutation = "2 6 3 1 4 8 5 7";
  std::string finalPermutation = "4 1 3 5 7 2 8 6";
  std::vector<unsigned long> initialPermutationVector;
  std::vector<unsigned long> finalPermutationVector;
  const std::vector<unsigned long> explode(const std::string&);
  bool checkPermutationVector(unsigned long, std::vector<unsigned long>&);
  std::string manipulateP(std::string&, std::vector<unsigned long>&);
  std::string txtLeft(std::string);
  std::string txtRight(std::string);
  std::string operationXor(std::string);

 public:
  TextEncoder(std::vector<std::string>, std::string, std::string, std::string, std::string);
  ~TextEncoder();
};

#endif /* TEXTENCODER_H_ */