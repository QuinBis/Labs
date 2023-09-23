#include <iostream>

#include "Header.h"


void outputArray(int* table, int size) {
	for (int i = 0; i < size; i++)
		std::cout << table[i] << " ";
}