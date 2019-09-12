/**
 * @file Socket.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Classe para tratar as conexões de socket
 * @version 0.1
 * @date 12-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <netinet/in.h>  // socket
#include <string>        // std::string

class Socket {
 private:
  // receber msg
  int server_fd;
  int new_socket;
  int valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  // enviar msg
  int sock = 0;
  struct sockaddr_in serv_addr;
  // porta
  unsigned long PORT = 5354;
  std::string statusReceiverNow = "on";
  // Criptografia
  // std::string encryption = "OFF";

 public:
  void startReceive(void);
  std::string receive(void);
  std::string getStatusReceive(void);
  void startSubmit(char const *);
  void submit(std::string);
  // std::string getEncryption(void);
  // void setEncryption(std::string);
  Socket(unsigned long);
  ~Socket(void);
};

#endif