# Atividade Prática – S-DES

Desenvolvido  por   [Allan de Miranda](https://github.com/allandemiranda)
                    [Odilon Júlio](https://github.com/OdilonJulio)       

11 de setembro de 2019 - Segurança de Redes - IMD

## Introdução

Implemente os algoritmos de criptografia apresentados em aula.

## Instalação

Para instalar e executar o programa siga as instruções:

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `git clone https://github.com/allandemiranda/criptografia-simetrica` 
3. `cd criptografia-simetrica/` 
4. `make` 

## Como utilizar o Codificador S-DES

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `cd criptografia-simetrica/` 
3. `./bin/main.o sdes <caminho do arquivo origem> <caminho do arquivo destino> <chave>` 
4. O arquivo de origem será o seu texto original
5. O arquivo de destino será o seu texto criptografado
6. A chave trata-se de uma entrada de 10-bits

Ex: `./bin/main.o sdes data/texto.txt out/texto_des.out 1010101010` 

## Como utilizar o Decodificador S-DES

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `cd criptografia-simetrica/` 
3. `./bin/main.o sdes <caminho do arquivo origem> <chave>` 
4. O arquivo de origem será o seu texto codificado
5. A chave trata-se de uma entrada de 10-bits
6. Texto decodificado aparecerá no terminal

Ex: `./bin/main.o sdes out/texto_des.out 1010101010` 

## Como utilizar o Codificador RC4

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `cd criptografia-simetrica/` 
3. `./bin/main.o rc4 <caminho do arquivo origem> <caminho do arquivo destino> <chave>` 
4. O arquivo de origem será o seu texto original
5. O arquivo de destino será o seu texto criptografado
6. A chave trata-se de uma entrada de 1 a 255 caracteres

Ex: `./bin/main.o rc4 data/texto.txt out/texto_des.out redes` 

## Como utilizar o Decodificador RC4

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `cd criptografia-simetrica/` 
3. `./bin/main.o rc4 <caminho do arquivo origem> <chave>` 
4. O arquivo de origem será o seu texto codificado
5. A chave trata-se de uma entrada de 1 a 255 caracteres
6. Texto decodificado aparecerá no terminal

Ex: `./bin/main.o rc4 out/texto_des.out redes` 

## Como utilizar o Chat

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `cd criptografia-simetrica/` 
3. `./bin/main.o chat <ip do parceiro>` 

Ex: `./bin/main.o chat 192.168.0.101` 

## Como modificar criptografia no Chat

1. No chat digite `\crypt [sdes | rc4 | none] [chave]` 
2. Obs: Para o tipo none (default) não é necessário uma chave

## Como utilizar o Chat com Diffie-Hellman

1. Abra o terminal do seu sistema operacional e digite `cd` 
2. `cd criptografia-simetrica/` 
3. `./bin/main.o chatDH <ip do parceiro>` 

Ex: `./bin/main.o chat 192.168.0.101` 

## Como modificar criptografia no Chat com Diffie-Hellman

1. No chat digite `\crypt [sdes | rc4 | none]` 

