#include <iostream>
#include <vector>

#include "Header.h"


std::vector<int> occurrence(std::string word, std::string text,int* table, int start = 0, int end = INT_MAX) {

	int lengthWord = word.length(),
		lengthText = text.length(),
		i = start + lengthWord - 1,
		j = lengthWord - 1,
		k = i;

	std::vector<int> allOccurrence;

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
			
			allOccurrence.push_back(k + 1);
			return allOccurrence;
		}

	}
	return allOccurrence;
}


int findFirstOccurrence(std::string word, std::string text) // find First Occurrence
{
	int lengthWord = word.length();
	
	int table[256] = { 0 };

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}

	std::vector<int> firstOccurrence = occurrence(word, text, table);
	
	if (firstOccurrence.size() > 0) {
		return firstOccurrence[0];
	}

	else {
		std::cout << "\nNo occurrences found." << std::endl;
		return -1;
	}
}

std::vector<int> findAllOccurrence(std::string word, std::string text) {

	int lengthText = text.length(),
		lengthWord = word.length(),
		start = 0,
		temp,
		end = lengthText-1;

	int table[256] = { 0 };

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}

	std::vector<int> occurrTemp,
							occurrences;

	for (int i = 0; start < end;) {

		occurrTemp = occurrence(word, text, table, start, end);
		
		if (occurrTemp.size() > 0) {
			occurrences.push_back(occurrTemp[0]);
			start = occurrTemp[0] + (lengthWord-1);
		}

	}
	
	return occurrences;

}

std::vector<int> findOccurrencesRange(std::string word, std::string text, int start, int end)
{
	int lengthText = text.length(),
		lengthWord = word.length();

	int table[256] = { 0 };

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}

	std::vector<int> occurrTemp,
		occurrences;

	for (int i = 0; start < end;) {

		occurrTemp = occurrence(word, text, table, start, end);

		if (occurrTemp.size() > 0) {
			occurrences.push_back(occurrTemp[0]);
			start = occurrTemp[0] + (lengthWord - 1);
		}
		else {
			start += end;
		}

	}

	return occurrences;

}

int algorithmBoyerMoore(std::string word, std::string text) {

	int lengthWord = word.length();

	int table[256] = { 0 };

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}
	
	std::vector<int> bmOccurrence = occurrence(word, text, table);

	if (bmOccurrence.size() > 0) {
		return bmOccurrence[0];
	}

	else {
		std::cout << "\nNo occurrences found." << std::endl;
		return -1;
	}
}
