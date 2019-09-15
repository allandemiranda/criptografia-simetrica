/**
 * @file ChatDH.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Métodos para class Chat
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "ChatDH.h"
#include <omp.h>  // omp parallel
#include <bitset>
#include <cstdlib>   // std::rand
#include <ctime>     // std::rand
#include <iostream>  // std::cin, std::endl, std::cout
#include <string>    // std::string
#include "RC4.h"
#include "SDES.h"

/**
 * @brief Construct a new Chat:: Chat object
 *
 * @param ip IP
 */
ChatDH::ChatDH(char const* ip) {
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
ChatDH::~ChatDH(void) {}

/**
 * @brief Canal para receber mensagens
 *
 * @param chat Socket
 */
void ChatDH::channelRX(Socket* chat) {
  chat->startReceive();
  while (chat->getStatusReceive() == "on") {
    std::vector<char> novaMsg = chat->receive();
    if (analyzerCriptMSG(decript(novaMsg)) == 2) {
      std::string novaMSG_S;
      bool prim = true;
      for (char c : decript(novaMsg)) {
        if (prim) {
          prim = false;
          continue;
        }
        novaMSG_S.push_back(c);
      }
      std::string mensagem = explode(novaMSG_S)[1];
      rand_num = getRandNum();
      int n_key_p = sendKeyPublic();
      mensagem.push_back(' ');
      mensagem += std::to_string(n_key_p);
      std::vector<char> charMsg;
      charMsg.push_back(
          static_cast<char>(std::bitset<8>("01011100").to_ulong()));
      for (char c : mensagem) {
        charMsg.push_back(c);
      }
      chat->submit(encript(charMsg));
      if (explode(novaMSG_S)[1] == "sdes") {
        std::vector<char> modifique;
        for (char c : explode(novaMSG_S)[1]) {
          modifique.push_back(c);
        }
        modifique.push_back(' ');
        std::string nova_chav =
            std::bitset<10>(receiveKeyPublic(std::stoll(explode(novaMSG_S)[2])))
                .to_string();
        for (char c : nova_chav) {
          modifique.push_back(c);
        }
        setCript(modifique);
      }
      if (explode(novaMSG_S)[1] == "rc4") {
        std::vector<char> modifique;
        for (char c : explode(novaMSG_S)[1]) {
          modifique.push_back(c);
        }
        modifique.push_back(' ');
        for (char c : std::to_string(
                 receiveKeyPublic(std::stoll(explode(novaMSG_S)[2])))) {
          modifique.push_back(c);
        }
        setCript(modifique);
      }
      if (explode(novaMSG_S)[1] == "none") {
        std::vector<char> modifique;
        for (char c : explode(novaMSG_S)[1]) {
          modifique.push_back(c);
        }
        modifique.push_back(' ');
        for (char c : std::to_string(
                 receiveKeyPublic(std::stoll(explode(novaMSG_S)[2])))) {
          modifique.push_back(c);
        }
        setCript(modifique);
      }
    } else {
      if (analyzerCriptMSG(decript(novaMsg)) == 3) {
        std::string novaMSG_S;
        bool prim = true;
        for (char c : decript(novaMsg)) {
          if (prim) {
            prim = false;
            continue;
          }
          novaMSG_S.push_back(c);
        }
        std::string tipo_g = explode(novaMSG_S)[0];
        std::string chave_g = explode(novaMSG_S)[1];
        if (tipo_g == "sdes") {            
          std::string modif = tipo_g;
          modif += " ";
          int cahve_g_n = std::stoi(chave_g);
          cahve_g_n = receiveKeyPublic(cahve_g_n);
          modif += std::bitset<10>(cahve_g_n).to_string();
          std::vector<char> modif_a;
          for(char c : modif){
              modif_a.push_back(c);
          }
          setCript(modif_a);
        }
        if (tipo_g  == "rc4") {
          std::string modif = tipo_g;
          modif += " ";
          int cahve_g_n = std::stoi(chave_g);
          cahve_g_n = receiveKeyPublic(cahve_g_n);
          modif += std::to_string(cahve_g_n);
          std::vector<char> modif_a;
          for(char c : modif){
              modif_a.push_back(c);
          }
          setCript(modif_a);
        }
        if (tipo_g  == "none") {
          std::string modif = tipo_g;
          modif += " ";
          int cahve_g_n = std::stoi(chave_g);
          cahve_g_n = receiveKeyPublic(cahve_g_n);
          modif += std::to_string(cahve_g_n);
          std::vector<char> modif_a;
          for(char c : modif){
              modif_a.push_back(c);
          }
          setCript(modif_a);
        }
      } else {
        std::cout << "Parceiro: ";
        for (char c : decript(novaMsg)) {
          std::cout << c;
        }
        std::cout << std::endl;
      }
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
void ChatDH::channelTX(Socket* chat, char const* ip) {
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
      if (analyzerCriptMSG(charMsg) == 1) {
        rand_num = getRandNum();
        int n_key_p = sendKeyPublic();
        std::string s_key_p = std::to_string(n_key_p);
        charMsg.push_back(' ');
        for (char c : s_key_p) {
          charMsg.push_back(c);
        }
      }
      chat->submit(encript(charMsg));
    }
  }
}

/**
 * @brief Função para converter a string em um vetor de informações
 *
 * @param P String com a sequência de texto
 * @return std::vector<std::string> Texto separado por informação
 */
std::vector<std::string> ChatDH::explode(const std::string& P) {
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
void ChatDH::setCript(std::vector<char> msg) {
  std::string msg_s;
  for (char c : msg) {
    msg_s.push_back(c);
  }
  std::vector<std::string> conf = explode(msg_s);
  cript = conf[0];
  if (cript != "none") {
    key = conf[1];
  } else {
    key = "";
  }
  std::cout << "---> Criptografia modificada para '" << cript << "' de chave '"
            << key << "'" << std::endl;
}

/**
 * @brief
 *
 * @param msg
 * @return unsigned int
 */
unsigned int ChatDH::analyzerCriptMSG(std::vector<char> msg) {
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
  if (conf.size() != 3) {
    if (conf.size() == 2) {
      if (conf[0] == "sdes") {
        if (conf[1].size() > 0) {
          return 3;
        }
      }
      if (conf[0] == "rc4") {
        if (conf[1].size() > 0) {
          return 3;
        }
      }
      if (conf[0] == "none") {
        if (conf[1].size() > 0) {
          return 3;
        }
      }
      if (conf[0] == "crypt") {
        if (conf[1] == "sdes") {
          return 1;
        }
        if (conf[1] == "rc4") {
          return 1;
        }
        if (conf[1] == "none") {
          return 1;
        }
      }
    }
    return false;
  } else {
    if (conf[0] == "crypt") {
      if (conf[1] == "sdes") {
        if (conf[2].size() > 0) {
          return 2;
        }
      }
      if (conf[1] == "rc4") {
        if (conf[2].size() > 0) {
          return 2;
        }
      }
      if (conf[1] == "none") {
        if (conf[2].size() > 0) {
          return 2;
        }
      }
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
std::vector<char> ChatDH::decript(std::vector<char> msg_cript) {
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
std::vector<char> ChatDH::encript(std::vector<char> msg) {
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

/**
 * @brief Gerar chave publica
 *
 * @return long long Chave publica para enviar
 */
long long ChatDH::sendKeyPublic(void) { return power(a_dh, rand_num, q_dh); }

/**
 * @brief Gerar chave de criptografia
 *
 * @param number_public Número publico recebido
 */
long long ChatDH::receiveKeyPublic(long long number_public) {
  return power(number_public, rand_num, q_dh);
}

/**
 * @brief Get the Rand Num object
 *
 * @return unsigned int
 */
unsigned int ChatDH::getRandNum(void) {
  std::srand(std::time(nullptr));
  return 1 + std::rand() / ((RAND_MAX + 1u) / q_dh);
}

/**
 * @brief Calcular mod muito grande
 *
 * @param x base
 * @param y expoente
 * @param p mod
 * @return long long resultado final
 */
long long ChatDH::power(long long x, long long y, long long p) {
  long long res = 1;  // Initialize result

  // Update x if it is more than or
  // equal to p
  x = x % p;

  while (y > 0) {
    // If y is odd, multiply x with the result
    if (y & 1) res = (res * x) % p;

    // y must be even now
    y = y >> 1;  // y = y/2
    x = (x * x) % p;
  }
  return res;
}