#ifndef CONSTRUCTORJSON_H
#define CONSTRUCTORJSON_H
#pragma once

#include "Actividad.hpp"
#include "ConstructorAbstracto.hpp"

class ConstructorJSON : public ConstructorAbstracto {
 private:
  std::string funcAuxiliar(Actividad* actividad, std::string indentacion);

 public:
  ConstructorJSON();
  ~ConstructorJSON();
  void serializadorActividad(Actividad* actividad) override;
};
#endif