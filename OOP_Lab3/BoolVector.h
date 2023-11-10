#pragma once

class BoolVector{

	friend std::ostream& operator<<(std::ostream& stream, const BoolVector& object);
	friend std::istream& operator>>(std::istream& stream, BoolVector& object);
	
private:

	class BoolRank;

public:

	BoolVector(const int length = 8, const bool value = false);
	BoolVector(const char* other);
	BoolVector(const BoolVector& object);
	~BoolVector();

	void printVector() const;
	void scanVector(const int length);

	int getLength() const;
	int getWeight() const;

	void mcell() {
		std::cout << m_cellCount << std::endl;
	}

	void set(const int pos, const bool value);
	void set(const int start, const int end, const bool value);
	void set(const bool value);

	void swap(BoolVector& object);

	void invert();
	void invert(const int index);

	BoolRank operator [] (const int index);
	const BoolRank operator [] (const int index) const;

	BoolVector operator & (const BoolVector& other) const;
	BoolVector& operator &= (const BoolVector& other);

	BoolVector operator | (const BoolVector& other) const;
	BoolVector& operator |= (const BoolVector& other);

	BoolVector operator ^ (const BoolVector& other) const;
	BoolVector& operator ^= (const BoolVector& other);

	BoolVector operator ~ () const;

	BoolVector operator >> (const int value) const;
	BoolVector operator << (const int value) const;
	BoolVector& operator >>= (int value);
	BoolVector& operator <<= (int value);

	BoolVector& operator = (const BoolVector& object); 

private:

	void m_twitching();

	unsigned int m_length = 0;
	unsigned int m_cellCount = 0; 

	uint8_t* m_cells = nullptr;
	uint8_t m_unsignificantRankCount = 0; 

};

class BoolVector::BoolRank {
public:
	BoolRank(uint8_t* currCell, const int& position);

	BoolRank& operator = (const BoolRank& other);
	BoolRank& operator = (const bool value);

	bool operator == (const BoolRank& object) const;
	bool operator == (const bool value) const;

	bool operator & (const bool value) const;
	bool operator ^ (const bool value) const;
	bool operator ~ () const;

	operator bool() const; 

private:
	uint8_t* m_currentCell = nullptr;
	uint8_t m_mask = 1 << 7;
};

std::ostream& operator << (std::ostream& stream, const BoolVector& object);
std::istream& operator >> (std::istream& stream, BoolVector& object);