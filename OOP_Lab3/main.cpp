#include <iostream>

#include "BoolVector.h"

int main()
{
	BoolVector temporary = "1111000011110000";

	temporary.invert();

	std::cout << temporary << std::endl;

	return 0;
}