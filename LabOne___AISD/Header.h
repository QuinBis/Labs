#pragma once


int** CreatingMatric(int rows); // Создание динамической матрицы
void RemovingMatric(int** matric, int cols); // Освобождение памяти от матрицы.
void OutputMatric(int** matr, int rows, int cols); // Вывод элементов матрицы.
void OutputArray(int* array, int cols); // Вывод элементов массива.
void CopyArray(int* array_from, int * array_to, int size); // Копировать значения из массива A в массив B
void RundNumMatric(int** matr, int rows); // Генерация матрицы с различными значениями её элементов
void InputMatric(int ** matric, int cols); // Ввод матрицы с клавиатуры
void RemovingArray(int* array, int cols); // Освобождение памяти от динамического массива
int* CreatingArray(int cols); // Создание динамического массива
int Factorial(int num); // Вычисление факториала от числа num

