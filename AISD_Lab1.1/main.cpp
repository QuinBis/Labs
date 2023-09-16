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

	int currentCost,
		minimumCost,
		column,
		currentWay = startCity;

	while (...) {

		minimumCost = 101;
		column = 0;

		// 

		for (int i = 0; i < quantityCities; i++) {

			if (i != currentWay) {

				currentCost = matrixWays[currentWay][i];

				if (currentCost < minimumCost) {

					minimumCost = currentCost;
					column = i;
				}
			}
		}
	}

	return 0;
}