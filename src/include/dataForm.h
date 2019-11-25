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

    template<class T>
    class API userInput{
        public:
            userInput();
			~userInput();
			virtual T update(inputMode mode = inputMode::io, bool temp = true, bool alwaysGetInput = true, bool formatted = true){
				T buffer;
				switch(mode){
					case 0:				//Zero
						// Do nothing
						break;
					case 1:				//Allow input and output
						std::cin >> buffer;
						break;
					case 2:				//Disable console output
						std::streambuf* stdbuf = std::cout.rdbuf();
						std::cout.rdbuf(NULL); // Set std::cout to output to nothing
						if(alwaysGetInput){
							if(formatted){
								std::cin >> buffer;
							}else{
								std::getline(std::cin, buffer);
							}
						}
						std::cout.rdbuf(stdbuf); // Reset to original buffer
						break;
					case 3:				//Only allow output
						// Do nothing..
						break;
					default:
						break;
				}
			};
			virtual T data(){ // Return user input unless specified
				return updated; 
			};
        private:
			T updated;
			inputMode myMode = inputMode::io; // Allow input and output by default.
    };
    
    
}

#endif