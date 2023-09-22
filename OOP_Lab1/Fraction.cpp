#include <iostream>

#include "Fraction.h"

Fraction::Fraction(const int numerator, const int denominator) : m_numerator(numerator) //������ ������� �������������
{

	if (denominator == 0) {
		std::cerr << "ERROR : denominator is 0, result will be numerator. \n";
	}

	else {
		m_denominator = denominator; // m_denominator � ��� ����� 1.
	}

	if (m_denominator < 0) {
		m_numerator = m_numerator * -1;
		m_denominator = m_denominator * -1;
	}

}

void Fraction::print() const
{

	std::cout << m_numerator << "/" << m_denominator << std::endl;

}

Fraction Fraction::sumNumbers(const Fraction number) const
{

	Fraction sum;

	sum.m_numerator = m_numerator * number.m_denominator + number.m_numerator * m_denominator;
	sum.m_denominator = m_denominator * number.m_denominator;

	return sum;
}

Fraction Fraction::minNumbers(const Fraction number) const
{

	Fraction min;

	min.m_numerator = m_numerator * min.m_denominator - m_denominator * min.m_numerator;
	min.m_denominator = m_denominator * min.m_denominator;

	return min;
}

Fraction Fraction::mulNumbers(const Fraction number) const
{

	if (m_denominator * number.m_denominator == 0) {
		return Fraction(0, 1);
	}

	Fraction mul;

	mul.m_numerator = m_numerator * number.m_numerator;
	mul.m_denominator = m_denominator * number.m_denominator;

	return mul;
}

Fraction Fraction::divNumbers(const Fraction number) const
{

	if (m_denominator * number.m_denominator == 0) {
		return Fraction(0, 1);
	}

	Fraction div;

	div.m_numerator = m_numerator * number.m_denominator;
	div.m_denominator = m_denominator * number.m_numerator;

	return div;

}

void Fraction::setNumerator(const int value)
{
	m_numerator = value;
}

void Fraction::setDenominator(const int value)
{
	m_denominator = value;
}


int Fraction::getNumerator() const {
	return m_numerator;
}

int Fraction::getDenominator() const {
	return m_denominator;
}

int computeGCD(const int numerator, const int denominator) {

	if (numerator % denominator == 0)
		return denominator;
	if (denominator % numerator == 0)
		return numerator;
	if (numerator > denominator)
		return computeGCD(numerator%denominator, denominator); 
	return computeGCD(numerator, denominator%numerator);
}

void Fraction::reduce()
{
	int gcd = computeGCD(m_numerator, m_denominator);
	m_numerator = m_numerator / gcd;
	m_denominator = m_denominator / gcd;
}

bool Fraction::operator == (const Fraction twoFraction) const {

	return ((m_numerator == twoFraction.m_numerator) && (m_denominator == twoFraction.m_denominator));

}

bool Fraction::operator != (const Fraction twoFraction) const {
	
	return (!operator ==(twoFraction));

}

bool Fraction::operator > (const Fraction twoFraction) const {

	return  ((m_numerator * twoFraction.m_denominator) > (twoFraction.m_numerator * m_denominator));

}

bool Fraction::operator < (const Fraction twoFraction) const {

	return (!operator > (twoFraction));

}