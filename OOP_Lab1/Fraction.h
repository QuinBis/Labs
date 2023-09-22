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
	void input();

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

	Fraction operator + (const Fraction twoFraction);
	Fraction operator - (const Fraction twoFraction);
	Fraction operator * (const Fraction twoFraction);
	Fraction operator / (const Fraction twoFraction);

	Fraction & operator ++ (); // suff fraction++ => fraction+1 =>      1/2++ = 3/2 
	Fraction operator ++ (int); // postfix
	Fraction & operator -- (); // suff
	Fraction operator -- (int); // postfix

	Fraction shifter();


private:
	int m_numerator = 0 ;
	int m_denominator = 1;


};
