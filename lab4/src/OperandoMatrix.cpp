#include "OperandoMatrix.hpp"

#include <sstream>
OperandoMatrix::OperandoMatrix() {}

OperandoMatrix::OperandoMatrix(std::string hilera) {
  string line = "GeeksForGeeks is a must try";

  // Vector of string to save tokens
  vector<string> filas;

  // stringstream class check1
  std::stringstream check1(hilera);
  string intermediate;

  // Tokenizing w.r.t. space '|'
  while (getline(check1, intermediate, '|')) {
    filas.push_back(intermediate);
  }

  for (auto &fila : filas) {
    stringstream check1(fila);
    vector<int> filaTemporal;
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
  vector<vector<int>> dataResultante;
  dataResultante = this->myData;

  for (int filaIndex = 0; filaIndex < dataResultante.size(); filaIndex++) {
    for (int columnaIndex = 0; columnaIndex < dataResultante[filaIndex].size();
         ++columnaIndex) {
      dataResultante[filaIndex][columnaIndex] =
          dataResultante[filaIndex][columnaIndex] +
          operando->getMyData()[filaIndex][columnaIndex];
    }
  }

  return *new OperandoMatrix(dataResultante);
}
OperandoMatrix &OperandoMatrix::operator-(Operando &oper) {
  OperandoMatrix *operando = dynamic_cast<OperandoMatrix *>(&oper);
  vector<vector<int>> dataResultante;
  dataResultante = this->myData;

  for (int filaIndex = 0; filaIndex < dataResultante.size(); filaIndex++) {
    for (int columnaIndex = 0; columnaIndex < dataResultante[filaIndex].size();
         ++columnaIndex) {
      dataResultante[filaIndex][columnaIndex] =
          dataResultante[filaIndex][columnaIndex] -
          operando->getMyData()[filaIndex][columnaIndex];
    }
  }

  return *new OperandoMatrix(dataResultante);
}
OperandoMatrix &OperandoMatrix::operator*(Operando &oper) {
  OperandoMatrix *operando = dynamic_cast<OperandoMatrix *>(&oper);

  vector<vector<int>> dataResultante;

  for (int filasMatriz1Index = 0; filasMatriz1Index < this->myData.size();
       ++filasMatriz1Index)
    for (int columnasMatrix2Index = 0;
         columnasMatrix2Index < operando->getMyData()[0].size();
         ++columnasMatrix2Index)
      for (int columnasMatrix1Index = 0;
           columnasMatrix1Index < this->myData[0].size();
           ++columnasMatrix1Index) {
        dataResultante[filasMatriz1Index][columnasMatrix2Index] +=
            this->myData[filasMatriz1Index][columnasMatrix1Index] *
            operando->getMyData()[columnasMatrix1Index][columnasMatrix2Index];
      }

  return *new OperandoMatrix(dataResultante);
}
OperandoMatrix &OperandoMatrix::operator/(Operando &oper) { return *this; }

string OperandoMatrix::toString() {
  stringstream streamOutput;

  for (auto &fila : this->myData) {
    for (int numeroIndex = 0; numeroIndex < fila.size(); numeroIndex++) {
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
