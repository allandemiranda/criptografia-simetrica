/**
 * @file main.cpp
 * @author Allan de Miranda Silva and Odilon Júlio dos Santos 
 * @brief 
 * @version 0.1
 * @date 14-09-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "RC4.h"
using namespace std;

int main(int argc, char argv[]){
    if (argc != 3){
        std::cerr << "Erro! Digite os argumentos corretamente.";
        return 0;
    } 
    else {
        RC4 on(argv[1], argv[2]);
        printf("Cifra RC4 realizada!");
    }

    system("pause");
}