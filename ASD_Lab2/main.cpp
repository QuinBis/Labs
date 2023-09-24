#include <iostream>
#include <string>
#include <vector>


#include "Header.h"


int main() {

	setlocale(0, "Russian");

	std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator",
				word = "tor";


	// building a BM table.

	int table[256] = { 0 };

	computeTableBM(table, word);

	// implementation of the BM algorithm.
	algorithmBoyerMoore(word, text, table);



	// Testing Function.
	int firstOccurrence = findFirstOccurrence(word, text, table);
	if (firstOccurrence != -1) {
		std::cout << "\nFunction findFirstOccurrence : " << firstOccurrence << std::endl;
	}

	std::vector<int> allOccurrence;
	allOccurrence = findAllOccurrence(word, text, table);
	if (allOccurrence.size() > 0) {
		std::cout << "Function findAllOccurrence : ";
		for (auto& vector : allOccurrence) {
			std::cout << vector << " ";
		}
	}
	

	std::vector<int> occurrenceRange;
	occurrenceRange = findOccurrencesRange(word, text, table, 0, 91);
	if (occurrenceRange.size() > 0) {
		std::cout << "\nFunction findOccurrencesRange in range [0, 91] : ";
		for (auto& vector : occurrenceRange) {
			std::cout << vector << " ";
		}
	}
	
	occurrenceRange = findOccurrencesRange(word, text, table, 17, 91);
	if (occurrenceRange.size() > 0) {
		std::cout << "\nFunction findOccurrencesRange in range [17, 91] : ";
		for (auto& vector : occurrenceRange) {
			std::cout << vector << " ";
		}
	}

	occurrenceRange = findOccurrencesRange(word, text, table, 28, 36);
	if (occurrenceRange.size() > 0) {
		std::cout << "\nFunction findOccurrencesRange in range [28, 36] : ";
		for (auto& vector : occurrenceRange) {
			std::cout << vector << " ";
		}
	}




	return 0;
}