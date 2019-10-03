/*
	export.h
		Defines API, thats it
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
#ifdef TERMDLL_EXPORT
#define API __attribute__((visibility("default")))
#endif
#endif
