#pragma once



class Array {

public:
	Array(const int size, const int value);
	Array(const int* array, const int size);
	Array(const Array &other);
	~Array();


	int getSize() const;
	int getIndexElement(const int value) const;
	int getIndexMaxElement();
	int getIndexMinElement();

	void printArray() const;
	void scanArray(const int size);

	void sort(); // shaker sort.

	bool addElementByIndex(const int index, const int value);
	bool popElementByIndex(const int index);
	bool popFirstElementByValue(const int value);
	bool popAllElementsByValue(const int value);

	int &operator [] (const int index);
	Array &operator = (const Array &other);



private:
	int* m_array;
	int m_size;
};