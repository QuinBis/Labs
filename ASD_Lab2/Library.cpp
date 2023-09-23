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
				return k;
			}


			else {
				i = i + table[text[k]];
				j = lengthWord - 1;
				k = i;
			}


		}


		// If no occurrence is found.
		else if (j < 0) {

			i = lengthtText;
			flag = 1;

		}

	}

	std::cout << "The fist Occurrence doesn't fit." << std::endl;
	return -1;
	
}

std::vector<int> findAllOccurrence(std::string word, std::string text, int* table) {

	int lengthWord = word.length(),
		lengthText = text.length(),
		k = lengthWord - 1,
		flag = 0;

	std::vector<int> allOccurrence;

	for (int i = lengthWord - 1, j = lengthWord - 1; i < lengthText;) {


		if (j >= 0) {

			// the symbols matched.
			if (word[j] == text[k]) {
				allOccurrence.push_back(k);
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
			
			i = lengthText;
			flag = 1;

		}

	}

	if (flag == 0) {
		std::cout << "The all Occurrence doesn't fit." << std::endl;
		return allOccurrence;
	}


	return allOccurrence;
}

std::vector<int> findOccurrencesRange(std::string word, std::string text, int* table, int Start, int End)
{

	int lengthWord = word.length(),
		lengthText = text.length(),
		k = Start + lengthWord - 1,
		flag = 0;

	std::vector<int> allOccurrence;


	// check errors.
	if (End > lengthText - 1) {
		std::cout << "\nERROR : End > lengthText" << std::endl;
		return allOccurrence;
	}
	if (Start + (lengthWord - 1) > End) {
		std::cout << "\nERROR : The word doesn't fit.";
		return allOccurrence;
	}




	for (int i = Start, j = lengthWord - 1; i < End;) {


		if (j >= 0) {

			// the symbols matched.
			if (word[j] == text[k]) {
				allOccurrence.push_back(k);
				j--; k--;
				if (k < Start) return allOccurrence;
			}

			// the symbols didn't match.
			else {
				i = i + table[text[k]];
				j = lengthWord - 1;
				k = i;
			}

		}

		else {

			i = End;
			flag = 1;

		}

	}
	if (flag == 0) {
		std::cout << "\n The word doesn't fit.";
		return allOccurrence;
	}


	return allOccurrence;
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
				std::cout << "The symbol of the word " << word[j] << " coincided with the symbol of the text " << text[k] << std::endl;
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
			std::cout << "\n\t\tThe word has been found!" << std::endl;
			std::cout << "\t\tIndex of the beginning of the occurrence : " << i;
			i = lengthText;
			flag = 1;
		}

	}

	if (flag == 0) {
		std::cout << "The word doesn't fit." << std::endl;
	}



}

void computeTableBM(int* table, std::string word) {

	int lengthWord = word.length();

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}

	
}