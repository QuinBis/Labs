#ifndef TEMPLATE_ARRAY
#define TEMPLATE_ARRAY

#include <iostream>
#include <assert.h>
#include <time.h>

#include "Array.h"



template<typename Type>
Array<Type>::Array(const int size, const Type& value)
{
	if (size < 0) {
		std::cerr << "Array:Arrray: size is negative, invert..." << std::endl;
		m_size = -size;
		std::cerr << "Size = " << m_size;
	}
	else {
		m_size = size;
	}


	m_array = new Type[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = value;

}

template<typename Type>
Array<Type>::Array(const Type* array, const int size)
{

	assert(size != 0);

	if (size < 0) {
		size = -size;
		std::cerr << "void Array::Array(const int*, int size): size is negative, invert." << std::endl;
	}

	m_size = size;

	m_array = new Type[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = array[i];

}

template<typename Type>
Array<Type>::Array(const Type& other) {

	m_array = new Type[other.m_size];
	for (m_size = 0; m_size < other.m_size;m_size++)
		m_array[m_size] = other.m_array[m_size];
}

template<typename Type>
Array<Type>::~Array() {
	
	delete[] m_array;
}

template <typename Type>
int Array<Type>::getSize() const
{

	return m_size;

}

template<typename Type>
void Array<Type>::swapArrays(Array& other) {

	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);

}

template<typename Type>
int Array<Type>::getIndex(const Type& value) const
{

	for (int i = 0; i < m_size; ++i) {

		if (m_array[i] == value) {
			return i;
		}

	}

	return -1;
}

template<typename Type>
void Array<Type>::printArray() const
{
	std::cout << *this;
}

template<typename Type>
void Array<Type>::scanArray(const int size)
{
	assert(size != 0);

	if (size < 0) {
		std::cerr << "Array::scanArray : size is negative, invert...";
		m_size = -size;
	}
	else {
		m_size = size;
	}

	Array temp(m_size, 0);
	std::cin >> temp;
	this->swapArrays(temp);
}

// bubble sort
template <typename Type>
void Array<Type>::sort() const {

	Type forSwap;
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++) {

			if (m_array[i] < m_array[j]) {

				forSwap = m_array[i];
				m_array[i] = m_array[j];
				m_array[j] = forSwap;

			}

		}

}

template<typename Type>
bool Array<Type>::insert(const int index, const Type& value)
{

	if (index < 0 || index > m_size) {
		std::cerr << "Array::addElementByIndex : index is invalid " << std::endl;
		return false;	
	}

	Type* temporary = new Type[m_size + 1];

	for (int i = 0, j = 0; i < m_size + 1; i++, j++) {
		if (i != index) {
			temporary[i] = m_array[j];
		}
		else {
			temporary[i] = value;
			j--;
		}
	}

	delete[] m_array;

	m_size++;
	m_array = temporary;
	return true;

}

template<typename Type>
bool Array<Type>::erase(const int index)
{

	if (index < 0 || index > m_size) {
		std::cerr << "Array::eraseByIndex : index is invalid " << std::endl;
		return false;
	}

	Type* temporary = new Type[m_size - 1];

	int i = 0, j = 0;
	while (i < m_size) {
		if (i != index) {
			temporary[j] = m_array[i];
			i++;
			j++;
		}
		else {
			i++;
		}
	}

	delete[] m_array;

	m_size--;
	m_array = temporary;
	return true;

}

template<typename Type>
bool Array<Type>::eraseFirst(const Type& value)
{

	for (int i = 0; i < m_size; i++) {

		if (m_array[i] == value) {
			erase(i);
			return true;
		}

	}

	return false;
}

template<typename Type>
bool Array<Type>::eraseAll(const Type& value)
{

	Type* temporaryArray = new Type [m_size];

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

	m_array = temporaryArray;

	return true;
}

template<typename Type>
Type Array<Type>::getMaxValue() const
{

	assert(m_size > 0);

	Type temp = m_array[0];

	for (int i = 0; i < m_size; i++) {

		if (m_array[i] > temp) {

			temp = m_array[i];

		}

	}

	return temp;

}

template<typename Type>
Type Array<Type>::getMinValue() const
{
	assert(m_size > 0);


	Type temp = m_array[0];

	for (int i = 0; i < m_size; i++) {

		if (m_array[i] < temp) {

			temp = m_array[i];

		}
	}

	return temp;
}

template <> inline
void Array<int>::setRandom(const int min, const int max) const
{
	srand((unsigned int)time(0));

	for (int i = 0; i < m_size; i++) {
		m_array[i] = rand() % (max - min + 1) + min;
	}

}

template <> inline
void Array<int>::setIncrease() const
{
	srand((unsigned int)time(0));

	m_array[0] = rand() % 10 + 1;

	for (int i = 1; i < m_size; i++) {
		m_array[i] = m_array[i - 1] + rand() % 5 + 1; // + (1 -> 5)
	}
}

template <> inline
void Array<int>::setDecrease() const
{
	srand((unsigned int)time(0));

	m_array[m_size - 1] = rand() % 10 + 1;

	for (int i = m_size - 2; i >= 0; i--) {
		m_array[i] = m_array[i + 1] + rand() % +10 + 1; // + (1 -> 10)
	}

}

template<typename Type>
Array<Type>& Array<Type>::operator = (const Array& other)
{

	if (this == &other) {
		return *this;
	}

	if (m_size != other.m_size) {
		m_size = other.m_size;
		delete[] m_array;
		m_array = new Type [m_size];
	}

	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}

	return *this;
}

template<typename Type>
Type& Array<Type>::operator [] (const int index) const
{
	assert(index >= 0 || index < m_size);
	return m_array[index];
}

template<typename Type>
bool Array<Type>::operator == (const Array& other) const
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

template<typename Type>
bool Array<Type>::operator != (const Array& other) const
{
	return !(*this == other);
}

template<typename Type>
Array<Type> Array<Type>::operator + (const Array& other) const
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

	std::cout << "Array Array::operator + (const Array& other) const" << std::endl;
	return temporaryArray;
}

template<typename Type>
Array<Type>& Array<Type>::operator += (const Array& other)
{

	*this = *this + other;

	std::cout << "Array& Array::operator += (const Array& other)" << std::endl;
	return *this;
}

template<typename Type>
Array<Type> Array<Type>::operator + (const Type& value)
{
	int newSize = m_size + 1;

	Array temporaryArray(newSize, 0);

	for (int i = 0; i < newSize - 1; i++) {
		temporaryArray.m_array[i] = m_array[i];
	}

	temporaryArray.m_array[newSize - 1] = value;

	return temporaryArray;
}

template<typename Type>
Array<Type>& Array<Type>::operator += (const Type& value)
{

	*this = *this + value;

	return *this;
}

template <typename Type>
template <typename IterType, typename ArrType>
Array<Type>::TemplateIterator<IterType, ArrType>::TemplateIterator(ArrType* array, const int position)
	: m_array(array)
	, m_pos(position)
{}

template<typename Type> typename
Array<Type>::Iterator Array<Type>::begin() {

	return Iterator(this, 0);

}

template <typename Type> typename
Array<Type>::Iterator Array<Type>::end() {

	return Iterator(this, getSize());

}

template<typename Type> typename
Array<Type>::ConstIterator Array<Type>::begin() const {

	return ConstIterator(this, 0);

}
template <typename  Type> typename
Array<Type>::ConstIterator Array<Type>::end() const {

	return ConstIterator(this, getSize());

}

template <typename Type>
template <typename IterType, typename ArrType>
IterType& Array<Type>::TemplateIterator<IterType, ArrType>::operator*()
{
	return (*m_array)[m_pos];
}

template <typename Type>
template <typename IterType, typename ArrType>
int Array<Type>::TemplateIterator<IterType, ArrType>::getPosition() const {
	return m_pos;
}

template <typename Type>
template <typename IterType, typename ArrType>
Array<Type>::TemplateIterator<IterType, ArrType>& Array<Type>::TemplateIterator<IterType, ArrType>::operator++()
{
	++m_pos;
	return *this;
}

template <typename Type>
template <typename IterType, typename ArrType>
Array<Type>::TemplateIterator<IterType, ArrType> Array<Type>::TemplateIterator<IterType, ArrType>::operator++(int)
{
	Iterator old(*this);
	m_pos++;
	return old;
}

template <typename Type>
template <typename IterType, typename ArrType>
bool Array<Type>::TemplateIterator<IterType, ArrType>::operator == (const TemplateIterator& other) const
{
	assert(m_array == other.m_array);
	return (m_pos == other.m_pos && m_array == other.m_array);
}

template <typename Type>
template <typename IterType, typename ArrType>
bool Array<Type>::TemplateIterator<IterType, ArrType>::operator != (const TemplateIterator& other) const
{
	return !(operator==(other));
}

template <typename Type>
template <typename IterType, typename ArrType>
Array<Type>::TemplateIterator<IterType, ArrType>&Array<Type>::TemplateIterator<IterType, ArrType>::operator += (const int &value) {
	m_pos += value;
	return *this;
}

template <typename Type> typename
Array<Type>::Iterator Array<Type>::insert(Iterator other, const Type& value)
{

	insert(other.m_pos, value);
	other.m_pos++;
	return other;

}

template <typename Type> typename
Array<Type>::Iterator Array<Type>::erase(const Iterator other, const Iterator otherTwo)
{
	assert(otherTwo.m_pos >= other.m_pos);

	int newSize = m_size - (otherTwo.m_pos - other.m_pos);

	Array temp(newSize, 0);

	Iterator temporaryIt = otherTwo;

	for (int i = 0, j = 0; i < m_size; i++, j++) {

		if (i < other.m_pos || i > otherTwo.m_pos) {
			temp.m_array[j] = m_array[i];
		}

		else if (i == other.m_pos) {
			i = otherTwo.m_pos;
			j--;
		}
	}

	swapArrays(temp);

	temporaryIt++;

	return temporaryIt;
}

template<typename Type>
void Array<Type>::resize(int size) {
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

template<typename Type>
std::ostream& operator<<(std::ostream& stream, const Array<Type>& arr)
{
	stream << '[';
	for (int i = 0; i < arr.getSize() - 1; ++i) {
		stream << arr[i] << ", ";
	}
	stream << arr[arr.getSize() - 1] << "]\n";

	return stream;
}

template<typename Type>
std::istream& operator>>(std::istream& stream, Array<Type>& arr)
{
	for (int i = 0; i < arr.getSize(); ++i) {
		std::cout << "[" << i << "] = ";
		stream >> arr[i];
	}

	return stream;
}

#endif
