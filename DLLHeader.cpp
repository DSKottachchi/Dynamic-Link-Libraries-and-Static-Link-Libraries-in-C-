/*Dynamic Link Library application*/

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h> //File which contains assert function

#ifndef DLL_HEADER
#define DLLHEADER __declspec(dllexport)
#else
#define DLLHEADER __declspec(dllimport) 

extern "C" __declspec(dllexport) int Filter(int data[], int count, const char parameterString[7]); //To export the filter function from the DLL to the SLL

	int Filter(int data[], int count, const char parameterString[7]) {
		int successCount = 0;
		std::stringstream ss(parameterString);
		int FirstInteger, SecondInteger; 
		ss >> FirstInteger >> SecondInteger;  //To store the values in the parameter string into variables
		for (int i = 0; i <= count; i++) {
			if (FirstInteger >= data[i]) {
				data[i] = FirstInteger;  //If the values in the array are lesser than the first integer
			}
			else if (SecondInteger <= data[i]) {
				data[i] = SecondInteger;   //If the values in the array are greater than the second integer 
			}
			else {
				data[i] = data[i];  //If the values in the array are greater than the first integer and lesser than the second integer
			}
			successCount++;
		}
		return successCount;
		assert(successCount == count);
	}

#endif
