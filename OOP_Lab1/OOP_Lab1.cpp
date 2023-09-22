#include <iostream>


#include "Fraction.h"

int main() {
	setlocale(0, "");

	Fraction One = { 3 , 1 };
	Fraction Two = { 8 , 0 };
	Fraction Three = One.mulNumbers(Two); // Операция не выполнилась, поскольку знаменатель = 0.
	Three.print();

	Two.setDenominator(5);

	Three = One.mulNumbers(Two);
	Three.print();


	


	

	

	return 0;
}