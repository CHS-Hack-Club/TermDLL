/*
	streams.h --- Contains all of the user input/output streams(think std::cout and std::cin but more customized)
		Contains class definitions similar to std::cout and std::cin; but are customized to have formatted input
		and formatted output, attached to the termdll library, with custom parsers.

*/
#ifndef _STREAMS_H_
#define _STREAMS_H_
#include "export.h"
#include "dataForm.h"

#include <iostream>
#include <vector>

namespace TermDLL{
    template<class T>
    class API userInput{
        public:
            userInput(){}
			~userInput(){}
			
			T update(inputMode mode = inputMode::io, bool temp = true, bool alwaysGetInput = true, bool formatted = false){
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

			T update(streamMode inputMode){
				return update(inputMode.myMode, inputMode.temporary, inputMode.alwaysGetInput, inputMode.formatted);
			}

			T update(){
				return update(myStreamMode);
			}
			
			virtual T data(){
				return updated;
			}
        private:
			T updated;
			inputMode myMode = inputMode::io; // Allow input and output by default.
			streamMode myStreamMode;
    };





	class API command : userInput<std::string>{
		public:
			command();
			~command();


		private:

		
	};

	
}




#endif