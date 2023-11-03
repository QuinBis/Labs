#include <iostream>
#include <assert.h>
#include <vector>
#include <random>
#include <string>

#include "Header.h"

bool isSorted(const std::vector<int> numbers)
{

	assert(!numbers.empty());

	for (auto it = numbers.begin(); it != numbers.end() - 1; it++) {
		if (*it > *(it + 1))
			return false;
	}

	return true;
}

void outputnum(std::vector<int> numbers)
{
	std::cout << "[ ";
	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "]";
}

void setRandomNumbers(std::vector<int>& numbers, int size, int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());  // to seed mersenne twister.
	std::uniform_int_distribution<> dist(min, max); // distribute results between min and max inclusive.

	for (int i = 0; i < size; i++) {
		numbers.push_back(dist(gen));
	}

}

std::string getNameSorting(int size, const int range)
{

	std::string nameFile = "Numbers_Size";

	nameFile += std::to_string(size) + "_Range";

	nameFile += std::to_string(range) + ".txt";

	return nameFile;
}

void readFile(std::vector<int>& numbers, const std::string nameFile) {

	char* name = new char[nameFile.length() + 1];
	std::strcpy(name, nameFile.c_str());

	FILE* f = fopen(name, "r");

	assert(f != NULL);

	{
		int i;
		while (fscanf(f, "%d", &i) != EOF) {
			numbers.push_back(i);
		}
	}


	delete[] name;
	fclose(f);
}