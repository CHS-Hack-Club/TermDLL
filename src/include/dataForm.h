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
            userInput(){}
			~userInput(){}
			virtual T update(inputMode mode = inputMode::io, bool temp = true, bool alwaysGetInput = true, bool formatted = true){
				T buffer;
				switch(mode){
					case inputMode::zero:			//Zero
						{break;}
					case inputMode::io:				//Allow input and output
					{
						if(formatted){
							std::cin >> buffer;				
						}else{
							std::getline(std::cin, buffer);
						}
						
						break;
					}
					case inputMode::ionly:				//Disable console output
					{
						std::cout.setstate(std::ios_base::failbit); // Disable std::cout
						if(alwaysGetInput){
							if(formatted){
								std::cin >> buffer;
							}else{
								std::getline(std::cin, buffer);
							}
						}
						std::cout.clear(); // Reset std::cout for output
						break;
					}
					case inputMode::outputonly:				//Only allow output
						// Do nothing..
						{break;}
					default:
						{break;}
				}
				updated = buffer;
				return updated;				
			}
			virtual T data(){ // Return user input unless specified
				return updated; 
			}
        private:
			T updated;
			inputMode myMode = inputMode::io; // Allow input and output by default.
    };
    
    
}

#endif