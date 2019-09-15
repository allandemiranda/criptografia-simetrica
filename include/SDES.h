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

#include <string>  // std::string
#include <vector>  // std::vector

class SDES {
 private:
  std::vector<char> chatTxt;

 public:
  SDES(std::string, std::string, std::string);
  SDES(std::string, std::string);
  SDES(std::vector<char>, std::string, bool);
  ~SDES(void);
  std::vector<char> getChatTxt(void);
};

#endif