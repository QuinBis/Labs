#pragma once

bool isSorted(const std::vector<int> numbers);
void outputnum(std::vector<int> numbers);
void setRandomNumbers(std::vector<int>& numbers, int size, int min, int max);

void sifting(std::vector<int>& numbers,const int size, int index = 0);
void heapSort(std::vector<int>& numbers);

std::string getNameSorting(int size, const int range);
void readFile(std::vector<int>& numbers, const std::string nameFile);