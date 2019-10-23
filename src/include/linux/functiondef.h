/*
	functiondef.h
		Contains all function/method declarations for linux

		All functions must return termDLL::functions::returnData;
			

*/

#pragma once

#ifndef LINUX_FUNCTION_DEF_H_
#define LINUX_FUNCTION_DEF_H_

#include <iostream>
#include <unistd.h>
#include "export.h"
#include "cross/functiondef.h"

namespace termDLL {
	namespace functions {
		namespace linuxFunc {
			template<typename T>
			API void init(returnDataMacro* data);
			GLOBAL_VAR std::unordered_map<std::string, std::function<returnDataMacro*(returnDataMacro*)>> linuxFuncs;

			
		}
	}
}


#endif