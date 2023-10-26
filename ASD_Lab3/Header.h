#pragma once

int* createArray(int cols);
void outputArray(int* array, int cols);
void setRundArray(int* array, int size, int max, int min);
void setIncrease(int* array, int size);
void setDecrease(int* array, int size);

bool isSorted(int* array, int size);

std::vector<int> shellSort(int* array, int size);