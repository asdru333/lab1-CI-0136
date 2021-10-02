#include <fstream>
#include <iostream>
#include <sstream>

#include "Compresor1.hpp"
#include "Compresor2.hpp"

int main() {
  std::fstream fstreamBuffer;
  std::ofstream ofstreamBuffer;
  std::stringstream stringstreamBuffer;
  std::ostringstream ostringstreamBuffer;

  stringstreamBuffer << "hola";

  Compresor1 compresor1(&stringstreamBuffer);
  Compresor2 compresor2(&stringstreamBuffer);
  compresor1 << "Javier y Asdrubal";
  compresor2 << "Compresion 2";
  std::cout << stringstreamBuffer.str();

  return 0;
}