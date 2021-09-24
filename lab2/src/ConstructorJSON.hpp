#ifndef CONSTRUCTORJSON_H
#define CONSTRUCTORJSON_H
#pragma once

#include "Actividad.hpp"
#include "ConstructorAbstracto.hpp"

class ConstructorJSON : public ConstructorAbstracto {
 private:
 public:
  ConstructorJSON();
  ~ConstructorJSON();
  int serializadorActividad(Actividad* actividad) override {}
};
#endif