#include <iostream>
#include <time.h>
#include <chrono>

#include "Header.h"

int main() {

	int quantityCities, startCity;

	std::cout << "Enter the quantity of cities : ";
	std::cin >> quantityCities;
	std::cout << "Enter the starting city : ";
	std::cin >> startCity;

	if ( startCity >= quantityCities || startCity <= 0) {

		completionProgramm();

	}

	exactAlgorithm(quantityCities, startCity);


	return 0;
}