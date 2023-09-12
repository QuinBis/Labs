#include <iostream>
#include "Fraction.h"

// Си функции всегда всё копируют



int main() {
	setlocale(0, "");

	Fraction fraction = { 1, 2 };
	Fraction twofraction = { 1, 2 };

	Fraction temp = fraction.SumFraction(twofraction);

	std::cout << "Выведем сумму..." << std::endl;
	temp.OutputFraction();

	std::cout << "Выведем разницу..." << std::endl;

	temp = fraction.DiffFraction(twofraction);
	temp.OutputFraction();

	std::cout << "Выведем произведение..." << std::endl;

	temp = fraction.MultiplyFraction(twofraction);
	temp.OutputFraction();


	std::cout << "Выведем частное..." << std::endl;

	temp = fraction.DivisionFraction(twofraction);
	temp.OutputFraction();

	return 0;
}