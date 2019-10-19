#include "export.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iterator>
#include <unordered_map>
#include <sstream>
#include <algorithm>

enum parserType {
	NA = 0,
	identifier = 1,
	setter = 2,
	variable = 3
};

#define STRNULL ""


namespace termDLL{
	namespace utils{

		std::vector<std::string> strParse(std::string input);

		API std::vector<std::string> strParse(std::string input, std::string delim);

		API std::string removeStr(std::string orig, std::string rem);

		API std::vector<std::string> removeVector(std::vector<std::string> in, std::string rem);

		// Copies from EzraJ/ModDLL bc reasons
		class API tokenParser {
		public:

			tokenParser(std::string toProcess, std::string etcdelim, std::string delim = STRNULL, std::string exclude = STRNULL);
			~tokenParser();
			void advance(std::string adv);
			void advanceType(std::string adv);



			parserType getType(std::string accesser) {
				try {
					return tokenParser::tokenTypes[accesser];
				}
				catch (std::exception e) {
					std::cout << e.what() << std::endl;
					return parserType::NA;
				}

			}

			std::string getString(std::string accesser) {
				try {
					return tokenParser::tokens[accesser];
				}
				catch (std::exception e) {
					std::cout << e.what() << std::endl;
					return STRNULL;
				}
			}


			int getNumberOfArgs() {
				return numberOfArgs;
			}

		private:
			int numberOfArgs = 0;
			int argT = 0;
			int argType = 0;
			std::unordered_map<std::string, std::string> tokens;
			std::unordered_map<std::string, parserType> tokenTypes;

			std::vector<std::string> parse(std::string inp) {
				std::istringstream ss(inp);
				using StrIt = std::istream_iterator<std::string>;
				std::vector<std::string> container(StrIt(ss), StrIt{});
				return container;
			}

		};
	}
}
