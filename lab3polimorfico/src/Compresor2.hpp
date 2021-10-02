#ifndef COMPRESOR2_H
#define COMPRESOR2_H
#pragma once

#include <ostream>

class Compresor2 : public std::ostream {
 private:
  std::ostream* buffer;

 public:
  Compresor2(std::ostream* buffer);

  ~Compresor2();

  std::ostream& operator<<(const char* str);
};

#endif