#ifndef OPERANDOMATRIX_H
#define OPERANDOMATRIX_H
#pragma once
#include <string>
#include <vector>

#include "Operando.hpp"

class OperandoMatrix : public Operando {
 private:
  std::vector<std::vector<int>> myData;

 public:
  // La matriz aplanada va a funcionar de esta manera:
  // Las ',' separan las columnas y '|' separan las filas
  OperandoMatrix();
  OperandoMatrix(std::string hilera);

  OperandoMatrix(std::vector<std::vector<int>> data);

  ~OperandoMatrix();
  OperandoMatrix& operator+(Operando& oper) override;
  OperandoMatrix& operator-(Operando& oper) override;
  OperandoMatrix& operator/(Operando& oper) override;
  OperandoMatrix& operator*(Operando& oper) override;
  std::string toString();
  std::vector<std::vector<int>> getMyData();
};
#endif