
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

	for (int* pointer_from = array_from, *pointer_to = array_to; pointer_from < array_from + size;) {

		*(pointer_to)++ = *(pointer_from)++;

	}

}



// �������� ������ ������? time_t � ������� RundNumMatric...

void RundNumMatric(int** matr, int rows) { // ��������� �������� ��������� ������� �� 1-100.

	srand(time(0));

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