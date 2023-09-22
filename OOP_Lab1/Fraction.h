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

	Fraction sumNumbers(const Fraction number) const;
	Fraction minNumbers(const Fraction number) const;
	Fraction mulNumbers(const Fraction number) const;
	Fraction divNumbers(const Fraction number) const;

	void setNumerator(const int value);
	void setDenominator(const int value);

	int getNumerator() const; // return value type int.
	int getDenominator() const;

	void reduce();
	
	bool operator == (const Fraction twoFraction) const;
	bool operator != (const Fraction twoFraction) const;
	bool operator > (const Fraction twoFraction) const;
	bool operator < (const Fraction twoFraction) const;


private:
	int m_numerator = 0 ;
	int m_denominator = 1;


};
