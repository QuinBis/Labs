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
	std::cout << "������� ��������� ����� : "; std::cin >> startCity;

	int **MatricWays = CreatingMatric(numberCities, numberCities);

	RundNumMatric(MatricWays, numberCities, numberCities);

	OutputMatric(MatricWays, numberCities, numberCities);

	







	// ������������ ������ �� ������������ �������.
	RemovingMatric(MatricWays, numberCities);
	

	return 0;
}