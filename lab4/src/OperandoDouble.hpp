#ifndef OPERANDODOUBLE_H
#define OPERANDODOUBLE_H
#pragma once

#include "Operando.hpp"

class OperandoDouble : public Operando {
 private:
  double valor;

 public:
  OperandoDouble(double valorInicial);
  ~OperandoDouble();
  double getValor();
  OperandoDouble& operator+(Operando& oper) override;
  OperandoDouble& operator-(Operando& oper) override;
  OperandoDouble& operator/(Operando& oper) override;
  OperandoDouble& operator*(Operando& oper) override;
};
#endif