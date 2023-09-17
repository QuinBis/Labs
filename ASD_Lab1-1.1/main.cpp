#include <iostream>
#include <time.h>
#include <chrono>

#include "Header.h"

// рефакторинг outputMatrix() - теперь 2 аргумента, вместо 3

void heuristicAlgorithm(int quantityCities, int startCity) {
	
	auto begin = std::chrono::steady_clock::now();


	int** matrixCost = createMatrix(quantityCities);
	generateRandomMatrix(matrixCost, quantityCities);
	//inputMatrix(matrixCost, quantityCities);
	outputMatrix(matrixCost, quantityCities);

	// The first and last index is the initial one
	int* currentWay = createArray(quantityCities + 1);
	currentWay[0] = currentWay[quantityCities] = startCity;
	//outputArray(currentWay, quantityCities + 1);

	int currentCity = startCity - 1,
		minimumCost = 0,
		currentCost = 0,
		minArc;

	for (int i = 1; i < quantityCities + 1; i++) {

		minimumCost = 0;

		outputArray(currentWay, quantityCities + 1);


		for (int j = 0; j < quantityCities; j++) {

			if (j != currentCity) { // 2 != 0


				// This check is done to avoid a new variable
				if (minimumCost == 0) {
					minimumCost = matrixCost[currentCity][j];
					minArc = j;
				}



				else {

					currentCost = matrixCost[currentCity][j];

					if ( (currentCost < minimumCost) && (currentCost != 0) ) { 

						minimumCost = currentCost; 
						minArc = j;

					}
				}


			}

		}

		matrixCost[minArc][currentCity] = 0;
		currentCity = minArc;
		currentWay[i] = currentCity + 1;

	}

	outputMatrix(matrixCost, quantityCities);

	destroyMatrix(matrixCost, quantityCities);
	destroyArray(currentWay, quantityCities + 1);
}

int main() {

	int quantityCities, startCity;

	std::cout << "Enter the quantity of cities : ";
	std::cin >> quantityCities;
	std::cout << "Enter the starting city : ";
	std::cin >> startCity;

	if ( startCity > quantityCities || startCity <= 0) {

		completionProgramm();

	}

	//exactAlgorithm(quantityCities, startCity);
	heuristicAlgorithm(quantityCities, startCity);

	return 0;
}