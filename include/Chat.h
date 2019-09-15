/**
 * @file Chat.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class com as funcionalidades do chat
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef CHAT_H_
#define CHAT_H_

#include <string>  // std::string
#include "Socket.h"

class Chat {
 private:
  void channelRX(Socket*);
  void channelTX(Socket*, char const*);
  std::string cript = "none";
  std::string key = "";
  void setCript(std::vector<char>);
  bool analyzerCriptMSG(std::vector<char>);
  std::vector<char> decript(std::vector<char>);
  std::vector<char> encript(std::vector<char>);
  std::vector<std::string> explode(const std::string&);

 public:
  Chat(char const*);
  ~Chat(void);
};

#endif