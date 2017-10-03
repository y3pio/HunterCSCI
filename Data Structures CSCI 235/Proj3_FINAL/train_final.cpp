/************************************************************************
 Title         : train_final.cpp
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : defines the train's functions
 Purpose       : trains and their cars move passengers throught a train system
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#include "train_final.h"
#include <cctype>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Passenger Train::find(int carNum, int pos)
{
	//This function finds a passenger in a specified position in a specified car.
	if(pos<0 || pos>64)
		throw "hell no";
	switch(carNum)
	{
		case 1:
			//car one
			if(pos<=numberInCar1)
				return car1.findPass(pos);
		case 2:
			//car two
			if(pos<=numberInCar2)
				return car2.findPass(pos);
		case 3:
			//car 3
			if(pos<=numberInCar3)
				return car3.findPass(pos);
		default:
			//out of bounds error
			throw "issue";
	}
}
Passenger Train::remove(int carNum, int pos)
{
	//This function removes a passenger at position pos in car carNum.
	//error checking
	if(pos<0 || pos>64)
		throw "hell no";
	switch(carNum)
	{
		case 1:
			//car one
			if(pos<=numberInCar1)
				return car1.remove(pos);
		case 2:
			//car two
			if(pos<=numberInCar2)
				return car2.remove(pos);
		case 3:
			//car three
			if(pos<=numberInCar3)
				return car3.remove(pos);
		default:
			//out of bounds error
			throw "issue";
	}
}
Train::Train(){}
Train::Train(string location, char direction, char line)
{
	//sets all of the member variables to what was passed.
	this->location = location;
	if(direction!='n' && direction!='s' && direction != 'N' && direction != 'S')
		throw "error";
	this->direction = direction;
	if(line!='r' && line!='b' && line!='R' && line!='B')
		throw "error";
	this->line = line;
	startingTime = g_Min;
	moved=false;
}

Train::~Train(){}
void Train::load(Passenger passenger, int carNum)
{
	//loads the passenger given to the specified car if the car is not already full.
	passenger.beenOnTrain = true;
	//beenOnTrain is used to calculate the second wait time for people who decide to transfer.
	switch(carNum)
	{
		//cases equate to car numbers.
		case 1:
			if(car1.getLength() >=64)
				throw 1;
			car1.insert(car1.getLength()+1, passenger);
			numberInCar1++;
			break;
		case 2:
			if(car2.getLength() >=64)
				throw 1;
			car2.insert(car2.getLength()+1, passenger);
			numberInCar2++;
			break;
		case 3:
			if(car3.getLength() >=64)
				throw 1;
			car3.insert(car3.getLength()+1, passenger);
			numberInCar3++;
			break;
		default:
			//out of bounds error.
			throw "error";
	}		
}
void Train::unload()
{
	//outstream is used to store passenger information to an external output file.
	ofstream outstream;
	outstream.open("output1.txt", ios::out | ios::app);
	Passenger temp;
	int i = 1;
	while(i<=car1.getLength())
	{
		//while loop removes all passengers from the current car that want to get off at this station.
		if(car1.retrieve(i).destination == location)
		{
			temp = car1.remove(i);
			outstream << "Starting Time: " << temp.startingTime << endl;
			outstream << "Wait Time One: " << temp.waitTime1 << endl;
			outstream << "Wait Time Two: " << temp.waitTime2 << endl;
			outstream << "Origin       : " << temp.startingStation << endl;
			outstream << "Destination  : " << temp.destination << endl;
			outstream << "Got off at   : " << location  << " Time:" << g_Min << endl;
			temp.totalTime=g_Min - temp.startingTime;
			outstream << "Total Time: " << temp.totalTime << endl << endl;
		}
		else
		{
			i++;
		}
	}
	i = 1;
	while(i<=car2.getLength())
	{
		if(car2.retrieve(i).destination == location)
		{
			temp = car2.remove(i);
			outstream << "Starting Time: " << temp.startingTime << endl;
			outstream << "Wait Time One: " << temp.waitTime1 << endl;
			outstream << "Wait Time Two: " << temp.waitTime2 << endl;
			outstream << "Origin       : " << temp.startingStation << endl;
			outstream << "Destination  : " << temp.destination << endl;
			outstream << "Got off at   : " << location  << " Time:" << g_Min << endl;
			temp.totalTime=g_Min - temp.startingTime;
			outstream << "Total Time: " << temp.totalTime << endl << endl;
		}
		else{
			i++;
		}
	}
	i = 1;
	while(i<=car3.getLength())
	{
		if(car3.retrieve(i).destination == location)
		{
			temp = car3.remove(i);
			outstream << "Starting Time: " << temp.startingTime << endl;
			outstream << "Wait Time One: " << temp.waitTime1 << endl;
			outstream << "Wait Time Two: " << temp.waitTime2 << endl;
			outstream << "Origin       : " << temp.startingStation << endl;
			outstream << "Destination  : " << temp.destination << endl;
			outstream << "Got off at   : " << location  << " Time:" << g_Min << endl;
			temp.totalTime=g_Min - temp.startingTime;
			outstream << "Total Time: " << temp.totalTime << endl << endl;		
		}
		else{
			i++;
		}
	}
	if(location == "B3B" || location == "B3R")
	//special case for B3, since the stations are actually named B3R and B3B
	{
		int i = 1;
		while(i<=car1.getLength())
		{
			if(car1.retrieve(i).destination == "B3")
			{
				temp = car1.remove(i);
				outstream << "Starting Time: " << temp.startingTime << endl;
				outstream << "Wait Time One: " << temp.waitTime1 << endl;
				outstream << "Wait Time Two: " << temp.waitTime2 << endl;
				outstream << "Origin       : " << temp.startingStation << endl;
				outstream << "Destination  : " << temp.destination << endl;
				outstream << "Got off at   : " << location  << " Time:" << g_Min << endl;
				temp.totalTime=g_Min - temp.startingTime;
				outstream << "Total Time: " << temp.totalTime << endl << endl;
			}
			else
			{
				i++;
			}
		}
		i = 1;
		while(i<=car2.getLength())
		{
			if(car2.retrieve(i).destination == "B3")
			{
				temp = car2.remove(i);
				outstream << "Starting Time: " << temp.startingTime << endl;
				outstream << "Wait Time One: " << temp.waitTime1 << endl;
				outstream << "Wait Time Two: " << temp.waitTime2 << endl;
				outstream << "Origin       : " << temp.startingStation << endl;
				outstream << "Destination  : " << temp.destination << endl;
				outstream << "Got off at   : " << location  << " Time:" << g_Min << endl;
				temp.totalTime=g_Min - temp.startingTime;
				outstream << "Total Time: " << temp.totalTime << endl << endl;
			}
			else{
				i++;
			}
		}
		i = 1;
		while(i<=car3.getLength())
		{
			if(car3.retrieve(i).destination == "B3")
			{
				temp = car3.remove(i);
				outstream << "Starting Time: " << temp.startingTime << endl;
				outstream << "Wait Time One: " << temp.waitTime1 << endl;
				outstream << "Wait Time Two: " << temp.waitTime2 << endl;
				outstream << "Origin       : " << temp.startingStation << endl;
				outstream << "Destination  : " << temp.destination << endl;
				outstream << "Got off at   : " << location  << " Time:" << g_Min << endl;
				temp.totalTime=g_Min - temp.startingTime;
				outstream << "Total Time: " << temp.totalTime << endl << endl;		
			}
			else{
				i++;
			}
		}
	}	
	outstream.flush();
	outstream.close();
}

//The remaining funcitons are simple and easy to read.
string Train::getLocation()
{return location;}

char Train::getLine()
{return line;}

char Train::getDirection()
{return direction;}

int Train::getNumberInCar(int carNumber)
{
	switch(carNumber)
	{
		case 1:
			return car1.getLength();
		case 2:
			return car2.getLength();
		case 3:
			return car3.getLength();
		default:
			throw "fit";
	}
}
void Train::setDirection(char direction)
{
	if(direction!='n' && direction !='s' && direction !='N' && direction !='S')
		throw "error";
	this->direction = direction;
}
void Train::setLocation(string location)
{this->location = location;}

void Train::setStartingTime(int minutes)
{startingTime = minutes;}

int Train::getStartingTime()
{return this->startingTime;}

void Train::setMoved(bool condition)
{moved=condition;}

bool Train::getMoved()
{return moved;}
