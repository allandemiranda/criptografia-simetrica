/**
 * @file main.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos
 * @brief
 * @version 0.1
 * @date 09-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "BinaryToText.h"
#include "Decode.h"
#include "Encode.h"
#include "KeyGeneration.h"
#include "OpenFile.h"
#include "SaveBinaryFile.h"
#include "TextToBinary.h"

#include <iostream>  // std::cout , std::endl
#include <string>    // std::string

void codificar(std::string);    // Codifiar texto
void decodificar(std::string);  // Decodificar texto binário

/**
 * @brief Função menu
 *
 * @param argc Quantidade de parãmetros recebidos
 * @param argv Parâmetros recebidos
 * @return int 0 WARNING Programa não execultou
 * @return int 1 ERROR Argumntos não digitados corretamente
 * @return int 2 ERROR Opção inválida
 * @return int 3 SUCCESS Arquivo codificado
 * @return int 4 SUCCESS Arquivo decodificado
 */
int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cout << "Erro! Digitar os argumentos corretamente." << std::endl;
    return 1;
  } else {
    std::string opcao = argv[1];
    std::string caminho = argv[2];
    if (opcao == "codificar") {
      codificar(caminho);
      std::cout << "Arquivo " << caminho << " codificado !" << std::endl;
      return 3;
    } else {
      if (opcao == "decodificar") {
        decodificar(caminho);
        return 4;
      } else {
        std::cout << "Erro! Digite uma opção válida" << std::endl;
        return 2;
      }
    }
  }
  return 0;
}

/**
 * @brief Função para codificar texto de um arquivo
 *
 * @param caminho Caminho do arquivo com o texto
 * @return std::string Texto codificado
 */
void codificar(std::string caminho) {
  OpenFile chavePrincipal("data/key.des");
  KeyGeneration subChaves(chavePrincipal.getLine(1));

  OpenFile arquivoTexto(caminho);
  std::string textoEmBinario;
  for (auto i(0u); i < arquivoTexto.getSizeText(); ++i) {
    TextToBinary paraBinario(arquivoTexto.getLine(i + 1));
    textoEmBinario += paraBinario.getBinary();
  }

  std::string textoCodficado;
  for (auto i(0u); i < (textoEmBinario.size() / 8); ++i) {
    std::string tempBinario;
    for (auto j(0u); j < 8; ++j) {
      tempBinario.push_back(textoEmBinario[(i * 8) + j]);
    }
    Encode codificado(tempBinario, subChaves.getKey(1), subChaves.getKey(2));
    textoCodficado += codificado.getFinalPlaintext();
  }

  SaveBinaryFile salvarBinario(textoCodficado);
}

/**
 * @brief Função para decodificar texto de um arquivo
 *
 * @param caminho Caminho do arquivo codificado
 */
void decodificar(std::string caminho) {
  OpenFile chavePrincipal("data/key.des");
  KeyGeneration subChaves(chavePrincipal.getLine(1));

  OpenFile arquivoBinario(caminho);
  std::string arquivoBinarioDecodificado;
  for (auto i(0u); i < (arquivoBinario.getLine(1).size() / 8); ++i) {
    std::string tempBinario;
    for (auto j(0u); j < 8; ++j) {
      tempBinario.push_back(arquivoBinario.getLine(1)[(i * 8) + j]);
    }
    Decode decodificado(tempBinario, subChaves.getKey(1), subChaves.getKey(2));
    arquivoBinarioDecodificado += decodificado.getFinalPlaintext();
  }

  BinaryToText textoFinal(arquivoBinarioDecodificado);
  for (auto i(0u); i < textoFinal.getSizeText(); ++i) {
    std::cout << textoFinal.getLine(i + 1) << std::endl;
  }
}