#pragma once

template <typename Type>
class Array {
public:
	template <typename IterType, typename ArrType>
	class TemplateIterator;
	using Iterator = TemplateIterator<Type, Array>;
	using ConstIterator = TemplateIterator<const Type, const Array>;

public:
	Array(const int size = 1, const Type& value = Type());		
	Array(const Type* array, const int size);							
	Array(const Type& other);										
	~Array();														

	int getSize() const;											

	void swap(Array& other);											

	int getIndex(const Type& value) const;							

	void printArray() const;										
	void scanArray(const int size);									

	void sort() const;												

	bool insert(const int index, const Type& value);					
	bool erase(const int index);									
	bool eraseFirst(const Type& value);									
	bool eraseAll(const Type& value);									

	Type getMaxValue() const;									
	Type getMinValue() const;									

	void setRandom(const int min, const int max) const;					
	void setIncrease() const;										
	void setDecrease() const;											

	Array& operator = (const Array& other);						
	Type& operator [] (const int index) const;							

	bool operator == (const Array& other) const;				
	bool operator != (const Array& other) const;				

	Array operator + (const Array& other) const;				
	Array& operator += (const Array& other);					

	Array operator + (const Type& value);							
	Array& operator += (const Type& value);								

	Iterator begin();												
	Iterator end();												

	Iterator insert(const Iterator other, const Type& value);
	Iterator erase(const Iterator other, const Iterator otherTwo);

	void resize(int size);

private:
	int* m_array = nullptr;
	int m_size = 0;
};


template <typename Type>
template <typename IterType, typename ArrType>
class Array<Type>::TemplateIterator
{
public:

	friend class Array;

	TemplateIterator(ArrType* array = nullptr, const int position = 0);

	IterType& operator*();									
	int getPosition() const;									

	TemplateIterator& operator++();								
	TemplateIterator operator++(int);							

	TemplateIterator &operator += (const int &value);			

	bool operator == (const TemplateIterator& other) const;		
	bool operator != (const TemplateIterator& other) const;			


private:
	ArrType* m_array = nullptr;
	int m_pos = 0;
};

template<typename Type>
std::ostream& operator<<(std::ostream& stream, const Array<Type>& arr);

template<typename Type>
std::istream& operator>>(std::istream& stream, Array<Type>& arr);
