#include <iostream>
#include <vector>

#include "Header.h"

// �������� ������ : ������ ����� �����

int main() {
	
	int size = 5;

	int* temp = createArray(size);

	setIncrease(temp, size);
	outputArray(temp, size);

	std::vector<int> temporary = shellSort(temp, size);

	for (auto it = begin(temporary); it != end(temporary); it++)
		std::cout << *it << std::endl;





	return 0;
}