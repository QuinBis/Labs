
#include <iostream>
#include <time.h>

#include "Header.h"

// Функции написаны исключительно для решения задачи коммивояжёра.

int** CreatingMatric(int rows) { // Выделение памяти под динамическую матрицу (квадратную)

	int **A;

	A = new int*[rows];

	for (int i = 0; i < rows; i++)

		A[i] = new int[rows];

	return A;

}

void RemovingMatric(int** matric, int cols) { // Освобождение памяти от динамической матрицы

	for (int i = 0; i < cols;i++) {

		delete[]matric[i];

	}

	delete[]matric;

}

void InputMatric(int** matric, int cols) { // Ввод значений элементов матрицы (стоимость путей).

	for (int i = 0; i < cols; i++) {

		for (int j = 0; j < cols; j++) {

			if (i != j) { // Ввод с клавиатуры стоимости пути из города i в город j.

				std::cout << "Укажите стоимость пути из города " << i << " в город " << j << " : ";

				std::cin >> matric[i][j];

			}

			else { // Из одного города в этот же вернуться нельзя.

				matric[i][j] = 0;

				std::cout << "Стоимость пути из города " << i << " в город " << j << " равна 0" << std::endl;

			}

		}

	}


}

int* CreatingArray(int cols) { // Выделение памяти под динамический массив.

	int* A;

	A = new int[cols];

	return A;

}

void RemovingArray(int* array, int cols) { // Освобождение памяти от динамического массива.

	delete[]array;

}

void OutputArray(int* array, int cols) { // Вывод элементов массива.

	for (int* pointer = array; pointer < array + cols; pointer++) {

		std::cout << *pointer << " ";

	}


}

void OutputMatric(int** matr, int rows, int cols) { // Вывод матрицы на экран.

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			std::cout << matr[i][j] << " ";
		}
		std::cout << "\n";
	}
}



void CopyArray(int* array_from, int * array_to, int size) { // Копировать значение элементов

	for (int* pointer_from = array_from, *pointer_to = array_to; pointer_from < array_from + size;) {

		*(pointer_to)++ = *(pointer_from)++;

	}

}



// Возможна потеря данных? time_t в функции RundNumMatric...

void RundNumMatric(int** matr, int rows) { // Генерация значения элементов матрицы от 1-100.

	srand(time(0));

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < rows; j++) {

			if (i != j) matr[i][j] = rand() % (100) + 1;

			else matr[i][j] = 0;

		}
	}

}



int Factorial(int num) { // Вычисление факториала числа.

	if (num == 0)

		return 1;

	else {

		return num * Factorial(num - 1);

	}

}