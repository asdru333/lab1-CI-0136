#include "Compresor2.hpp"

#include <cstring>

Compresor2::Compresor2(std::ostream* buffer) : buffer(buffer) {}

Compresor2::~Compresor2() {}

std::ostream& Compresor2::operator<<(const char* str) {
  for (size_t x = 0; x < strlen(str); ++x) *buffer << str[x] << ".";
  return *buffer;
}