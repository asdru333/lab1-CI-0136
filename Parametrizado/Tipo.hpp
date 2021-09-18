#ifndef TIPO_H
#define TIPO_H

#pragma once
#include <string>

class Tipo {
 private:
  std::string nombre;
  Tipo* padre;
  Tipo* hijo;

 public:
  Tipo(std::string nombre, Tipo* padre = nullptr, Tipo* hijo = nullptr);

  ~Tipo();

  std::string getNombre();
  void setNombre(std::string nuevoNombre);

  Tipo* getPadre();
  void setPadre(Tipo* nuevoPadre);

  Tipo* getHijo();
  void setHijo(Tipo* nuevoHijo);
};
#endif