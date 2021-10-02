#include <fstream>
#include <iostream>
#include <sstream>

#include "CompresorAlpha.hpp"
#include "CompresorBeta.hpp"

int main() {
  std::stringstream sstream;
  CompresorAlpha compresorSs(&sstream);
  compresorSs << "Prueba:stringstream-compresorAlpha";
  std::cout << sstream.str();

  std::cout << std::endl;

  std::ostringstream osstream;
  CompresorBeta compresorOss(&osstream);
  compresorOss << "Prueba:ostringstream-compresorBeta";

  std::cout << osstream.str();

  std::fstream fstream;
  CompresorAlpha compresorFs(&fstream);
  fstream.open("text1fs.txt", std::fstream::out);
  compresorFs << "Prueba:fstream-compresorAlpha";
  fstream.close();

  std::ofstream ofstream;
  CompresorBeta compresorOfs(&ofstream);
  ofstream.open("text1ofs.txt", std::fstream::out);
  compresorOfs << "Prueba:ofstream-compresorBeta";
  ofstream.close();
  return 0;
}