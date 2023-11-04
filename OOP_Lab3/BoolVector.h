#pragma once

class BoolVector{
	friend std::ostream& operator<<(std::ostream& stream, const BoolVector& object);
	friend std::istream& operator>>(std::istream& stream, BoolVector& object);
public:

	BoolVector(const int& length = 8, const int& value = 0);
	BoolVector(const char* other);
	BoolVector(const BoolVector& other);
	~BoolVector();

	void printVector() const;
	void scanVector(const int& length);

	int getLength() const;

	void set(const int& pos, const bool& value);

	void swap(BoolVector& other);

	void invert();


private:

	void m_twitching();

	unsigned int m_length = 0; // Длина вектора.
	unsigned int m_cellCount = 0; // Количество ячеек.

	uint8_t* m_cells = nullptr; // Ячейки
	uint8_t m_unsignificantRankCount = 0; // Количество незначащих нулей.

};
