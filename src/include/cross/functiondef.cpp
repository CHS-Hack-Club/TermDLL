/*
	cross/functiondef.cpp
		Contains all definitions of cross platform functions/methods
*/


#include "cross/functiondef.h" // Includes cross/filesystem.h
#include "global.h"

namespace termDLL{
	namespace functions{

		void init(returnDataMacro* data){
			termDLL::core::currentWorkingDirectory = std::filesystem::current_path();
			osFunctions::init(data); // Pass data through
		}
			
	}	
}

