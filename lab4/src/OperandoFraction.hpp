#ifndef FRACTION_H
#define FRACTION_H

#pragma once

class OperandoFraction: public Operando
{
	private:
		long long numerator;
		long long denominator;
	
	public:
		/// Default constructor (ctor) and conversion constructor
		OperandoFraction(const long long numerator = 0, const long long denominator = 1);
		OperandoFraction(const std::string);
		OperandoFraction& operator+(Operando& other) override;
		OperandoFraction& operator-(Operando& other) override;
		OperandoFraction& operator*(Operando& other) override;
		OperandoFraction& operator/(Operando& other) override;
		void print();

	private:
		void simplify();
		long long greatestCommonDivisor(long long numerator, long long denominator);
		bool verifyStr(std::string fraction);
};
