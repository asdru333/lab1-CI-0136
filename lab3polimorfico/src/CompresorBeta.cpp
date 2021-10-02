#include "CompresorBeta.hpp"

#include <cstring>
#include <string>

CompresorBeta::CompresorBeta(std::ostream* buffer) : buffer(buffer) {}

CompresorBeta::~CompresorBeta() {}

void CompresorBeta::algoritmoBeta(const char* str) {
  for (size_t x = 0; x < strlen(str); ++x) *buffer << str[x] << ".";
}

// Para agregar texto directamente al stream, ejemplo: sstream << "hola";
std::ostream& CompresorBeta::operator<<(const char* str) {
  this->algoritmoBeta(str);
  return *buffer;
}

/* Para agregar una variable std::string al stream ejemplo:
 * std::string str = "hola";
 * sstream << str; */
std::ostream& CompresorBeta::operator<<(std::string& str) {
  const char* cString = str.c_str();
  this->algoritmoBeta(cString);
  return *buffer;
}