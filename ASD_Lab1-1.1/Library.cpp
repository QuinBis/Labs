#include <iostream>
#include <time.h>

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

void outputMatrix(int** matrix, int rows, int cols)
{

	std::cout << "\nThe matrix of the cost of ways : " << std::endl;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
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

int computeFactorial(int num) { // Вычисление факториала числа.
	if (num == 0) {
		return 1;
	}

	else {
		return num * computeFactorial(num - 1);
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