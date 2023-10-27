#include <iostream>
#include <vector>
#include <assert.h>

#include "Header.h"

int main() {
	std::vector<int> numbers;
		clock_t start, end;
		double fullTimeSorting = 0;
		for (int sizeNumbers = 10000; sizeNumbers <= 1000000; sizeNumbers *= 10) {
			std::cout << "Size numbers -> " << sizeNumbers;
			for (int rangeNumbers = 10; rangeNumbers <= 100000; rangeNumbers *= 100) {
				std::cout << " -> Range numbers -" << rangeNumbers << " " << rangeNumbers << std::endl;
				setRandomNumbers(numbers, sizeNumbers, -rangeNumbers, rangeNumbers);
				for (int count = 1; count <= 3; count++) {
					start = clock();
					sortingThreeSteps(numbers, rangeNumbers, count);
					end = clock();	
					fullTimeSorting += double(end - start) / CLOCKS_PER_SEC;
				}
				std::cout << "Medium time -> " << fullTimeSorting / 3 << std::endl;
				fullTimeSorting = 0;
			}
		}


	return 0;
}