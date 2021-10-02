#include "CompresorBeta.hpp"

#include <cstring>

CompresorBeta::CompresorBeta(std::ostream* buffer) : buffer(buffer) {}

CompresorBeta::~CompresorBeta() {}

std::ostream& CompresorBeta::operator<<(const char* str) {
  for (size_t x = 0; x < strlen(str); ++x) *buffer << str[x] << ".";
  return *buffer;
}