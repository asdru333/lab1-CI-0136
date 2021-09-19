#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#pragma once

#include <string>
class ActividadSimple;

template <typename Self>
class Actividad {
 protected:
 public:
  Actividad();
  ~Actividad();
  std::string nombre;

  template <typename T>
  void add(T& other) {
    for (ActividadSimple& yo : *static_cast<Self*>(this)) {
      for (ActividadSimple& hijo : other) {
        //  yo.insertHijos(other);
        // hijo.setPadre(&yo);
      }
    }
  }
};

template <typename Self>
Actividad<Self>::Actividad() {}

template <typename Self>
Actividad<Self>::~Actividad() {}

#endif