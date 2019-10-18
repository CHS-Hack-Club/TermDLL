#include "parser.h"


namespace termDLL{
	namespace utils{


		tokenParser::~tokenParser() {
			std::cout << "\n TDOR \n";
		}

		std::vector<std::string> strParse(std::string input, std::string delim) {
			std::string buffer = input;
			size_t delimPos = buffer.find(delim);
			buffer.insert(delimPos - delim.length(), " ");
			buffer.insert(delimPos + delim.length(), " ");
			return strParse(buffer);
		}

		std::vector<std::string> strParse(std::string input) {
			std::istringstream ss(input);
			using StrIt = std::istream_iterator<std::string>;
			std::vector<std::string> contain(StrIt(ss), StrIt{});
			return contain;
		}

		std::string removeStr(std::string orig, std::string rem) {
			std::string buffer = orig;
			size_t pos = buffer.find(rem);
			buffer.erase(pos, rem.length() - 1);
			return buffer;
		}


		tokenParser::tokenParser(std::string toProcess, std::string etcdelim, std::string delim, std::string exclude) {
			removeStr(toProcess, etcdelim);
			std::vector<std::string> bufferVector = strParse(toProcess, delim);
			/*std::vector<std::string> excludedProcess;
			for (std::vector<std::string>::iterator it = bufferVector.begin(); it != bufferVector.end(); it++) {
				if (*it != exclude && *it != " ") {
					excludedProcess.emplace_back(*it);
					std::cout << *it;
				}
			} */

			for (std::vector<std::string>::iterator it = bufferVector.begin(); it != bufferVector.end(); it++) {
				std::cout << "PROC: " << *it << std::endl;
				numberOfArgs++;
				advance(*it);
			}
		}
	
		void tokenParser::advance(std::string adv) {
			tokens[std::string("arg" + std::to_string(argT))] = adv;
			argT++;
			std::cout << "PROC(2): " << adv << std::endl;
			advanceType(adv);
		}
	
		void tokenParser::advanceType(std::string adv) {
			parserType bufferType = parserType::NA;
			if (adv == "=") {
				bufferType = parserType::setter;
			}
			else {
				if (argT - 1 != -1) {
					if (tokens["arg" + std::to_string(argT - 1)] == "=") {
						bufferType = parserType::variable;
					}
					else if (tokens["arg" + std::to_string(argT + 1)] == "=") {
						bufferType = parserType::variable;
					}
				}
			}
			tokenTypes[std::string("arg" + std::to_string(argType))] = bufferType;
			std::cout << "Assign: " << adv << " T: " << bufferType << std::endl;
			argType++;
		}





	}
}
