/************************************************************************
 Title         : system_final.h
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : declares the class System
 Purpose       : system takes care of all processes including moving
		 trains and making sure passengers transfer accordingly
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#ifndef SYSTEM_FINAL_H
#define SYSTEM_FINAL_H
#include "station_final.h"
#include "train_final.h"
#include "time_final.h"

struct systemTrack
{
	Train* aTrain;
	Station* aStation;
};

class System
{
	private:
		
		systemTrack redLines[38];
		systemTrack blueLines[26];
	public:
		System();
		//constructor does construction more effeciently than the MTA.
		void setNameForStations();
		//precondition: no arguments taken
		//postcondition: sets all station names.
		void moveTrains(char, int, int, int);
		//precondition: takes a character, and three ints.
		//postcondition: moves the trains accordingly.
		void setMoved(char line, int j, bool condition);
		//precondition: takes a character, an int and a bool.
		//postcondition: sets the moved condition on the train in the station.
		void sendNewTrain(char line, int index);
		//precondition: a character line and the index of the station
		//postcondition: sends a new train object to the specified station
		void transferB3(char line, int index);
		//precondition: takes a character and an int.
		//postcondition: transfers all passengers to the appropriate queues.
		void passAndQueue(int bDestination, int people, string station);
		//precondition: takes int, int and string.
		//postcondtion: creates the appropriate number of passengers and queues them up.
		void callPassAndQueue(int aVolume, int bVolume, int dest);
		//precondition: takes three ints.
		//postcondition: calls pass and queue with a randomized number of passengers within the limits.
		void increaseWaitTime();
		//precondition: nonempty queues.
		//postcondition: increments all proper wait times.
	
};

#endif
