/*
    dataForm.h --- Contains structure definitions for standard data types
        EG: userInput, event
*/
#ifndef _DATAFORM_H_
#define _DATAFORM_H_
#include "export.h"
#include <iostream>
#include <vector>


namespace TermDLL{

	enum class inputMode{
		zero=0, 	// Don't get any input or output
		io, 		// Allow input and output
		ionly, 	    // Allow NO std::cout, std::cerr, etc
		outputonly  // Only allow output, no input
	};    

	struct streamMode{
		inputMode myMode;
		bool temporary;
		bool alwaysGetInput;
		bool formatted;		
	};

}

#endif