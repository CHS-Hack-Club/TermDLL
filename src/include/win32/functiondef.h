/*
	functiondef.h
		Contains all of the #includes and declarations of functions/methods used.


*/



#ifndef WIN32_FUNCTION_DEF_H_
#define WIN32_FUNCTION_DEF_H_

#include <iostream>
#include <Windows.h>
#include "export.h"


namespace termDLL{
	namespace funtions{
		namespace windowsFunc{
			API void init(returnDataMacro* data);
			GLOBAL_VAR std::unordered_map<std::string, std::function<returnDataMacro*(returnDataMacro*)>> linuxFuncs;
		}
	}
}


#endif