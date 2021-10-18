#include "OperandoMatrix.hpp"

#include <iostream>
#include <sstream>
OperandoMatrix::OperandoMatrix() {}

OperandoMatrix::OperandoMatrix(std::string hilera) {
  std::string line = "GeeksForGeeks is a must try";

  // Vector of string to save tokens
  std::vector<std::string> filas;

  // stringstream class check1
  std::stringstream check1(hilera);
  std::string intermediate;

  // Tokenizing w.r.t. space '|'
  while (getline(check1, intermediate, '|')) {
    filas.push_back(intermediate);
  }

  for (auto &fila : filas) {
    std::stringstream check1(fila);
    std::vector<int> filaTemporal;
    while (getline(check1, intermediate, ',')) {
      filaTemporal.push_back(stoi(intermediate));
    }
    this->myData.push_back(filaTemporal);
  }
}

OperandoMatrix::OperandoMatrix(std::vector<std::vector<int>> data) {
  this->myData = data;
}

OperandoMatrix::~OperandoMatrix() {}

OperandoMatrix &OperandoMatrix::operator+(Operando &oper) {
  OperandoMatrix *operando = dynamic_cast<OperandoMatrix *>(&oper);
  std::vector<std::vector<int>> dataResultante;
  dataResultante = this->myData;

  for (size_t filaIndex = 0; filaIndex < dataResultante.size(); filaIndex++) {
    for (size_t columnaIndex = 0;
         columnaIndex < dataResultante[filaIndex].size(); ++columnaIndex) {
      dataResultante[filaIndex][columnaIndex] =
          dataResultante[filaIndex][columnaIndex] +
          operando->getMyData()[filaIndex][columnaIndex];
    }
  }

  return *new OperandoMatrix(dataResultante);
}
OperandoMatrix &OperandoMatrix::operator-(Operando &oper) {
  OperandoMatrix *operando = dynamic_cast<OperandoMatrix *>(&oper);
  std::vector<std::vector<int>> dataResultante;
  dataResultante = this->myData;

  for (size_t filaIndex = 0; filaIndex < dataResultante.size(); filaIndex++) {
    for (size_t columnaIndex = 0;
         columnaIndex < dataResultante[filaIndex].size(); ++columnaIndex) {
      dataResultante[filaIndex][columnaIndex] =
          dataResultante[filaIndex][columnaIndex] -
          operando->getMyData()[filaIndex][columnaIndex];
    }
  }

  return *new OperandoMatrix(dataResultante);
}
OperandoMatrix &OperandoMatrix::operator*(Operando &oper) {
  OperandoMatrix *operando = dynamic_cast<OperandoMatrix *>(&oper);
  std::vector<std::vector<int>> dataResultante(this->myData.size());
  for (size_t index = 0; index < dataResultante.size(); ++index) {
    dataResultante[index].resize(operando->getMyData()[0].size());
  }
  for (size_t filasMatriz1Index = 0; filasMatriz1Index < this->myData.size();
       ++filasMatriz1Index)
    for (size_t columnasMatrix2Index = 0;
         columnasMatrix2Index < operando->getMyData()[0].size();
         ++columnasMatrix2Index)
      for (size_t columnasMatrix1Index = 0;
           columnasMatrix1Index < this->myData[0].size();
           ++columnasMatrix1Index) {
        dataResultante[filasMatriz1Index][columnasMatrix2Index] +=
            this->myData[filasMatriz1Index][columnasMatrix1Index] *
            operando->getMyData()[columnasMatrix1Index][columnasMatrix2Index];
      }

  return *new OperandoMatrix(dataResultante);
}

OperandoMatrix &OperandoMatrix::operator/(Operando &oper) { return *this; }

std::string OperandoMatrix::toString() {
  std::stringstream streamOutput;

  for (auto &fila : this->myData) {
    for (size_t numeroIndex = 0; numeroIndex < fila.size(); numeroIndex++) {
      streamOutput << fila[numeroIndex];
      if (numeroIndex != fila.size() - 1) {
        streamOutput << ',';
      }
    }

    streamOutput << '|';
  }

  return streamOutput.str();
}

std::vector<std::vector<int>> OperandoMatrix::getMyData() {
  return this->myData;
}
