#include <iostream>
#include <assert.h>

#include "Header.h"

Array::Array(const int* array, const int size)
{

	assert(size != 0);	

	if (size < 0) {
		std::cerr << "Array::Array: size is negative, invert..." << std::endl;
		m_size = -size;
	}
	else {
		m_size = size;
	}

	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++) {
		m_array[i] = array[i];
	}
}

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



int Array::getSize() const
{
	return m_size;
}

void Array::printArray() const
{
	std::cout << "[";
	for (int i = 0; i < m_size - 1; ++i) {
		std::cout << m_array[i] << ", ";
	}
	std::cout << m_array[m_size - 1] << "]\n";
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

	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++) {
		std::cout << "Array[" << i << "] = ";
		std::cin >> m_array[i];
	}
}

int Array::getIndexElement(const int value) const
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

void Array::sort()
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

bool Array::addElementByIndex(const int index, const int value)
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
	delete[] m_array;

	m_size++;
	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++) {
		m_array[i] = temporaryArray[i];
	}

	delete[] temporaryArray;

	return true;


}

bool Array::popElementByIndex(const int index)
{

	if (index < 0 || index > m_size) {
		std::cerr << "Array::popElementByIndex : index is invalid " << std::endl;
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

	delete[] m_array;

	m_size--;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_array[i] = temporaryArray[i];
	}

	delete[] temporaryArray;

	return true;
}

bool Array::popFirstElementByValue(const int value)
{

	for (int i = 0; i < m_size; i++) {
		
		if (m_array[i] == value) {
			popElementByIndex(i);
			return true;
		}

	}

	return false;
}

Array &Array::operator = (const Array &other)
{
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
}

int &Array::operator [] (const int index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

bool Array::popAllElementsByValue(const int value)
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

	delete[] m_array;

	m_size = newSize;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_array[i] = temporaryArray[i];
	}
	
	delete[] temporaryArray;

	return true;


}

int Array::getIndexMaxElement()
{

	int value = m_array[0],
		index = 0;

	for (int i = 0; i < m_size; i++) {

		if (m_array[i] > value) {

			value = m_array[i];
			index = i;

		}

	}

	return index; // ???? or value????

}

int Array::getIndexMinElement()
{

	int value = m_array[0],
		index = 0;

	for (int i = 0; i < m_size; i++) {

		if (m_array[i] < value) {

			value = m_array[i];
			index = i;

		}
	}

	return index; // ???
}