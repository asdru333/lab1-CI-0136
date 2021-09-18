#ifndef ACTIVIDAD_HPP
#define ACTIVIDAD_HPP

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Tipo.hpp"
// class ActividadCompuesta;
template <typename Self, typename Hijo>

class Actividad {
 protected:
  ActividadCompuesta* padre;
  std::vector<Actividad<Hijo>*> hijos;

  Tipo* tipo;
  std::string responsable;
  std::string fechaPlanteadaInicio;
  std::string fechaPlanteadaFinal;
  std::string fechaRealInicio;
  std::string fechaRealFinalizacion;
  std::string descripcion;

 private:
  std::string calcularFecha(std::string fechaActual, std::string fechaCandidata,
                            int signo) {
    std::string fecha1, fecha2;
    int index = fechaActual.size() - 1;
    while (index >= 0) {
      if (fechaActual[index] != '/') {
        fecha1.insert(0, fechaActual.substr(index, 1));
        fecha2.insert(0, fechaCandidata.substr(index, 1));
      } else {
        int resultado = (stoi(fecha1) - stoi(fecha2)) * signo;
        if (resultado != 0) {
          if (resultado > 0)
            return fechaCandidata;
          else
            return fechaActual;
        } else {
          fecha1.clear();
          fecha2.clear();
        }
      }
      --index;
    }
    return fechaActual;
  }

 public:
  Actividad* getPadre() { return this->padre; }

  template <typename T>
  void setPadre(T* nuevoPadre) {
    if (nuevoPadre && (this->tipo->getPadre()->getNombre() ==
                       nuevoPadre->getTipo()->getNombre()))
      this->padre = nuevoPadre;
    else
      std::cout << "Padre inválido" << std::endl;
  }

  void calcularFechas() {
    if (this->hijos.size() > 0) {
      std::string fechaCandidataInicio =
          this->hijos[0]->getFechaPlanteadaInicio();
      std::string fechaCandidataFinal =
          this->hijos[0]->getFechaPlanteadaFinal();
      for (int index = 1; index < hijos.size(); ++index) {
        fechaCandidataInicio = this->calcularFecha(
            fechaCandidataInicio, this->hijos[index]->getFechaPlanteadaInicio(),
            1);
        fechaCandidataFinal = this->calcularFecha(
            fechaCandidataFinal, this->hijos[index]->getFechaPlanteadaFinal(),
            -1);
      }
      this->fechaPlanteadaInicio = fechaCandidataInicio;
      this->fechaPlanteadaFinal = fechaCandidataFinal;
    }
  }

  void add(Hijo* nuevoHijo) {
    if (!nuevoHijo)
      std::cout << "No se permiten agregar hijos nulos" << std::endl;
    else {
      Tipo* elPadre = nuevoHijo->getTipo()->getPadre();
      Tipo* elHijo = this->tipo->getHijo();
      if (elHijo and elPadre and
          elPadre->getNombre() == this->tipo->getNombre() and
          nuevoHijo->getTipo()->getNombre() == elHijo->getNombre()) {
        nuevoHijo->setPadre(this);
        this->hijos.push_back(nuevoHijo);
      } else
        std::cout << "No se puede agregar el hijo por problemas de jerarquía"
                  << std::endl;
    }
  }

  void remove(Hijo* nuevoHijo) {
    std::vector<Actividad*>::iterator iterator = this->hijos.begin();
    while (*iterator != noHijo and iterator != this->hijos.end()) {
      ++iterator;
    }
    if (iterator != this->hijos.end()) {
      noHijo->setPadre(nullptr);
      this->hijos.erase(iterator);
    }
  }

  std::vector<Actividad<hijo>*> getHijos() { return this->hijos; }

  // Setters and guetters
  Tipo* getTipo() { return this->tipo; }

  void setTipo(Tipo* nuevoTipo) { this->tipo = nuevoTipo; }

  std::string getResponsable() { return this->responsable; }
  void setResponsable(std::string nuevoResponsable) {
    this->responsable = nuevoResponsable;
  }

  std::string getFechaPlanteadaInicio() { return this->fechaPlanteadaInicio; }
  void setFechaPlanteadaInicio(std::string NuevafechaPlanteadaInicio) {
    this->fechaPlanteadaInicio = NuevafechaPlanteadaInicio;
  }

  std::string getFechaPlanteadaFinal() { return this->fechaPlanteadaFinal; }
  void setFechaPlanteadaFinal(std::string nuevaFechaPlanteadaFinal) {
    this->fechaPlanteadaFinal = nuevaFechaPlanteadaFinal;
  }

  std::string getFechaRealInicio() { return this->fechaRealInicio; }
  void setFechaRealInicio(std::string nuevaFechaRealFinal) {
    this->fechaRealInicio = nuevaFechaRealFinal;
  }

  std::string getFechaRealFinalizacion() { return this->fechaRealFinalizacion; }
  void setFechaRealFinalizacion(std::string nuevaFechaRealFinalizacion) {
    this->fechaRealFinalizacion = nuevaFechaRealFinalizacion;
  }

  std::string getDescripcion() { return this->descripcion; }
  void setDescripcion(std::string nuevaDescripcion) {
    this->descripcion = nuevaDescripcion;
  }
};

#endif