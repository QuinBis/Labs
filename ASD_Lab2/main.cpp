#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Header.h"



int main() {

	setlocale(0, "Russian");

	std::string text = "Hello world!";
	std::string word = "world";

	// building a BM table.

	int lengthWord = word.length(),
		lengthText = text.length();

	int table[256] = { 0 };

	for (int i = 0; i < 256; i++) table[i] = lengthWord;

	for (int i = 0; i < lengthWord - 1; i++) {
		table[word[i]] = lengthWord - 1 - i;
	}


	// implementation of the BM algorithm.


	int k = lengthWord - 1;

	for (int i = lengthWord - 1 , j = lengthWord - 1; i < lengthText;) { 


		if (j >= 0) {

			// the symbols matched.
			if (word[j] == text[k]) {
				std::cout << "The symbol of the word " << word[j] << " coincided with the symbol of the text " << text[k] << std::endl;
				j--;k--;
			}

			// the symbols didn't match.
			else { 
				std::cout << text[k] << std::endl;
				i = i + table[text[k]];
				j = lengthWord - 1;
				k = i;
			}

		}

		else {

			std::cout << "The word has been found!" << std::endl;
			std::cout << "The word : " << word << std::endl;
			std::cout << "The text : " << text << std::endl;
			std::cout << "Index of the beginning of the occurrence : " << i;
			i = lengthText; // exiting the function.

		}
		
	}









	return 0;
}