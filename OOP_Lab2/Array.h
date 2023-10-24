class Array {
public:
	class Iterator;

public:
	Array(const int size = 10, const int value = 0);					// ����������� �� ��������� 
	Array(const int* array, const int size);							// ����������� �� �������� �������	
	Array(const Array& other);											// ����������� �����������
	~Array();															// ����������

	int getSize() const;												// �������� ���������� �������� ���������

	void swap(Array& other);											// ����� ����������� � ������ ��������

	int getIndex(const int value) const;								// ����� ������� �������� �� ��������

	void printArray() const;											// ����� � �������
	void scanArray(const int size);										// ���� � �������

	void sort() const;													// ��������� ����������

	bool insert(const int index, const int value);						// ������� �������� �� �������
	bool erase(const int index);										// �������� �������� �� �������
	bool eraseFirst(const int value);									// �������� �������� �� ��������
	bool eraseAll(const int value);										// �������� ���� ��������� �� ��������

	int getMaxValue() const;											// ��������� ������������� ��������
	int getMinValue() const;											// ��������� ������������ ��������

	void setRandom(const int min, const int max) const;					// ��������� ������������������ ��-��
	void setIncrease() const;											// ��������� ������������ ������������������
	void setDecrease() const;											// ��������� ��������� ������������������

	Array& operator = (const Array& other);								// �������� ������������
	int& operator [] (const int index) const;							// ��������� ������ �� ������� �� �������

	bool operator == (const Array& other) const;						// ��������� ���� ��������
	bool operator != (const Array& other) const;						// ����������� ���� ��������

	Array operator + (const Array& other) const;						// ������������ A = B + C	
	Array& operator += (const Array& other);							// ������������ A += B

	Array operator + (const int value);									// ���������� �������� � ����� ������� A = B + 5
	Array& operator += (const int value);								// ���������� �������� � ����� ������� A += 5

	Iterator begin();													// ��������� ��������� �� ������
	Iterator end();														// ��������� ��������� �� �����

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

	Iterator(Array* array = nullptr, const int position = 0);			// ����������� �� ���������

	int& operator*();													// �������� ��������������� 
	int getPosition() const;											// ��������� ������� ���������

	Iterator& operator++();												// ��������� �� 1 ������� ���������
	Iterator operator++(int);											// ��������� ����� 1

	Iterator &operator += (const int &value);							// �������� ��������� �� �������

	bool operator == (const Iterator& other) const;						// ��������� ����������
	bool operator != (const Iterator& other) const;						// ����������� ����������


private:
	Array* m_array = nullptr;
	int m_pos = 0;
};
