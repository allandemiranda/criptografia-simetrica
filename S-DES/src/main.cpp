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

#include "OpenFile.h"
#include "KeyGeneration.h"
#include "TextToBinary.h"

#include <iostream>
#include <string>
#include <vector>

std::string codificar(std::string);    // Codifiar texto
std::string decodificar(std::string);  // Decodificar texto binário

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

/**
 * @brief Função para codificar texto de um arquivo
 *
 * @param caminho Caminho do arquivo com o texto
 * @return std::string Texto codificado
 */
std::string codificar(std::string caminho) {     
    OpenFile chavePrincipal("data/key.des");
    KeyGeneration subChaves(chavePrincipal.getLine(1));

    OpenFile arquivoTexto(caminho);
    TextToBinary arquivoEmBinario();

}
