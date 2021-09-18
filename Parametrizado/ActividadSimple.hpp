#ifndef ACTIVIDADSIMPLE_H
#define ACTIVIDADSIMPLE_H
#pragma once

#include <string>

#include "Actividad.hpp"
#include "Tipo.hpp"

class ActividadSimple : public Actividad<ActividadSimple> {
 private:
 public:
  ActividadSimple(std::string responsable, Tipo* tipo,
                  std::string fechaPlanteadaInicio,
                  std::string fechaPlanteadaFinal, std::string fechaRealInicio,
                  std::string fechaRealFinalizacion, std::string descripcion);
  ~ActividadSimple();
};
#endif
