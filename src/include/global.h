/*
	global.h
		Defines variables(mostly to avoid linker errors...) that are globally used in namespaces
*/


#pragma once

#ifndef GLOBAL_H_
#define GLOBAL_H_
#define GLOBAL_VAR __declspec(selectany)

#include "TermDLL.h"

namespace termDLL{
	namespace core {
		GLOBAL_VAR std::string currentWorkingDirectory;
	}
}

#endif