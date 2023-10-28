#pragma once

bool isSorted(const std::vector<int> numbers);
void outputnum(std::vector<int> numbers);
void setRandomNumbers(std::vector<int>& numbers, int size, int min, int max);
void swapNumbers(int& x, int& y);

void quickSort(std::vector<int>& numbers, int leftBorder, int rightBorder);

std::string getNameSorting(int size, const int range);
void readFile(std::vector<int>& numbers, const std::string nameFile);
