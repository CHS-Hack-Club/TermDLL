/*
	session.h
		Defines the session class that defines a session..
*/


#pragma once

#ifndef SESSION_H_
#define SESSION_H_

#include <iostream>
#include <string>
#include "export.h"


namespace termDLL {
	namespace core {
		class API session {
			public:
				session(std::string directory); // Set local variables, and find out permission level
				~session(); // Delete this
			private:
				std::string myWorkingDir; // Completely local, but copied from session(directory)

		};
	}
}

#endif