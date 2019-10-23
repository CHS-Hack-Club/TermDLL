/*
	export.h
		Defines API and GLOBAL_VAR, thats it
*/

#pragma once

// Define API keyword
#ifdef TERMDLL_EXPORT
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

// Linux doesn't support __declspec(dllexport)
#ifdef __linux__
	#define GLOBAL_VAR static

	#ifdef TERMDLL_EXPORT
		#define API __attribute__((visibility("default")))
	#endif

#else
	#define GLOBAL_VAR __declspec(selectany)
#endif
