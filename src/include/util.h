/*

	util.h
		General utility library for use in termdll(eg: filesystem stuff)

*/

#pragma once

#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include "export.h"
#include "cross/filesystem"

namespace termDLL{

	namespace utils{

		namespace fs{
			API std::string getPath();
			API void setPath(std::string pathStr);
		}
		
	}

}


#endif