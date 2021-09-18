#ifndef ACTIVIDADCOMPUESTA_HPP
#define ACTIVIDADCOMPUESTA_HPP

#pragma once

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Actividad.hpp"
#include "Tipo.hpp"

template <typename hijo>
class ActividadCompuesta : public Actividad<ActividadCompuesta, hijo> {
 private:
 public:
  ActividadCompuesta(std::string responsable, Tipo* tipo,
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
      std::cout << "Una actividad compuesta no puede "
                   "contener el tipo más bajo "
                   "de la jerarquía (que no tenga hijo)"
                << std::endl;
    }
  }
  ~ActividadCompuesta() {
    this->padre = nullptr;
    this->hijos.empty();
  }
};
#endif