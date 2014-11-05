
/* 
run this simple c++ code and if your installation was done correctly,
the console should open and continously print out the the real time tracking data.
*/

// for printing to console
#include <iostream>

// these sleep function are in the tutorial for demonstration purposes only
#ifdef _WIN32
    #include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif


// +++++++++++++++++++++++++   HERE IT GETS INTERESTING +++++++++++++++++++++++++++++++++


// include the header of the FaceSpaceTracker
#include "FaceSpaceTracker.h"

/*
create a global variable of a Tracker. name it whatever you like
this boots the tracker with the configuration of the file "FaceSpaceTrackerDefault.cfg",
this is also the defualt config file that will be called if the brackets are omited.
*/
FaceSpaceTracker myTracker("FaceSpaceTrackerDefault.cfg");


int main(){

	// you dont have to initialize anything here
	// To get an understanding what is being tracked, set the following boolean true
	bool showcamera = true;

	// print out the log of the camera
	myTracker.reportStatus();


	// print info for what will happen if showcamera = true
	if(showcamera){
		std::cout << "Opening a new window to show the tracking input. " << std::endl;
		std::cout << "This is for demonstration purpose only, it will slow down the program " << std::endl;
		std::cout << "------ legend -------- " << std::endl;
		std::cout << " Green rectangle: opencv highlighted face area " << std::endl;
		std::cout << " Red rectangle: area where the face is expected in the next tracking" << std::endl;
		std::cout << " Tiny black rectangle: estimated position of the eyes, this is the point being tracked " << std::endl;
		std::cout << "----end legend -------- " << std::endl;
		
		// activate the camera window.
		myTracker.setShowCamFrame(showcamera);
	}

		std::cout << " note: close the console to terminate this program " << std::endl;

	// then start your main loop
	while(true){
		
		// call this method to update the trackdata. Try to use it once per frame
		myTracker.updateTrackData();

		// Now you can ask the tracker for the latest data
		double xPosition = myTracker.getXposition();
		double yPosition = myTracker.getYposition();
		double zPosition = myTracker.getZposition();

		// lets print it
		
		std::cout << " ( x = " << xPosition << " | y = " << yPosition << " | z = " << zPosition << " ) " ;//<< std::endl;
		std::cout << std::string(100, '\b');
		
		// do whatever you want with this data

		//...

		// here we send the program to sleep for 17 milliseconds to simulate the
		// waiting time of a programm that runs 60 loops per second,
		// like in a smooth visualisation that runs 60 frames per second 
		sleep(17);


	}

}