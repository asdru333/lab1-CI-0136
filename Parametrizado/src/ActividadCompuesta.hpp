#ifndef ACTIVIDADCOMPUESTA_H
#define ACTIVIDADCOMPUESTA_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "Actividad.hpp"
#include "ActividadSimple.hpp"

class ActividadCompuesta : public vector<ActividadSimple>,
                           public Actividad<ActividadCompuesta> {
 private:
 public:
  ActividadCompuesta(std::string nombre);
  ~ActividadCompuesta();

  void quienEsMiPapaYmiHijo();
};

void ActividadCompuesta::quienEsMiPapaYmiHijo() {
  std::cout << "Mi papa es " << this->nombre << " Mis hijos son:\n";
  for (ActividadSimple& hijo : this->begin()->getHijos()) {
    std::cout << hijo.nombre << ", \n";
  }
  std::cout << std::endl;
}

ActividadCompuesta::ActividadCompuesta(std::string nombre) {
  this->emplace_back(ActividadSimple(nombre));
}
ActividadCompuesta::~ActividadCompuesta() {}
#endif