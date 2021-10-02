#ifndef COMPRESOR2_H
#define COMPRESOR2_H
#pragma once

#include <ostream>

class CompresorBeta : public std::ostream {
 private:
  std::ostream* buffer;
  void algoritmoBeta(const char* str);

 public:
  CompresorBeta(std::ostream* buffer);

  ~CompresorBeta();

  std::ostream& operator<<(const char* str);
  std::ostream& operator<<(std::string& str);
};

#endif