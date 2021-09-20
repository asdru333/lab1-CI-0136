#pragma once
#include <vector>
using namespace std;

#include "Actividad.h"

class ActividadSimple : public Actvidad<ActividadSimple> {
 public:
  ActividadSimple(string nombre);
  ~ActividadSimple();

  std::string responsable;
  std::string fechaPlanteadaInicio;
  std::string fechaPlanteadaFinal;
  std::string fechaRealInicio;
  std::string fechaRealFinalizacion;
  std::string descripcion;

  // unsigned int gId();
  void out_push_back(ActividadSimple& other);
  void in_push_back(ActividadSimple& other);
  ActividadSimple* begin() { return this; };
  ActividadSimple* end() { return this + 1; };
  ActividadSimple* parent;
  void quienEsMiPapaYmiHijo();
  vector<ActividadSimple> out;
  void calcularFechas() override;

  std::string getResponsable() override { return this->responsable; }
  void setResponsable(std::string nuevoResponsable) override {
    this->responsable = nuevoResponsable;
  }
  std::string getFechaPlanteadaInicio() override {
    return this->fechaPlanteadaInicio;
  }
  void setFechaPlanteadaInicio(std::string NuevafechaPlanteadaInicio) override {
    this->fechaPlanteadaInicio = NuevafechaPlanteadaInicio;
  }
  std::string getFechaPlanteadaFinal() override {
    return this->fechaPlanteadaFinal;
  }
  void setFechaPlanteadaFinal(std::string nuevaFechaPlanteadaFinal) override {
    this->fechaPlanteadaFinal = nuevaFechaPlanteadaFinal;
  }
  std::string getFechaRealInicio() override { return this->fechaRealInicio; }
  void setFechaRealInicio(std::string nuevaFechaRealFinal) override {
    this->fechaRealFinalizacion = nuevaFechaRealFinal;
  }
  std::string getFechaRealFinalizacion() override {
    return this->fechaRealFinalizacion;
  }
  void setFechaRealFinalizacion(
      std::string nuevaFechaRealFinalizacion) override {
    this->fechaRealFinalizacion = nuevaFechaRealFinalizacion;
  }
  std::string getDescripcion() override { return this->descripcion; }
  void setDescripcion(std::string nuevaDescripcion) override {
    this->descripcion = nuevaDescripcion;
  }

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

void ActividadSimple::calcularFechas() {}

void ActividadSimple::quienEsMiPapaYmiHijo() {
  std::cout << "Mi papa es " << this->parent->nombre << " Mis hijos son:\n";
  for (ActividadSimple& hijo : this->out) {
    std::cout << hijo.nombre << ", \n";
  }
  std::cout << std::endl;
}