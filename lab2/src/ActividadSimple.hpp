#pragma once
#include <string>

#include "Actividad.hpp"
#include "Tipo.hpp"

class ActividadSimple : public Actividad {
 public:
  ActividadSimple(std::string responsable, Tipo* tipo,
                  std::string fechaPlanteadaInicio,
                  std::string fechaPlanteadaFinal, std::string fechaRealInicio,
                  std::string fechaRealFinalizacion, std::string descripcion) {
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

  ~ActividadSimple() { this->padre = nullptr; }

  void calcularFechas() override { ; }
  void add(Actividad*) override { ; }
  void remove(Actividad*) override { ; }
  std::vector<Actividad*> getHijos() override {
    std::vector<Actividad*> vectorVacio;
    vectorVacio.clear();
    return vectorVacio;
  }
};
