/**
 * @file KSA.h
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief Class de agendamento de chaves
 * @version 0.1
 * @date 14-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef KSA_H_
#define KSA_H_

#include <string>  // std::string
#include <vector>  // std::vector

class KSA {
 private:
  std::vector<unsigned int> setOrdenation(void);  // Definir vetor ordenado
  std::vector<unsigned int> setK(std::string);    // Definir o vetor da chave
  std::vector<unsigned int> setT(
      std::vector<unsigned int>);  // Definir vetor chave temporária
  std::vector<unsigned int> setPermutatio(
      std::vector<unsigned int>,
      std::vector<unsigned int>);  // Operação de permutação entre vetores
  std::vector<unsigned int> S;     // Vetor S final

 public:
  std::vector<unsigned int> getS(void);
  KSA(std::string);
  ~KSA(void);
};

#endif