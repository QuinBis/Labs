#include <iostream>


#include "Fraction.h"

int main() {
	setlocale(0, "");

	Name_Class One_Fraction = { 1 , 2 }; // Инициализация первой дроби
	Name_Class Two_Fraction = { 1, 0 }; // Инициализация второй дроби

	std::cout << "Выводим сумму..." << std::endl;
	One_Fraction.OutputFractionTwo(One_Fraction.SumNumbers(Two_Fraction));

	std::cout << "Выводим разность..." << std::endl;
	One_Fraction.OutputFractionTwo(One_Fraction.DiffNumbers(Two_Fraction));

	std::cout << "Выводим произведение..." << std::endl;
	One_Fraction.OutputFractionTwo(One_Fraction.MultiplyNumbers(Two_Fraction));

	std::cout << "Выводим частное..." << std::endl;
	One_Fraction.OutputFractionTwo(One_Fraction.DivisionNumbers(Two_Fraction));

	return 0;
}