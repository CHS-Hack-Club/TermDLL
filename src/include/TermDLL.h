/*
	Project rules
		camelCase
		If you're making a pull request, state what the changes are and the purpose
		Massive changes should only be considered with a good reason

	TermDLL.h
		The main file that declares the "entry" of TermDLL, will include
		init(), run(), and include other important structs for data processing.
*/

#pragma once

#ifndef TERMDLL_H_
#define TERMDLL_H_


// Standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iterator>


// TermDLL Libraries
#include "util.h"
#include "cross/functiondef.h" // Includes cross/filesystem.h
#include "export.h"
#include "global.h"

// OS specific libraries
#ifdef _WIN32
#include "win32/functiondef.h"
#elif __linux__
#include "linux/functiondef.h"
#endif



namespace termDLL {

	namespace core {
		API void init(returnDataMacro* data);
		API bool run(returnDataMacro* data); // Runtime
	}
	

}

#endif


