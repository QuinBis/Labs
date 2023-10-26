#include <iostream>
#include <vector>

#include "Header.h"
#include <time.h>

int* createArray(int cols)
{

	int* A;

	A = new int[cols];

	return A;
}

void outputArray(int* array, int cols)
{
	std::cout << "[";
	for (int i = 0; i < cols-1; i++) {
		std::cout << array[i] << ",";
	}

	std::cout << array[cols-1] << "]" <<std::endl;
}

void setRundArray(int* array, int size,int max, int min)
{
	srand((unsigned int)time(0));

	for (int i = 0; i < size; i++) {
		array[i] = rand() % (max - min + 1) + min;
	}
}

void setIncrease(int* array, int size)
{
	srand((unsigned int)time(0));

	array[0] = rand() % 10 + 1;
	
	for (int i = 1; i < size; i++) {
		array[i] = array[i - 1] + rand() % 5 + 1;
	}
}

void setDecrease(int* array, int size)
{
	srand((unsigned int)time(0));

	array[size-1] = rand() % 10 + 1;

	for (int i = size - 2; i >= 0; i--) {
		array[i] = array[i + 1] + rand() % 10 + 1;
	}

}

bool isSorted(int* array, int size) {

	for (int i = 0; i < size-1; i++) {
		if (array[i] > array[i + 1])
			return false;
	}
	
	return true;
}

std::vector<int> shellSort(int* array, int size) {

	std::vector<int> steps;

	for (int i = size / 2; i >= 1; i / 2) {
		steps.push_back(i);
	}

	return steps;
}