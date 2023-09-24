#include <iostream>
#include <vector>

#include "Header.h"


void outputArray(int* table, int size) {
	for (int i = 0; i < size; i++)
		std::cout << table[i] << " ";
}

int findFirstOccurrence(std::string word, std::string text, int* table) // find First Occurrence
{
	int lengthWord = word.length(),
		lengthtText = text.length(),
		k = lengthWord - 1,
		flag = 0;

	for (int i = lengthWord - 1, j = lengthWord - 1; i < lengthtText;) {


		if (j >= 0) {


			if (word[j] == text[k]) {
				j--;k--;
			}


			else {
				i = i + table[text[k]];
				j = lengthWord - 1;
				k = i;
			}


		}

		else if (j < 0) {

			return k + 1;

		}

	}

	std::cout << "Function findFirstOccurence didn't find the index." << std::endl;
	return -1;	
	
}

std::vector<int> findAllOccurrence(std::string word, std::string text, int* table) {

	int lengthWord = word.length(),
		lengthText = text.length(),
		i = lengthWord - 1,
		j = lengthWord - 1,
		k = i;

	std::vector<int> allOccurrence;

	while (i < lengthText) {


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

	if (allOccurrence.size() > 0) {
		return allOccurrence;
	}

	else {
		std::cout << "Function findAllOccurence didn't find the indexes." << std::endl;
		return allOccurrence;
	}
}

std::vector<int> findOccurrencesRange(std::string word, std::string text, int* table, int start, int end)
{

	int lengthWord = word.length(),
		lengthText = text.length(),
		i = start + lengthWord-1,
		k = i,
		j = lengthWord - 1;


	std::vector<int> allOccurrenceRange;

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

			allOccurrenceRange.push_back(k + 1);
			j = lengthWord - 1;
			i += table[text[k]];
			k = i;

		}

	}

	if (allOccurrenceRange.size() > 0) {
		return allOccurrenceRange;
	}

	else {
		std::cout << "Function findAllOccurence didn't find the indexes." << std::endl;
		return allOccurrenceRange;
	}


}

void algorithmBoyerMoore(std::string word, std::string text, int* table) {
	
	int lengthWord = word.length(),
		lengthText = text.length(),
		k = lengthWord - 1,
		flag = 0;

	for (int i = lengthWord - 1, j = lengthWord - 1; i < lengthText;) {

		if (j >= 0) {

			// the symbols matched.
			if (word[j] == text[k]) {
				j--;k--;
			}

			// the symbols didn't match.
			else {
				i = i + table[text[k]];
				j = lengthWord - 1;
				k = i;
			}

		}

		else if (j < 0) {
			std::cout << "BM search found a word, the index of occurrence : " << k+1;
			i = lengthText;
			flag = 1;
		}

	}

	if (flag == 0) {
		std::cout << "BM search did not find the word." << std::endl;
	}



}

void computeTableBM(int* table, std::string word) {

	int lengthWord = word.length();

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}

	
}