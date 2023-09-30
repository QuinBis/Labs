#include <iostream>

#include "Header.h"


int main() {

	int testArray[5] = { 1, 2 ,3 ,4 ,5 };
	Array arr(testArray, 5);

	int size = arr.getSize();
	std::cout << "Array::getSize : size array : " << size << std::endl;


	std::cout << "Array::operator[] : arrTestArray[2] = " << arr[2] << std::endl;

	int indexValue = arr.getIndexElement(3);
	std::cout << "Array::getIndexElement : value(3) = index(" << indexValue << ")" << std::endl;

	std::cout << "Array::printArray : Array -> ";
	arr.printArray();

	Array arrTwo(5, 1);
	std::cout << "Array::scanArray : " << std::endl;
	arrTwo.scanArray(5);

	arrTwo.sort();
	std::cout << "Array::sort (shaker) : -> ";
	arrTwo.printArray();

	bool tempValue = arrTwo.addElementByIndex(5, 100);

	if (tempValue) {
		std::cout << "Array::addElementByIndex(5, 100) : is True -> ";
		arrTwo.printArray();
	}

	else {
		std::cout << "Array::addElementByIndex(5, 100) : is False." << std::endl;
	}

	tempValue = arrTwo.popElementByIndex(3);
	if (tempValue) {
		std::cout << "Array::popElementByIndex(3) : is True -> ";
		arrTwo.printArray();
	}
	else {
		std::cout << "Array::popElementByIndex(3) : is False." << std::endl;
	}

	tempValue = arrTwo.popFirstElementByValue(5);
	if (tempValue) {
		std::cout << "Array::popFirstElementByValue(5) : is True -> ";
		arrTwo.printArray();
	}
	else {
		std::cout << "Array::popFirstElementByValue(5) : is False." << std::endl;
	}


	std::cout << "&Array::operator = : ";
	Array arrThree(6, 10);
	arrThree = arrTwo;
	arrThree.printArray();

	std::cout << "&Array::operator [3] : " << arrThree[3] << std::endl;

	std::cout << "Array::popAllElementsByValue(0) : start array -> ";
	Array arrFour(5, 0);
	arrFour.printArray();
	arrFour[4] = 1;
	arrFour.popAllElementsByValue(0);
	std::cout << "\t\t\t\t  end array   -> ";
	arrFour.printArray();

	int maxElement = arrTwo.getIndexMaxElement(),
		minElement = arrTwo.getIndexMinElement();

	arrTwo.printArray();
	std::cout << "Array::getIndexMaxElement : index is " << maxElement << std::endl;
	std::cout << "Array::getIndexMinElement : index is " << minElement << std::endl;



	return 0;
}