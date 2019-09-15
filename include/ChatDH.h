/**
 * @file ChatDH.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class com as funcionalidades do chat
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef CHATDH_H_
#define CHATDH_H_

#include <string>  // std::string
#include "Socket.h"

class ChatDH {
 private:
  void channelRX(Socket*);
  void channelTX(Socket*, char const*);
  std::string cript = "none";
  std::string key = "";
  void setCript(std::vector<char>);
  unsigned int analyzerCriptMSG(std::vector<char>);
  std::vector<char> decript(std::vector<char>);
  std::vector<char> encript(std::vector<char>);
  std::vector<std::string> explode(const std::string&);
  unsigned int q_dh = 353;
  unsigned int a_dh = 3;
  unsigned int rand_num = 1;
  unsigned int getRandNum(void);
  long long sendKeyPublic(void);
  long long receiveKeyPublic(long long);
  long long power(long long, long long, long long);

 public:
  ChatDH(char const*);
  ~ChatDH(void);
};

#endif