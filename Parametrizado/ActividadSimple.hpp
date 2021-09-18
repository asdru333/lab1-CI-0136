#ifndef ACTIVIDADSIMPLE_HPP
#define ACTIVIDADSIMPLE_HPP
#pragma once

#include "Actividad.hpp"

class ActividadSimple : Actividad<ActividadSimple> {
 private:
 public:
  ActividadSimple(std::string responsable, Tipo* tipo,
                  std::string fechaPlanteadaInicio,
                  std::string fechaPlanteadaFinal, std::string fechaRealInicio,
                  std::string fechaRealFinalizacion, std::string descripcion);
  ~ActividadSimple();
};
#endif