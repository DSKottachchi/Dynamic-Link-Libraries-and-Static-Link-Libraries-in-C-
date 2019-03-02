# Dynamic-Link-Libraries-and-Static-Link-Libraries-in-C-

Creation of static and dynamically linked libraries on Visual studio C++.


# Problem Description 
Data (“signals”) from a device such as a microphone can be processed (“filtered”) in various ways, for example it can be smoothed to reduce the effect of random noise or limited to prevent the signal outside a specified range. 

A dynamic linked library(DLL) has been implemented so that the system can process signals using different algorithms("filters") each stored in the DLL. The signal will be stored in a text file(one integer per line).


The static link library will be used to:
 1. To read the data from the input file and store measurements in an array.
 2. To load DLL by name and use the function it contains to process the measurements in the array.
 3. To output the processed data to an array.
 
