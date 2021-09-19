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
  ActividadSimple();
  ActividadSimple(std::string nombre) { this->nombre = nombre; };

  ~ActividadSimple();
  std::string nombre;

  std::string getNombre() { return this->nombre; }
  void setNombre(std::string nombre) { this->nombre = nombre; }

  ActividadSimple* getPadre() { return this->padre; }
  void setPadre(ActividadSimple* padre) { this->padre = padre; }

  void insertHijos(ActividadSimple& hijo) { this->hijos.push_back(hijo); }

  void quienEsMiPapaYmiHijo() {
    std::cout << "Mi papa es " << this->padre->getNombre()
              << " Mis hijos son:\n";
    for (ActividadSimple& hijo : this->hijos) {
      std::cout << hijo.getNombre() << ", \n";
    }
    std::cout << std::endl;
  }

  std::vector<ActividadSimple> getHijos() { return this->hijos; }
};
#endif