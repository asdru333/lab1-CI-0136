#ifndef COMPRESOR1_H
#define COMPRESOR1_H
#pragma once

#include <iostream>

// TODO : Arreglar el diseño
class Compresor1 : public std::ostream {
 private:
 public:
  std::ostream *buffer;

  Compresor1(std::ostream *buffer);

  ~Compresor1();

   std::ostream &operator<<(std::string hilera);

};

#endif