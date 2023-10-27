#include <iostream>
#include <string>

#include "Array.h"


int main() {

	char  s[5] = "qwer";
	
	Array<std::string> test(9, s);

	std::cout << test << std::endl;



	return 0;
}