#include "parser.h"


namespace termDLL{
	namespace utils{

		int parser::size() {
			return parser::assigned.size();
		}

		parser::parser(std::string delim, int type, bool quotes, std::vector<std::string> input){
			parser::myBuffer = input;
			parser::myBuffer.erase(std::remove(parser::myBuffer.begin(), parser::myBuffer.end(), delim), parser::myBuffer.end());
			int num = 0;
			for(std::vector<std::string>::iterator it = parser::myBuffer.begin(); it != parser::myBuffer.end(); it++){
				std::string b = *it;
				std::cout << "PARSE: " << *it << " (SIZE: " << b.length() << ")" << std::endl;
				if(*it == "="){
					parser::assigned.push_back(1); // Setter
					num++;
					continue;
				}
				else {
					if (num != 0 && num + 1 != parser::myBuffer.size()) {
						if (parser::myBuffer.at(num + 1) == "=") {
							parser::assigned.push_back(0); // Identifier
							num++;
							continue;
						}
						else if (parser::myBuffer.at(num - 1) == "=") {
							parser::assigned.push_back(2); // Variable content
							num++;
							continue;
						}
						else {
							parser::assigned.push_back(-1);
							num++;
							continue;
						}
					}
				}
			}

		}

		int parser::getType(int in) {
			return parser::assigned.at(in);
		}

		std::string parser::getValue(int in) {
			return parser::myBuffer.at(in);
		}

		parser::~parser() {
			std::cout << "parser dtor" << std::endl;
		}


	}
}
