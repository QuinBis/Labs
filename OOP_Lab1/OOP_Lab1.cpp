#include <iostream>


#include "Fraction.h"


int main() {
	setlocale(0, "");

	Fraction One = { 3 , 1 };
	Fraction Two = { 8 , 0 };
	Fraction Three = One.mulNumbers(Two); // Операция не выполнилась, поскольку знаменатель = 0.
	Three.print();


	//Method set.
	Two.setDenominator(5);
	Three = One.mulNumbers(Two);
	Three.print();


	// Method get.
	int a = Three.getNumerator();
	std::cout << a << std::endl;
	
	
	// Method reduce.
	Three.reduce();
	Three.print();

	// Method bool (==) , (!=) , (>) , (<).
	One = { 1 , 1 }, Two = { 1, 1 };
	bool temp = (One == Two);
	std::cout << temp << std::endl; // true. 1 == 1
	temp = (One != Two);
	std::cout << temp << std::endl; // false. 1 != 1

	Two.setDenominator(2);
	temp = (One != Two);
	std::cout << temp << std::endl; // true. 1 != 0.5

	temp = (One > Two);
	std::cout << temp << std::endl; // true. 1 > 0.5

	temp = (One < Two);
	std::cout << temp << std::endl; // false. 1 < 0.5


	

	

	return 0;
}