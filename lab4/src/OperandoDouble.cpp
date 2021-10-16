#include "OperandoDouble.hpp"

OperandoDouble::OperandoDouble(double valorInicial) {
  this->valor = valorInicial;
}

OperandoDouble::OperandoDouble(std::string valorInicial) {
  this->valor = std::stod(valorInicial);
}

OperandoDouble::~OperandoDouble() {}

double OperandoDouble::getValor() { return this->valor; }

std::string OperandoDouble::toString() { return std::to_string(this->valor); }

OperandoDouble& OperandoDouble::operator+(Operando& oper) {
  OperandoDouble* operando = dynamic_cast<OperandoDouble*>(&oper);
  OperandoDouble* resultado = new OperandoDouble(0);
  resultado->valor = this->valor + operando->valor;
  return *resultado;
}
OperandoDouble& OperandoDouble::operator-(Operando& oper) {
  OperandoDouble* operando = dynamic_cast<OperandoDouble*>(&oper);
  OperandoDouble* resultado = new OperandoDouble(0);
  resultado->valor = this->valor - operando->valor;
  return *resultado;
}
OperandoDouble& OperandoDouble::operator/(Operando& oper) {
  OperandoDouble* operando = dynamic_cast<OperandoDouble*>(&oper);
  OperandoDouble* resultado = new OperandoDouble(0);
  resultado->valor = this->valor / operando->valor;
  return *resultado;
}
OperandoDouble& OperandoDouble::operator*(Operando& oper) {
  OperandoDouble* operando = dynamic_cast<OperandoDouble*>(&oper);
  OperandoDouble* resultado = new OperandoDouble(0);
  resultado->valor = this->valor * operando->valor;
  return *resultado;
}