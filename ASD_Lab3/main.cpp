#include <iostream>
#include <vector>

#include "Header.h"

// �������� ������ : ������ ����� �����

int main() {
	
	std::vector<int> numbers;
	setRandomNumbers(numbers, 15, 1, 200);
	outputnum(numbers);



	return 0;
}