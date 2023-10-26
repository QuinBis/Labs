#include <iostream>
#include <vector>

#include "Header.h"

// Исходные данные : массив целых чисел

int main() {
	
	std::vector<int> numbers;
	setRandomNumbers(numbers, 15, 1, 200);
	outputnum(numbers);



	return 0;
}