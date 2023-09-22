#include <iostream>

#include "Fraction.h"


// Тип Имя_Класса :: Имя_Функции (список)  ===== Тип - типо возвращаемого значения, Список - список аргументов

void Fraction::print() const {
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}

Fraction Fraction::SumNumbers(const Fraction &Number) const{ // Сложение

	Fraction sum;

	sum.m_numerator = (m_numerator * Number.m_denominator) + (m_denominator * Number.m_numerator);

	sum.m_denominator = m_denominator * Number.m_denominator;

	return sum;
}


Fraction Fraction::MinusNumbers(const Fraction &Number) const{ // Вычитание

	Fraction Minus;

	Minus.m_numerator = (m_numerator * Number.m_denominator) - (m_denominator*Number.m_numerator);
	Minus.m_denominator = m_denominator * Number.m_denominator;

	return Minus;

}

Fraction Fraction::MultiplyNumbers(const Fraction &Number) const { // Умножение


	if ((m_denominator * Number.m_denominator) == 0) {
		std::cerr << "Fraction::d error: (one or two)m_numerator is 0, won't devide.";
		return Fraction(0,1);
	}

	Fraction Multiply;

	Multiply.m_numerator = m_numerator * Number.m_numerator;
	Multiply.m_denominator = m_denominator * Number.m_denominator;
	return Multiply;
}

Fraction Fraction::DivisionNumbers(const Fraction &Number) const // Деление
{

	if (Number.m_numerator == 0) {
		std::cerr << "Fraction::DivisionNumbers error: number.m_numerator is 0, won't devide.";
		return Fraction(0,1);
	}
	
	Fraction Division;

	Division.m_numerator = m_numerator * Number.m_denominator;
	Division.m_denominator = m_denominator * Number.m_numerator;
	return Division;
}

Fraction::Fraction(const int numerator, const int denominator) {
	this->m_numerator = numerator;
	if (denominator != 0) {
		this->m_denominator = denominator;
	}
	else {

		std::cerr << "Fraction::Fraction - error; denominator is 0" << std::endl;
		std::cerr << "The denominator has been corrected to 1." << std::endl;
		this->m_denominator = 1;

	}
}

void Fraction::setNumerator(const int number) {
	m_numerator = number;
	return;
}

void Fraction::setDenominator(const int number) {
	m_denominator = number;
	return;
}

int Fraction::getNumerator() const {
	return m_numerator;
}

int Fraction::getDenominator() const {
	return m_denominator;
}

bool Fraction::operator == (const Fraction other) {

	return ( (m_numerator == other.m_numerator) && (m_denominator == other.m_denominator) );

}

bool Fraction::operator != (const Fraction other) {

	return ( !(operator == (other) ) );
}

bool Fraction::operator < (const Fraction other) {
	return ( (m_numerator * other.m_denominator) < (other.m_numerator * m_denominator) );
}

bool Fraction::operator > (const Fraction other) {
	return (!(operator < (other) ));
}

unsigned int computeGreatestCommonDivisior(const unsigned int denominatorOne,
	const unsigned int denominatorTwo)
{
	if (denominatorOne % denominatorTwo == 0)
		return denominatorTwo;
	if (denominatorTwo % denominatorOne)
		return denominatorOne;
	if (denominatorOne > denominatorTwo)
		return computeGreatestCommonDivisior(denominatorOne % denominatorTwo, denominatorTwo);
	return computeGreatestCommonDivisior(denominatorOne, denominatorTwo % denominatorOne);
}

void Fraction::reduce() {
	int nod = computeGreatestCommonDivisior(m_numerator, m_denominator);

	m_numerator /= nod;
	m_denominator /= nod;

	return;
}

void Fraction::scan() {
	std::cout << "Enter the numerator : ";
	std::cin >> m_numerator;

	std::cout << "Enter the denominator : ";
	std::cin >> m_denominator;

	while (m_denominator == 0) {
		std::cout << "enter a non-zero denominator : ";
		std::cin >> m_denominator;
	}

}

Fraction Fraction::operator + (const Fraction other) {
	return SumNumbers(other);
}
Fraction Fraction::operator - (const Fraction other) {
	return MinusNumbers(other);
};
Fraction Fraction::operator * (const Fraction other) {
	return MultiplyNumbers(other);
}
Fraction Fraction::operator / (const Fraction other) {
	return DivisionNumbers(other);
}


