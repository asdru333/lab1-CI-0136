#include "ConstructorJSON.hpp"

#include <sstream>

ConstructorJSON::ConstructorJSON() {}
ConstructorJSON::~ConstructorJSON() {}
void ConstructorJSON::serializadorActividad(Actividad* actividad) {
  std::string actividadSerializada = "{";

  actividadSerializada += this->funcAuxiliar(actividad, "") += '}';

  std::cout << actividadSerializada;
}

std::string ConstructorJSON::funcAuxiliar(Actividad* actividad,
                                          std::string indentacion) {
  std::stringstream hilera;

  hilera << indentacion << "\"Tipo\": " << '"'
         << actividad->getTipo()->getNombre() << '"' << ",\n";
  hilera << indentacion << "\"Descripcion\": \"" << actividad->getDescripcion()
         << "\",\n";
  hilera << indentacion << "\"Fecha planteada de inicio\": \""
         << actividad->getFechaPlanteadaInicio() << "\",\n";
  hilera << indentacion << "\"Fecha planteada de finalizacion\": \""
         << actividad->getFechaPlanteadaFinal() << "\",\n";

  if (actividad->getTipo()->getTipoActividad() == "ACTIVIDADCOMPUESTA") {
    for (size_t hijo = 0; hijo < actividad->getHijos().size(); hijo++) {
      hilera << funcAuxiliar(actividad->getHijos()[hijo], indentacion + "\t");
    }
  }

  return hilera.str();
}
