#include "export.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iterator>
#include <sstream>
#include <algorithm>



enum class parserType{
	command, variable, programmable
};



namespace termDLL{
	namespace utils{

		std::vector<std::string> strParse(std::string input){
			std::istringstream ss(input);
			using StrIt = std::istream_iterator<std::string>;
			std::vector<std::string> contain(StrIt(ss), StrIt{});
			return contain;
		}

		std::vector<std::string> strParse(std::string input, std::string delim, std::string delim2 = " ") {
			std::string buffer = input;
			size_t delimPos = buffer.find(delim);
			buffer.insert(delimPos - delim.length() , " ");
			buffer.insert(delimPos + delim.length(), " ");
			return strParse(buffer);
		}




		class API parser{
			public:
				parser(std::string delim, int type, bool quotes, std::vector<std::string> input); // Process by space (eg: alias test = x, not alias test=x)
				~parser();
				int getType(int in); // Return assignment of one type; eg: arg(0) 
				std::string getValue(int in);
				std::pair<int, std::string> get(int in);
				int size();
			private:
				bool parseQuotes;
				std::vector<std::string> myBuffer;
				std::string myStrBuffer;
				std::vector<int> assigned; // For each processed input:
							   // 0 = identifier
							   // 1 = setter (=)
							   // 2 = name


		};
	}
}
