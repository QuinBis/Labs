#include <iostream>
#include <vector>
#include <assert.h>

#include "Header.h"

int main() {

	std::vector<int> numbers, copy;

	clock_t start, end;

	double fullTimeSorting = 0;

	for (int sizeNumbers = 10'000; sizeNumbers <= 1'000'000; sizeNumbers *= 10) {
		for (int rangeNumbers = 10; rangeNumbers <= 100'000; rangeNumbers *= 100) {

			std::cout << "Size : " << sizeNumbers << " Range : " << rangeNumbers << std::endl;

			readFile(numbers, getNameSorting(sizeNumbers, rangeNumbers));

			for (int count = 1; count <= 3; count++) {
				copy = numbers;
				
				start = clock();
				quickSort(copy, 0, sizeNumbers-1);
				end = clock();

				assert(isSorted(copy));

				fullTimeSorting = double(end - start) / CLOCKS_PER_SEC;
			}

			std::cout << "Medium time -> " << fullTimeSorting / 3 << std::endl;
			fullTimeSorting = 0;
			numbers.clear();
		}
	}



	return 0;
}