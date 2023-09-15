#include "Header.h"
#include <iostream>
#include <time.h>

int** CreatingMatric(int rows, int cols) {

	int **A;

	A = new int*[rows];

	for (int i = 0; i < rows; i++)

		A[i] = new int[cols];

	return A;

}

void RemovingMatric(int** matric, int cols) {

	for (int i = 0; i < cols;i++) {

		delete[]matric[i];
	
	}
	
	delete[]matric;

}

void InputMatric(int** matric, int cols) {

	for (int i = 0; i < cols; i++) {

		for (int j = 0; j < cols; j++) {

			std::cout << "”кажите стоимость пути из города " << i << " в город " << j << " : ";

			std::cin >> matric[i][j];

		}

	}

	
}

void OutputMatric(int** matr, int rows, int cols) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			std::cout << matr[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void RundNumMatric(int** matr, int rows, int cols) {

	srand(time(0));

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			if (i != j) matr[i][j] = rand() % (100) + 1;

			else matr[i][j] = 0;

		}
	}

}

int Factorial(int num) {

	if (num == 0) 

		return 1;

	else { 
		return num * Factorial(num - 1); 

	}

}