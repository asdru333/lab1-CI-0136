//
// Created by carlo on 10/22/2021.
//

#ifndef LAB5_MEDIADOR_SESION_HPP
#define LAB5_MEDIADOR_SESION_HPP

#include "Colega.hpp"
#include "Mediador.hpp"

class Sesion : public Colega {
 public:
  using Colega::Colega;
  std::string enviarBroadcast(Mediador &mediator,
                              const std::string &message) override;
  std::string enviarP2P(Mediador &mediator, const std::string &message,
                        Colega &receptor) override;
  std::string recibirMensaje(Colega *, const std::string &) override;
};

#endif  // LAB5_MEDIADOR_SESION_HPP
