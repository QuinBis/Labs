#include <iostream>
#include <string>
#include <vector>


#include "Header.h"


int main() {

	setlocale(0, "Russian");

	std::string text = "Hello world!";
	std::string word = "world";


	// building a BM table.

	int table[256] = { 0 };

	computeTableBM(table, word);

	// implementation of the BM algorithm.
	algorithmBoyerMoore(word, text, table);


	
	// Testing function.
	int firstOccurrence = findFirstOccurrence(word, text, table);
	std::cout << "\n\nIndex of first occurrence : " << firstOccurrence << std::endl;



	std::vector<int> allOccurrence = findAllOccurrence(word, text, table);
	std::cout << "Indexes of all occurrences : ";
	for (auto& v : allOccurrence) {
		std::cout << v << " ";
	}


	std::vector<int> occurrenceRange = findOccurrencesRange(word, text, table, 6, 11);
	std::cout << "\nIndexes of all occurrences in the range : ";
	for (auto& v : occurrenceRange)
		std::cout << v << " ";

	




	return 0;
}