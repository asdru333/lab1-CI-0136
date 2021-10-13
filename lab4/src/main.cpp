#include <iostream>

#include "OperandoDouble.hpp"

int main() {
  OperandoDouble op1(1024.5);
  OperandoDouble op2("765.2");
  OperandoDouble res = op1 + op2;
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