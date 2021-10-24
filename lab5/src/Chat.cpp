//
// Created by carlo on 10/22/2021.
//

#include "Chat.hpp"

#include <iostream>

Chat::Chat(std::string elNombre) { this->nombre = elNombre; }

std::string Chat::difundirMensaje(Colega *sender, const std::string &message) {
  std::string bitacora = "";
  for (Colega *x : getMiembros())
    if (x != sender) bitacora += x->recibirMensaje(sender, message);
  return bitacora;
}

std::string Chat::difundirMensaje(Colega *emisor, const std::string &message,
                                  Colega *receptor) {
  bool encontrado = false;
  std::string bitacora;
  for (auto index : this->getMiembros()) {
    if (index == receptor) {
      encontrado = true;
      break;
    }
  }

  if (encontrado) {
    bitacora = receptor->recibirMensaje(emisor, message);
  } else {
    bitacora = "Receptor no encontrado\n";
  }
  return bitacora;
}

std::string Chat::meterAlChat(Colega *elColega) {
  this->getMiembros().emplace_back(elColega);
  std::string bitacora = elColega->getNombre() += " entro al chat ";
  bitacora += this->nombre;
  bitacora += "\n";
  return bitacora;
}