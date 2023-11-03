#include <iostream>
#include <vector>
#include <assert.h>

#include "Header.h"

int main() {
	
	std::vector<int> numbers;
	setRandomNumbers(numbers, 10, 1, 10);

	outputnum(numbers);


	return 0;
}