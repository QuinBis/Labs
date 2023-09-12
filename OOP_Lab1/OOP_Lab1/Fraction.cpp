#include <iostream>

#include "Fraction.h"

void Fraction::OutputFraction() {

	std::cout << numerator << "/" << denominator << std::endl;

}

Fraction Fraction::SumFraction(Fraction twofraction) { // Сложение двух дробей

	Fraction sum;

	sum.numerator = numerator * twofraction.denominator + twofraction.numerator * denominator;
	sum.denominator = denominator * twofraction.denominator;

	return sum;

}

Fraction Fraction::DiffFraction(Fraction twofraction) {

	Fraction difference;

	difference.numerator = numerator * twofraction.denominator - twofraction.numerator * denominator;
	difference.denominator = denominator * twofraction.denominator;

	return difference;

}

Fraction Fraction::MultiplyFraction(Fraction twofraction) {

	Fraction Multiply = {0 , 0};

	if ((denominator * twofraction.denominator) == 0) {
		
		return Multiply;
		
	}

	Multiply.numerator = numerator * twofraction.numerator;
	Multiply.denominator = denominator * twofraction.denominator;
	return Multiply;

}

Fraction Fraction::DivisionFraction(Fraction twofraction) {

	Fraction Division = { 0,0 };

	if ((denominator * twofraction.numerator) == 0) {
		return Division;
	}
	Division.numerator = numerator * twofraction.denominator;
	Division.denominator = denominator * twofraction.numerator;

	return Division;
}