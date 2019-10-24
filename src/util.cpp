#include "util.h"

namespace termDLL{
	namespace utils{
		std::string getPath(){
			return std::filesystem::current_path();
		}

		void setPath(std::string pathStr){
			std::filesystem::current_path() = std::filesystem::path(pathStr);
		}
		
	}	
}

