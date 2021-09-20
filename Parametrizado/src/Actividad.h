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
  std::string responsable;
  std::string fechaPlanteadaInicio;
  std::string fechaPlanteadaFinal;
  std::string fechaRealInicio;
  std::string fechaRealFinalizacion;
  std::string descripcion;

  template <typename T>
  void add(T& other) {
    Tipo* elPadre = other.getTipo()->getPadre();
    Tipo* elHijo =this->tipo->getHijo();
    for (ActividadSimple& from : *static_cast<Self*>(this)) {
      for (ActividadSimple& to : other) {
        if (elHijo and elPadre and elPadre->getNombre() == this->tipo->getNombre() 
				and other.getTipo()->getNombre() == elHijo->getNombre()){
          from.out_push_back(to);
          to.parent = &from;
        }
        else {
          std::cout << "No se puede agregar el hijo por problemas de jerarquía" << std::endl;
        }
        
      }
    }
  }

  Tipo* getTipo() { return this->tipo; }

  void setTipo(Tipo* nuevoTipo) { this->tipo = nuevoTipo; }

  std::string getResponsable() { return this->responsable; }

  void setResponsable(std::string nuevoResponsable) {
    this->responsable = nuevoResponsable;
  }

   std::string getFechaPlanteadaInicio() { return this->fechaPlanteadaInicio; }
  void setFechaPlanteadaInicio(std::string NuevafechaPlanteadaInicio) {
    this->fechaPlanteadaInicio = NuevafechaPlanteadaInicio;
  }
  std::string getFechaPlanteadaFinal() { return this->fechaPlanteadaFinal; }
  void setFechaPlanteadaFinal(std::string nuevaFechaPlanteadaFinal) {
    this->fechaPlanteadaFinal = nuevaFechaPlanteadaFinal;
  }
  std::string getFechaRealInicio() { return this->fechaRealInicio; }
  void setFechaRealInicio(std::string nuevaFechaRealFinal) {
    this->fechaRealInicio = nuevaFechaRealFinal;
  }
  std::string getFechaRealFinalizacion() { return this->fechaRealFinalizacion; }
  void setFechaRealFinalizacion(std::string nuevaFechaRealFinalizacion) {
    this->fechaRealFinalizacion = nuevaFechaRealFinalizacion;
  }
  std::string getDescripcion() { return this->descripcion; }
  void setDescripcion(std::string nuevaDescripcion) {
    this->descripcion = nuevaDescripcion;
  }

};

template <typename Self>
Actvidad<Self>::Actvidad() {}

template <typename Self>
Actvidad<Self>::~Actvidad() {}
