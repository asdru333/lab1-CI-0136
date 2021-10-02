#ifndef COMPRESORALPHA_H
#define COMPRESORALPHA_H
#pragma once
#include <cstring>
#include <ostream>

// TODO : Arreglar el diseño
class CompresorAlpha : public std::ostream {
 private:
 public:
  std::ostream *buffer;
  CompresorAlpha(std::ostream *buffer);

  ~CompresorAlpha();

  std::ostream &operator<<(const char *str);
};

#endif