#include <iostream>
#include <time.h>

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







	// ������������ ������ �� ������������ �������.
	RemovingMatr(matri�, numberCities);


	return 0;
}