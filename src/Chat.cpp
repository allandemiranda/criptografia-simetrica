/**
 * @file Chat.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos para class Chat
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Chat.h"
#include <omp.h>     // omp parallel
#include <iostream>  // std::cin, std::endl, std::cout
#include <string>    // std::string
#include "RC4.h"
#include "SDES.h"

/**
 * @brief Construct a new Chat:: Chat object
 *
 * @param ip IP
 */
Chat::Chat(char const* ip) {
  Socket novoSocket(5354);
#pragma omp parallel
  {
#pragma omp sections
    {
#pragma omp section
      { channelRX(&novoSocket); }
#pragma omp section
      { channelTX(&novoSocket, ip); }
    }
  }
}

/**
 * @brief Destroy the Chat:: Chat object
 *
 */
Chat::~Chat(void) {}

/**
 * @brief Canal para receber mensagens
 *
 * @param chat Socket
 */
void Chat::channelRX(Socket* chat) {
  chat->startReceive();
  while (chat->getStatusReceive() == "on") {
    std::vector<char> novaMsg = chat->receive();
    if (analyzerCriptMSG(decript(novaMsg))) {
      setCript(decript(novaMsg));
    } else {
      std::cout << "Parceiro: ";
      for (char c : decript(novaMsg)) {
        std::cout << c;
      }
      std::cout << std::endl;
    }
  }
  std::cout << "Chat fechado pelo Parceiro" << std::endl;
  std::cout << "Digite qualquer tecla para sair..." << std::endl;
}

/**
 * @brief Canal para enviar mensagens
 *
 * @param chat Socket
 */
void Chat::channelTX(Socket* chat, char const* ip) {
  chat->startSubmit(ip);
  while (chat->getStatusReceive() == "on") {
    std::string mensagem;
    std::getline(std::cin, mensagem);
    if (mensagem.size() > 1024) {
      std::cout << "Erro! Mensagem muito grande" << std::endl;
    } else {
      std::vector<char> charMsg;
      for (char c : mensagem) {
        charMsg.push_back(c);
      }
      chat->submit(encript(charMsg));
      if (analyzerCriptMSG(charMsg)) {
        setCript(charMsg);
      }
    }
  }
}

/**
 * @brief Função para converter a string em um vetor de informações
 *
 * @param P String com a sequência de texto
 * @return std::vector<std::string> Texto separado por informação
 */
std::vector<std::string> Chat::explode(const std::string& P) {
  char c = ' ';
  std::string buff{""};
  std::vector<std::string> v;

  for (auto n : P) {
    if (n != c) {
      buff += n;
    } else if (n == c && buff != "") {
      v.push_back(buff);
      buff = "";
    }
  }
  if (buff != "") {
    v.push_back(buff);
  }

  return v;
}

/**
 * @brief Set the Cript object
 *
 * @param msg Mensagem (decriptografada)
 */
void Chat::setCript(std::vector<char> msg) {
  std::string msg_s;
  for (char c : msg) {
    msg_s.push_back(c);
  }
  std::vector<std::string> conf = explode(msg_s);
  cript = conf[1];
  if (cript != "none") {
    key = conf[2];
  } else {
    key = "";
  }
  std::cout << "---> Criptografia modificada para '" << cript << "' de chave '"
            << key << "'" << std::endl;
}

/**
 * @brief Analizador de mensagem
 *
 * @param msg Mensagem (decriptografada)
 * @return true Possui código de modificação de criptografia
 * @return false Não possui código de modificação de criptografia
 */
bool Chat::analyzerCriptMSG(std::vector<char> msg) {
  std::string msg_s;
  bool prim = true;
  for (char c : msg) {
    if (prim) {
      prim = false;
      continue;
    }
    msg_s.push_back(c);
  }
  std::vector<std::string> conf = explode(msg_s);
  if ((conf.size() == 0) or (conf.size() > 3)) {
    return false;
  }
  if (conf[0] == "crypt") {
    if (conf[1] == "sdes") {
      if (conf[2].size() == 10) {
        return true;
      }
    }
    if (conf[1] == "rc4") {
      if ((conf[2].size() > 1) and (conf[2].size() < 256)) {
        return true;
      }
    }
    if (conf[1] == "none") {
      return true;
    }
  }
  return false;
}

/**
 * @brief Decriptar mensagem recebida
 *
 * @param msg_cript Mensagem recebida
 * @return std::vector<char> Mensagem descriptografada
 */
std::vector<char> Chat::decript(std::vector<char> msg_cript) {
  if (cript == "sdes") {
    SDES descriptar(msg_cript, key, false);
    return descriptar.getChatTxt();
  } else {
    if (cript == "rc4") {
      RC4 desciptar(msg_cript, key);
      return desciptar.getChatTxt();
    } else {
      if (cript == "none") {
        return msg_cript;
      } else {
        throw "Erro ao selecionar a decriptação da msg";
      }
    }
  }
}

/**
 * @brief Encriptar mensagem antes de enviar
 *
 * @param msg Mensagem
 * @return std::vector<char> Mensagem encriptada
 */
std::vector<char> Chat::encript(std::vector<char> msg) {
  if (cript == "sdes") {
    SDES criptar(msg, key, true);
    return criptar.getChatTxt();
  } else {
    if (cript == "rc4") {
      RC4 ciptar(msg, key);
      return ciptar.getChatTxt();
    } else {
      if (cript == "none") {
        return msg;
      } else {
        throw "Erro ao selecionar a criptação da msg";
      }
    }
  }
}