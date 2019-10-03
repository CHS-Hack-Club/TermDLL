#include "session.h"

namespace termDLL {
	namespace core {
		session::session(std::string dir) {
			session::myWorkingDir = dir;
		}

		session::~session() {
			std::cout << "dtor" << std::endl;
		}
	}
}

