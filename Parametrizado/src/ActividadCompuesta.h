#pragma once
#include <vector>
using namespace std;

#include "Actividad.h"
#include "ActividadSimple.h"

class ActividadCompuesta : public vector<ActividadSimple>,
                           public Actvidad<ActividadCompuesta> {
 public:
  // Construye una ActividadCompuesta con "count" neuronas.
  ActividadCompuesta(string nombre);
  ~ActividadCompuesta();
  void quienEsMiPapaYmiHijo();
  void calcularFechas() override;
  std::string calcularFecha(std::string fechaActual, std::string fechaCandidata,
                            int signo);

  std::string getResponsable() override { return this->begin()->responsable; }
  void setResponsable(std::string nuevoResponsable) override {
    this->begin()->responsable = nuevoResponsable;
  }
  std::string getFechaPlanteadaInicio() override {
    return this->begin()->fechaPlanteadaInicio;
  }
  void setFechaPlanteadaInicio(std::string NuevafechaPlanteadaInicio) override {
    this->begin()->fechaPlanteadaInicio = NuevafechaPlanteadaInicio;
  }
  std::string getFechaPlanteadaFinal() override {
    return this->begin()->fechaPlanteadaFinal;
  }
  void setFechaPlanteadaFinal(std::string nuevaFechaPlanteadaFinal) override {
    this->begin()->fechaPlanteadaFinal = nuevaFechaPlanteadaFinal;
  }
  std::string getFechaRealInicio() override {
    return this->begin()->fechaRealInicio;
  }
  void setFechaRealInicio(std::string nuevaFechaRealFinal) override {
    this->begin()->fechaRealFinalizacion = nuevaFechaRealFinal;
  }
  std::string getFechaRealFinalizacion() override {
    return this->begin()->fechaRealFinalizacion;
  }
  void setFechaRealFinalizacion(
      std::string nuevaFechaRealFinalizacion) override {
    this->begin()->fechaRealFinalizacion = nuevaFechaRealFinalizacion;
  }
  std::string getDescripcion() override { return this->begin()->descripcion; }
  void setDescripcion(std::string nuevaDescripcion) override {
    this->begin()->descripcion = nuevaDescripcion;
  }
};

ActividadCompuesta::ActividadCompuesta(string nombre) {
  emplace_back(ActividadSimple{nombre});
}

ActividadCompuesta::~ActividadCompuesta() {}

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