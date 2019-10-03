// Define functions in TermDLL and include other header files.

#include "TermDLL.h"


namespace termDLL {
	namespace core {
		void init(std::string dir, bool printInfo) {
			termDLL::core::currentWorkingDirectory = dir;

		}


	}
}