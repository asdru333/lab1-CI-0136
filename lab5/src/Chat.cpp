//
// Created by carlo on 10/22/2021.
//

#include "Chat.hpp"

#include <iostream>

void Chat::difundirMensaje(Colega *sender, const std::string &message) {
  for (Colega *x : getMiembros())
    if (x != sender)  // Do not send the message back to the sender
      x->recibirMensaje(sender, message);
}

void Chat::difundirMensaje(Colega *emisor, const std::string &message,
                           Colega *receptor) {
  bool encontrado = false;

  for (auto index : this->getMiembros()) {
    if (index == receptor) {
      encontrado = true;
      break;
    }
  }

  if (encontrado) {
    receptor->recibirMensaje(emisor, message);
  } else {
    std::cout << "Receptor no encontrado" << std::endl;
  }
}
