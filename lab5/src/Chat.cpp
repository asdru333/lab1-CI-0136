//
// Created by carlo on 10/22/2021.
//

#include "Chat.hpp"

#include <iostream>
#include <sstream>

Chat::Chat(std::string elNombre) { this->nombre = elNombre; }

std::string Chat::difundirMensaje(Colega *sender, const std::string &mensaje) {
  std::string bitacora = "";
  for (Colega *x : getMiembros())
    if (x != sender) bitacora += x->recibirMensaje(sender, mensaje);
  return bitacora;
}

std::string Chat::difundirMensaje(Colega *emisor, const std::string &mensaje,
                                  Colega *receptor) {
  bool encontrado = false;
  std::stringstream bitacora;
  for (auto index : this->getMiembros()) {
    if (index == receptor) {
      encontrado = true;
      break;
    }
  }

  if (encontrado) {
    bitacora << receptor->recibirMensaje(emisor, mensaje);
  } else {
    bitacora << "Receptor " << receptor->getNombre()
             << " no se encuentra en este momento" << std::endl;
  }
  return bitacora.str();
}

std::string Chat::meterAlChat(Colega *elColega) {
  this->getMiembros().push_back(elColega);
  std::string bitacora = elColega->getNombre() += " entro al chat ";
  bitacora += this->nombre;
  bitacora += "\n";
  return bitacora;
}

std::string Chat::sacarDelChat(Colega *elColega) {
  for (std::vector<Colega *>::iterator it = this->getMiembros().begin();
       it != this->getMiembros().end(); ++it) {
    if (*it == elColega) {
      this->getMiembros().erase(it);
    }
  }
  std::string bitacora = elColega->getNombre() += " salio del chat ";
  bitacora += this->nombre;
  bitacora += "\n";
  return bitacora;
}