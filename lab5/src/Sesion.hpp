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
  std::string enviarBroadcast(Mediador &mediador,
                              const std::string &mensaje) override;
  std::string enviarP2P(Mediador &mediador, const std::string &mensaje,
                        Colega &receptor) override;
  std::string recibirMensaje(Colega *, const std::string &) override;
};

#endif  // LAB5_MEDIADOR_SESION_HPP
