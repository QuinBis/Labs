#pragma once


int** CreatingMatric(int rows);
void RemovingMatric(int** matric, int cols); // Освобождение памяти от матрицы.
void OutputMatric(int** matr, int rows, int cols); // Вывод элементов матрицы.
void OutputArray(int* array, int cols); // Вывод элементов массива.
void CopyArray(int* array_from, int * array_to, int size);
void RundNumMatric(int** matr, int rows);
void InputMatric(int ** matric, int cols);
void RemovingArray(int* array, int cols);
int* CreatingArray(int cols);
int Factorial(int num);