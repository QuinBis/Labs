#include <iostream>
#include <vector>
#include <assert.h>

#include "Header.h"


int main() {
	
	std::vector<int> numbers;
	setRandomNumbers(numbers,10, 1000000, 1000000);
	outputnum(numbers);


	/*{
		clock_t start, end;

		for (int sizeNumbers = 10000; sizeNumbers <= 1000000; sizeNumbers *= 10) {
			for (int rangeNumbers = 10; rangeNumbers <= 100000; rangeNumbers *= 100) {



				for (int count = 1; count <= 3; count++) {

					switch (count) {
					case(1):



					case(2):
					case(3):
					default:

					}



				}




			}
		}
	}*/


	return 0;
}