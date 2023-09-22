#include <iostream>


#include "Fraction.h"

int main() {
	setlocale(0, "");

	Fraction One_Fraction = { 1 , 2 }; // Инициализация первой дроби
	Fraction Two_Fraction = { 1, 0 }; // Инициализация второй дроби
	Fraction temp;

	temp = One_Fraction / Two_Fraction;

	temp.print();

	One_Fraction.print();
	
	One_Fraction.reduce();

	One_Fraction.print();

	if (One_Fraction < Two_Fraction) std::cout << " true " << std::endl;
	if (One_Fraction > Two_Fraction) std::cout << " false " << std::endl;

	One_Fraction = One_Fraction * Two_Fraction;
	One_Fraction.print();


	return 0;

	

	return 0;
}