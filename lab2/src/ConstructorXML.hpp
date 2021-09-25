#ifndef CONSTRUCTORXML_H
#define CONSTRUCTORXML_H
#pragma once

#include <string>

#include "Actividad.hpp"
#include "ConstructorAbstracto.hpp"

class ConstructorXML : public ConstructorAbstracto {
 private:
  std::string serializacion;
  std::string funcAuxiliar(Actividad* actividad, std::string indentacion);

 public:
  ConstructorXML();
  ~ConstructorXML();
  void serializadorActividad(Actividad* actividad) override;
};

#endif