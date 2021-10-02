#ifndef COMPRESORALPHA_H
#define COMPRESORALPHA_H
#pragma once
#include <cstring>
#include <ostream>
#include <string>

class CompresorAlpha : public std::ostream {
 private:
  void algoritmoAlpha(const char *str);

 public:
  std::ostream *buffer;
  CompresorAlpha(std::ostream *buffer);

  ~CompresorAlpha();

  std::ostream &operator<<(const char *str);
  std::ostream &operator<<(std::string &str);
};

#endif