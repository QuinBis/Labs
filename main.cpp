#include <iostream>
#include "Fraction.h"

// �� ������� ������ �� ��������



int main() {
	setlocale(0, "");

	Fraction fraction = { 1, 2 } ;
	Fraction twofraction = { 1, 2 };

	Fraction temp = fraction.SumFraction(twofraction);
	
	std::cout << "������� �����..." << std::endl;
	temp.OutputFraction();

	std::cout << "������� �������..." << std::endl;

	temp = fraction.DiffFraction(twofraction);
	temp.OutputFraction();

	std::cout << "������� ������������..." << std::endl;

	temp = fraction.MultiplyFraction(twofraction);
	temp.OutputFraction();


	std::cout << "������� �������..." << std::endl;

	temp = fraction.DivisionFraction(twofraction);
	temp.OutputFraction();

	return 0;
}