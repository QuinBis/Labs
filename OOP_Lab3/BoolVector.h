#pragma once

class BoolVector{
	
public:
	BoolVector();
	BoolVector(const char* string);
	BoolVector(const BoolVector& other);


private:
	unsigned int m_length = 0; // ����� �������.
	unsigned int m_cellCount = 0; // ���������� �����.
	uint8_t* m_cells = nullptr; // ������
	uint8_t m_unsignificantRankCount = 0; // ���������� ���������� �����.

};