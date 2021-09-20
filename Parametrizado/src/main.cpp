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

  ActividadCompuesta proy("proy"), f1("f1");

  proy.setTipo(proyecto);
  f1.setTipo(fase);

  proy.add<ActividadCompuesta>(f1);
  //proy.quienEsMiPapaYmiHijo();

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