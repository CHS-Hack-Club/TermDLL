#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iterator>
#include <sstream>
#include <algorithm>
#include "parser.h"

std::string myString = "alias testing = xyz";

termDLL::utils::parser myParser("alias", 0, false, termDLL::utils::strParse(myString));

int main() {

	std::cout << myParser.getValue(0) << std::endl;
	std::cout << myParser.getValue(1) << std::endl;
	std::cout << myParser.getValue(2) << std::endl;
	return 0;
}