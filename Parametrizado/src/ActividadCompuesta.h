#pragma once
#include <vector>
using namespace std;

#include "Actividad.h"
#include "ActividadSimple.h"

class ActividadCompuesta : public vector<ActividadSimple>,
                           public Actvidad<ActividadCompuesta> {
 public:
  // Construye una ActividadCompuesta con "count" neuronas.
  ActividadCompuesta(string nombre);
  ~ActividadCompuesta();
  void quienEsMiPapaYmiHijo();
};

ActividadCompuesta::ActividadCompuesta(string nombre) {
  emplace_back(ActividadSimple{nombre});
}

ActividadCompuesta::~ActividadCompuesta() {}

void ActividadCompuesta::quienEsMiPapaYmiHijo() {
  if (this->begin()->parent == nullptr) {
    cout << "NO tengo papa\n";
  } else {
    std::cout << "Mi papa es " << this->begin()->parent->nombre;
  }
  cout << " Mis hijos son:\n";
  for (ActividadSimple& hijo : this->begin()->out) {
    std::cout << hijo.nombre << ", \n";
  }
  std::cout << std::endl;
}