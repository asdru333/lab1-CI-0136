#ifndef OPERANDO_H
#define OPERANDO_H
#pragma once

class Operando {
 private:
 public:
  virtual Operando& operator+(Operando&) = 0;
  virtual Operando& operator-(Operando&) = 0;
  virtual Operando& operator/(Operando&) = 0;
  virtual Operando& operator*(Operando&) = 0;
};
#endif