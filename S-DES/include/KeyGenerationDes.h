/**
 * @file KeyGenerationDes.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class para a geração de chaves do S-DES
 * @version 0.1
 * @date 13-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef KEYGENERATIONDES_H_
#define KEYGENERATIONDES_H_

#include <omp.h>   // OpenMP
#include <bitset>  // std::bitset
#include <vector>  // std::vector

class KeyGenerationDes {
 private:
  char keyMaster;                                     // Chave principal
  std::vector<char> keys;                             // Chaves geradas
  char getKeyMaster(void);                            // Obter chave principal
  void setKeyMaster(char);                            // Definir chave principal
  void setSubKey(char);                               // Definir sub chave
  void generateSubKeys(char);                         // Gerar as sub chaves
  char permutation(char, std::vector<unsigned int>);  // Permutação de chave
  std::vector<unsigned int> P10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};  // P10
  std::vector<unsigned int> P8 = {6, 3, 7, 4, 8, 5, 10, 9};         // P8
  char LS(char, unsigned int);                                      // LS
  char keyRight(char);  // Parte direita da chave
  char keyLeft(char);   // Parte esquerda da chave

 public:
  char getSubKey(unsigned int);  // Ober sub chave
  KeyGenerationDes(char);
  ~KeyGenerationDes(void);
};

/**
 * @brief Construct a new Key Generation Des:: Key Generation Des object
 *
 * @param key_master Chave principal
 */
KeyGenerationDes::KeyGenerationDes(char key_master) {}

/**
 * @brief Destroy the Key Generation Des:: Key Generation Des object
 *
 */
KeyGenerationDes::~KeyGenerationDes(void) {}

/**
 * @brief Get the Key Master object
 *
 * @return char Chave principal
 */
char KeyGenerationDes::getKeyMaster(void) { return keyMaster; }

/**
 * @brief Set the Key Master object
 *
 * @param key_master Chave princial
 */
void KeyGenerationDes::setKeyMaster(char key_master) { keyMaster = key_master; }

/**
 * @brief Set the Sub Key object
 *
 * @param sub_key Sub chave
 */
void KeyGenerationDes::setSubKey(char sub_key) { keys.push_back(sub_key); }

/**
 * @brief Gerar as sub chaves
 *
 * @param key_master Chave principal
 */
void KeyGenerationDes::generateSubKeys(char key_master) { /** FAZER **/
}

/**
 * @brief Permutar a chave
 *
 * @param key Chave
 * @param feistel Sequência de permutação
 * @return char Chave permutada
 */
char KeyGenerationDes::permutation(char key,
                                   std::vector<unsigned int> feistel) {
  for (unsigned int i = 0; i < feistel.size(); ++i) {
    if (feistel[i] > 8) {
      throw "Vetor Feistel contem elemento maior que tamanho da chave";
    }
    if (feistel[i] == 0) {
      throw "Vetor Feistel contem elemento menor que tamanho da chave";
    }
  }

  std::string key_string = std::bitset<8>(key).to_string();

  std::string final_Key;
  for (unsigned int position : feistel) {
    final_Key.push_back(key_string[position - 1]);
  }

  return static_cast<char>(std::bitset<8>(key_string).to_ulong());
}

#endif