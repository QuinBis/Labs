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
	one.scanArray(5);
	std::cout << one << std::endl;

	one.insert(5, 10);
	std::cout << one << std::endl;
	// Изначальный массив [2, 3, 5, 9, 10]
	// После использования метода insert -> [0, 2, 3, 5, 9, 10]
	// Итератор it2 остался также указывать на 2 (по условию). 






	

	return 0;
}