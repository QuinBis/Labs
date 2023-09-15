#include <iostream>
#include <time.h>
#include <math.h>

#include "Header.h"

// Число всевозможных гамильтоновых циклов без повторений = (n-1)! (как только набираем такое количество - завершаем цикл)
// Решение задачи основано на алгоритме Дейкстры.


int main(int) {

	/*========================Инициализация переменных========================*/

	int numberCities, startCity, waylength = 0, minlength = 0;

	std::cout << "Enter the number of cities : "; std::cin >> numberCities;
	std::cout << "Enter the starting city : "; std::cin >> startCity; std::cout << "\n";

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
			minimumWay[numberCities] = startCity;
			minimumWay[i] = startCity;
			i++;
		}

		else if (countCities == startCity) { countCities++; } // Если текущий город = начальному, увеличить текущий город на 1.

		else { // Во всех иных случаях, просто выставляем города, ошибок не будет.
			Ways[i] = countCities;
			countCities++;
			i++;
		}
	}

	std::cout << "\nThe first way looks like this : ";
	OutputArray(Ways, numberCities + 1);
	waylength = CostOfTheWay(Ways, MatricWays, numberCities);
	std::cout << "\nThe cost of the way : : " << waylength << std::endl;

	minlength = waylength; // Сразу берем стоимость первого маршрута за минимальную, в последующем будем сравнивать.
	CopyArray(Ways, minimumWay, numberCities); // Запоминаем и сам маршрут.

	// Реализация алгоритма Дейкстры.

	int numberofcycles = Factorial(numberCities-1); // Будем выполнять цикл (n-1)! раз, больше не имеет смысла. (n-1)! - количество всевозможных ПРАВИЛЬНЫХ циклов.

	int countCycles = 1;

	while (countCycles != numberofcycles) {
		/* ============= Начанием построение нового маршрута ============ */
		for (int i = numberCities-2; i >= 1; i--) {
			int next_index = i + 1;
			// Ищем первый элемент , начинаю со второго по счету города, этот город должен быть младше следующего.
			if ( (i < numberCities-1) && (Ways[i] < Ways[next_index]) ) { 
				// Как только нашли такой город, начинаем искать второй.
				for (int j = numberCities - 1; j > i;j--) {
					// Следующий город ищем с конца, этот город должен быть старше по значению чем первый.
					if ( ( j <= numberCities-1) && ( Ways[i] < Ways[j] )) {

						// Теперь меняем местами города
						// И считаем сумму нового маршурат, в случае если этот маршрут оказался дешевле, запоминаем его.
						
						SwapElementInArray(Ways[i], Ways[j]);
						for (int invert_i = i + 1, invert_j = numberCities - 1; invert_i <= invert_j;invert_i++,invert_j--) {
								SwapElementInArray(Ways[invert_i], Ways[invert_j]);
							}

						waylength = CostOfTheWay(Ways, MatricWays, numberCities);

						if (minlength > waylength) {
							minlength = waylength;
							CopyArray(Ways, minimumWay, numberCities);
						}

						std::cout << "\nCompleted permutation : ";
						OutputArray(Ways, numberCities+1);
						std::cout << "\nThe cost of the way : " << waylength << std::endl;
						i = numberCities - 1;
						countCycles++; // Показываем что мы сделали 1 перестановку
						std::cout << "There are permutations left : " << countCycles << std::endl;
					}
				}
			}



			
		}
	}
	


	std::cout << "\nThe minimum cost way is : "; OutputArray(minimumWay, numberCities+1);
	std::cout << "\nIts cost will be as follows : " << minlength << std::endl;



	// Освобождение памяти от динамической матрицы.
	RemovingArray(Ways, numberCities + 1);
	RemovingArray(minimumWay, numberCities + 1);
	RemovingMatric(MatricWays, numberCities);


	return 0;
}