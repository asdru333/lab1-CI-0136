#pragma once
class ActividadSimple;
#include <string>

#include "Tipo.hpp"
template <typename Self>
class Actvidad {
 public:
  Actvidad();
  ~Actvidad();
  string nombre;
  Tipo* tipo;

  template <typename T>
  void add(T& other) {
    Tipo* elPadre = other.getTipo()->getPadre();
    Tipo* elHijo = this->tipo->getHijo();

    ActividadSimple& from = *this->begin();
    ActividadSimple& to = *other.begin();

    if (elHijo and elPadre and
        elPadre->getNombre() == this->tipo->getNombre() and
        other.getTipo()->getNombre() == elHijo->getNombre()) {
      from.out_push_back(to);
      to.parent = &from;
    } else {
      std::cout << "No se puede agregar el hijo por problemas de jerarquía"
                << std::endl;
    }
  }
  Tipo* getTipo() { return this->tipo; }

  void setTipo(Tipo* nuevoTipo) { this->tipo = nuevoTipo; }

  virtual ActividadSimple* begin() = 0;
  virtual void calcularFechas() = 0;
};

template <typename Self>
Actvidad<Self>::Actvidad() {}

template <typename Self>
Actvidad<Self>::~Actvidad() {}
