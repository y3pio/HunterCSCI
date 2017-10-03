/************************************************************************
 Title         : Passenger.h
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : defines the struct passenger.
 Purpose       : to define the struct passenger
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#include <string>
using namespace std;
#include "time_final.h"
#ifndef PASSENGER_H
#define PASSENGER_H

struct Passenger{
	string destination;
	string startingStation;
	int startingTime;
	int waitTime1;
	int waitTime2;
	bool beenOnTrain;
	int totalTime;
	//all of this data is used at some point in the program, and most of it is used in the output file.
};

#endif
