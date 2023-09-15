#include <iostream>
#include <time.h>
#include <math.h>

#include "Header.h"

// Число всевозможных гамильтоновых циклов без повторений = (n-1)! (как только набираем такое количество - завершаем цикл)
// Решение задачи основано на алгоритме Дейкстры.

int main() {

	setlocale(0, "Russian"); // Для вывода русских символов в консоль.

	/*========================Инициализация переменных========================*/
	
	int numberCities, startCity, waylength = 0, minlength = 0;

	std::cout << "Введите количество городов : "; std::cin >> numberCities; int numberofcycles = Factorial(numberCities - 1);
	std::cout << "Укажите начальный город : "; std::cin >> startCity;

	int **MatricWays = CreatingMatric(numberCities);
	InputMatric(MatricWays, numberCities);
	//RundNumMatric(MatricWays, numberCities);
	OutputMatric(MatricWays, numberCities, numberCities);

	
	// Массив Ways для генерации путей, его размер должен быть numberCities+1 (Поскольку строится цепочка 1-2-3-1)
	int *Ways = CreatingArray(numberCities + 1), *minimumWay = CreatingArray(numberCities + 1);

	// Генерация первого пути и вычисление стоимости маршрута.

	int i = 0, index = 0, countCities = 1;

	while (index != (numberCities + 1) ) {

		if (index == 0 or index == numberCities + 1){  // Первый и конечный город в цепочке равен начальному.

			Ways[index] = startCity;
			index++;

		}

		else if ((Ways[--index] == startCity) and (countCities < startCity)) { // Исключение второй  по очереди город в цепочке.

			Ways[index] = countCities;
			index++;
			countCities++;
		}

		else if (countCities > Ways[--index]) {// если следующий город > больше предыдущего

			Ways[index] = countCities;
			index++;
			countCities;

		}







	}
	
	OutputArray(Ways, numberCities + 1);



	// Реализация алгоритма Дейкстры.

	//for (int i = 0; i < numberofcycles; i++) {}






	// Освобождение памяти от динамической матрицы.
	RemovingMatric(MatricWays, numberCities);
	

	return 0;
}