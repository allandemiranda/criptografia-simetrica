/**
 * @file RC4.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class com a funcionalidade do RC4
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef RC4_H_
#define RC4_H_

#include <string>  // std::string
#include <vector>  // std::vector

class RC4 {
 private:
  std::vector<char> arrayInt_Char(std::vector<unsigned int>);
  std::vector<char> chatTxt;

 public:
  RC4(std::string, std::string);
  RC4(std::string, std::string, std::string);
  RC4(std::vector<char>, std::string);
  ~RC4(void);
  std::vector<char> getChatTxt(void);
};

#endif