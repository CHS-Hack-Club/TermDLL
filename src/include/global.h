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
#define GLOBAL_VAR extern
#define DEFAULT_PATH "/home/"
#endif

#include <iostream>
#include <string>
#include "session.h"


namespace termDLL{
	namespace core {
		GLOBAL_VAR std::string currentWorkingDirectory;
		GLOBAL_VAR std::string version = "1.0";
		GLOBAL_VAR session firstSession(DEFAULT_PATH);

	}
}

#endif
