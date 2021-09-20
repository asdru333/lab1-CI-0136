#include <iostream>
using namespace std;

#include "ActividadCompuesta.h"
#include "ActividadSimple.h"

int main() {
  Tipo* proyecto = new Tipo("proyecto");
  Tipo* tarea = new Tipo("tarea");
  Tipo* fase = new Tipo("fase", proyecto, tarea);

  tarea->setPadre(fase);
  proyecto->setHijo(fase);

  ActividadSimple t1("t1"), t2("t2");
  t1.setTipo(tarea);
  t2.setTipo(tarea);
  // t1.setFechaPlanteadaFinal("01/12/1999");
  /*t1.setFechaPlanteadaInicio("02/01/1999");

  t2.setFechaPlanteadaInicio("02/01/1999");
  t2.setFechaPlanteadaFinal("01/03/2000");*/

  ActividadCompuesta proy("proy"), f1("f1"), f2("f2");
  proy.setTipo(proyecto);
  f1.setTipo(fase);
  f2.setTipo(fase);
  proy.add<ActividadCompuesta>(f1);
  proy.add<ActividadCompuesta>(f2);
  proy.quienEsMiPapaYmiHijo();
  cout << f1.begin()->parent->nombre;

  cout << "============================================================\n";

  f1.add<ActividadSimple>(t1);
  f1.quienEsMiPapaYmiHijo();
  cout << "============================================================\n";

  f1.add<ActividadSimple>(t2);
  f1.quienEsMiPapaYmiHijo();

  cout << "============================================================\n";

  f1.add<ActividadCompuesta>(proy);
  t2.quienEsMiPapaYmiHijo();
  cin.ignore();
  cout << "end" << endl;
}