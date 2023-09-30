#include <iostream>

#include "Header.h"


int main() {
	
	int arrStandart[5] = { 2, 5, 1, 9, 3 };
	Array oneArr(arrStandart, 5);
	Array twoArr(6, 0);
	twoArr.scanArray(6);


	bool temp = (oneArr != twoArr);

	if (temp) {
		std::cout << "Array::operator == ---> oneArr != twoArr";
	}
	else {
		std::cout << "Array::operator == ---> oneArr == twoArr ";
	}



	return 0;
}