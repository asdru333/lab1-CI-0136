//
// Created by carlo on 10/22/2021.
//

#ifndef LAB5_MEDIADOR_COLEGA_HPP
#define LAB5_MEDIADOR_COLEGA_HPP

class Mediador;

#include <string>

class Colega {
 private:
  std::string nombre;

 public:
  Colega(const std::string& newNombre) : nombre(newNombre) {}
  std::string getNombre() const { return nombre; }
  virtual std::string enviarBroadcast(Mediador&, const std::string&) = 0;
  virtual std::string enviarP2P(Mediador& mediador, const std::string& mensaje,
                                Colega& receptor) = 0;
  virtual std::string recibirMensaje(Colega*, const std::string&) = 0;
};

#endif  // LAB5_MEDIADOR_COLEGA_HPP
