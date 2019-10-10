#include "parser.h"


namespace termDLL{
	namespace utils{
		parser::parser(std::string delim, int type, bool quotes, std::vector<std::string> input){
			parser::myBuffer = input;
			parser::myBuffer.erase(std::remove(parser::myBuffer.begin(), parser::myBuffer.end(), delim), parser::myBuffer.end());
			int num = 0;
			for(std::vector<std::string>::iterator it = parser::myBuffer.begin(); it != parser::myBuffer.end(); it++){
				if(*it == "="){
					parser::assigned.push_back(0); // Identifer
					if(num != 0 && num+1 != parser::myBuffer.size()){

					}
				}

				num++;
			}

		}
	}
}
