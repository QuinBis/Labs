#include <iostream>
#include <time.h>
#include <math.h>

#include "Header.h"

// ����� ������������ ������������� ������ ��� ���������� = (n-1)! (��� ������ �������� ����� ���������� - ��������� ����)
// ������� ������ �������� �� ��������� ��������.

int main() {

	//setlocale(0, "Russian"); // ��� ������ ������� �������� � �������.

	/*========================������������� ����������========================*/

	int numberCities, startCity, waylength = 0, minlength = 0;

	std::cout << "������� ���������� ������� : "; std::cin >> numberCities; int numberofcycles = Factorial(numberCities - 1);
	std::cout << "������� ��������� ����� : "; std::cin >> startCity; std::cout << "\n";

	int **MatricWays = CreatingMatric(numberCities);
	//InputMatric(MatricWays, numberCities);
	RundNumMatric(MatricWays, numberCities);
	OutputMatric(MatricWays, numberCities, numberCities);


	// ������ Ways ��� ��������� �����, ��� ������ ������ ���� numberCities+1 (��������� �������� ������� 1-2-3-1).
	// ������ minimumWay ��� ������ �������� � ����������� ����������.
	int *Ways = CreatingArray(numberCities + 1), *minimumWay = CreatingArray(numberCities + 1);




	/* ===================== ��������� ������� ���� � ���������� ��������� �������� ========================= */

	for (int i = 0, countCities = 1, previndex = 0; i < numberCities;) {

		if (i == 0) { // ������ �������� 1 � ��������� ��������� �� �������� ���������� ������.

			Ways[i] = startCity;
			Ways[numberCities] = startCity;
			i++;

		}

		else if (countCities == startCity) { countCities++; } // ���� ������� ����� = ����������, ��������� ������� ����� �� 1.

		else { // �� ���� ���� �������, ������ ���������� ������, ������ �� �����.

			previndex = i - 1;

			Ways[i] = countCities;

			waylength += MatricWays[Ways[previndex] - 1][Ways[i] - 1];

			countCities++;

			i++;

		}
	}

	waylength += MatricWays[Ways[numberCities - 1] - 1][Ways[numberCities] - 1];
	OutputArray(Ways, numberCities + 1);
	std::cout << "\n��������� ����� �������� : " << waylength << std::endl;

	minlength = waylength; // ����� ����� ������ ������� �� �����������, � ����������� ����� ����������.
	OutputArray(Ways, numberCities + 1);

	// ���������� ��������� ��������.






	// ������������ ������ �� ������������ �������.
	RemovingArray(Ways, numberCities + 1);
	RemovingArray(minimumWay, numberCities + 1);
	RemovingMatric(MatricWays, numberCities);


	return 0;
}