# Atividade Prática – S-DES

Desenvolvido  por   [Allan de Miranda](https://github.com/allandemiranda)
                    [Odilon Júlio](https://github.com/OdilonJulio)

11 de setembro de 2019 - Segurança de Redes - IMD

## Introdução

Implemente o algoritmo de criptografia S-DES apresentado em aula para cifrar/decifrar um
arquivo texto passado por parâmetro em linha de comando.

## Instalação

Para instalar e executar o programa siga as instruções:

1. Abra o terminal do seu sistema operacional e digite `cd`
2. `git clone https://github.com/allandemiranda/criptografia-simetrica`
3. `cd criptografia-simetrica/S-DES/`
4. `make`

## Como utilizar o Codificador

1. Abra o terminal do seu sistema operacional e digite `cd`
2. `cd criptografia-simetrica/S-DES/`
3. `./bin/main.o codificador <caminho do arquivo>`
4. `vi out/TextoCodificado.txt`

## Como utilizar o Decodificador

1. Abra o terminal do seu sistema operacional e digite `cd`
2. `cd criptografia-simetrica/S-DES/`
3. `./bin/main.o decodificador <caminho do arquivo>`

## Modificar chave S-DES 10-bit

1. Abra o terminal do seu sistema operacional e digite `cd`
2. `cd criptografia-simetrica/S-DES/`
3. `vi data/key.des`
4. `i`
5. Digite uma nova chave binária de 10 caracteres, sobrescrevendo a atual.
6. `:wq`