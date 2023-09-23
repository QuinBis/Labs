#pragma once


void outputArray(int* table, int size);

void computeTableBM(int* table, std::string word);

void algorithmBoyerMoore(std::string word, std::string text, int* table);

int findFirstOccurrence(std::string word, std::string text, int* table);

std::vector<int> findAllOccurrence(std::string word, std::string text, int* table);

std::vector<int> findOccurrencesRange(std::string word, std::string text, int* table, int Start, int End);