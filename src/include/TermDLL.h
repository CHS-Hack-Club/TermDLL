/*
	Project rules:
		filename(only headers) --- summary
			Description with usage
	For example:

		TermDLL.h --- Main TermDLL include header to be used 
			Contains init(), run(), etc(), etc

*/
#ifndef _TERMDLL_H_
#define _TERMDLL_H_
#include "dataForm.h"
#include "export.h"
#include "TermDLL.h"


namespace TermDLL{
	API void init();
	API void run();
}


#endif