class Array {
public:
	class Iterator;

public:
	Array(const int size = 10, const int value = 0);					// Конструктор по умолчанию 
	Array(const int* array, const int size);							// Конструктор из обычного массива	
	Array(const Array& other);											// Конструктор копирования
	~Array();															// Деструктор

	int getSize() const;												// Получить количество хранимых элементов

	void swap(Array& other);											// Обмен содержимого с другим массивом

	int getIndex(const int value) const;								// Поиск индекса элемента по значению

	void printArray() const;											// Вывод в консоль
	void scanArray(const int size);										// Ввод с консоли

	void sort() const;													// Шейкерная сортировка

	bool insert(const int index, const int value);						// Вставка элемента по индексу
	bool erase(const int index);										// Удаление элемента по индексу
	bool eraseFirst(const int value);									// Удаление элемента по значению
	bool eraseAll(const int value);										// Удаление всех элементов по значению

	int getMaxValue() const;											// Получение максимального элемента
	int getMinValue() const;											// Получение минимального элемента

	void setRandom(const int min, const int max) const;					// Генерация последовательности от-до
	void setIncrease() const;											// Генерация возрастающей последовательности
	void setDecrease() const;											// Генерация убывающей последовательности

	Array& operator = (const Array& other);								// Оператор присваивания
	int& operator [] (const int index) const;							// Получение ссылки на элемент по индексу

	bool operator == (const Array& other) const;						// Сравнение двух массивов
	bool operator != (const Array& other) const;						// Несравнение двух массивов

	Array operator + (const Array& other) const;						// Конкатенация A = B + C	
	Array& operator += (const Array& other);							// Конкатенация A += B

	Array operator + (const int value);									// Добавление элемента в конец массива A = B + 5
	Array& operator += (const int value);								// Добавление элемента в конец массива A += 5

	Iterator begin();													// Получение итератора на начало
	Iterator end();														// Получение итератора на конец

	Iterator insert(const Iterator& other, const int value);
	Iterator erase(const Iterator& other, const Iterator& otherTwo);

	void resize(int size);

private:
	int* m_array = nullptr;
	int m_size = 0;
};

std::ostream& operator<<(std::ostream& stream, const Array& arr);
std::istream& operator>>(std::istream& stream, Array& arr);


class Array::Iterator
{
public:

	friend class Array;

	Iterator(Array* array = nullptr, const int position = 0);			// Конструктор по умолчанию

	int& operator*();													// Оператор разыменовования 
	int getPosition() const;											// Получение позиции итератора

	Iterator& operator++();												// Увеличить на 1 позицию итератора
	Iterator operator++(int);											// прибавить после 1

	Iterator &operator += (const int &value);							// Сместить итератора на позиций

	bool operator == (const Iterator& other) const;						// Равенство итераторов
	bool operator != (const Iterator& other) const;						// Неравенство итераторов


private:
	Array* m_array = nullptr;
	int m_pos = 0;
};
