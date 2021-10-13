#include "OperandoEntero.hpp"

OperandoEntero::OperandoEntero(int valorInicial) { this->valor = valorInicial; }

OperandoEntero::~OperandoEntero() {}

int OperandoEntero::getValor() { return this->valor; }

OperandoEntero& OperandoEntero::operator+(Operando& oper) {
  OperandoEntero* operando = dynamic_cast<OperandoEntero*>(&oper);
  OperandoEntero* resultado = new OperandoEntero(0);
  resultado->valor = this->valor + operando->valor;
  return *resultado;
}
OperandoEntero& OperandoEntero::operator-(Operando& oper) {
  OperandoEntero* operando = dynamic_cast<OperandoEntero*>(&oper);
  OperandoEntero* resultado = new OperandoEntero(0);
  resultado->valor = this->valor - operando->valor;
  return *resultado;
}
OperandoEntero& OperandoEntero::operator/(Operando& oper) {
  OperandoEntero* operando = dynamic_cast<OperandoEntero*>(&oper);
  OperandoEntero* resultado = new OperandoEntero(0);
  resultado->valor = this->valor / operando->valor;
  return *resultado;
}
OperandoEntero& OperandoEntero::operator*(Operando& oper) {
  OperandoEntero* operando = dynamic_cast<OperandoEntero*>(&oper);
  OperandoEntero* resultado = new OperandoEntero(0);
  resultado->valor = this->valor * operando->valor;
  return *resultado;
}