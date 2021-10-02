#include <fstream>
#include <iostream>
#include <sstream>

#include "CompresorAlpha.hpp"
#include "CompresorBeta.hpp"

int main() {
  std::string prueba = "stringstream-compresorAlpha con variable std::string";
  std::stringstream sstream;
  CompresorAlpha compresorSs(&sstream);
  compresorSs << prueba;
  std::cout << sstream.str();

  std::cout << std::endl;

  std::ostringstream osstream;
  CompresorBeta compresorOss(&osstream);
  compresorOss << "ostringstream-compresorBeta texto directo";

  std::cout << osstream.str() << std::endl;

  std::fstream fstream;
  CompresorAlpha compresorFs(&fstream);
  fstream.open("text1fs.txt", std::fstream::out);
  compresorFs << "fstream-compresorAlpha texto directo";
  fstream.close();

  prueba = "ofstream-compresorBeta con variable std::string";
  std::ofstream ofstream;
  CompresorBeta compresorOfs(&ofstream);
  ofstream.open("text1ofs.txt", std::fstream::out);
  compresorOfs << prueba;
  ofstream.close();
  return 0;
}