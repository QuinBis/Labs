#include <iostream>
#include <assert.h>

#include "BoolVector.h"

BoolVector::BoolVector(const int& length, const int& value)
{
	assert(length >= 0);
	m_length = length;
	
	m_cellCount = length / 8 + (length % 8 ? 1 : 0);
	m_unsignificantRankCount = (m_cellCount * 8) - m_length;
	m_cells = new uint8_t[m_cellCount];

	if (value) {
		
		for (int i = 0; i < m_cellCount; i++)
			m_cells[i] = 255;
	}

	else {

		for (int i = 0; i < m_cellCount; i++)
			m_cells[i] = 0;

	}
	
	m_twitching();

}

BoolVector::BoolVector(const BoolVector& other) :
	m_length(other.m_length),
	m_cellCount(other.m_cellCount),
	m_unsignificantRankCount(other.m_unsignificantRankCount)
{
	m_cells = new uint8_t[m_cellCount];
	
	for (int i = 0; i < m_cellCount; i++) {
		m_cells[i] = other.m_cells[i];
	}

}

BoolVector::BoolVector(const char* other)
{
	assert(strlen(other) != 0);

	m_length = strlen(other);
	m_cellCount = m_length / 8 + (m_length % 8 ? 1 : 0);
	m_unsignificantRankCount = (m_cellCount * 8) - m_length;
	m_cells = new uint8_t[m_cellCount];

	for (unsigned int i = 0; i < m_length; i++) {
		if (other[i] != '0')
			set(i, 1);
		else
			set(i, 0);
	}
}

BoolVector::~BoolVector() {
	delete m_cells;
}

void BoolVector::m_twitching()
{
	m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
	m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
}

void BoolVector::printVector() const
{
	std::cout << *this;
}

void BoolVector::scanVector(const int& length)
{
	assert(length != 0);

	if (length < 0) {
		std::cerr << "BoolVector::scanVector : legnth is negative, invert...";
		m_length = -length;
	}
	else {
		m_length = length;
	}

	BoolVector temp(m_length, 0);
	std::cin >> temp;
	this->swap(temp);

	m_twitching();
}

int BoolVector::getLength() const
{
	return m_length;
}

void BoolVector::set(const int& pos, const bool& value)
{
	assert(pos >= 0 && pos < m_length);

	int currentCell = pos / 8,
		position = pos % 8;

	uint8_t mask = 1;
	mask <<= 7 - position;
	
	if (value) {
		m_cells[currentCell] |= mask;
	}
	else {
		m_cells[currentCell] = m_cells[currentCell] & ~mask;
	}

}

void BoolVector::swap(BoolVector& other)
{
	std::swap(m_length, other.m_length);
	std::swap(m_cellCount, other.m_cellCount);
	std::swap(m_unsignificantRankCount, other.m_unsignificantRankCount);
	std::swap(m_cells, other.m_cells);
}

void BoolVector::invert()
{	
	int pos = 0;
	for (int i = 0; i < m_cellCount; i++) {

		for (uint8_t m = 1 << 7 ; m > 0; m >>= 1) {

			if (m_cells[i] & m) {
				set(pos, 0);
			}
			
			else {
				set(pos, 1);
			}
			pos++;
		}
	}

	m_twitching();
}

inline std::ostream& operator<<(std::ostream& stream, const BoolVector& object)
{
	for (int i = 0; i < object.m_cellCount; i++) {

		stream << "[";

		for (uint8_t j = 1 << 7; j > 0; j >>= 1) {

			if (object.m_cells[i] & j) {
				stream << "1";

			}

			else {
				stream << "0";
			}

		}

		stream << "] ";
	}

	return stream;
}

inline std::istream& operator>>(std::istream& stream, BoolVector& object)
{
	char* temporaryString = new char[object.m_length];

	for (int i = 0; i < object.m_length; i++) {
		stream >> temporaryString[i];
	}
	

	for (int i = 0; i < object.m_length; i++) {
		if (temporaryString[i] != '0')
			object.set(i, 1);

		else {
			object.set(i, 0);
		}
	}

	delete[] temporaryString;

	object.m_twitching();

	return stream;
}