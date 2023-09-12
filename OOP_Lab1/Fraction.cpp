
#include <iostream>

#include "Fraction.h"




// ��� ���_������ :: ���_������� (������)  ===== ��� - ���� ������������� ��������, ������ - ������ ����������

void Name_Class::OutputFractionTwo(const Name_Class Number) { // ����� �� �����

	if (Number.NumberOne == 0) {
		std::cout << "0" << "\n\n";
	}

	else if (Number.NumberOne == Number.NumberTwo) { std::cout << "1" << "\n\n"; }

	else if (Number.NumberTwo == 0) { std::cout << "������ �� ���� ������!" << "\n\n"; }

	else { std::cout << Number.NumberOne << "/" << Number.NumberTwo << "\n\n"; }
}


Name_Class Name_Class::SumNumbers(const Name_Class Number) { // ��������

	Name_Class sum;

	sum.NumberOne = (NumberOne * Number.NumberTwo) + (NumberTwo * Number.NumberOne);

	sum.NumberTwo = NumberTwo * Number.NumberTwo;

	return sum;
}


Name_Class Name_Class::DiffNumbers(const Name_Class Number) { // ���������

	Name_Class Difference;

	Difference.NumberOne = (NumberOne * Number.NumberTwo) - (NumberTwo*Number.NumberOne);
	Difference.NumberTwo = NumberTwo * Number.NumberTwo;

	return Difference;

}

Name_Class Name_Class::MultiplyNumbers(const Name_Class Number) { // ���������

	Name_Class Multiply = { 0 , 1 };

	if ((NumberTwo * Number.NumberTwo) == 0) {
		return Multiply;
	}

	Multiply.NumberOne = NumberOne * Number.NumberOne;
	Multiply.NumberTwo = NumberTwo * Number.NumberTwo;
	return Multiply;
}

Name_Class Name_Class::DivisionNumbers(const Name_Class Number) { // �������

	Name_Class Division = { 0 , 1 };

	if ((NumberOne * Number.NumberTwo) == 0) {
		return Division;
	}

	Division.NumberOne = NumberOne * Number.NumberTwo;
	Division.NumberTwo = NumberTwo * Number.NumberOne;
	return Division;
}
