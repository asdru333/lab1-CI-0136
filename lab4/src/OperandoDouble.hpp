#ifndef OPERANDODOUBLE_H
#define OPERANDODOUBLE_H
#pragma once

#include <string>

#include "Operando.hpp"

class OperandoDouble : public Operando {
 private:
  double valor;

 public:
  OperandoDouble(double);
  OperandoDouble(std::string);
  ~OperandoDouble();
  double getValor();
  std::string toString();
  OperandoDouble& operator+(Operando& oper) override;
  OperandoDouble& operator-(Operando& oper) override;
  OperandoDouble& operator/(Operando& oper) override;
  OperandoDouble& operator*(Operando& oper) override;
};
#endif