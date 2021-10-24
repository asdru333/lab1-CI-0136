//
// Created by carlo on 10/22/2021.
//

#ifndef LAB5_MEDIADOR_CHAT_HPP
#define LAB5_MEDIADOR_CHAT_HPP

#include "Mediador.hpp"

class Chat : public Mediador {
 private:
  std::string nombre;

 public:
  Chat(std::string nombre);
  std::string difundirMensaje(Colega*, const std::string&) override;
  std::string difundirMensaje(Colega*, const std::string&,
                              Colega* receptor) override;
  std::string meterAlChat(Colega*) override;
};

#endif  // LAB5_MEDIADOR_CHAT_HPP
