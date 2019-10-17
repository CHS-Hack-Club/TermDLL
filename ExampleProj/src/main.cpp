#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iterator>
#include <sstream>
#include <algorithm>
#include "parser.h"


int main() {
	std::string in;
	std::getline(std::cin, in);
	termDLL::utils::parser myParser("alias", 0, false, in);
	std::cout << myParser.getValue(0) << std::endl;
	std::cout << myParser.getValue(1) << std::endl;
	std::cout << myParser.getValue(2) << std::endl;
	std::cin.get();
	return 0;
}