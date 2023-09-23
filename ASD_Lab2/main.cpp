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

	// testing...
	for (int i = 0; i < lengthWord; i++)
		std::cout << word[i] << " = " << table[word[i]] << std::endl;


	return 0;
}