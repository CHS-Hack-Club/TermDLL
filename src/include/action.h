/*
	action.h
		"Tagging" system that tells TermDLL what to do after, before, and with the input provided.

		process: default, do the normal processing
		file: A file is being read/used
		
		input: immediatly ask for input
		output: Output without asking for input
		finish: Finish reading and input, give the terminal control

		etc: special wildcard

*/

#ifndef ACTION_H_
#define ACTION_H_

#include "TermDLL.h"
#include <string>

namespace termDLL{
	namespace actions{

		enum class actionType{process, file, etc};
		enum class afterEffect{input, output, finish};
		struct action{
			std::vector<actionType> myActions; // What type of action
			std::vector<std::string> descriptions; // Descriptions for each action
			int actionID; // For management
		};
	}
}



#endif
