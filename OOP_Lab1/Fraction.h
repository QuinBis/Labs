#pragma once

/*

*private - ч/данные и ч/функции доступны только ч/функци€м класса

**protected - ч/данные и ч/функции доступны ч/функци€м базового и порожденного классов (неизвестно пока)

***public - ч/данные и ч/функции общедоступны

*/

///  ласс по умолчанию - private (по сути мы всЄ спр€тали в капсулу "»Ќ јѕ—”Ћя÷»я")


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
