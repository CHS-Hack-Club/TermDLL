#include "parser.h"


namespace termDLL{
	namespace utils{


		tokenParser::~tokenParser() {
			std::cout << "\n TDOR \n";
		}

		std::vector<std::string> strParse(std::string input, std::string delim) {
			std::string buffer = input;
			size_t delimPos = buffer.find(delim);
			buffer.insert(delimPos, " ");
			buffer.insert(delimPos + delim.length() + 1, " "); // + 1 to account for the space added
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

		std::vector<std::string> removeVector(std::vector<std::string> in, std::string rem) {
			std::vector<std::string> buffer = in;
			buffer.erase(std::remove(buffer.begin(), buffer.end(), rem), buffer.end());
			return buffer;
		}

		tokenParser::tokenParser(std::string toProcess, std::string etcdelim, std::string delim, std::string exclude) {
			std::vector<std::string> bufferVector = strParse(toProcess, delim);
			bufferVector = removeVector(bufferVector, etcdelim);
			int temp = 0;
			for (std::vector<std::string>::iterator it = bufferVector.begin(); it != bufferVector.end(); it++) {
				tokenParser::tokens["arg" + std::to_string(temp)] = *it;
				temp++;
			}
			

			for (std::vector<std::string>::iterator it = bufferVector.begin(); it != bufferVector.end(); it++) {
				numberOfArgs++;
				advance(*it);
			}
		}
	
		void tokenParser::advance(std::string adv) {
			if (adv == STRNULL || adv == " ") {
				return;
			}
			tokens[std::string("arg" + std::to_string(argT))] = adv;
			argT++;
			advanceType(adv);
		}
	
		void tokenParser::advanceType(std::string adv) {
			parserType bufferType = parserType::NA;
			if (adv == "=") {
				bufferType = parserType::setter;
			}
			else {
				if (argT - 1 != -1) {
					if (tokens["arg" + std::to_string(argType - 1)] == "=") {
						bufferType = parserType::variable;
					}
					else if (tokens["arg" + std::to_string(argType + 1)] == "=") {
						bufferType = parserType::identifier;
					}
				}
			}
			tokenTypes[std::string("arg" + std::to_string(argType))] = bufferType;
			std::cout << "Assign: " << adv << " T: " << bufferType << std::endl;
			argType++;
		}

	}
}
