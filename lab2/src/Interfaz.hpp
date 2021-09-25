#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Actividad.hpp"
#include "ActividadCompuesta.hpp"
#include "ActividadSimple.hpp"
#include "ConstructorJSON.hpp"
#include "ConstructorXML.hpp"
#include "Tipo.hpp"

class Interfaz {
 private:
  std::vector<Tipo*> vectorTipos;
  std::vector<std::vector<Actividad*>> vectorActividades;
  ConstructorXML XML;
  ConstructorJSON JSON;

 public:
  Interfaz(int cantidad, std::vector<Tipo*> vectorTipos) {
    this->vectorTipos = vectorTipos;
    this->vectorActividades.resize(cantidad);
  }

  void director() {
    int opcion = 0;
    std::cout << "Elija el formato en el que desea serializar: " << std::endl;
    std::cout << "1.JSON\n2.XML" << std::endl;
    std::cin >> opcion;
    if (opcion == 1) {
      // for (size_t index = 0; index < this->vectorActividades.size(); index++)
      // {
      this->JSON.serializadorActividad(this->vectorActividades[0][0]);
      //}
    } else if (opcion == 2) {
      // for (size_t index = 0; index < this->vectorActividades.size(); index++)
      // {
      this->XML.serializadorActividad(this->vectorActividades[0][0]);
      //}
    } else {
      std::cout << "Opcion incorrecta\n";
    }
  }

  void menuPrincipal() {
    bool terminar = 0;
    int opcion = 0;
    while (!terminar) {
      std::cout << "Por favor seleccione algunas de las siguientes opciones:"
                << std::endl;
      std::cout << "1. Crear instancias de tipos" << std::endl;
      // std::cout << "2. Ver actividad padre" << std::endl;
      std::cout << "2. Ver jerarquia de tipos" << std::endl;
      std::cout << "3. Ver instancias" << std::endl;
      std::cout << "4. serializar" << std::endl;
      std::cout << "5. salir" << std::endl;
      std::cin >> opcion;
      switch (opcion) {
        case 1:
          crearInstancias();
          break;
        case 2:
          verJerarquia();
          break;
        case 3:
          verInstancias();
          break;
        case 4:
          director();
          break;
        case 5:
          terminar = 1;
          break;
        default:
          std::cout << "Opcion incorrecta. Por favor escriba un numero valido"
                    << std::endl;
          break;
      }
    }
  }

  void crearInstancias() {
    Actividad* proyecto;
    int tamano = this->vectorTipos.size();
    if (tamano == 0)
      std::cout << "Error con la jerarquía de tipos (no existe)" << std::endl;
    else if (tamano == 1) {
      proyecto = CrearActividadSimple(0);
      this->vectorActividades[0].push_back(proyecto);
    } else {
      proyecto = CrearActividadCompuesta(0);
      this->vectorActividades[0].push_back(proyecto);
      int numHijos = 0;
      Actividad* hijo;
      for (int contador = 0; contador < tamano - 1; ++contador) {
        for (int index = 0; index < this->vectorActividades[contador].size();
             ++index) {
          std::cout << "Ingrese la cantidad de hijos que quiere para "
                    << this->vectorTipos[contador]->getNombre() << index + 1
                    << std::endl;
          std::cin >> numHijos;
          for (int contador2 = 0; contador2 < numHijos; ++contador2) {
            this->crearHijos(this->vectorActividades[contador][index],
                             contador + 1);
          }
        }
      }
    }
  }

  void verJerarquia() {
    for (int index = 0; index < this->vectorTipos.size(); ++index) {
      std::cout << this->vectorTipos[index]->getNombre();
      if (index + 1 != this->vectorTipos.size())
        std::cout << " > ";
      else
        std::cout << '\n';
    }
  }

  void verInstancias() {
    ActividadCompuesta* actividad = nullptr;
    if (this->vectorActividades.empty())
      std::cout << "No existen las instancias" << std::endl;
    else {
      for (int row = 0; row < vectorActividades.size(); ++row) {
        for (int col = 0; col < vectorActividades[row].size(); ++col) {
          std::cout << "Se tiene "
                    << vectorActividades[row][col]->getTipo()->getNombre()
                    << col << std::endl;
        }
      }
    }
  }

 private:
  Actividad* CrearActividadCompuesta(int index) {
    return new ActividadCompuesta("Javier", vectorTipos[index], "20/02/2021",
                                  "26/07/2021", "02/03/2021", "30/10/2021", "");
  }

  Actividad* CrearActividadSimple(int index) {
    return new ActividadSimple("Carlos", vectorTipos[index], "21/07/2021",
                               "26/07/2021", "21/07/2021", "26/07/2021", "");
  }

  void crearHijos(Actividad* padre, int index) {
    Actividad* hijo;
    if (index + 1 < this->vectorTipos.size())
      hijo = CrearActividadCompuesta(index);
    else
      hijo = CrearActividadSimple(index);
    padre->add(hijo);
    this->vectorActividades[index].push_back(hijo);
  }
};
