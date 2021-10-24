//
// Created by carlo on 10/22/2021.
//

#ifndef LAB5_MEDIADOR_MEDIADOR_HPP
#define LAB5_MEDIADOR_MEDIADOR_HPP

#include <list>
#include <vector>

#include "Colega.hpp"

class Mediador {
 private:
  std::vector<Colega*> miembros;

 public:
  std::vector<Colega*>& getMiembros() { return miembros; }
  virtual std::string difundirMensaje(Colega* emisor, const std::string&) = 0;
  virtual std::string difundirMensaje(Colega* emisor, const std::string&,
                                      Colega* receptor) = 0;

  virtual std::string meterAlChat(Colega* colleague) = 0;
};

#endif  // LAB5_MEDIADOR_MEDIADOR_HPP
