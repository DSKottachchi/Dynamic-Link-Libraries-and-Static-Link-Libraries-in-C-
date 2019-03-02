/*Static Link Library Application*/

#include "filter.h"  //SLL Header Import
#include <Windows.h> 
#include <iostream>
#include <fstream>
#include <assert.h>  //File which contains assert function
#include <string> 
#include <sstream>
	

//Load Measurements- To read data from a input file and store in a array
	int LoadMeasurements(const char* inputFile, int data[], int maxSizeofArr) {
		
		int num, count;
		short loop = 0;
		std::string line;

		std::ifstream InputFile;  
		InputFile.open(inputFile);  

		try {
			if (InputFile.is_open()) {
				while (!InputFile.eof()) {
					std::getline(InputFile, line, '\n');
					std::stringstream sst(line);  //Convert from string to integer
					sst >> num;
					data[loop] = num;  // Storing the values in the file in a array 
					std::cout << data[loop] << "\n";  
					loop++;
				}
			}
			else {
				return InvalidParameters; //Cannot find file
			}
		}
		catch (const std::exception&) {
			return UnknownError;
		}

		InputFile.close();  //Close File
		return loop;   
	}


//Use Filter- To load the DLL at run time from the file
	int UseFilter(const char* dllName, int data[], int count, const char parameterString[7]) {
		
		try {
			HMODULE handle = LoadLibrary(dllName);  //Loading the DLL library

			if (handle != NULL) {
				FNPTR fn = (FNPTR)GetProcAddress(handle, "Filter"); //Loading the function from th DLL

				if (!fn) {
					std::cout << "\nCould not locate function";
					return DLLInvalidFormat; //When the function could not be loaded from the DLL
				}
				else {
					int algorithm = fn(data, count, parameterString);  
					return algorithm;  
				}
			}
			else {
				std::cout << "Could not Load the library" << std::endl;
				return DLLNotFound; //When the DLL cannot be loaded
			}

			FreeLibrary(handle); //Free the DLL when it's done being used
		}
		catch (const std::exception&) {
			return UnknownError;
		}
	}


//Save Measurements- To save the data from the array to a output file
	int SaveMeasurements(const char* outputFile, int data[], int maxSize) {
		int count;
		std::ofstream OutFile;
		OutFile.open(outputFile, std::ios::app); //Creating the output file
		try {
			if (OutFile.is_open()) {
				for (count = 0; count < maxSize; count++) {
					OutFile << data[count] << std::endl;  //Output the values in the array to a file
					std::cout << data[count] << std::endl;  
				}
			}
			else {
				std::cout << "Unable to open file" << std::endl;
				return InvalidParameters; //Cannot find file
			}
		}
		catch (const std::exception&) {
			return UnknownError;
		}

		OutFile.close(); //Close the output file
		return count;
	}
