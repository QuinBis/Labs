#pragma once

int** createMatrix(int rows);
void destroyMatrix(int** matrix, int cols);
void outputMatrix(int** matr, int rows);
void generateRandomMatrix(int** matr, int rows);
void inputMatrix(int ** matrix, int cols);

void outputArray(int* array, int cols);
void copyArray(int* arrayFrom, int* arrayTo, int size);
void destroyArray(int* array, int cols);
int* createArray(int cols);



int computeCostWay(int* array, int** matrix, int cols);

void swapValues(int& firstValue, int& secondValue);

void completionProgramm();

void exactAlgorithm(int quantityCities, int startCity);

