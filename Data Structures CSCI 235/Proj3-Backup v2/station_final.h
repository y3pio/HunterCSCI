#ifndef STATION_FINAL_H
#define STATION_FINAL_H
#include "train_final.h"
#include "time_final.h"
#include <cstdlib>

class Station
{

	private:

	string stationName;
	Train* northTrain;
	Train* southTrain;
	Queue northQueue[12];
	Queue southQueue[12];
	      
	
	public:
	
	Station();
	//precondition:
	//post condition: set the pointers northTrain and southTrain to NUL. Creat a station that has 24 empty queues and no traines
	
	//Station(Queue nQueue[], Queue sQueue[],int size, string sName); //Not needed?


	Station(Train* aTrain, char direction);
	//preconditions: the constructor takes a Train pointer and a direction type char
	//post conditions: a station ids created and one of its Train pointers, the southTrain or the northTrain
			//is set to the pointer that was passed as an argument according to the direction	
			//specified                                                                         
 
	bool emptyQueues(int start, int lessThan, char direction);     
	//precondition:the function take two integers which signify from which index in the array and until not including index in
 			//the array there are passengers. There is also a char parameter that tell the function in which array to look
			// at the north or the south queue 
	//postcondition: if there is any passengers in any of the queues that the function was assigned to search in the function will return true.
        		// If there are no passengers at all in these queues the function will return false
           
	void fromQueueToTrain(char direction);
	//precondition: the function takes a parameter type char.
	//Post condition: according to the char parameter the function load the passenger from north or south queue to the train.
			// The passengers on queues in indexes 0-3 inclusive will be loaded to the first car of the train.
			// The passengers on queues in indexes 4-7 inclusive will be loaded to the second car of the train.
			// The passengers on queues in indexes 8-11 inclusive will be loaded to the 3rd car of the train. 
	
	string getStationName();
	//Precondition: none
	//post condition: returns the station name.

	void setStationName(string name);
	//precondition: take a string
	//postcondition: set the station name to the string argument
	
	Passenger* fromTrainToQueue(char direction);//YE
	//Precondition: takes a direction:
	//Postcondition: returns a passenger that needs to transfer off the train in station going in direction

	void unloadTrain(char direction);//YE
	//Precondition: takes a direction
	//Postcondition: will unload ALL passengers that needs to get off at the current station from the train going in directionl;

	void randomQueue(char direction, Passenger person); //Kevin's addition
	//Precondition: given a direction and a passenger variable
	//Postcondition: queues the passenger on either the north of south bound queues (12 of them) at the current station that is being called.
	
	void setNorthTrain(Train* aTrain);
	//preconditions: takes a Train pointer as an argument  
	//post conditions: set the northTrain pointer in the station to the argument passed
	
	Train* getNorthTrain();
	//precondition:
	//post condition: returns the pointer northTrain 
	
	void setSouthTrain(Train* aTrain);
	//preconditions: takes a Train pointer as an argument  
	//post conditions: set the southTrain pointer in the station to the argument passed
	
	Train* getSouthTrain();
	//precondition:
	//post condition: returns the pointer southTrain 
	
	void incrementWaitTime();
	//Precondition: created queues in stations.
	//Postcondition: increments the number of the appropriate waiting time. throws an error if the queue is empty. 
};  

#endif                                                                                                                                                                                                                                                                                   
