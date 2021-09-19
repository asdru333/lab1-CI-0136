#ifndef ACTIVIDADCOMPUESTA_H
#define ACTIVIDADCOMPUESTA_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Actividad.hpp"
#include "ActividadSimple.hpp"
class ActividadCompuesta : std::vector<ActividadSimple>,
                           public Actividad<ActividadCompuesta> {
 private:
 public:
  ActividadCompuesta(std::string nombre) {
    this->emplace_back(ActividadSimple(nombre));
  }
  ~ActividadCompuesta();

  void quienEsMiPapaYmiHijo() {
    ActividadSimple* act = this->begin()._Ptr;

    std::cout << "Mi papa es " << act->getNombre() << " Mis hijos son:\n";
    for (ActividadSimple& hijo : act->getHijos()) {
      std::cout << hijo.getNombre() << ", \n";
    }
    std::cout << std::endl;
  }
};
#endif