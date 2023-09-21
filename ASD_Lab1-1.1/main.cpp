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

	if (startCity > quantityCities || startCity <= 0) {

		std::cout << "Error!";
		return 0;

	}

	int** matrixCost = createMatrix(quantityCities);
	generateRandomMatrix(matrixCost, quantityCities);
	outputMatrix(matrixCost, quantityCities);

	int* maxWay = createArray(quantityCities + 1), *minWay = createArray(quantityCities + 1),* heuristicWay = createArray(quantityCities + 1);


	clock_t start = clock();

	exactAlgorithm(matrixCost, quantityCities,maxWay , minWay, startCity);

	clock_t end = clock();
	double secondsExact = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();

	heuristicAlgorithm(matrixCost,quantityCities,heuristicWay, startCity);

	end = clock();
	double secondsHeuristic = (double)(end - start) / CLOCKS_PER_SEC;

	int minLength = computeCostWay(minWay, matrixCost, quantityCities),
		maxLength = computeCostWay(maxWay, matrixCost, quantityCities),
		heurLength = computeCostWay(heuristicWay, matrixCost, quantityCities);
	float qualitySolution = 0;
	double speedSolution = 0;


	// Report.
	

	// Консоль иначе выводит -inf.
	if (maxLength == heurLength) {
		qualitySolution = 0;
	}
	else {
		qualitySolution = ((float)(minLength - heurLength) / (float)(minLength - maxLength)) * 100;
		qualitySolution = 100 - qualitySolution;
	}
	
	std::cout << "\n\t\t Report!\n";
	std::cout << "The quality of the solution of the heuristic algorithm will be as follows : " << qualitySolution << "%" << std::endl;
	

	speedSolution = (secondsExact / secondsHeuristic) + 100;

	
	std::cout << "The speed of the heuristic algorithm will be as follows : " << speedSolution << "%" << std::endl;
	

	return 0;
}