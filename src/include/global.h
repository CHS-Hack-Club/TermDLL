/*
	global.h
		Defines variables(mostly to avoid linker errors...) that are globally used in namespaces
*/


#pragma once

#ifndef GLOBAL_H_
#define GLOBAL_H_

#ifdef _WIN32
#define GLOBAL_VAR __declspec(selectany)
#define DEFAULT_PATH "C:\\"
#else
#define GLOBAL_VAR static
#define DEFAULT_PATH "/home/"
#endif

#include <iostream>
#include <string>
#include <vector>
#include "action.h"


namespace termDLL{
	namespace core {
		GLOBAL_VAR std::string currentWorkingDirectory;
		GLOBAL_VAR std::vector<::termDLL::actions::action> myActionList;
		GLOBAL_VAR std::string version;
		
	}
}

#endif
