#include <iostream>

#include "BoolVector.h"

int main()
{
    BoolVector tmp = "010101010101010101010101010101010101010101010101";

    std::cout << "\n\t\tBoolVector >> shifting\t\t\t\t\t\t\tBoolVector << shifting\n" << std::endl;
    for (int i = 0, j = 0; i <= tmp.getLength(); i++, j++) {
        std::cout << (tmp >> i) << " " << i << "\t" << (tmp << j) << std::endl;
    }

	return 0;
}