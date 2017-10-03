/************************************************************************
 Title         : station_final.cpp
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : defines all of the funcitons used in the station class
 Purpose       : stations are used to hold passengers waiting for trains
		 and for unloading and loading trains
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#include "station_final.h"
#include "time_final.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "queue_final.h"
#include "train_final.h"
using namespace std;

/* most of these functions are simple functions to set or retrieve data. */
Station::Station()
{
	stationName="";
	aTrain=NULL;
}

void Station::setTrain(Train* train)
{
	aTrain=train;
}

Train* Station::getTrain()
{
	return aTrain;
}

void Station::setStationName(string name)
{
	stationName=name;
}

string Station::getStationName()
{
	return stationName;
}

void Station::fromQueueToTrain()
{


	Train *train = aTrain;
	Queue *queue = aQueue;

	if(!train)
		return; //If there is no train, end the function.

	for(int i=0; i<12; i++)
	{
		// all i that are less than 4 will be rounded to zero
		double cabin = floor(i/4);

		//convert the double to an int type
		int car= static_cast<int>(cabin);

		//get that number in car+1= from 1-3
		int numberInCar = train->getNumberInCar(car+1);
		//This while loop loads all passengers waiting on the queues into the trains.
		while(numberInCar != 64 && emptyQueues(car*4))
		{
				for(int i=car*4; i<((car*4)+4); i++)
				{
					if((queue)[i].isEmpty()==false && numberInCar < 64)
					{	
						train->load((queue)[i].dequeue(),car+1);
						numberInCar=train->getNumberInCar(car+1);
						
					}
				}

		}


	}
}

bool Station::emptyQueues(int start)//return false if all four queues are empty
{
		if(aQueue[start].getnOfPassengers()!=0 || aQueue[start+1].getnOfPassengers() != 0 || aQueue[start+2].getnOfPassengers() != 0 
		|| aQueue[start+3].getnOfPassengers() != 0)
			return true;
		else
			return false;

}

Passenger Station::fromTrainToQueue()
{
		Passenger curr;
		Train *train = aTrain;
		
	//This for loop goes through all train cars, finds everyone who needs to transfer at B3 and brings them to the appropriate station queue.
	for(int j=1;j<4;j++)
	{	
		for(int i=1; i<=train->getNumberInCar(j); i++)
		{
			curr=train->find(j, i);
	
			if(stationName=="B3R" && (curr.destination=="B1" || curr.destination=="B2" || curr.destination=="A5")) //If the station is B3-RED && Passenger wants to go to BLUE stations
				{
					curr=train->remove(j,i); //Remove the passenger at Car 1, pos i
					return curr; 			//Return the temp pointer for the removed passenger to transferB3()
				}

				//Else if north train is on a blue line.
			else if(stationName=="B3B" && (curr.destination=="A1" || curr.destination=="A2" ||
				curr.destination=="A3" || curr.destination=="A4" || curr.destination=="B4" ||
				curr.destination=="B5")) //If the station is B3-BLUE && Passenger wants to go to RED stations
				{
					curr=train->remove(j,i); //Car 1, at pos i
					return curr; //Return temp to transferB3()
				}
		}
	}
	//If nobody else wants to transfer, the desination is set to -1. This is used to end the loop in the caller function transferB3().
	curr.destination = "-1";
	return curr;
}

void Station::randomQueue(Passenger person)
{
	aQueue[rand() % 12].enqueue(person);
	//puts a passenger on a randomly selected queue in the station.
}

void Station::incrementWaitTime()
{
	for(int i = 0; i<12; i++)
	{
		if(aQueue[i].isEmpty()==false)
			aQueue[i].increaseWaitTime();
	}
}
