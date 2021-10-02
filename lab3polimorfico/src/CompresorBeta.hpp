#ifndef COMPRESOR2_H
#define COMPRESOR2_H
#pragma once

#include <ostream>

class CompresorBeta : public std::ostream {
 private:
  std::ostream* buffer;

 public:
  CompresorBeta(std::ostream* buffer);

  ~CompresorBeta();

  std::ostream& operator<<(const char* str);
};

#endif