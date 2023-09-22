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
	void scan();

	Fraction SumNumbers(const Fraction &Number) const; // —ложение
	Fraction MinusNumbers(const Fraction &Number) const; // ¬ычитание
	Fraction MultiplyNumbers(const Fraction &Number) const; // ”множение
	Fraction DivisionNumbers(const Fraction &Number) const; // ƒеление


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

	// —обственные методы

private:
	int m_numerator;
	int m_denominator;


};
