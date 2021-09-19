#ifndef ACTIVIDADSIMPLE_H
#define ACTIVIDADSIMPLE_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Actividad.hpp"
class ActividadSimple : public Actividad<ActividadSimple> {
 private:
  std::vector<ActividadSimple> hijos;

  ActividadSimple* padre;

 public:
  ActividadSimple(std::string nombre);

  ~ActividadSimple();

  ActividadSimple* getPadre() { return this->padre; }
  void setPadre(ActividadSimple* padre) { this->padre = padre; }

  void insertHijos(ActividadSimple& hijo) { this->hijos.push_back(hijo); }

  void quienEsMiPapaYmiHijo();

  std::vector<ActividadSimple> getHijos() { return this->hijos; }
};

void ActividadSimple::quienEsMiPapaYmiHijo() {
  std::cout << "Mi papa es " << this->padre->nombre << " Mis hijos son:\n";
  for (ActividadSimple& hijo : this->hijos) {
    std::cout << hijo.nombre << ", \n";
  }
  std::cout << std::endl;
}

ActividadSimple::ActividadSimple(std::string nombre) { this->nombre = nombre; }

ActividadSimple::~ActividadSimple() {}
#endif