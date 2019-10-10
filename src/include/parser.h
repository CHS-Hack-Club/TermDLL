#include "TermDLL.h"

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




		class parser{
			public:
				parser(std::string delim, int type, bool quotes, std::vector<std::string> input);
				~parser();
				int getType(int in); // Return assignment of one type; eg: arg(0) 
				std::string getValue(int in);
				std::pair<int, std::string> get(int in);
			private:
				bool parseQuotes;
				std::vector<std::string> myBuffer;
				std::vector<int> assigned; // For each processed input:
							   // 0 = identifier
							   // 1 = setter (=)
							   // 2 = name


		};
	}
}
