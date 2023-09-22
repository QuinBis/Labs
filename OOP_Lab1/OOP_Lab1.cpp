#include <iostream>


#include "Fraction.h"


int main() {
	setlocale(0, "");

	Fraction oneFraction = { 3 , 1 };
	Fraction twoFraction = { 8 , 0 };
	Fraction Three = oneFraction.mulNumbers(twoFraction); // Операция не выполнилась, поскольку знаменатель = 0.
	Three.print();


	//Method set.
	twoFraction.setDenominator(5);
	Three = oneFraction.mulNumbers(twoFraction);
	Three.print();


	// Method get.
	int a = Three.getNumerator();
	std::cout << a << std::endl;
	
	
	// Method reduce.
	Three.reduce();
	Three.print();

	// Method bool (==) , (!=) , (>) , (<).
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

	temp = (oneFraction < twoFraction);
	std::cout << temp << std::endl; // false. 1 < 0.5

	// Method input.
	Fraction fourFraction;
	fourFraction.input();
	fourFraction.print();

	// Method overload.
	oneFraction = oneFraction + twoFraction;
	oneFraction.print();

	// Own method (increment).
	Fraction fiveFraction = { 1, -2 };
	++fiveFraction;
	fiveFraction.print();
	fiveFraction++;
	fiveFraction.print();

	// Own method. (shifter).
	Fraction sixFraction = { 10, 20 };
	sixFraction.shifter();
	sixFraction.print();


	

	

	return 0;
}