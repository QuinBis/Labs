#pragma once

void setRandomNumbers(std::vector<int>& numbers, int size, int min, int max);

bool isSorted(const std::vector<int> numbers);

void sorting(std::vector<int>& numbers, const int step);
void stepsShell(std::vector<int>& numbers);
void stepsPapernovStasevich(std::vector<int>& numbers);
void stepsHibbard(std::vector<int>& numbers);

void createFile(std::vector<int>& numbers, const std::string nameFile);
void sortingThreeSteps(std::vector<int>& numbers, int rangeNumbers, int count);
std::string getNameSorting(const int size, const int range);
void readFile(std::vector<int>& numbers, const std::string nameFile);





void outputnum(std::vector<int> numbers);
