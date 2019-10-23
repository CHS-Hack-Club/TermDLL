/*
	cross/functiondef.h
		Contains all declarations of cross platform functions/methods
*/

#pragma once

#ifndef FUNCTION_DEF_H_
#define FUNCTION_DEF_H_
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include "export.h"

#define returnDataMacro termDLL::functions::baseData

namespace termDLL {
	namespace functions {


		class baseData {}; // Declaring this so: std::vector<baseData*> can contain different templates of returnData<T>


		template<class T = std::string> // Most of the time this will most likely be a string
		class returnData : public baseData {
			// Custom data
			std::vector<T> myData;

			// String data
			std::vector<std::string> strData;
			std::vector<char> charData;

			// Number data
			std::vector<int> intData;
			std::vector<float> floatData; // Use returnData<double> for double values
		};

		API void init();

	}
}


#endif
