#include <iostream>
#include <vector>
#include <algorithm>

#include "Header.h"

int main() {

	std::vector<int> temporary;
	setRandomNumbers(temporary, 10, 1, 100);
	outputnum(temporary);


	// ���� size%2==0 (�� ����� ������ ������ �������) : ����� �������� 1 � ����� �������
	
	for (int sizeNumbers = 10'000; sizeNumbers <= 1'000'000; sizeNumbers *= 10) {

		for (int rangeNumbers = 10; rangeNumbers <= 100'000; rangeNumbers *= 100) {




		}


	}




	return 0;
}