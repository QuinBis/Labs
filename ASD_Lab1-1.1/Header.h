#pragma once


int** createMatrix(int rows);
void destroyMatrix(int** matrix, int cols);
void outputMatrix(int** matr, int rows);
void generateRandomMatrix(int** matr, int rows);
void inputMatrix(int** matrix, int cols);
void copyMatrix(int** matrixFrom, int** matrixTo, int quantityCities);
int indexMinNumberInRow(int** matrix, int quantityCities, int row);


int* createArray(int cols);
void destroyArray(int* array, int cols);
void outputArray(int* array, int cols);
void copyArray(int* arrayFrom, int* arrayTo, int size);



int computeCostWay(int* array, int** matrix, int cols);

void swapValues(int& firstValue, int& secondValue);

void exactAlgorithm(int** matrixOne, int quantityCities,int* maxLength,int* minLength, int startCity);
void heuristicAlgorithm(int** matrixOne, int quantityCities,int* heuristicWay, int startCity);