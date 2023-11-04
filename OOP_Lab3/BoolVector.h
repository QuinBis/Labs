#pragma once

class BoolVector{
	
public:
	BoolVector();
	BoolVector(const char* string);
	BoolVector(const BoolVector& other);


private:
	unsigned int m_length = 0; // Длина вектора.
	unsigned int m_cellCount = 0; // Количество ячеек.
	uint8_t* m_cells = nullptr; // Ячейки
	uint8_t m_unsignificantRankCount = 0; // Количество незначащих нулей.

};