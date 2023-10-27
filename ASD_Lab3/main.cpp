#include <iostream>
#include <vector>
#include <assert.h>

#include "Header.h"

std::string getSteps(int count) {

	switch (count) {
	case(1):
		return "Steps Shell";
		break;
	case(2):
		return "Steps Papenov & Stasevich";
		break;
	case(3):
		return "Steps Hibbard";
		break;
	default:
		assert(false);
		break;
	}
}

int main() {

	std::vector<int> numbers, copy;

	clock_t start, end;

	double fullTimeSorting = 0;
	
	for (int sizeNumbers = 10'000; sizeNumbers <= 1'000'000; sizeNumbers *= 10) {
		for (int rangeNumbers = 10; rangeNumbers <= 100'000; rangeNumbers *= 100) {

			std::cout << "Size : " << sizeNumbers << " Range : " << rangeNumbers << std::endl;

			//setRandomNumbers(numbers, sizeNumbers, -rangeNumbers, rangeNumbers);
			//createFile(numbers, getNameSorting(sizeNumbers, rangeNumbers));
			readFile(numbers, getNameSorting(sizeNumbers, rangeNumbers));

			for (int i = 1; i <= 3; i++) {
				std::cout << getSteps(i) << std::endl;
				for (int count = 1; count <= 3; count++) {
					copy = numbers;
					start = clock();
					sortingThreeSteps(copy, rangeNumbers, i);
					end = clock();
					assert(isSorted(copy));
					fullTimeSorting += double(end - start) / CLOCKS_PER_SEC;
				}
				std::cout << getNameSorting(sizeNumbers, rangeNumbers);
				std::cout << "Medium time -> " << fullTimeSorting / 3 << std::endl;
				fullTimeSorting = 0;
			}
			numbers.clear();

		}
	}

	

	return 0;
}