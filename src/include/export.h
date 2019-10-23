/*
	export.h
		Defines API and GLOBAL_VAR, thats it
*/

#pragma once

// Define API and GLOBAL_VAR keyword

#ifdef _WIN32
	#ifndef API
		#ifdef TERMDLL_EXPORT
			#define API __declspec(dllexport)
		#else
			#define API __declspec(dllimport)
		#endif
	#endif
	#define GLOBAL_VAR __declspec(selectany)
#endif


#ifdef __linux__
	#define API
	#define GLOBAL_VAR static
#endif