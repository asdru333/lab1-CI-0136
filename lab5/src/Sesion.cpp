//
// Created by carlo on 10/22/2021.
//

#include <iostream>
#include "Sesion.hpp"

void Sesion::enviarBroadcast ( Mediador& mediator, const  std::string& message)  {
    mediator.distributeMessage (this, message);
}

void Sesion::enviarP2P( Mediador &mediator, const  std::string &message,  Colega &receptor)  {
    Sesion *receptorPointer = dynamic_cast<Sesion*>(&receptor) ;
    mediator.distributeMessage (this, message, receptorPointer);
}


void Sesion::receiveMessage ( Colega* sender,  const std::string& message)  {
    std::cout << getName() << " received the message from " << sender->getName() << ": " << message << std::endl;
}

