#include "ActividadSimple.hpp"

ActividadSimple::ActividadSimple(std::string responsable, Tipo* tipo,
                                 std::string fechaPlanteadaInicio,
                                 std::string fechaPlanteadaFinal,
                                 std::string fechaRealInicio,
                                 std::string fechaRealFinalizacion,
                                 std::string descripcion) {
  if (!tipo->getHijo()) {
    this->responsable = responsable;
    this->tipo = tipo;
    this->fechaPlanteadaInicio = fechaPlanteadaInicio;
    this->fechaPlanteadaFinal = fechaPlanteadaFinal;
    this->fechaRealInicio = fechaRealInicio;
    this->fechaRealFinalizacion = fechaRealFinalizacion;
    this->descripcion = descripcion;
    this->padre = nullptr;
  } else {
    std::cout << "La actividad simple debe ser la más baja de la jerarquía "
                 "de tipos (el tipo asignado no puede tener hijo)"
              << std::endl;
  }
}

ActividadSimple::~ActividadSimple() { this->padre = nullptr }