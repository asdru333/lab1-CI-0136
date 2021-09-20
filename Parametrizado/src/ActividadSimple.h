#pragma once
#include <vector>
using namespace std;

#include "Actividad.h"

class ActividadSimple : public Actvidad<ActividadSimple> {
 public:
  ActividadSimple(string nombre);
  ~ActividadSimple();

  // unsigned int gId();
  void out_push_back(ActividadSimple& other);
  void in_push_back(ActividadSimple& other);
  ActividadSimple* begin() { return this; };
  ActividadSimple* end() { return this + 1; };
  ActividadSimple* parent;
  void quienEsMiPapaYmiHijo();
  vector<ActividadSimple> out;

 private:
  // static unsigned int idg;

  // unsigned int id;
};

// Definici�n de variables static:
// unsigned int ActividadSimple::idg = 0;

// Definici�n de m�todos:
ActividadSimple::ActividadSimple(string nombre) {
  // this->id = ActividadSimple::idg++;
  this->nombre = nombre;
}

ActividadSimple::~ActividadSimple() {}

// unsigned int ActividadSimple::gId() { return id; }

void ActividadSimple::out_push_back(ActividadSimple& other) {
  out.push_back(other);
}

void ActividadSimple::quienEsMiPapaYmiHijo() {
  std::cout << "Mi papa es " << this->parent->nombre << " Mis hijos son:\n";
  for (ActividadSimple& hijo : this->out) {
    std::cout << hijo.nombre << ", \n";
  }
  std::cout << std::endl;
}