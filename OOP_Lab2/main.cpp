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
	one.setRandom(100,500);
	one.printArray();

	for (auto it = one.begin(); it != one.end(); it++) {

	}

	


	

	return 0;
}