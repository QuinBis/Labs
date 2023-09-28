#include <iostream>
#include <vector>

#include "Header.h"


int occurrence(std::string word, std::string text,int* table, int start = 0, int end = INT_MAX) {

	int lengthWord = word.length(),
		lengthText = text.length(),
		i = start + lengthWord - 1,
		j = lengthWord - 1,
		k = i;

	int occurrence;

	// Find all occurrences in range.

	if (end == INT_MAX)
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
			
			return (k+1);
		}

	}
	return -1;
}

int* computeTable(std::string word) {

	int lengthWord = word.length();

	int* table = new int[256];

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}

	return table;
}

void freeMemoryTable(int* table) {

	delete[]table;
}


int findFirstOccurrence(std::string word, std::string text) // find First Occurrence
{
	int lengthWord = word.length();
	
	int* tableBM = computeTable(word);

	int firstOccurrence = occurrence(word, text, tableBM);
	
	if (firstOccurrence != -1) {
		freeMemoryTable(tableBM);
		return firstOccurrence;
	}

	else {
		std::cout << "\nNo occurrences found." << std::endl;
		freeMemoryTable(tableBM);
		return -1;
	}


}

std::vector<int> findAllOccurrence(std::string word, std::string text) {

	int lengthText = text.length(),
		lengthWord = word.length(),
		start = 0,
		temp,
		end = lengthText-1;

	int* tableBM = computeTable(word);

	int occurrenceT;

	std::vector<int> occurrences;

	for (int i = 0; start < end;) {

		occurrenceT = occurrence(word, text, tableBM, start, end);
		
		if (occurrenceT != -1) {
			occurrences.push_back(occurrenceT);
			start = occurrenceT + (lengthWord-1);
		}

	}
	freeMemoryTable(tableBM);
	return occurrences;

}

std::vector<int> findOccurrencesRange(std::string word, std::string text, int start, int end)
{
	int lengthText = text.length(),
		lengthWord = word.length();

	int* tableBM = computeTable(word);

	int occurrenceT;
	std::vector<int> occurrences;

	for (int i = 0; start < end;) {

		occurrenceT = occurrence(word, text, tableBM, start, end);

		if (occurrenceT != -1) {
			occurrences.push_back(occurrenceT);
			start = occurrenceT + (lengthWord - 1);
		}
		else {
			start += end;
		}

	}

	freeMemoryTable(tableBM);
	return occurrences;

}

int algorithmBoyerMoore(std::string word, std::string text) {

	int lengthWord = word.length();

	int* tableBM = computeTable(word);
	
	int bmOccurrence = occurrence(word, text, tableBM);

	if (bmOccurrence != -1) {
		freeMemoryTable(tableBM);
		return bmOccurrence;
	}

	else {
		std::cout << "\nNo occurrences found." << std::endl;
		freeMemoryTable(tableBM);
		return -1;
	}
}
