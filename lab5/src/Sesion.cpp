//
// Created by carlo on 10/22/2021.
//

#include "Sesion.hpp"

#include <iostream>

void Sesion::enviarBroadcast(Mediador& mediator, const std::string& message) {
  mediator.difundirMensaje(this, message);
}

void Sesion::enviarP2P(Mediador& mediator, const std::string& message,
                       Colega& receptor) {
  Sesion* receptorPointer = dynamic_cast<Sesion*>(&receptor);
  mediator.difundirMensaje(this, message, receptorPointer);
}

void Sesion::recibirMensaje(Colega* sender, const std::string& message) {
  std::cout << getNombre() << " received the message from "
            << sender->getNombre() << ": " << message << std::endl;
}
