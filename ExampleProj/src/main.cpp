#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <exception>
#include "parser.h"


int main() {
	std::string in;
	std::getline(std::cin, in);
	termDLL::utils::parser myParse("alias", 0, false, termDLL::utils::strParse(in, "="));
	std::cout << "Done parsing";
	std::cout << "Size: " << myParse.size() << std::endl;

	std::cout << "Content: " << myParse.getValue(0) << " ID: " << myParse.getType(0) << std::endl;
	std::cout << "Content: " << myParse.getValue(1) << " ID: " << myParse.getType(1) << std::endl;
	std::cout << "Content: " << myParse.getValue(2) << " ID: " << myParse.getType(2) << std::endl;

	return 0;
}