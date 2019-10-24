/*

	util.h
		General utility library for use in termdll(eg: filesystem stuff)

*/

#pragma once

#ifndef UTIL_H_
#define UTIL_H_

#include "export.h"
#include <iostream>
#include <filesystem>

namespace termDLL{

	namespace utils{

		namespace fs{
			API std::string getPath();
			API void setPath(std::string path);
		}
		
	}

}


#endif