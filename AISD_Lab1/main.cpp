#include <iostream>
#include <time.h>
#include <math.h>

#include "Header.h"

// ����� ������������ ������������� ������ ��� ���������� = (n-1)! (��� ������ �������� ����� ���������� - ��������� ����)
// ������� ������ �������� �� ��������� ��������.

int main() {

	setlocale(0, "Russian"); // ��� ������ ������� �������� � �������.

	/*========================������������� ����������========================*/
	
	int numberCities, startCity, waylength = 0, minlength = 0;

	std::cout << "������� ���������� ������� : "; std::cin >> numberCities; int numberofcycles = Factorial(numberCities - 1);
	std::cout << "������� ��������� ����� : "; std::cin >> startCity;

	int **MatricWays = CreatingMatric(numberCities);
	InputMatric(MatricWays, numberCities);
	//RundNumMatric(MatricWays, numberCities);
	OutputMatric(MatricWays, numberCities, numberCities);

	
	// ������ Ways ��� ��������� �����, ��� ������ ������ ���� numberCities+1 (��������� �������� ������� 1-2-3-1)
	int *Ways = CreatingArray(numberCities + 1), *minimumWay = CreatingArray(numberCities + 1);

	// ��������� ������� ���� � ���������� ��������� ��������.

	int i = 0, index = 0, countCities = 1;

	while (index != (numberCities + 1) ) {

		if (index == 0 or index == numberCities + 1){  // ������ � �������� ����� � ������� ����� ����������.

			Ways[index] = startCity;
			index++;

		}

		else if ((Ways[--index] == startCity) and (countCities < startCity)) { // ���������� ������  �� ������� ����� � �������.

			Ways[index] = countCities;
			index++;
			countCities++;
		}

		else if (countCities > Ways[--index]) {// ���� ��������� ����� > ������ �����������

			Ways[index] = countCities;
			index++;
			countCities;

		}







	}
	
	OutputArray(Ways, numberCities + 1);



	// ���������� ��������� ��������.

	//for (int i = 0; i < numberofcycles; i++) {}






	// ������������ ������ �� ������������ �������.
	RemovingMatric(MatricWays, numberCities);
	

	return 0;
}