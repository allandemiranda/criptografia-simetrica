#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <string>
#define PORT 5354

int main(int argc, char const *argv[]) {
#pragma omp parallel
  {
#pragma omp sections
    {
#pragma omp section
      {
        int server_fd, new_socket, valread;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        if ((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
          perror("socket failed");
          exit(EXIT_FAILURE);
        }
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                       sizeof(opt))) {
          perror("setsockopt");
          exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
          perror("bind failed");
          exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 3) < 0) {
          perror("listen");
          exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0) {
          perror("accept");
          exit(EXIT_FAILURE);
        }
        bool flagWhile = true;
        while (flagWhile) {
          char buffer[1024] = {0};
          valread = recv(new_socket, buffer, 1024, 0);
          if (valread == 0) {
            std::cout << "Chat fechado" << std::endl;
            flagWhile = false;
            continue;
          }
          printf("%s\n", buffer);
        }
      }
#pragma omp section
      {
        int sock = 0, valread;
        struct sockaddr_in serv_addr;
        // char *hello = "Hello from client";
        // char buffer[1024] = {0};
        if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
          printf("\n Socket creation error \n");
        }
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
          printf("\nInvalid address/ Address not supported \n");
        }
        while (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) <
               0) {
          // Aguardando outro usuário
        }
        while (true) {
          std::string aaa;
          std::getline(std::cin, aaa);
          send(sock, aaa.c_str(), strlen(aaa.c_str()), 0);
          aaa.clear();
        }
      }
    }
  }
  return 0;
}
