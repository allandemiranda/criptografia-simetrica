/**
 * @file PRGA.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class para geração pseudo-aleatória
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef PRGA_H_
#define PRGA_H_

#include <string>  // std::string
#include <vector>  // std::vector

class PRGA {
 private:
  std::vector<unsigned int> textF;
  int getXor(int, char);

 public:
  std::vector<unsigned int> getText(void);
  PRGA(std::vector<unsigned int>, std::vector<char>);
  ~PRGA(void);
};

#endif