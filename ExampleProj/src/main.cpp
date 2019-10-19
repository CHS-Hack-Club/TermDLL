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
	termDLL::utils::tokenParser myParse(in, "alias", "=");
	std::cout << "Done parsing" << std::endl;
	std::cout << "Content: " << myParse.getString("arg0") << " ID: " << myParse.getType("arg0") << std::endl;
	std::cout << "Content: " << myParse.getString("arg1") << " ID: " << myParse.getType("arg1") << std::endl;
	std::cout << "Content: " << myParse.getString("arg2") << " ID: " << myParse.getType("arg2") << std::endl;

	std::cin.get();
	return 0;
}