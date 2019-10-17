#include "parser.h"


namespace termDLL{
	namespace utils{


		parser::parser(std::string delim, int type, bool quotes, std::string input) {
			parser::myStrBuffer = input;
			
			size_t pos = std::string::npos;

			while ((pos != parser::myStrBuffer.find(delim)) != std::string::npos) {
				parser::myStrBuffer.erase(pos, delim.length());

			}

			std::string proc;
			int num = 0;
			for (char& it : parser::myStrBuffer) {
				if (it == '=') {
					// Stop
					parser::myBuffer.push_back(proc);
					parser::assigned.push_back(1); // Setter
					proc = ""; // Start over.
					continue;
				}else {
					if (num != 0 && num + 1 != parser::myBuffer.size()) {
						if (parser::myBuffer.at(num + 1) == "=") {
							parser::myBuffer.push_back(proc);
							parser::assigned.push_back(0); // Identifier
							proc = "";
							continue;
						}

						if (parser::myBuffer.at(num - 1) == "=") {
							parser::myBuffer.push_back(proc);
							parser::assigned.push_back(3); // Variable
							proc = "";
							continue;
						}

					}
				}
				proc += it;
				num++;
			}

		}


		parser::parser(std::string delim, int type, bool quotes, std::vector<std::string> input){
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
