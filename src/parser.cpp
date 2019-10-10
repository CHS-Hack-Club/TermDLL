#include "parser.h"


namespace termDLL{
	namespace utils{
		API parser::parser(std::string delim, int type, bool quotes, std::vector<std::string> input){
			parser::myBuffer = input;
			parser::myBuffer.erase(std::remove(parser::myBuffer.begin(), parser::myBuffer.end(), delim), parser::myBuffer.end());
			int num = 0;
			for(std::vector<std::string>::iterator it = parser::myBuffer.begin(); it != parser::myBuffer.end(); it++){
				if(*it == "="){
					parser::assigned.push_back(1); // Setter
				}

				if (num != 0 && num + 1 != parser::myBuffer.size()) {
					if (parser::myBuffer.at(num + 1) == "=") {
						parser::assigned.push_back(0); // Identifer
						continue;
					}
					if (parser::myBuffer.at(num - 1) == "=") {
						parser::assigned.push_back(2); // Variable
						continue;
					}
				}

				num++;
			}

		}

		API int parser::getType(int in) {
			return parser::assigned.at(in);
		}

		API std::string parser::getValue(int in) {
			return parser::myBuffer.at(in);
		}




	}
}
