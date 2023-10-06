#include <iostream>

#include "Array.h"

// Создан массив по умолчанию.
// getMax и getMin при нулевом размере возвращают индекс -1
// Добавлен модификатор const в operator[], sort, setRandom, setIncreaseRandom, setDecreaseRandom,
// Переписана operator + (const int value);
// написан метод swapArray(Array &other);
// Реализован метод добавления элемента перед итератором.

int main() {

	Array one(5, 0);
	one.setRandom(100,500);
	one.printArray();

	for (auto it = one.begin(); it != one.end(); it++) {

	}

	


	

	return 0;
}