#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "Actividad.hpp"
#include "ActividadCompuesta.hpp"
#include "ActividadSimple.hpp"
#include "Interfaz.hpp"
#include "Tipo.hpp"

int main() {
  bool terminar = 0;
  while (!terminar) {
    int opcion = 0;
    std::cout << "Con cual tipo de proyecto quiere trabajar" << std::endl;
    std::cout << "1. Proyecto simple" << std::endl;
    std::cout << "2. Proyecto compuesto" << std::endl;
    std::cout << "3. salir" << std::endl;
    std::cin >> opcion;
    if (opcion == 1 or opcion == 2) {
      std::vector<Tipo*> vectorTipos;
      if (opcion == 1) {
        Tipo* proyecto = new Tipo("proyectoSimple", "ACTIVIDADCOMPUESTA");
        Tipo* tarea = new Tipo("tarea", "ACTIVIDADSIMPLE");
        proyecto->setHijo(tarea);
        tarea->setPadre(proyecto);
        vectorTipos.push_back(proyecto);
        vectorTipos.push_back(tarea);
      } else {
        Tipo* proyecto = new Tipo("proyectoCompuesto", "ACTIVIDADCOMPUESTA");
        Tipo* tarea = new Tipo("tarea", "ACTIVIDADSIMPLE");
        Tipo* fase = new Tipo("fase", "ACTIVIDADCOMPUESTA", proyecto, tarea);
        tarea->setPadre(fase);
        proyecto->setHijo(fase);
        vectorTipos.push_back(proyecto);
        vectorTipos.push_back(fase);
        vectorTipos.push_back(tarea);
      }
      Interfaz* interfaz = new Interfaz(vectorTipos.size(), vectorTipos);
      interfaz->menuPrincipal();
    }

    else if (opcion == 3) {
      terminar = 1;
    }

    else {
      std::cout << "Opcion incorrecta. Por favor escriba un numero valido"
                << std::endl;
    }
  }
  return 0;
}
