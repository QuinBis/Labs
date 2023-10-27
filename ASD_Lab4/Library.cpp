#include <iostream>
#include <vector>
#include <assert.h>
#include <random>

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

void sifting(std::vector<int>& numbers, int index)
{
    unsigned int size = numbers.size();

    int childs = 2 * index + 1;

    while (index < size) {

        if (childs < size) {

            // the next child exists.
            if ((childs + 1) < size) {

                if (numbers[childs] < numbers[childs + 1]) {
                    // It becomes current
                    childs += 1;
                }

                // We change places for parents with a large descendant
                if (numbers[index] < numbers[childs]) {
                    std::swap(numbers[index], numbers[childs]);
                    index = childs;
                    childs = 2 * index + 1;
                }
            }

            // There is no next child
            else {
                index += size;
            }
        }

        else { // end while
            index += size;
        }
    }
}

void heapsort(std::vector<int>& numbers) {

    unsigned int size = numbers.size();

    // i = size/2-1    ---> We take the last one to the parents.
    for (int i = size / 2 - 1; i >= 0; i--) {
        sifting(numbers, i);
    }

}
