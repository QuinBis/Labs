#include "Header.h"
#include <iostream>
#include <time.h>

int** CreatingMatr(int rows, int cols) {
	int **A;
	A = new int*[rows];
	for (int i = 0; i < rows; i++)
		A[i] = new int[cols];
	return A;
}

void RemovingMatr(int** matric, int cols) {
	for (int i = 0; i < cols;i++) {
		delete[]matric[i];
	}
	delete[]matric;
}

void OutputMatr(int** matr, int rows, int cols) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			std::cout << matr[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void RundNumMatr(int** matr, int rows, int cols) {

	srand(time(0));

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			if (i != j) matr[i][j] = rand() % (100) + 1; // Генерация случайного числа в диапазоне от 1 до 100.

			else matr[i][j] = 0; // Исключаем возможность попадания из одного города в себя.

		}
	}
}

int Factorial(int num) {
	if (num == 0) return 1;
	else { return num * Factorial(num - 1); }
}