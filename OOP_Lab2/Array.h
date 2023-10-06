#pragma once



class Array {
public:
	class Iterator;

public:
	Array(const int size = 10, const int value = 0);
	Array(const Array &other);
	Array(Array &&other);
	~Array();

	Iterator begin();
	Iterator end();
	Iterator insert(const Iterator &other, const int value);
	Iterator erase(const Iterator &other, const Iterator &otherTwo);

	int getSize() const;
	
	int getIndex(const int value) const;
	int getIndexMax() const;
	int getIndexMin() const;

	void printArray() const;
	void scanArray(const int size);
	void sort() const;

	bool insert(const int index, const int value);

	void setRandom(const int min, const int max) const;
	void setIncrease() const;
	void setDecrease() const;

	void swapArrays(Array &other);

	bool erase(const int index);
	bool eraseFirst(const int value);
	bool eraseAll(const int value);

	int &operator [] (const int index) const;

	Array &operator = (const Array &other); // A = B
	Array operator + (const Array &other) const; // A = B + C
	Array &operator += (const Array &other); // A += B

	Array operator + (const int value);
	Array &operator += (const int value);
	
	bool operator == (const Array &other) const;
	bool operator != (const Array &other) const;

	void resize(int size);



private:
	int* m_array;
	int m_size;
};

std::ostream &operator<<(std::ostream &stream, const Array &arr);
std::istream &operator>>(std::istream &stream, Array &arr);


class Array::Iterator
{
public:
	
	friend class Array;

	Iterator(Array *array, const int position);

	int &operator*();

	Iterator &operator++();
	Iterator operator++(int);

	bool operator==(const Iterator &other) const;
	bool operator!=(const Iterator &other) const;


private:
	Array *m_array = nullptr;
	int m_pos = 0;
};
