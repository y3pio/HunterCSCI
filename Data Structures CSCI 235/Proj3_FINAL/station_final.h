/************************************************************************
 Title         : station_final.h
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : declares the class Station
 Purpose       : stations are used to hold passengers waiting for trains
		 and for unloading and loading trains
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#ifndef STATION_FINAL_H
#define STATION_FINAL_H
#include "train_final.h"
#include "queue_final.h"
#include <cstdlib>
using namespace std;
class Station
{
	private:
		string stationName;
		Train* aTrain;
		Queue aQueue[12];

	public:
		Station();
		Station(Train* train);
		//previous two are constructors
		void setTrain(Train* train);
		//precondition: valid train pointer.
		//postcondition: sets the aTrain to the passed train pointer.
		Train* getTrain();
		//precondition: none
		//postcondition: returns aTrain.
		void setStationName(string name);
		//precondition: valid station name as specified by project design.
		//postcondition: sets the station name.
		string getStationName();
		//precondition: no arguments taken
		//postcondition: returns stationName.
		
		void fromQueueToTrain();
		//precondition: nonempty queues.
		//postcondition: moves all people from the queues onto a train.
		bool emptyQueues(int start);
		//precondition: int start is the number referring to the index of the first (of four) queues we want
		//	      : to check.
		//postcondition: returns boolean value according to presence of passengers.
		Passenger fromTrainToQueue();
		//precondition: called at B3station to transfer passengers. No parameters.
		//postcondition: returns a passenger that is then put onto a queue.
		void randomQueue(Passenger transfer);
		//precondition: valid passenger who needs to transfer
		//postcondition: places passenger onto random queue of corresponding platform.
		void incrementWaitTime();
		//precondition: non-empty queues.
		//postcondition: increases the appropriate wait time of all the people in the queues.
		
		
};

#endif                                                                                                                                                                                                                                                                                   
