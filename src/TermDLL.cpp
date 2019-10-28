// Define functions in TermDLL and include other header files.

#include "TermDLL.h"
#include "global.h"

namespace termDLL {
	namespace core {
#ifdef _WIN32
		void init(returnDataMacro* data) {
			termDLL::core::currentWorkingDirectory = dir;
			termDLL::functions::init(data);
		}
#elif __linux__
	void init(returnDataMacro* data) {
		termDLL::core::currentWorkingDirectory = dir;
		termDLL::functions::init(data);
	}

#endif

	}
}
