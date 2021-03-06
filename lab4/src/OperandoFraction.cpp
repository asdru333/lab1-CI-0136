#include "OperandoFraction.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

OperandoFraction::OperandoFraction(const long long numerator,
                                   const long long denominator)
    : numerator{numerator}, denominator{denominator} {
  this->simplify();
}

OperandoFraction::OperandoFraction(std::string fraction) {
  if (!this->verifyStr(fraction))
    std::cout << "El cadena que representa la fracciÃ³n es invalida";
}

OperandoFraction& OperandoFraction::operator+(Operando& oper) {
  OperandoFraction* other = dynamic_cast<OperandoFraction*>(&oper);
  OperandoFraction* returned =
      new OperandoFraction(this->numerator * other->denominator +
                               this->denominator * other->numerator,
                           this->denominator * other->denominator);
  return *returned;
}

OperandoFraction& OperandoFraction::operator-(Operando& oper) {
  OperandoFraction* other = dynamic_cast<OperandoFraction*>(&oper);
  OperandoFraction* returned =
      new OperandoFraction(this->numerator * other->denominator -
                               this->denominator * other->numerator,
                           this->denominator * other->denominator);
  return *returned;
}

OperandoFraction& OperandoFraction::operator*(Operando& oper) {
  OperandoFraction* other = dynamic_cast<OperandoFraction*>(&oper);
  OperandoFraction* returned =
      new OperandoFraction(this->numerator * other->numerator,
                           this->denominator * other->denominator);
  return *returned;
}

OperandoFraction& OperandoFraction::operator/(Operando& oper) {
  OperandoFraction* other = dynamic_cast<OperandoFraction*>(&oper);
  OperandoFraction* returned =
      new OperandoFraction(this->numerator * other->denominator,
                           this->denominator * other->numerator);
  return *returned;
}

std::string OperandoFraction::toString() {
  std::stringstream stream;
  stream << this->numerator << '|' << this->denominator;
  return stream.str();
}

void OperandoFraction::simplify() {
  long long gcd =
      OperandoFraction::greatestCommonDivisor(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;

  if (this->denominator < 0) {
    this->numerator *= -1;
    this->denominator *= -1;
  }
}

long long OperandoFraction::greatestCommonDivisor(long long numerator,
                                                  long long denominator) {
  numerator = abs(numerator);
  denominator = abs(denominator);

  while (denominator) {
    long long denominator_copy = denominator;
    denominator = numerator % denominator;
    numerator = denominator_copy;
  }
  return numerator;
}

bool OperandoFraction::verifyStr(std::string fraction) {
  std::size_t found = fraction.find('|');
  if (found != std::string::npos) {
    std::string firstPart = fraction.substr(0, found);
    std::string secondPart = fraction.substr(found + 1, fraction.size());
    for (size_t counter = 0; counter < firstPart.size(); ++counter) {
      if (isdigit(firstPart[counter]) == 0) return 0;
    }
    for (size_t counter = 0; counter < secondPart.size(); ++counter) {
      if (isdigit(secondPart[counter]) == 0) return 0;
    }
    this->numerator = std::stoi(firstPart);
    this->denominator = std::stoi(secondPart);
    return 1;
  }
  return 0;
}
