#include <iostream>

#include "Header.h"

int** createMatrix(int rows) {

	int** a;
	a = new int*[rows];

	for (int i = 0; i < rows; i++) {
		a[i] = new int[rows];
	}

	return a;
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









void completionProgramm()
{
	std::cout << "ERROR!" << std::endl;
	exit(0);
}