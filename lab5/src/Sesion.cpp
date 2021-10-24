//
// Created by carlo on 10/22/2021.
//

#include "Sesion.hpp"

#include <iostream>
#include <sstream>

std::string Sesion::enviarBroadcast(Mediador& mediador,
                                    const std::string& mensaje) {
  return mediador.difundirMensaje(this, mensaje);
}

std::string Sesion::enviarP2P(Mediador& mediador, const std::string& mensaje,
                              Colega& receptor) {
  Sesion* receptorPointer = dynamic_cast<Sesion*>(&receptor);
  return mediador.difundirMensaje(this, mensaje, receptorPointer);
}

std::string Sesion::recibirMensaje(Colega* sender, const std::string& mensaje) {
  std::stringstream sstream;
  sstream << getNombre() << " recibio un mensaje de " << sender->getNombre()
          << ": " << mensaje << std::endl;
  return sstream.str();
}
