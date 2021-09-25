#include "ConstructorXML.hpp"

#include <sstream>

ConstructorXML::ConstructorXML() {}
ConstructorXML::~ConstructorXML() {}
void ConstructorXML::serializadorActividad(Actividad* actividad) {
  std::string actividadSerializada =
      "<?xml version= \"personalizada\" encoding= \"utf-8\"?>\n";
  actividadSerializada += "\t<Actividades>\n";
  actividadSerializada += this->funcAuxiliar(actividad, "\t\t");
  actividadSerializada += "\n\t</Actividades>";
  std::cout << actividadSerializada;
}

std::string ConstructorXML::funcAuxiliar(Actividad* actividad,
                                         std::string indentacion) {
  std::stringstream hilera;

  hilera << indentacion << "<Tipo= " << '"' << actividad->getTipo()->getNombre()
         << '"' << ">\n";
  hilera << indentacion << "<Descripcion= \"" << actividad->getDescripcion()
         << ">\n";
  hilera << indentacion << "<Fecha planteada de inicio= \""
         << actividad->getFechaPlanteadaInicio() << "\">\n";
  hilera << indentacion << "<Fecha planteada de finalizacion= \""
         << actividad->getFechaPlanteadaFinal() << "\">\n";

  if (actividad->getTipo()->getTipoActividad() == "ACTIVIDADCOMPUESTA") {
    for (size_t hijo = 0; hijo < actividad->getHijos().size(); hijo++) {
      hilera << funcAuxiliar(actividad->getHijos()[hijo], indentacion + "\t");
    }
  }
  return hilera.str();
}