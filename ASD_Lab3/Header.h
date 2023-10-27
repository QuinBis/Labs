#pragma once

void setRandomNumbers(std::vector<int>& numbers, int size, int min, int max);

bool isSorted(const std::vector<int> numbers);

void sorting(std::vector<int>& numbers, const int step);
void stepsShell(std::vector<int>& numbers);
void stepsPapernovStasevich(std::vector<int>& numbers);
void stepsHibbard(std::vector<int>& numbers);

void createFile(std::vector<int>& numbers, const std::string nameFile);
std::string getNameSorting(const int count);





void outputnum(std::vector<int> numbers);
