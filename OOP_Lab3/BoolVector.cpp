#include <iostream>
#include <assert.h>

#include "BoolVector.h"

/* bool vector */

BoolVector::BoolVector(const int length, const bool value)
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

BoolVector::BoolVector(const BoolVector& object) :
	m_length(object.m_length),
	m_cellCount(object.m_cellCount),
	m_unsignificantRankCount(object.m_unsignificantRankCount)
{
	m_cells = new uint8_t[m_cellCount];
	
	for (int i = 0; i < m_cellCount; i++) {
		m_cells[i] = object.m_cells[i];
	}

}

BoolVector::BoolVector(const char* other)
{
	assert(strlen(other) >= 0);

	m_length = strlen(other);
	m_cellCount = m_length / 8 + (m_length % 8 ? 1 : 0);
	m_unsignificantRankCount = (m_cellCount * 8) - m_length;
	m_cells = new uint8_t[m_cellCount];

	for (int i = 0; i < m_length; i++) {
		if (other[i] != '0')
			set(i, 1);
		else
			set(i, 0);
	}
}

BoolVector::~BoolVector() {
	delete m_cells;
}

void BoolVector::printVector() const
{
	std::cout << *this;
}

void BoolVector::scanVector(const int length)
{
	assert(length != 0);

	if (length < 0) {
		std::cerr << "BoolVector::scanVector : length is negative, invert...";
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

void BoolVector::m_twitching()
{
	m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
	m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
}

int BoolVector::getLength() const
{
	return m_length;
}

int BoolVector::getWeight() const
{
	int countWeight = 0;

	for (int i = 0; i < m_cellCount; ++i) {

		for (uint8_t mask = 1 << 7; mask != 0; mask >>= 1) {

			if (m_cells[i] & mask)
				++countWeight;
		}
	}
	return countWeight;
}

void BoolVector::set(const int pos, const bool value)
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

void BoolVector::set(const int start, const int end, const bool value) {
	assert(start >= 0 && end < m_length);
	assert(start <= end);

	for (int i = start; i <= end; ++i) {
		(*this)[i] = value;
	}

}

void BoolVector::set(const bool value) {
	for (int i = 0; i < m_cellCount; ++i) {
		if (value)
			m_cells[i] = 255;
		else
			m_cells[i] = 0;
	}
	m_twitching();
}

void BoolVector::swap(BoolVector& object)
{
	std::swap(m_length, object.m_length);
	std::swap(m_cellCount, object.m_cellCount);
	std::swap(m_unsignificantRankCount, object.m_unsignificantRankCount);
	std::swap(m_cells, object.m_cells);
}

void BoolVector::invert() {
	*this = ~(*this);
	m_twitching();
}

void BoolVector::invert(const int index)
{
	assert(index >= 0 && index < m_length);

	(*this)[index] = ~(*this)[index];
}

BoolVector& BoolVector::operator = (const BoolVector& object) {

	if (this != &object) {
		delete[] m_cells;
		m_length = object.m_length;
		m_cellCount = object.m_cellCount;
		m_unsignificantRankCount = object.m_unsignificantRankCount;
		m_cells = new uint8_t[object.m_cellCount];

		for (int i = 0; i < m_cellCount; ++i) {
			m_cells[i] = object.m_cells[i];
		}
	}

	return *this;

}

BoolVector::BoolRank BoolVector::operator [] (const int index)
{
	assert(index >= 0 && index < m_length);

	return BoolRank(m_cells + index / 8, index % 8);
}

const BoolVector::BoolRank BoolVector::operator [] (const int index) const
{
	assert(index >= 0 && index < m_length);

	return BoolRank(m_cells + index / 8, index % 8);
}

BoolVector BoolVector::operator & (const BoolVector& object) const
{
	assert(m_length == object.m_length);

	BoolVector newVector(*this);

	for (int i = 0; i < m_cellCount; ++i) {
		newVector.m_cells[i] = m_cells[i] & object.m_cells[i];
	}

	return newVector;
}

BoolVector& BoolVector::operator &= (const BoolVector& object)
{
	*this = *this & object;
	return *this;
}

BoolVector BoolVector::operator | (const BoolVector& object) const
{
	assert(m_length == object.m_length);

	BoolVector newVector(object);

	for (int i = 0; i < m_cellCount; i++) {
		newVector.m_cells[i] = m_cells[i] | object.m_cells[i];
	}

	return newVector;
}

BoolVector& BoolVector::operator |= (const BoolVector& object)
{
	*this = *this | object;
	return *this;
}

BoolVector BoolVector::operator ^ (const BoolVector& object) const
{
	assert(m_length == object.m_length);

	BoolVector newVector(object);

	for (int i = 0; i < m_cellCount; ++i) {
		newVector.m_cells[i] = m_cells[i] ^ object.m_cells[i];
	}

	return newVector;
}

BoolVector& BoolVector::operator ^= (const BoolVector& object)
{
	*this = *this ^ object;
	return *this;
}

BoolVector BoolVector::operator ~ () const
{
	BoolVector newVector(*this);

	for (int i = 0; i < m_cellCount; i++) {
		newVector.m_cells[i] = ~newVector.m_cells[i];
	}

	return newVector;
}

BoolVector& BoolVector::operator >>= (int value)
{
	assert(value >= 0 && value <= m_length);

	if (value > 7) {
		for (int i = m_cellCount - 1; i >= 1; --i) {
			m_cells[i] = m_cells[i - value / 8];
		}
		for (int i = 0; i < value / 8; ++i) {
			m_cells[i] = 0;
		}
		value = value % 8;
	}

	if (value > 0) {

		uint8_t mask;

		for (int i = m_cellCount - 1; i > 0; i--) {
			m_cells[i] >>= value;
			mask = m_cells[i - 1];
			mask <<= (8 - value);
			m_cells[i] |= mask;
		}

		m_cells[0] >>= value;
	}

	m_twitching();
	return *this;
}

BoolVector& BoolVector::operator <<= (int value)
{
	assert(value >= 0 && value <= m_length);

	if (value > 7) {

		for (int i = 0; i < m_cellCount - value / 8; ++i) {
			m_cells[i] = m_cells[i + value / 8];
		}

		for (int i = 1; i <= value / 8; ++i) {
			m_cells[m_cellCount - i] = 0;
		}

		value %= 8;
	}

	if (value > 0) {

		uint8_t mask;

		for (int i = 0; i < m_cellCount-1; i++) {

			m_cells[i] <<= value;
			mask = m_cells[i + 1];
			mask >>= (8 - value);
			m_cells[i] |= mask;
		}

		m_cells[m_cellCount - 1] <<= value;
	}
	
	
	return *this;
}

BoolVector BoolVector::operator << (const int value) const
{
	BoolVector newVector(*this);
	newVector <<= value;
	return newVector;
}

BoolVector BoolVector::operator >> (const int value) const {
	BoolVector result(*this);
	result >>= value;
	return result;
}

/* bool rank */

BoolVector::BoolRank::BoolRank(uint8_t* currCell, const int& position)
{
	m_currentCell = currCell;
	m_mask >>= position;
}

BoolVector::BoolRank& BoolVector::BoolRank::operator = (const bool value)
{
	if (value)
		(*m_currentCell) |= m_mask;
	else
		(*m_currentCell) &= ~m_mask;

	return *this;
}

BoolVector::BoolRank& BoolVector::BoolRank::operator = (const BoolRank& object)
{
	return *this = ( (bool)object );
}

BoolVector::BoolRank::operator bool() const
{

	if ( m_mask & (*m_currentCell) ) // is true
		return true;

	return false;
}

bool BoolVector::BoolRank::operator == (const BoolRank& object) const
{
	return ( *this == ( (bool)object) );
}

bool BoolVector::BoolRank::operator == (const bool value) const
{
	return (bool)*this == value;
}

bool BoolVector::BoolRank::operator & (const bool value) const
{
	if (!value)
		return false;
	return (bool)(*m_currentCell) & m_mask;
}

bool BoolVector::BoolRank::operator ^ (const bool value) const
{
	return (bool)(*this) ^ value;
}

bool BoolVector::BoolRank::operator ~ () const
{
	return !(this->operator bool());
}

// output/input

std::ostream& operator << (std::ostream& stream, const BoolVector& object)
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

std::istream& operator >> (std::istream& stream, BoolVector& object)
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