#include <iostream>
#include <time.h>
#include <math.h>

#include "Header.h"

// Число всевозможных гамильтоновых циклов без повторений = (n-1)! (как только набираем такое количество - завершаем цикл)
// Решение задачи основано на алгоритме Дейкстры.

int main() {
	setlocale(0, "Russian"); // Для вывода русских символов в консоль.

	/*========================Инициализация переменных========================*/

	int numberCities, startCity;

	std::cout << "Укажите количество городов : "; std::cin >> numberCities;
	//std::cout << "Введите начальный город : "; std::cin >> startCity;


	// Создание и выделение памяти под динамическую матрицу.
	int **matriс = CreatingMatr(numberCities, numberCities);

	RundNumMatr(matriс, numberCities, numberCities);
	OutputMatr(matriс, numberCities, numberCities);

	//int **Road = CreatingMatr(factorial)
	
	int kolvociklov = Factorial(numberCities - 1);

	int **Road = CreatingMatr( kolvociklov , numberCities); // 1 аргумент - количество циклов всевозможных, 2 - количество вершин

	for (int i = 0; i < kolvociklov; i++) {
		Road[i][0] = startCity;
	}

	for (int i = 0; i < kolvociklov; i++) {
		for
	}




	// Освобождение памяти от динамической матрицы.
	RemovingMatr(matriс, numberCities);


	return 0;
}