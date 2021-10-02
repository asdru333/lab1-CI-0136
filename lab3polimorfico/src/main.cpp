#include "Compresor1.hpp"
#include "Compresor2.hpp"


#include <fstream>
#include <sstream>

int main() {
  std::fstream fstreamBuffer;
  std::ofstream ofstreamBuffer;
  std::stringstream stringstreamBuffer;
  std::ostringstream ostringstreamBuffer;

  stringstreamBuffer << "hola";

  Compresor1 compresor1(&fstreamBuffer);
  compresor1 << "Javier y Asdrubal";
  std::cout << stringstreamBuffer.str();

  return 0;
}