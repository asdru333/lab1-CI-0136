#pragma once
class ActividadSimple;
#include <string>

#include "Tipo.hpp"

template <typename Self>
class Actvidad {
 public:
  Actvidad();
  ~Actvidad();
  Tipo* tipo;
  std::string nombre;

  template <typename T>
  void add(T& other) {
    Tipo* elPadre = other.getTipo()->getPadre();
    Tipo* elHijo = this->tipo->getHijo();
    for (ActividadSimple& from : *static_cast<Self*>(this)) {
      for (ActividadSimple& to : other) {
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
    }
  }

  virtual void calcularFechas() = 0;

  Tipo* getTipo() { return this->tipo; }

  void setTipo(Tipo* nuevoTipo) { this->tipo = nuevoTipo; }

  virtual std::string getResponsable() = 0;

  virtual void setResponsable(std::string nuevoResponsable) = 0;

  virtual std::string getFechaPlanteadaInicio() = 0;

  virtual void setFechaPlanteadaInicio(
      std::string NuevafechaPlanteadaInicio) = 0;

  virtual std::string getFechaPlanteadaFinal() = 0;

  virtual void setFechaPlanteadaFinal(std::string nuevaFechaPlanteadaFinal) = 0;

  virtual std::string getFechaRealInicio() = 0;

  virtual void setFechaRealInicio(std::string nuevaFechaRealFinal) = 0;

  virtual std::string getFechaRealFinalizacion() = 0;

  virtual void setFechaRealFinalizacion(
      std::string nuevaFechaRealFinalizacion) = 0;

  virtual std::string getDescripcion() = 0;

  virtual void setDescripcion(std::string nuevaDescripcion) = 0;
};

template <typename Self>
Actvidad<Self>::Actvidad() {}

template <typename Self>
Actvidad<Self>::~Actvidad() {}
