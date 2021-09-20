#pragma once
#include <vector>
using namespace std;
#include "Actividad.h"

class ActividadSimple : public Actvidad<ActividadSimple> {
 public:
  std::string responsable;
  std::string fechaPlanteadaInicio;
  std::string fechaPlanteadaFinal;
  std::string fechaRealInicio;
  std::string fechaRealFinalizacion;
  std::string descripcion;

  ActividadSimple(string nombre);
  ~ActividadSimple();
  vector<ActividadSimple> out;
  ActividadSimple* parent;

  // unsigned int gId();
  void out_push_back(ActividadSimple& other);
  void in_push_back(ActividadSimple& other);
  ActividadSimple* begin() { return this; };
  ActividadSimple* end() { return (this + 1); };
  void quienEsMiPapaYmiHijo();
  std::string getFechaPlanteadaFinal();
  std::string getResponsable();

  void setResponsable(std::string nuevoResponsable);

  std::string getFechaPlanteadaInicio();

  void setFechaPlanteadaInicio(std::string NuevafechaPlanteadaInicio);

  void setFechaPlanteadaFinal(std::string nuevaFechaPlanteadaFinal);

  std::string getFechaRealInicio();

  void setFechaRealInicio(std::string nuevaFechaRealFinal);

  std::string getFechaRealFinalizacion();

  void setFechaRealFinalizacion(std::string nuevaFechaRealFinalizacion);

  std::string getDescripcion();

  void setDescripcion(std::string nuevaDescripcion);
  void calcularFechas() override;

 private:
  // static unsigned int idg;

  // unsigned int id;
};

// Definici�n de variables static:
// unsigned int ActividadSimple::idg = 0;

// Definici�n de m�todos:
ActividadSimple::ActividadSimple(string nombre) {
  // this->id = ActividadSimple::idg++;
  this->nombre = nombre;
}

ActividadSimple::~ActividadSimple() {}

// unsigned int ActividadSimple::gId() { return id; }

void ActividadSimple::out_push_back(ActividadSimple& other) {
  out.push_back(other);
}

void ActividadSimple::quienEsMiPapaYmiHijo() {
  std::cout << "Mi papa es " << this->parent->nombre << " Mis hijos son:\n";
  for (ActividadSimple& hijo : this->out) {
    std::cout << hijo.nombre << ", \n";
  }
  std::cout << std::endl;
}

void ActividadSimple::calcularFechas() {}

std::string ActividadSimple::getResponsable() { return this->responsable; }

void ActividadSimple::setResponsable(std::string nuevoResponsable) {
  this->responsable = nuevoResponsable;
}
std::string ActividadSimple::getFechaPlanteadaInicio() {
  return this->fechaPlanteadaInicio;
}
void ActividadSimple::setFechaPlanteadaInicio(
    std::string NuevafechaPlanteadaInicio) {
  this->fechaPlanteadaInicio = NuevafechaPlanteadaInicio;
}
std::string ActividadSimple::getFechaPlanteadaFinal() {
  return this->fechaPlanteadaFinal;
}
void ActividadSimple::setFechaPlanteadaFinal(
    std::string nuevaFechaPlanteadaFinal) {
  this->fechaPlanteadaFinal = nuevaFechaPlanteadaFinal;
}
std::string ActividadSimple::getFechaRealInicio() {
  return this->fechaRealInicio;
}
void ActividadSimple::setFechaRealInicio(std::string nuevaFechaRealFinal) {
  this->fechaRealFinalizacion = nuevaFechaRealFinal;
}
std::string ActividadSimple::getFechaRealFinalizacion() {
  return this->fechaRealFinalizacion;
}
void ActividadSimple::setFechaRealFinalizacion(
    std::string nuevaFechaRealFinalizacion) {
  this->fechaRealFinalizacion = nuevaFechaRealFinalizacion;
}
std::string ActividadSimple::getDescripcion() { return this->descripcion; }
void ActividadSimple::setDescripcion(std::string nuevaDescripcion) {
  this->descripcion = nuevaDescripcion;
}