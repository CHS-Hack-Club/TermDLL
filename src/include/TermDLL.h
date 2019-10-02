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
#include <stdio.h>
#include <stdlib.h>


// Define API keyword
#ifdef TERMDLL_EXPORT
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

// Linux doesn't support __declspec(dllexport)
#ifdef __linux__
#ifdef TERMDLL_EXPORT
#define API __attribute__((visibility("default")))
#endif
#endif

// OS specific libraries
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif

// TermDLL Libraries
#include "global.h"
#include "session.h"
#include "permissions.h"

namespace termDLL {

	namespace core {
		API void init(std::string dir);
		API bool run(std::vector<std::string> input);
	}


}

#endif

