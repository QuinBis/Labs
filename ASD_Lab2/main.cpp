#include <iostream>
#include <string>
#include <vector>


#include "Header.h"


int main() {

	setlocale(0, "Russian");

	std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator",
				word = "tor";

	int bmsearch = algorithmBoyerMoore(word, text);
	if (bmsearch != -1) {
		std::cout << "\nBM search : " << bmsearch << std::endl;
	}



	// Testing Function.
	int firstOccurrence = findFirstOccurrence(word, text);
	if (firstOccurrence != -1) {
		std::cout << "\nFunction findFirstOccurrence : " << firstOccurrence << std::endl;
	}

	std::vector<int> allOccurrence;
	allOccurrence = findAllOccurrence(word, text);
	if (allOccurrence.size() > 0) {
		std::cout << "Function findAllOccurrence : ";
		for (auto& vector : allOccurrence) {
			std::cout << vector << " ";
		}
	}

	std::vector<int> occurrencesInRange = findOccurrencesRange(word, text, 0, 91);
	if (occurrencesInRange.size() > 0) {
		std::cout << "\nFunctioon findOccurrencesRange range [0,91] : ";
		for (auto& vector : occurrencesInRange) {
			std::cout << vector << " ";
		}
	}

	std::vector<int> occurrencesInRange2 = findOccurrencesRange(word, text, 17, 91);
	if (occurrencesInRange.size() > 0) {
		std::cout << "\nFunctioon findOccurrencesRange range [17, 91] : ";
		for (auto& vector : occurrencesInRange2) {
			std::cout << vector << " ";
		}
	}

	std::vector<int> occurrencesInRange3 = findOccurrencesRange(word, text, 28, 36);
	if (occurrencesInRange.size() > 0) {
		std::cout << "\nFunctioon findOccurrencesRange range [28, 36] : ";
		for (auto& vector : occurrencesInRange3) {
			std::cout << vector << " ";
		}
	}

	return 0;
}