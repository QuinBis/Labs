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

	std::cout << "Введите количество городов : "; std::cin >> numberCities;
	std::cout << "Укажите начальный город : "; std::cin >> startCity;

	int **MatricWays = CreatingMatric(numberCities, numberCities);

	RundNumMatric(MatricWays, numberCities, numberCities);

	OutputMatric(MatricWays, numberCities, numberCities);

	







	// Освобождение памяти от динамической матрицы.
	RemovingMatric(MatricWays, numberCities);
	

	return 0;
}