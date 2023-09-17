#include <iostream>
#include <time.h>
#include <chrono>

#include "Header.h"

int** createMatrix(int rows) {

	int** A;
	A = new int*[rows];

	for (int i = 0; i < rows; i++) {
		A[i] = new int[rows];
	}

	return A;
}

void destroyMatrix(int** matrix, int cols)
{

	for (int i = 0; i < cols;i++) {

		delete[] matrix[i];

	}

	delete[]matrix;
}

void outputMatrix(int** matrix, int rows)
{

	std::cout << "\nThe matrix of the cost of ways : " << std::endl;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < rows; j++) {
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;

	}
}

void inputMatrix(int** matrix, int cols)
{
	for (int i = 0; i < cols; i++) {

		for (int j = 0; j < cols; j++) {

			if (i != j) {

				std::cout << "Specify the cost of the way from city " << i << " to city " << j << " : ";
				std::cin >> matrix[i][j];

				if (matrix[i][j] == 0) {

					completionProgramm();

				}
			}

			else {
				matrix[i][j] = 0;
			}
		}
	}
}

void generateRandomMatrix(int** matrix, int rows)
{
	srand((unsigned int)time(0));

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < rows; j++) {

			if (i != j) {
				matrix[i][j] = rand() % (100) + 1;
			}

			else {
				matrix[i][j] = 0;
			}
		}
	}
}

int* createArray(int cols){

	int* A;

	A = new int[cols];

	return A;
}

void destroyArray(int* array, int cols)
{
	delete[]array;
}

void outputArray(int* array, int cols)
{

	for (int i = 0; i < cols ; i++) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}


void copyArray(int* arrayFrom, int* arrayTo, int size)
{
	for (int i = 0; i < size; i++) {
		arrayTo[i] = arrayFrom[i];
	}
}

void swapValues(int& firstValue, int& secondValue)
{ 
	int temp = firstValue;
	firstValue = secondValue;
	secondValue = temp;
}

int computeCostWay(int* array, int** matrix, int size) {

	int cost = 0, nextIndex = 0;

	for (int i = 0; i < size; i++) {
		nextIndex = i + 1;
		cost += matrix[array[i] - 1][array[nextIndex] - 1];
	}

	return cost;
}

void completionProgramm()
{
	std::cout << "ERROR!";
	exit(0);
}

void exactAlgorithm(int quantityCities, int startCity)
{

	clock_t start = clock();

	int** matrixWays = createMatrix(quantityCities);
	//inputMatrix(matrixWays, quantityCities);
	generateRandomMatrix(matrixWays, quantityCities);
	outputMatrix(matrixWays, quantityCities);

	int* currentWay = createArray(quantityCities + 1),
	   * minimumWay = createArray(quantityCities + 1);

	for (int i = 0, k = 1; i < quantityCities; ) {

		if (i == 0) {
			currentWay[i] = startCity;
			currentWay[quantityCities] = startCity;

			i++;
		}

		else if (k == startCity) {
			k++;
		}

		else {
			currentWay[i] = k;
			k++;
			i++;
		}

	}

	int countCycles = 1;

	std::cout << "\nPossible ways for this solution : \n";
	outputArray(currentWay, quantityCities + 1);

	int currentLength = computeCostWay(currentWay, matrixWays, quantityCities);


	copyArray(currentWay, minimumWay, quantityCities + 1);

	int nextIndex,
		minimumLength = currentLength;



	for (int i = quantityCities - 2; i >= 1; i--){

		nextIndex = i + 1;

		if ((i < quantityCities - 1) && (currentWay[i] < currentWay[nextIndex])) {

			for (int j = quantityCities - 1; j > i; j--) {

				if ((j <= quantityCities - 1) && (currentWay[i] < currentWay[j])) {

					swapValues(currentWay[i], currentWay[j]);

					for (int k = i + 1, l = quantityCities - 1; k <= l; k++, l--) {
						swapValues(currentWay[k], currentWay[l]);
					}


					currentLength = computeCostWay(currentWay, matrixWays, quantityCities);


					if (minimumLength > currentLength) {

						copyArray(currentWay, minimumWay, quantityCities + 1);

						minimumLength = currentLength;

					}


					//outputArray(currentWay, quantityCities + 1);
					countCycles++;

					// We returned the index to the end so as not to miss the solution.
					i = quantityCities - 1;
				}
			}
		}
	}

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "\nThe minimum cost way is : "; outputArray(minimumWay, quantityCities + 1);
	std::cout << "The cost of this way : " << minimumLength << std::endl;
	std::cout << "The time - " << seconds << "s" << std::endl;


	// Freeing up memory from arrays and matrix.
	destroyArray(currentWay, quantityCities + 1);
	destroyArray(minimumWay, quantityCities + 1);
	destroyMatrix(matrixWays, quantityCities);

}