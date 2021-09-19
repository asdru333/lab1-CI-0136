#include <iostream>

#include "Actividad.hpp"
#include "ActividadCompuesta.hpp"
#include "ActividadSimple.hpp"

int main(void) {
  ActividadSimple simple1("simple1"), simple2("simple2");

  ActividadCompuesta proyecto("proy"), fase1("fase1"), fase2("fase2");

  proyecto.add<ActividadCompuesta>(fase1);
  proyecto.add<ActividadCompuesta>(fase2);

  fase1.add<ActividadSimple>(simple1);
  fase2.add<ActividadSimple>(simple2);

  proyecto.quienEsMiPapaYmiHijo();
  fase1.quienEsMiPapaYmiHijo();
  fase2.quienEsMiPapaYmiHijo();
  fase1.quienEsMiPapaYmiHijo();
  fase2.quienEsMiPapaYmiHijo();

  return 0;
}