#include <iostream>
#include <time.h>
#include <math.h>

#include "Header.h"

// ����� ������������ ������������� ������ ��� ���������� = (n-1)! (��� ������ �������� ����� ���������� - ��������� ����)
// ������� ������ �������� �� ��������� ��������.

int main() {
	setlocale(0, "Russian"); // ��� ������ ������� �������� � �������.

	/*========================������������� ����������========================*/

	int numberCities, startCity;

	std::cout << "������� ���������� ������� : "; std::cin >> numberCities;
	//std::cout << "������� ��������� ����� : "; std::cin >> startCity;


	// �������� � ��������� ������ ��� ������������ �������.
	int **matri� = CreatingMatr(numberCities, numberCities);

	RundNumMatr(matri�, numberCities, numberCities);
	OutputMatr(matri�, numberCities, numberCities);

	//int **Road = CreatingMatr(factorial)
	
	int kolvociklov = Factorial(numberCities - 1);

	int **Road = CreatingMatr( kolvociklov , numberCities); // 1 �������� - ���������� ������ ������������, 2 - ���������� ������

	for (int i = 0; i < kolvociklov; i++) {
		Road[i][0] = startCity;
	}

	for (int i = 0; i < kolvociklov; i++) {
		for
	}




	// ������������ ������ �� ������������ �������.
	RemovingMatr(matri�, numberCities);


	return 0;
}