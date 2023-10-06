#include <iostream>
#include <assert.h>
#include <algorithm>
#include <time.h>

#include "Array.h"

Array::Array(const int size, const int value)
{

	if (size < 0) {
		std::cerr << "Array:Arrray: size is negative, invert..." << std::endl;
		m_size = -size;
	}
	else {
		m_size = size;
	}


	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++) {
		m_array[i] = value;
	}
}


Array::Array(const Array &other) : m_size(other.m_size)
{
	m_array = new int[m_size];

	for (int i = 0;i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}
}

Array::~Array() {
	delete[] m_array;
}

Array::Array(Array &&other)
{
	//m_size == 0, m_array == nullptr
	std::cout << "Array::Array(Array &&other): begin \n";
	swapArrays(other);
}

int Array::getSize() const
{
	return m_size;
}

void Array::printArray() const
{
	std::cout << *this;
}

void Array::scanArray(const int size)
{

	assert(size != 0);

	if (size < 0) {
		std::cerr << "Array::scanArray : size is negative, invert...";
		m_size = -size;
	}
	else {
		m_size = size;
	}
	
	Array temp(m_size,0);
	std::cin >> temp;
	this->swapArrays(temp);
}

void Array::resize(int size) {
	if (size < 0) {
		std::cerr << "ArraY::resize: size is negative, invert... \n";
		size = -size;
	}
	
	Array res(size);

	int count = std::min(m_size, size);
	for (int i = 0; i < count; ++i) {
		res.m_array[i] = m_array[i];
	}

	res.swapArrays(*this);
}

int Array::getIndex(const int value) const
{

	for (int i = 0; i < m_size; i++) {

		if (m_array[i] == value) {
			return i;
		}

	}

	return -1;
}

void Swap(int* x, int* y) {
	int value = *x;
	*x = *y;
	*y = value;
}

void Array::sort() const
{ // shaker Sort

	int i, j, k, n = m_size;

	for (i = 0; i < n - 1;) {

		for (j = i + 1; j < n; j++) {
			if (m_array[j - 1] > m_array[j])
				Swap(&m_array[j - 1], &m_array[j]);
		}

		n--;

		for (k = n - 1; k > i; k--) {
			if (m_array[k - 1] > m_array[k])
				Swap(&m_array[k - 1], &m_array[k]);
		}

		i++;

	}

}

bool Array::insert(const int index, const int value)
{

	if ( index < 0 || index > m_size) {
		std::cerr << "Array::addElementByIndex : index is invalid " << std::endl;
		return false;
	}

	int* temporaryArray = new int[m_size + 1];

	for (int i = 0, j = 0; i < m_size + 1; i++, j++) {

		if (i != index) {
			temporaryArray[i] = m_array[j];
		}

		else {
			temporaryArray[i] = value;
			j--;
		}

	}

	std::swap(m_array, temporaryArray);
	m_size++;
	
	return true;
}

bool Array::erase(const int index)
{

	if (index < 0 || index > m_size) {
		std::cerr << "Array::eraseByIndex : index is invalid " << std::endl;
		return false;
	}

	int* temporaryArray = new int[m_size - 1];

	for (int i = 0, j = 0; j < m_size - 1;) {

		if (i != index) {
			temporaryArray[j] = m_array[i];
			i++; j++;
		}
		else {
			i++;
		}

	}

	std::swap(m_array, temporaryArray);
	m_size--;

	return true;
}


bool Array::eraseFirst(const int value)
{

	for (int i = 0; i < m_size; i++) {
		
		if (m_array[i] == value) {
			erase(i);
			return true;
		}

	}

	return false;
}


bool Array::eraseAll(const int value)
{

	int* temporaryArray = new int[m_size];
	int newSize = 0;

	for (int i = 0, j = 0; i < m_size; i++, j++) {

		if (m_array[i] != value) {
			temporaryArray[j] = m_array[i];
			newSize++;
		}
		else {
			j--;
		}

	}

	std::swap(m_array, temporaryArray);
	std::swap(m_size, newSize);


	return true;
}

void Array::setRandom(const int min, const int max) const
{
	srand((unsigned int)time(0));

	for (int i = 0; i < m_size; i++) {
		m_array[i] = rand() % (max - min + 1) + min;
	}

}

void Array::setIncrease() const
{
	srand((unsigned int)time(0));

	m_array[0] = rand() % 10 + 1;

	for (int i = 1; i < m_size; i++) {
		m_array[i] = m_array[i - 1] + rand() % 5 + 1; // + (1 -> 5)
	}
}

void Array::setDecrease() const
{
	srand((unsigned int)time(0));

	m_array[m_size - 1] = rand() % 10 + 1;

	for (int i = m_size - 2; i >= 0; i--) {
		m_array[i] = m_array[i + 1] + rand() % +10 + 1; // + (1 -> 10)
	}

}

int Array::getIndexMax() const
{
	
	if (m_size == 0) {
		std::cerr << "Array::getIndexMinElement : size is 0..., returned -1";
		return -1;
	}

	int value = m_array[0],
		index = 0;

	for (int i = 0; i < m_size; i++) {

		if (m_array[i] > value) {

			value = m_array[i];
			index = i;

		}

	}

	return index;

}

int Array::getIndexMin() const
{
	if (m_size == 0) {
		std::cerr << "Array::getIndexMinElement : size is 0..., returned -1";
		return -1;
	}


	int value = m_array[0],
		index = 0;

	for (int i = 0; i < m_size; i++) {

		if (m_array[i] < value) {

			value = m_array[i];
			index = i;

		}
	}

	return index;
}

Array Array::operator + (const int value)
{
	int newSize = m_size + 1;

	Array temporaryArray(newSize, 0);

	for (int i = 0; i < newSize-1; i++) {
		temporaryArray.m_array[i] = m_array[i];
	}

	temporaryArray.m_array[newSize-1] = value;

	return temporaryArray;
}

Array &Array::operator += (const int value)
{

	*this = *this + value;

	return *this;
}

Array Array::operator + (const Array &other) const
{

	int newSize = m_size + other.m_size;
	
	Array temporaryArray(newSize, 0);

	for (int i = 0, j = 0; i < newSize; i++) {
		if (i < m_size) {
			temporaryArray.m_array[i] = m_array[i];
		}

		else {
			temporaryArray.m_array[i] = other.m_array[j];
			j++;
		}
	}

	return temporaryArray;
}

/*
Array &Array::operator = (const Array &&other) { // семантика перемещения
	if (this == &other) return*this;
	delete[] m_array;
	m_array = other.m_array;
	other.m_array = nulptr;
	m_size = other.m_size;
}
*/


Array &Array::operator += (const Array &other)
{

	Array temp = *this + other;
	this->swapArrays(temp);

	//*this = *this + other; // std::move(*this + other); явное перемещение этой переменной в *this.

	return *this;
}

Array &Array::operator = (const Array &other)
{
	// Array &Array::operator=(Array other)
	// { swap(other); return *this;

	if (this == &other) {
		return *this;
	}
	if (m_size != other.m_size) {
		m_size = other.m_size;
		delete[] m_array;
		m_array = new int[m_size];
	}

	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}

	return *this;

	// swapArray(other) ; return *this;
}

bool Array::operator == (const Array &other) const
{
	if (m_size != other.m_size) {
		return false;
	}

	for (int i = 0; i < m_size; i++) {
		
		if (m_array[i] != other.m_array[i]) {
			return false;
		}
	}

	return true;

}

bool Array::operator != (const Array &other) const
{
	return !(*this == other);
}

int &Array::operator [] (const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

void Array::swapArrays(Array &other) {

	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);

}

Array::Iterator::Iterator(Array *array, const int position)
	: m_array(array)
	, m_pos(position)
{}

Array::Iterator Array::begin()
{
	return Iterator(this, 0);
}

Array::Iterator Array::end()
{
	return Iterator(this, m_size);
}

int &Array::Iterator::operator*()
{
	return (*m_array)[m_pos];
}

Array::Iterator &Array::Iterator::operator++()
{
	++m_pos;
	return *this;
}

Array::Iterator Array::Iterator::operator++(int)
{
	Iterator old(*this);
	m_pos++;
	return old;
}


bool Array::Iterator::operator == (const Iterator &other) const
{
	assert(m_array == other.m_array);
	return (m_pos == other.m_pos && m_array == other.m_array);
}

bool Array::Iterator::operator != (const Iterator &other) const
{
	return !( operator==(other) );
}

Array::Iterator Array::insert (const Iterator &other, const int value)
{

	Iterator temporaryIt = other;
	
	insert(temporaryIt.m_pos, value);

	temporaryIt.m_pos++;

	return temporaryIt;

}

Array::Iterator Array::erase(const Iterator &other, const Iterator &otherTwo)
{
	assert(other.m_pos == otherTwo.m_pos);

	int* temporaryArray = new int[m_size];
	Iterator temporaryIt = otherTwo;
	
	for (int i = 0, j = 0; i < m_size; i++, j++) {

		if (i < other.m_pos || i > otherTwo.m_pos) {
			temporaryArray[j] = m_array[i];
		}

		else if (i == other.m_pos) {
			i = otherTwo.m_pos;
			j--;
		}
	}
	
	int newSize = m_size - (otherTwo.m_pos - other.m_pos + 1);

	delete[] m_array;

	m_array = temporaryArray;
	
	temporaryIt++;

	return temporaryIt;

}

std::ostream &operator<<(std::ostream &stream, const Array &arr)
{
	stream << '[';
	for (int i = 0; i < arr.getSize() - 1; ++i) {
		stream << arr[i] << ", ";
	}
	stream << arr[arr.getSize() - 1] << "]\n";

	return stream;
}
std::istream &operator>>(std::istream &stream, Array &arr)
{	
	for (int i = 0; i < arr.getSize(); ++i) {
		stream >> arr[i];
	}

	return stream;
}