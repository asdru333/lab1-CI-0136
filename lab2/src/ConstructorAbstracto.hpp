#ifndef CONSTRUCTOR_ABSTRACTO_HPP
#define CONSTRUCTOR_ABSTRACTO_HPP

#include <string>

#include "Actividad.hpp"

class ConstructorAbstracto {
 private:
  std::string resultado;

 public:
  virtual void serializadorActividad(Actividad* actividad) = 0;
};

#endif