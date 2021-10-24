//
// Created by carlo on 10/22/2021.
//

#include "Sesion.hpp"

#include <iostream>
#include <sstream>

std::string Sesion::enviarBroadcast(Mediador& mediador,
                                    const std::string& mensaje) {
  std::stringstream sstream;	
  sstream << this->getNombre() << " envio un mensaje broadcast\n" 
    << mediador.difundirMensaje(this, mensaje);
  return sstream.str();
}

std::string Sesion::enviarP2P(Mediador& mediador, const std::string& mensaje,
                              Colega& receptor) {
  Sesion* receptorPointer = dynamic_cast<Sesion*>(&receptor);
  std::stringstream sstream;
  sstream << this->getNombre() << " envio un mensaje p2p a " << 
    receptor.getNombre() << "\n" << 
    mediador.difundirMensaje(this, mensaje, receptorPointer);
  return sstream.str();
}

std::string Sesion::recibirMensaje(Colega* sender, const std::string& mensaje) {
  std::stringstream sstream;
  sstream << getNombre() << " recibio un mensaje de " << sender->getNombre()
          << ": " << mensaje << std::endl;
  return sstream.str();
}
