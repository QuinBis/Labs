#include <iostream>
#include <time.h>
#include <math.h>

#include "Header.h"

// Число всевозможных гамильтоновых циклов без повторений = (n-1)! (как только набираем такое количество - завершаем цикл)
// Решение задачи основано на алгоритме Дейкстры.

int main() {

	//setlocale(0, "Russian"); // Для вывода русских символов в консоль.

	/*========================Инициализация переменных========================*/

	int numberCities, startCity, waylength = 0, minlength = 0;

	std::cout << "Введите количество городов : "; std::cin >> numberCities; int numberofcycles = Factorial(numberCities - 1);
	std::cout << "Укажите начальный город : "; std::cin >> startCity; std::cout << "\n";

	int **MatricWays = CreatingMatric(numberCities);
	//InputMatric(MatricWays, numberCities);
	RundNumMatric(MatricWays, numberCities);
	OutputMatric(MatricWays, numberCities, numberCities);


	// Массив Ways для генерации путей, его размер должен быть numberCities+1 (Поскольку строится цепочка 1-2-3-1).
	// Массив minimumWay для записи маршрута с минимальной стоимостью.
	int *Ways = CreatingArray(numberCities + 1), *minimumWay = CreatingArray(numberCities + 1);




	/* ===================== Генерация первого пути и вычисление стоимости маршрута ========================= */

	for (int i = 0, countCities = 1, previndex = 0; i < numberCities;) {

		if (i == 0) { // Меняем значение 1 и последних элементов на значение начального города.

			Ways[i] = startCity;
			Ways[numberCities] = startCity;
			i++;

		}

		else if (countCities == startCity) { countCities++; } // Если текущий город = начальному, увеличить текущий город на 1.

		else { // Во всех иных случаях, просто выставляем города, ошибок не будет.

			previndex = i - 1;

			Ways[i] = countCities;

			waylength += MatricWays[Ways[previndex] - 1][Ways[i] - 1];

			countCities++;

			i++;

		}
	}

	waylength += MatricWays[Ways[numberCities - 1] - 1][Ways[numberCities] - 1];
	OutputArray(Ways, numberCities + 1);
	std::cout << "\nСтоимость этого маршрута : " << waylength << std::endl;

	minlength = waylength; // Сразу берем первый маршрут за минимальный, в последующем будем сравнивать.
	OutputArray(Ways, numberCities + 1);

	// Реализация алгоритма Дейкстры.






	// Освобождение памяти от динамической матрицы.
	RemovingArray(Ways, numberCities + 1);
	RemovingArray(minimumWay, numberCities + 1);
	RemovingMatric(MatricWays, numberCities);


	return 0;
}