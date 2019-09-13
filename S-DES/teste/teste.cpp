
#include <bitset>
#include <fstream>   // std::ifstream
#include <iostream>  // std::cerr
#include <string>    // std::string
#include <vector>    // std::vector

int main(int argc, char const *argv[]) {
  std::ifstream file("texto.txt");
  char c;
  while (file.get(c)) {
    std::cout << c;;
  }
  file.close();

  // std::string binaryText;
  // for (std::string a : text) {
  //   binaryText += a;
  // }

  // std::ofstream newFile;
  // newFile.open("Final.txt", std::ios::trunc);
  // for (char n : binaryText) {
  //   if (std::bitset<8>(n).to_ulong() == 10) {
  //     std::cout << "SIM ";
  //   }
  //   newFile << n;
  // }

  // newFile.close();
  return 0;
  // std::cout << "a";
  //   std::cout << static_cast<char>(std::bitset<8>("00001010").to_ulong()) <<
  //   std::endl;
  // std::cout << "a";
}
