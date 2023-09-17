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

	int* mainWay = createArray(quantityCities + 1);

	// Начало реализации эвристического решения
	

	int currentCost = 0,
		minimumCost = 101,
		minimumWay,

	// Поскольку индексация идет с 0.
		currentCity = startCity - 1;

	for (int i = 0; i < quantityCities; i++) {

		if (i != currentCity) { // Чтобы избежать попадания из одного города в тот же.

			currentCost = matrixCost[currentCity][i];

			if (currentCost < minimumCost) {
				
				minimumCost = currentCost;


			}
		}
	}


	destroyMatrix(matrixCost, quantityCities);
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

	exactAlgorithm(quantityCities, startCity);

	return 0;
}