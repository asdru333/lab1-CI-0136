#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Tipo.hpp"

class Actividad {
 protected:
  Actividad* padre;
  Tipo* tipo;
  std::string responsable;
  std::string fechaPlanteadaInicio;
  std::string fechaPlanteadaFinal;
  std::string fechaRealInicio;
  std::string fechaRealFinalizacion;
  std::string descripcion;

 public:
  Actividad* getPadre() { return this->padre; }
  void setPadre(Actividad* nuevoPadre) {
    if ((!nuevoPadre) or (this->tipo->getPadre()->getNombre() ==
                          nuevoPadre->getTipo()->getNombre()))
      this->padre = nuevoPadre;
    else
      std::cout << "Padre inválido" << std::endl;
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
  virtual void calcularFechas() = 0;
  virtual void add(Actividad*) = 0;
  virtual void remove(Actividad*) = 0;
};
