/*
	cross/functiondef.cpp
		Contains all definitions of cross platform functions/methods
*/


#include "cross/functiondef.h"

namespace termDLL{
	namespace functions{

		void init(){
			termDLL::core::currentWorkingDirectory = std::filesystem::current_path();
			
		}
			
	}	
}

