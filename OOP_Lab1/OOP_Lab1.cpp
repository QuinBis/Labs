#include <iostream>


#include "Fraction.h"


int main() {
	setlocale(0, "");

	Fraction oneFraction = { 3 , 1 };
	Fraction twoFraction = { 8 , 0 };
	Fraction Three = oneFraction.mulNumbers(twoFraction); // Операция не выполнилась, поскольку знаменатель = 0.
	Three.print();


	//Method set.
	std::cout << "\n Method set:" << std::endl;
	twoFraction.setDenominator(5);
	Three = oneFraction.mulNumbers(twoFraction);
	Three.print();


	// Method get.
	std::cout << "\n Method get:" << std::endl;
	int a = Three.getNumerator();
	std::cout << a << std::endl;
	
	
	// Method reduce.
	std::cout << "\n Method reduce:" << std::endl;
	Three.reduce();
	Three.print();

	// Method bool (==) , (!=) , (>) , (<).
	std::cout << "\n Method bool:" << std::endl;
	oneFraction = { 1 , 1 }, twoFraction = { 1, 1 };
	bool temp = (oneFraction == twoFraction);
	std::cout << temp << std::endl; // true. 1 == 1
	temp = (oneFraction != twoFraction);
	std::cout << temp << std::endl; // false. 1 != 1

	twoFraction.setDenominator(2);
	temp = (oneFraction != twoFraction);
	std::cout << temp << std::endl; // true. 1 != 0.5

	temp = (oneFraction > twoFraction);
	std::cout << temp << std::endl; // true. 1 > 0.5

	oneFraction = { 1, 1 }, twoFraction = { 1 , 1 };
	std::cout << "<<<<<<<<<<<" << std::endl;
	temp = (oneFraction < twoFraction);
	std::cout << temp << std::endl; // false. 1 < 0.5

	// Method input.
	std::cout << "\n Method input:" << std::endl;
	Fraction fourFraction;
	fourFraction.input();
	fourFraction.print();

	// Method overload.
	std::cout << "\n Method overload :" << std::endl;
	oneFraction = oneFraction + twoFraction;
	oneFraction.print();

	// Own method (increment).
	std::cout << "\n Method increment :" << std::endl;
	Fraction fiveFraction = { 1, -2 };
	++fiveFraction;
	fiveFraction.print();
	fiveFraction++;
	fiveFraction.print();

	// Own method. (shifter).
	std::cout << "\n Method shifter:" << std::endl;
	Fraction sixFraction = { 0, 20 };
	sixFraction.shifter();
	sixFraction.print();	

	return 0;
}