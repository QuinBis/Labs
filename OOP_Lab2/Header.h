#pragma once



class Array {

public:
	Array(const int size, const int value);
	Array(const int* array, const int size);
	Array(const Array &other);
	~Array();


	int getSize() const;
	int getIndexElement(const int value) const;
	int getIndexMaxElement() const;
	int getIndexMinElement() const;

	void printArray() const;
	void scanArray(const int size);

	void sort(); // shaker sort.

	void setRandom(const int min, const int max);
	void setIncreaseRandom();
	void setDecreaseRandom();
	

	bool addElementByIndex(const int index, const int value);
	bool popElementByIndex(const int index);
	bool popFirstElementByValue(const int value);
	bool popAllElementsByValue(const int value);

	int &operator [] (const int index);
	Array &operator = (const Array &other);
	Array operator + (const Array &other);
	Array &operator += (const Array &other);
	Array operator + (const int value);
	Array &operator += (const int value);
	
	bool operator == (const Array &other) const;
	bool operator != (const Array &other) const;



private:
	int* m_array;
	int m_size;
};