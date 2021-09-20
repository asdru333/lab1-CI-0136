#pragma once
#include <vector>
using namespace std;

#include "Actividad.h"
#include "ActividadSimple.h"

// Este uso de la herencia no es muy apropiado porque una ActividadCompuesta NO
// es un ejemplo de vector< Neuron >, es decir, NO es un vector lo que implica
// que se heredan muchos métodos que no tienen sentido para un
// ActividadCompuesta.
class ActividadCompuesta : public Actvidad<ActividadCompuesta> {
 public:
  // Construye una ActividadCompuesta con "count" neuronas.
  ActividadCompuesta(string nombre);
  ActividadSimple* actividadEncapsulada;

  ~ActividadCompuesta();
  ActividadSimple* begin();
  ActividadSimple* end();
  void quienEsMiPapaYmiHijo();
  void calcularFechas() override;
  std::string calcularFecha(std::string fechaActual, std::string fechaCandidata,
                            int signo);

  std::string getResponsable();

  void setResponsable(std::string nuevoResponsable);

  std::string getFechaPlanteadaInicio();

  void setFechaPlanteadaInicio(std::string NuevafechaPlanteadaInicio);

  std::string getFechaPlanteadaFinal();

  void setFechaPlanteadaFinal(std::string nuevaFechaPlanteadaFinal);

  std::string getFechaRealInicio();

  void setFechaRealInicio(std::string nuevaFechaRealFinal);

  std::string getFechaRealFinalizacion();

  void setFechaRealFinalizacion(std::string nuevaFechaRealFinalizacion);

  std::string getDescripcion();

  void setDescripcion(std::string nuevaDescripcion);
};

ActividadCompuesta::ActividadCompuesta(string nombre) {
  this->actividadEncapsulada = new ActividadSimple(nombre);
}

ActividadSimple* ActividadCompuesta::begin() {
  return this->actividadEncapsulada;
}
ActividadSimple* ActividadCompuesta::end() {
  return (this->actividadEncapsulada + 1);
}

ActividadCompuesta::~ActividadCompuesta() {}

void ActividadCompuesta::quienEsMiPapaYmiHijo() {
  if (this->begin()->parent == nullptr) {
    cout << "NO tengo papa\n";
  } else {
    std::cout << "Mi papa es " << this->begin()->parent->nombre;
  }
  cout << " Mis hijos son:\n";
  for (ActividadSimple& hijo : this->begin()->out) {
    std::cout << hijo.nombre << ", \n";
  }
  std::cout << std::endl;
}
void ActividadCompuesta::calcularFechas() {
  if (this->begin()->out.size() > 0) {
    std::string fechaCandidataInicio =
        this->begin()->out[0].getFechaPlanteadaInicio();
    std::string fechaCandidataFinal =
        this->begin()->out[0].getFechaPlanteadaFinal();
    for (int index = 1; index < begin()->out.size(); ++index) {
      fechaCandidataInicio = this->calcularFecha(
          fechaCandidataInicio,
          this->begin()->out[index].getFechaPlanteadaInicio(), 1);
      fechaCandidataFinal = this->calcularFecha(
          fechaCandidataFinal,
          this->begin()->out[index].getFechaPlanteadaFinal(), -1);
    }
    this->begin()->fechaPlanteadaInicio = fechaCandidataInicio;
    this->begin()->fechaPlanteadaFinal = fechaCandidataFinal;
  }
}

std::string ActividadCompuesta::calcularFecha(std::string fechaActual,
                                              std::string fechaCandidata,
                                              int signo) {
  std::string fecha1, fecha2;
  int index = fechaActual.size() - 1;
  while (index >= 0) {
    if (fechaActual[index] != '/') {
      fecha1.insert(0, fechaActual.substr(index, 1));
      fecha2.insert(0, fechaCandidata.substr(index, 1));
    } else {
      int resultado = (stoi(fecha1) - stoi(fecha2)) * signo;
      if (resultado != 0) {
        if (resultado > 0)
          return fechaCandidata;
        else
          return fechaActual;
      } else {
        fecha1.clear();
        fecha2.clear();
      }
    }
    --index;
  }
  return fechaActual;
}

void ActividadCompuesta::setFechaPlanteadaInicio(
    std::string NuevafechaPlanteadaInicio) {
  this->actividadEncapsulada->fechaPlanteadaInicio = NuevafechaPlanteadaInicio;
}

std::string ActividadCompuesta::getResponsable() {
  return this->actividadEncapsulada->responsable;
}

void ActividadCompuesta::setResponsable(std::string nuevoResponsable) {
  this->actividadEncapsulada->responsable = nuevoResponsable;
}
std::string ActividadCompuesta::getFechaPlanteadaInicio() {
  return this->actividadEncapsulada->fechaPlanteadaInicio;
}

std::string ActividadCompuesta::getFechaPlanteadaFinal() {
  return this->actividadEncapsulada->fechaPlanteadaFinal;
}
void ActividadCompuesta::setFechaPlanteadaFinal(
    std::string nuevaFechaPlanteadaFinal) {
  this->actividadEncapsulada->fechaPlanteadaFinal = nuevaFechaPlanteadaFinal;
}
std::string ActividadCompuesta::getFechaRealInicio() {
  return this->actividadEncapsulada->fechaRealInicio;
}
void ActividadCompuesta::setFechaRealInicio(std::string nuevaFechaRealFinal) {
  this->actividadEncapsulada->fechaRealFinalizacion = nuevaFechaRealFinal;
}
std::string ActividadCompuesta::getFechaRealFinalizacion() {
  return this->actividadEncapsulada->fechaRealFinalizacion;
}
void ActividadCompuesta::setFechaRealFinalizacion(
    std::string nuevaFechaRealFinalizacion) {
  this->actividadEncapsulada->fechaRealFinalizacion =
      nuevaFechaRealFinalizacion;
}
std::string ActividadCompuesta::getDescripcion() {
  return this->actividadEncapsulada->descripcion;
}
void ActividadCompuesta::setDescripcion(std::string nuevaDescripcion) {
  this->actividadEncapsulada->descripcion = nuevaDescripcion;
}