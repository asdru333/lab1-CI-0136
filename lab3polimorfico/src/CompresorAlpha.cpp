#include "CompresorAlpha.hpp"

#include <ostream>

CompresorAlpha::CompresorAlpha(std::ostream* buffer) : buffer(buffer) {}

CompresorAlpha::~CompresorAlpha() {}

std::ostream& CompresorAlpha::operator<<(const char* str) {
  for (size_t x = 0; x < strlen(str); ++x) *buffer << str[x] << " ";
  return *buffer;
}