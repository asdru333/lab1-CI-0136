#include <sstream>
#include "Compresor1.hpp"


Compresor1::Compresor1(std::ostream *buffer) : buffer(buffer) {}

Compresor1::~Compresor1() {}

std::ostream &Compresor1::operator<<(std::string hilera) {
  return *this->buffer;
}


/*
std::ostream &Compresor1::operator<<(std::string hilera) {
  hilera += "MODIFICADA";
  *this->buffer << hilera;
  return *this->buffer;
}*/
