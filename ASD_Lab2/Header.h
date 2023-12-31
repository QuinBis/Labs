#pragma once

int occurrence(std::string word, std::string text,int* table, int start, int end);

int algorithmBoyerMoore(std::string word, std::string text);

int findFirstOccurrence(std::string word, std::string text);

std::vector<int> findAllOccurrence(std::string word, std::string text);

std::vector<int> findOccurrencesRange(std::string word, std::string text,int start, int end);

int* computeTable(std::string word);

void freeMemoryTable(int* table);