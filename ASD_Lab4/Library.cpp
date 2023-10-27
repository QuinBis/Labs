#include <iostream>
#include <vector>
#include <assert.h>
#include <random>
#include <string>

#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS

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

void sifting(std::vector<int>& numbers, const int size, int index)
{

    int childs = 2 * index + 1;

    while (index < size) {

        if (childs < size) {

            // the next child exists.
            if ((childs + 1) < size)

                if (numbers[childs + 1] > numbers[childs])
                    // It becomes current
                    childs += 1;

            // We change places for parents with a large descendant
            if (numbers[index] < numbers[childs]) {
                std::swap(numbers[index], numbers[childs]);
                index = childs;
                childs = 2 * index + 1;
            }

            // There is no next child
            else {
                index += size;
            }
        }

        // end while
        else {
            index += size;
        }
    }
}

void heapSort(std::vector<int>& numbers) {

    const int size = (int)numbers.size();

    // i = size/2-1    ---> We take the last one to the parents.
    for (int i = size / 2 - 1; i >= 0; i--) {
        sifting(numbers,size, i);
    }

    for (int j = size - 1; j > 0; j--) {
        std::swap(numbers[0], numbers[j]);
        sifting(numbers, j);

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

