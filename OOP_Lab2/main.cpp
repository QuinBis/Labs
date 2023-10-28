#include <iostream>

#include "Array.h"

int main() {

	char test[21] = "hello world!";

	Array<std::string> temp(101,test);

	std::cout << temp << std::endl;

}