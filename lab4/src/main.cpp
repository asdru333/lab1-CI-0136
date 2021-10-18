#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "Operando.hpp"
#include "OperandoDouble.hpp"
#include "OperandoFraction.hpp"
#include "OperandoMatrix.hpp"

enum tipos { Double, Fraction, Matriz };  // aqui se pueden agregar nuevos tipos

bool verificarSigno(std::string str) {
  if (str.compare("+") == 0 || str.compare("-") == 0 || str.compare("*") == 0 ||
      str.compare("/") == 0) {
    return 1;
  }
  return 0;
}

void operar(std::stack<std::string>& operandos, int tipo, std::string signo) {
  std::string op2 = operandos.top();
  operandos.pop();
  std::string op1 = operandos.top();
  operandos.pop();
  std::string resultado;
  switch (tipo) {
    case Double: {
      OperandoDouble operando1(op1);
      OperandoDouble operando2(op2);
      if (signo == "+")
        resultado = (operando1 + operando2).toString();
      else if (signo == "-")
        resultado = (operando1 - operando2).toString();
      else if (signo == "/")
        resultado = (operando1 / operando2).toString();
      else if (signo == "*")
        resultado = (operando1 * operando2).toString();
      operandos.push(resultado);
      break;
    }
    case Fraction: {
      OperandoFraction operando1(op1);
      OperandoFraction operando2(op2);
      if (signo == "+")
        resultado = (operando1 + operando2).toString();
      else if (signo == "-")
        resultado = (operando1 - operando2).toString();
      else if (signo == "/")
        resultado = (operando1 / operando2).toString();
      else if (signo == "*")
        resultado = (operando1 * operando2).toString();
      operandos.push(resultado);
      break;
    }
    case Matriz: {
      OperandoMatrix operando1(op1);
      OperandoMatrix operando2(op2);
      if (signo == "+")
        resultado = (operando1 + operando2).toString();
      else if (signo == "-")
        resultado = (operando1 - operando2).toString();
      else if (signo == "/")
        resultado = (operando1 / operando2).toString();
      else if (signo == "*")
        resultado = (operando1 * operando2).toString();
      operandos.push(resultado);
      break;
    }
  }
}

void metodoPlantilla(std::string operacion, int tipo, std::string del = " ") {
  std::stack<std::string> operandos;
  int start = 0;
  int end = operacion.find(del);
  std::string substr;
  while (end != -1) {
    substr = operacion.substr(start, end - start);
    if (substr.size() == 1 && verificarSigno(substr)) {
      operar(operandos, tipo, substr);
    } else {
      operandos.push(operacion.substr(start, end - start));
    }
    start = end + del.size();
    end = operacion.find(del, start);
  }
  substr = operacion.substr(start, end - start);
  operar(operandos, tipo, substr);

  std::cout << operandos.top() << std::endl;
}

int main() {
  std::string pruebaMatriz =
      "1,1,1|2,2,2|3,3,3 1,1,1|2,2,2|3,3,3| * 10,10,10|20,20,20|30,30,30 + "
      "1,2,3|4,5,6|7,8,9 -";
  std::cout << "Operacion con matriz: \n" << pruebaMatriz << " = ";
  metodoPlantilla(pruebaMatriz, Matriz);
  std::string pruebaDouble = "4.5 3 * 5.2 8 * + 12 2 * 4 6.4 * / +";
  std::cout << "Operacion con Double: \n" << pruebaDouble << " = ";
  metodoPlantilla(pruebaDouble, Double);
  std::string pruebaFraction = "10|5 1|2 2|3 + 2|6 * +";
  std::cout << "Operacion con Fraction: \n" << pruebaFraction << " = ";
  metodoPlantilla(pruebaFraction, Fraction);
  return 0;
}
