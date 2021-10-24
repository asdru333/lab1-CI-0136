//
// Created by carlo on 10/22/2021.
//

#include "Sesion.hpp"

#include <iostream>
#include <sstream>

std::string Sesion::enviarBroadcast(Mediador& mediator,
                                    const std::string& message) {
  return mediator.difundirMensaje(this, message);
}

std::string Sesion::enviarP2P(Mediador& mediator, const std::string& message,
                              Colega& receptor) {
  Sesion* receptorPointer = dynamic_cast<Sesion*>(&receptor);
  return mediator.difundirMensaje(this, message, receptorPointer);
}

std::string Sesion::recibirMensaje(Colega* sender, const std::string& message) {
  std::stringstream sstream;
  sstream << getNombre() << " recibio un mensaje de " << sender->getNombre()
          << ": " << message << std::endl;
  return sstream.str();
}
