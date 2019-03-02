/*Main CPP File*/

#include "filter.h"
#include<iostream>
#include<string>

using namespace std;
int main() {
	
	int date[MAX_DATA];
	const char stringPara[] = "3 6";
	int count = LoadMeasurements("inputFile.txt", date, MAX_DATA);  //Reading the data from the input file & store measurements in an array
	cout << "Number of Measurements Loaded :" << count << endl; 
	int filterCount= UseFilter("DynamicLinkLibrary.dll", date, count, stringPara);  //To load the DLL by name and use that function to process the array measurements
	if (filterCount > 0) {
		int countSave = SaveMeasurements("outputFile.txt", date, count);  //To output the processed data to the file
		cout << "Save Measurements: " << countSave << endl;
	}
	else {
		return UnknownError;
	}

	cin.get();
}