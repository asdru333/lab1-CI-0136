#ifndef OPERANDOENTERO_H
#define OPERANDOENTERO_H
#pragma once

#include "Operando.hpp"

class OperandoEntero : public Operando {
 private:
  int valor;

 public:
  OperandoEntero(int valorInicial);
  ~OperandoEntero();
  int getValor();
  OperandoEntero& operator+(Operando& oper) override;
  OperandoEntero& operator-(Operando& oper) override;
  OperandoEntero& operator/(Operando& oper) override;
  OperandoEntero& operator*(Operando& oper) override;
};
#endif