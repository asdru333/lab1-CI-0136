#include "Compresor1.hpp"

#include <ostream>

Compresor1::Compresor1(std::ostream* buffer) : buffer(buffer) {}

Compresor1::~Compresor1() {}

std::ostream& Compresor1::operator<<(const char* str) {
  for (size_t x = 0; x < strlen(str); ++x) *buffer << str[x] << " ";
  return *buffer;
}