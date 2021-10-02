#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>

#include "CompresorAlpha.hpp"
#include "CompresorBeta.hpp"

int main() {
  std::string hola("hola");
  CompresorAlpha<std::stringstream> compresorSs;
  compresorSs << hola;
  std::cout << compresorSs.str();

  std::cout << std::endl;

  CompresorAlpha<std::ostringstream> compresorOs;
  compresorOs << hola;
  std::cout << compresorOs.str();

  std::cout << std::endl;

  CompresorAlpha<std::fstream> compresorFs;
  compresorFs.open("text1fs.txt", std::fstream::out);
  compresorFs << hola;
  compresorFs.close();

  CompresorAlpha<std::ofstream> compresorOfs;
  compresorOfs.open("text1ofs.txt", std::fstream::out);
  compresorOfs << hola;
  compresorOfs.close();

  CompresorBeta<std::stringstream> compresorSs2;
  compresorSs2 << hola;
  std::cout << compresorSs2.str();

  return 0;
}
