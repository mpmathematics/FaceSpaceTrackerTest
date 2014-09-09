
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

	// then start your main loop
	while(true){
		
		// call this method to update the trackdata. Try to use it once per frame
		myTracker.updateTrackData();

		// Now you can ask the tracker for the latest data
		double xPosition = myTracker.getXHumanPosition();
		double yPosition = myTracker.getYHumanPosition();
		double zPosition = myTracker.getZHumanPosition();

		// lets print it
		std::cout << " ( " << xPosition << " | " << yPosition << " | " << zPosition << " ) " << std::endl;
		
		// do whatever you want with this data

		//...

		// now we send the program to sleep for 17 milliseconds to simulate the
		// waiting time of a programm that runs 60 loops per second,
		// like in a smooth visualisation that runs 60 frames per second 
		sleep(17);


	}

}