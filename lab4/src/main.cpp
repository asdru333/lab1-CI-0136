#include <iostream>

#include "OperandoEntero.hpp"

int main() {
  OperandoEntero op1(1024);
  OperandoEntero op2(256);
  OperandoEntero res = op1 + op2;
  std::cout << "Suma: ";
  std::cout << res.getValor() << std::endl;
  res = op1 - op2;
  std::cout << "Resta: ";
  std::cout << res.getValor() << std::endl;
  res = op1 * op2;
  std::cout << "Multiplicacion: ";
  std::cout << res.getValor() << std::endl;
  res = op1 / op2;
  std::cout << "Division: ";
  std::cout << res.getValor() << std::endl;
  return 0;
}