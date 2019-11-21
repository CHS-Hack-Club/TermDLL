/*
    export.h -- defines "API" keyword for exporting functions 
        That's it
*/
#ifndef _EXPORT_H_
#define _EXPORT_H_

#ifdef _WIN32
    #ifdef TERMDLL_EXPORTS
        #define API __declspec(dllexport)
    #else
        #define API __declspec(dllimport)
    #endif
    #define GLOBAL_VARIABLE __declspec(selectany)
#endif

#ifdef __linux__
    #define API
    #define GLOBAL_VARIABLE static
#endif

#endif // _EXPORT_H_