#include <iostream>
#include <vector>

#include "Header.h"


std::vector<int> occurrence(std::string word, std::string text,int start = 0, int end = 1000) {

	int lengthWord = word.length(),
		lengthText = text.length(),
		i = start + lengthWord - 1,
		j = lengthWord - 1,
		k = i;

	std::vector<int> allOccurrence;

	// Compute Table BM.

	int table[256] = { 0 };

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}

	// Find all occurrences in range.

	if (end == 1000)
		end = lengthText - 1;

	while (i <= end) {


		if (j >= 0) {
			if (word[j] == text[k]) {
				j--; k--;
			}

			else {
				i += table[text[k]];
				j = lengthWord - 1;
				k = i;
			}
		}

		if (j < 0) {

			allOccurrence.push_back(k + 1);
			j = lengthWord - 1;
			i += table[text[k]];
			k = i;

		}

	}

	return allOccurrence;
}


int findFirstOccurrence(std::string word, std::string text) // find First Occurrence
{
	std::vector<int> firstOccurrence = occurrence(word, text);
	
	if (firstOccurrence.size() > 0) {
		return firstOccurrence[0];
	}

	else {
		std::cout << "\nNo occurrences found." << std::endl;
		return -1;
	}
}

std::vector<int> findAllOccurrence(std::string word, std::string text) {

	std::vector<int> occurrences = occurrence(word, text);
	if (occurrences.size() > 0) {
		return occurrences;
	}

	else {
		std::cout << "\nNo occurrences found." << std::endl;
		return occurrences;
	}

}

std::vector<int> findOccurrencesRange(std::string word, std::string text, int start, int end)
{
	
	std::vector<int> rangeOccurrences = occurrence(word, text, start, end);
	if (rangeOccurrences.size() > 0) {
		return rangeOccurrences;
	}

	else {
		std::cout << "\nNo occurrences found." << std::endl;
		return rangeOccurrences;
	}
}

int algorithmBoyerMoore(std::string word, std::string text) {
	
	std::vector<int> firstOccurrence = occurrence(word, text);

	if (firstOccurrence.size() > 0) {
		return firstOccurrence[0];
	}

	else {
		std::cout << "\nNo occurrences found." << std::endl;
		return -1;
	}

}
