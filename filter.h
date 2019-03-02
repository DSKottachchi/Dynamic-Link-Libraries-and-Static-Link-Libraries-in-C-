/*Static Link Library Header File*/

#ifndef _FILTER_H
#define _FILTER_H

typedef int(*FNPTR)(int*, int, const char[]);

const int Success = 0;
const int Failure = -1;
const int DLLNotFound = -2;       //can't find dll to import
const int DLLInvalidFormat = -3;  //Unable to find import function in the dll
const int UnknownError = -4;
const int InvalidParameters = -5;

const int MAX_DATA = 1000;        //the maximum size of the array for loading data    		
		
int LoadMeasurements(const char* inputFile, int data[],int maxSize);   //To read data from a input file and store in a array
int UseFilter(const char* dllName, int data[], int count, const char parameterString[7]);  // To load the DLL at run time from the file
int SaveMeasurements(const char* outputFile, int data[], int maxSize); // To save the data from the array to a output file
	
#endif