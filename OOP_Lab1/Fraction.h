#pragma once

/*

*private - �/������ � �/������� �������� ������ �/�������� ������

**protected - �/������ � �/������� �������� �/�������� �������� � ������������ ������� (���������� ����)

***public - �/������ � �/������� ������������

*/

/// ����� �� ��������� - private (�� ���� �� �� �������� � ������� "������������")


class Fraction {

public:

	Fraction() = default;
	Fraction(const int numerator, const int denominator);
	~Fraction() = default;

	void print() const;
	void scan();

	Fraction SumNumbers(const Fraction &Number) const; // ��������
	Fraction MinusNumbers(const Fraction &Number) const; // ���������
	Fraction MultiplyNumbers(const Fraction &Number) const; // ���������
	Fraction DivisionNumbers(const Fraction &Number) const; // �������


	Fraction operator + (const Fraction other);
	Fraction operator - (const Fraction other);
	Fraction operator * (const Fraction other);
	Fraction operator / (const Fraction other);
	Fraction operator ++();
	Fraction operator ++(int);

	void setNumerator(const int number);
	void setDenominator(const int number);

	int getNumerator() const;
	int getDenominator() const;
	
	bool operator == (const Fraction other);
	bool operator != (const Fraction other);
	bool operator < (const Fraction other);
	bool operator > (const Fraction other);

	void reduce();

	// ����������� ������

private:
	int m_numerator;
	int m_denominator;


};
