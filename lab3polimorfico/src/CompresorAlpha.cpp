#include "CompresorAlpha.hpp"

#include <ostream>

CompresorAlpha::CompresorAlpha(std::ostream* buffer) : buffer(buffer) {}

CompresorAlpha::~CompresorAlpha() {}

void CompresorAlpha::algoritmoAlpha(const char* str) {
  for (size_t x = 0; x < strlen(str); ++x) *buffer << str[x] << " ";
}

// Para agregar texto directamente al stream, ejemplo: sstream << "hola";
std::ostream& CompresorAlpha::operator<<(const char* str) {
  this->algoritmoAlpha(str);
  return *buffer;
}

/* Para agregar una variable std::string al stream ejemplo:
 * std::string str = "hola";
 * sstream << str; */
std::ostream& CompresorAlpha::operator<<(std::string& str) {
  const char* cString = str.c_str();
  this->algoritmoAlpha(cString);
  return *buffer;
}