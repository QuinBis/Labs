#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <random>

#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS

void setRandomNumbers(std::vector<int>& numbers, int size, int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());  // to seed mersenne twister.
	std::uniform_int_distribution<> dist(min, max); // distribute results between min and max inclusive.

	for (int i = 0; i < size; i++) {
		numbers.push_back(dist(gen));
	}

}

bool isSorted(const std::vector<int> numbers)
{

	assert(!numbers.empty());

	for (auto it = numbers.begin(); it != numbers.end() - 1; it++) {
		if (*it > *(it + 1))
			return false;
	}

	return true;
}

void stepsShell(std::vector<int>& numbers) // N/2 - N - size array
{
	int size = (unsigned int)numbers.size();

	for (int step = size / 2; step > 0; step /= 2) {
		sorting(numbers, step);
	}
}

void stepsPapernovStasevich(std::vector<int>& numbers) // 2^k + 1 prefixed with 1.
{
	int step = 1;
	for (; step < numbers.size();) step *= 2;
	step = step / 2 + 1;

	for (; step >= 3; step = step / 2 + 1) {
		sorting(numbers, step);
	}

	// prefixed with 1.
	sorting(numbers, 1);
}

void stepsHibbard(std::vector<int>& numbers) // 2^k - 1.
{
	int step = 1;
	while (step < numbers.size()) step *= 2;
	step = step / 2 - 1;

	for (; step > 0; step /= 2) {
		sorting(numbers, step);
	}
}

void sorting(std::vector<int>& numbers, const int step)
{
	assert(step > 0);

	int j;

	for (int i = 0; i < numbers.size() - step; i++) {
		j = i;
		while (j >= 0 && numbers[j] > numbers[j + step]) {
			std::swap(numbers[j], numbers[j + step]);
			j -= step;
		}
	}
}

void createFile(std::vector<int>& numbers, const std::string nameFile) {
	
	char* name = new char[nameFile.length() + 1];
	std::strcpy(name, nameFile.c_str());

	FILE* f = fopen(name, "w");

	assert(f != NULL);

	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		fprintf(f, "%d ", *it);
	}
	delete[] name;
	fclose(f);
}

std::string getNameSorting(int size, const int range)
{

	std::string nameFile = "Numbers_Size";

	nameFile += std::to_string(size) + "_Range";

	nameFile += std::to_string(range) + ".txt";

	return nameFile;
}

void sortingThreeSteps(std::vector<int>& numbers, int rangeNumbers ,int count) {

	std::cout << "Sorting -> " << getNameSorting(numbers.size(), rangeNumbers) << std::endl;

	switch (count) {
	case(1):
		stepsShell(numbers);
		break;
	case(2):
		stepsPapernovStasevich(numbers);
		break;
	case(3):
		stepsHibbard(numbers);
		break;
	default:
		assert(false);
		break;
	}

	assert(isSorted(numbers));

	}


void outputnum(std::vector<int> numbers) {
	std::cout << "[ ";
	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "]";
}