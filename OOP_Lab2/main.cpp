#include <iostream>

#include "Array.h"

// ������ ������ �� ���������.
// getMax � getMin ��� ������� ������� ���������� ������ -1
// �������� ����������� const � operator[], sort, setRandom, setIncreaseRandom, setDecreaseRandom,
// ���������� operator + (const int value);
// ������� ����� swapArray(Array &other);
// ���������� ����� ���������� �������� ����� ����������.

int main() {

	Array one(5, 0);
	one.scanArray(5);
	std::cout << one << std::endl;

	one.insert(5, 10);
	std::cout << one << std::endl;
	// ����������� ������ [2, 3, 5, 9, 10]
	// ����� ������������� ������ insert -> [0, 2, 3, 5, 9, 10]
	// �������� it2 ������� ����� ��������� �� 2 (�� �������). 






	

	return 0;
}