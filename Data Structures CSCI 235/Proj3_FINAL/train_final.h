/************************************************************************
 Title         : train_final.h
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : declares the class Train
 Purpose       : trains and their cars move passengers throught a train system
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#ifndef TRAIN_FINAL_H
#define TRAIN_FINAL_H
#include "PassengerLinkedList.h"
#include "time_final.h"
using namespace std;
class Train{
	private:
		PassengerLinkedList car1;
		PassengerLinkedList car2;
		PassengerLinkedList car3;
		int numberInCar1;
		int numberInCar2;
		int numberInCar3;
		string location;
		char direction;
		char line;
		int startingTime;
		bool moved;
	public:
		Passenger find(int carNum, int pos);
		//precondition: valid car number and position
		//postcondition: returns the passenger without removing him/her
		Passenger remove(int carNum, int pos);
		//precondition: valid car number and position
		//postcondition: returns the passenger after removing him/her
		Train();
		Train(string location, char direction, char line);
		//constructor
		~Train();
		void load(Passenger passenger, int carNum);
		//precondition: valid passenger and car number
		//postcondition: if car is not full, the passenger will be loaded.
		void unload();
		//precondition: in a valid station with the proper location set.
		//postcondition: unloads all passengers with the current location as their destination.
		string getLocation();
		//precondition: valid train object
		//postcondition: returns location
		char getLine();
		//precondition: valid train object
		//postcondition: returns line color.
		char getDirection();
		//precondition: valid train object
		//postcondition: returns train direction
		int getNumberInCar(int carNumber);
		//precondition: valid train object, and car number.
		//postcondition: returns number in specified car.
		void setDirection(char direction);
		//precondition: direction can never be anything but n or s. This will be checked.
		//postcondition: direction will be set if it is valid.
		void setLocation(string location);
		//precondition: Please only pass valid location. Locations will not be checked.
		//postcondition: sets location member data to parameter.
		void setStartingTime(int minutes);
		//precondition: minutes needs to be positive (will not be checked)
		//postcondition: sets data startingTime to value of minutes.
		int getStartingTime();
		//precondition: none.
		//postcondition: returns startingTime.
		
		void setMoved(bool condition);
		//precondition: valid boolean condition
		//postcondition: moved member data set to condition.
		bool getMoved();
		//returns moved member data.
};

#endif	
