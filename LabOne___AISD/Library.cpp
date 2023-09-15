
#include <iostream>
#include <time.h>

#include "Header.h"

// ������� �������� ������������� ��� ������� ������ �����������.

int** CreatingMatric(int rows) { // ��������� ������ ��� ������������ ������� (����������)

	int **A;

	A = new int*[rows];

	for (int i = 0; i < rows; i++)

		A[i] = new int[rows];

	return A;

}

void RemovingMatric(int** matric, int cols) { // ������������ ������ �� ������������ �������

	for (int i = 0; i < cols;i++) {

		delete[]matric[i];

	}

	delete[]matric;

}

void InputMatric(int** matric, int cols) { // ���� �������� ��������� ������� (��������� �����).

	for (int i = 0; i < cols; i++) {

		for (int j = 0; j < cols; j++) {

			if (i != j) { // ���� � ���������� ��������� ���� �� ������ i � ����� j.

				std::cout << "������� ��������� ���� �� ������ " << i << " � ����� " << j << " : ";

				std::cin >> matric[i][j];

			}

			else { // �� ������ ������ � ���� �� ��������� ������.

				matric[i][j] = 0;

				std::cout << "��������� ���� �� ������ " << i << " � ����� " << j << " ����� 0" << std::endl;

			}

		}

	}


}

int* CreatingArray(int cols) { // ��������� ������ ��� ������������ ������.

	int* A;

	A = new int[cols];

	return A;

}

void RemovingArray(int* array, int cols) { // ������������ ������ �� ������������� �������.

	delete[]array;

}

void OutputArray(int* array, int cols) { // ����� ��������� �������.

	for (int* pointer = array; pointer < array + cols; pointer++) {

		std::cout << *pointer << " ";

	}


}

void OutputMatric(int** matr, int rows, int cols) { // ����� ������� �� �����.

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			std::cout << matr[i][j] << " ";
		}
		std::cout << "\n";
	}
}



void CopyArray(int* array_from, int * array_to, int size) { // ���������� �������� ���������

	for (int i = 0; i < size; i++) {
		array_to[i] = array_from[i];
	}
}



// �������� ������ ������? time_t � ������� RundNumMatric...

void RundNumMatric(int** matr, int rows) { // ��������� �������� ��������� ������� �� 1-100.

	srand( (unsigned int ) time(0));

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < rows; j++) {

			if (i != j) matr[i][j] = rand() % (100) + 1;

			else matr[i][j] = 0;

		}
	}

}



int Factorial(int num) { // ���������� ���������� �����.

	if (num == 0)

		return 1;

	else {

		return num * Factorial(num - 1);

	}

}

void SwapElementInArray(int &FirstElement, int &SecondElement) { 
	int temp = FirstElement;
	FirstElement = SecondElement;
	SecondElement = temp;

}

int CostOfTheWay(int*array, int**matric, int size) {

	int cost = 0, next_index = 0;

	for (int i = 0; i < size; i++) {
		next_index = i + 1;
		cost += matric[array[i] - 1][array[next_index] - 1];

	}

	return cost;

}