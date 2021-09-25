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

/**
  // Definiendo los tipos y la jerarquia
  Tipo* proyecto = new Tipo("proyecto", "ACTIVIDADCOMPUESTA");
  Tipo* tarea = new Tipo("tarea", "ACTIVIDADSIMPLE");
  Tipo* fase = new Tipo("fase", "ACTIVIDADCOMPUESTA", proyecto, tarea);
  tarea->setPadre(fase);
  proyecto->setHijo(fase);

  // creando una actividad compuesta (proyecto) y comprobar si funciona
  // mostrandotodos sus atributos
  ActividadCompuesta* proyecto1 =
      new ActividadCompuesta("Asdrubal", proyecto, "01/07/1997", "17/08/2021",
                             "01/07/1999", "17/08/2021", "proyecto global");
  std::cout << proyecto1->getResponsable() << std::endl;
  std::cout << proyecto1->getDescripcion() << std::endl;
  std::cout << proyecto1->getFechaPlanteadaInicio() << std::endl;
  std::cout << proyecto1->getFechaPlanteadaFinal() << std::endl;
  std::cout << proyecto1->getFechaRealInicio() << std::endl;
  std::cout << proyecto1->getFechaRealFinalizacion() << std::endl;
  std::cout << proyecto1->getTipo()->getNombre() << std::endl;
  // Comprando que el padre no exista

  if (!proyecto1->getPadre()) {
    std::cout << "EXITO" << std::endl;
  }

  // Creando una actividad compuesta fase y agregrandola como hija al proyecto
  ActividadCompuesta* fase1 =
      new ActividadCompuesta("", fase, "01/07/1999", "17/08/2021",
"01/07/1999", "17/08/2021", "primera fase"); proyecto1->add(fase1); std::cout
<< proyecto1->getHijos()[0]->getDescripcion() << std::endl; std::cout <<
proyecto1->getHijos()[0]->getPadre()->getDescripcion()
            << std::endl;
  std::cout << fase1->getResponsable() << std::endl;
  // Comprobando la cadena de responsabilidad

  // Creando otra fase y agregandola al proyecto. Aqui se prueba el metodo
  // removey calcular fecha
  ActividadCompuesta* fase2 =

      new ActividadCompuesta("Juan", fase, "01/07/1998", "17/08/2022",
                             "01/07/1998", "17/08/2021", "segunda fase");
  proyecto1->add(fase2);
  proyecto1->calcularFechas();
  std::cout << proyecto1->getFechaPlanteadaInicio() << std::endl;
  std::cout << proyecto1->getFechaPlanteadaFinal() << std::endl;
  proyecto1->remove(fase1);
  if (proyecto1->getHijos().size() == 1 && !fase1->getPadre())
    std::cout << "EXITO2" << std::endl;
  ActividadSimple* tarea1 =
      new ActividadSimple("Jose", tarea, "01/07/1998", "17/08/2022",
                          "01/07/1998", "17/08/2021", "primera tarea");
  std::cout << tarea1->getDescripcion() << std::endl;
  fase2->add(tarea1);
  std::cout << tarea1->getPadre()->getDescripcion() << std::endl;
  std::cout << fase2->getHijos()[0]->getDescripcion() << std::endl;

  // probando las retricciones
  fase2->add(proyecto1);
  ActividadSimple* tarea2 =
      new ActividadSimple("Jose", proyecto, "01/07/1998", "17/08/2022",
                          "01/07/1998", "17/08/2021", "primera tarea");
  ActividadCompuesta* proyecto2 =
      new ActividadCompuesta("Asdrubal", tarea, "01/07/1999", "17/08/2021",
                             "01/07/1999", "17/08/2021", "primera fase");

  // Probando la flexibilidad, para evitar cambios en la jerarquía anterior,
se
  // vana crear dos tipos nuevos
  Tipo* otroProyecto = new Tipo("proyecto", "ACTIVIDADCOMPUESTA");
  Tipo* otraTarea = new Tipo("tarea", "ACTIVIADSIMPLE");
  otroProyecto->setHijo(otraTarea);
  otraTarea->setPadre(otroProyecto);

  ActividadCompuesta* proyecto3 = new ActividadCompuesta(
      "Asdrubal", otroProyecto, "01/07/1997", "17/08/2021", "01/07/1999",
      "17/08/2021", "proyecto global");
  ActividadSimple* tarea3 =
      new ActividadSimple("", otraTarea, "01/07/1998", "17/08/2022",
                          "01/07/1998", "17/08/2021", "primera tarea");
  proyecto3->add(tarea3);
  std::cout << tarea3->getPadre()->getDescripcion() << std::endl;
  std::cout << tarea3->getResponsable() << std::endl;
  proyecto1->remove(fase2);
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // PROBAR CONSTRUCTOR JSON
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  proyecto1->add(fase1);
  proyecto1->add(fase2);
  fase1->add(tarea1);

  ConstructorJSON constructorJSON;
  ConstructorXML xml;
  // NO SE PUEDE CON PROYECTO 2 DA SEGMENTATION FAULT CUANDO EL CONSTRUCTOR
JSON
  // INTENTA ACCEDER A LOS DATOS ESTO ES PORQUE EN EL CONTRUCTOR DE PROYECTO2
  // NUNCA SE LE ASIGNAN LOS ATRIBUTOS.. PORQUE TIENE UN TIPO NO VALIDO POR
  /// AL SER ACTIVIDAD COMPUESTA NO PUEDE TENER TIPO TAREA ENTONCES NI
SIQUIERA
  /// LE ASIGNA LOS ATRIBUTOS
  // constructorJSON.serializadorActividad(proyecto2);

  std::cout << "JSON: " << std::endl;
  constructorJSON.serializadorActividad(proyecto1);
  std::cout << std::endl << std::endl;

  constructorJSON.serializadorActividad(proyecto3);
  std::cout << std::endl << std::endl;

  std::cout << "XML: " << std::endl;
  xml.serializadorActividad(proyecto1);
  std::cout << std::endl << std::endl;

  xml.serializadorActividad(proyecto3);
  std::cout << std::endl << std::endl;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  std::cout << std::endl << "FIN" << std::endl;
}

**/