#include "ActividadCompuesta.hpp"

ActividadCompuesta::ActividadCompuesta(std::string responsable, Tipo* tipo,
                                       std::string fechaPlanteadaInicio,
                                       std::string fechaPlanteadaFinal,
                                       std::string fechaRealInicio,
                                       std::string fechaRealFinalizacion,
                                       std::string descripcion) {
  if (tipo->getHijo()) {
    this->responsable = responsable;
    this->tipo = tipo;
    this->fechaPlanteadaInicio = fechaPlanteadaInicio;
    this->fechaPlanteadaFinal = fechaPlanteadaFinal;
    this->fechaRealInicio = fechaRealInicio;
    this->fechaRealFinalizacion = fechaRealFinalizacion;
    this->descripcion = descripcion;
    this->padre = nullptr;
  } else {
    std::cout << "Una actividad compuesta no puede contener el tipo más bajo "
                 "de la jerarquía (que no tenga hijo)"
              << std::endl;
  }
}

ActividadCompuesta::~ActividadCompuesta() {
  this->padre = nullptr;
  this->hijos.empty();
}

std::vector<Actividad*> ActividadCompuesta::getHijos() { return this->hijos; }
