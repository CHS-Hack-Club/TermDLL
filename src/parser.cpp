#include "parser.h"


namespace termDLL{
	namespace utils{
		parser::parser(std::string delim, int type, bool quotes, std::vector<std::string> input){
			parser::myBuffer = input;

			for(std::vector<std::string>::iterator it = parser::myBuffer.begin(); it != parser::myBuffer.end(); it++){
				if(*it != delim){
					
				}
			}
		}
	}
}
