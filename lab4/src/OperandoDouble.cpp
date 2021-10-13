#include "OperandoDouble.hpp"

OperandoDouble::OperandoDouble(double valorInicial) {
  this->valor = valorInicial;
}

OperandoDouble::~OperandoDouble() {}

double OperandoDouble::getValor() { return this->valor; }

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