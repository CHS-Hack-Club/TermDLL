/*
	global.h
		Defines variables(mostly to avoid linker errors...) that are globally used in namespaces
*/


#pragma once

#ifndef GLOBAL_H_
#define GLOBAL_H_

#ifdef _WIN32
#define GLOBAL_VAR __declspec(selectany)
#else
#define GLOBAL_VAR extern
#endif

#include "TermDLL.h"

namespace termDLL{
	namespace core {
		GLOBAL_VAR std::string currentWorkingDirectory;
	}
}

#endif
