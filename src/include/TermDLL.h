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
#include <mutex>
#include <thread>
#include <future>
#include <any>
#include <algorithm>
#include <tuple>
#include <utility>
#include <sstream>
#include <stdio.h>
#include <iterator>
#include <stdlib.h>

// OS specific libraries
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif

// TermDLL Libraries
#include "export.h"
//#include "global.h"

namespace termDLL {

	namespace core {
		API void init(std::string dir, bool printInfo);
		API bool run(std::vector<std::string> input);
	}
	

}

#endif


