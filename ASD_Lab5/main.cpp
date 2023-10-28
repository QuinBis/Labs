#include <iostream>
#include <vector>

#include "Header.h"

int main() {

	std::vector<int> temp;
	setRandomNumbers(temp, 10, 1, 50);

	outputnum(temp);


	return 0;
}