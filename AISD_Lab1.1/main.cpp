#include <iostream>

#include "Header.h"

int main() {

	int startCity, quantityCities;

	std::cout << "Enter the quantity of cities : ";
	std::cin >> quantityCities;
	std::cout << "Enter the starting city : ";
	std::cin >> startCity;

	if ((startCity >= quantityCities) || (startCity <= 0)) {

		completionProgramm();

	}

	int** matrixWays = createMatrix(quantityCities);
	inputMatrix(matrixWays, quantityCities);
	outputMatrix(matrixWays, quantityCities);

	return 0;
}