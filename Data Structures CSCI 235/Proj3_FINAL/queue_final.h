/************************************************************************
 Title         : queue_final.h
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : declares the class Queue
 Purpose       : Queues are used in each station to hold passengers
		 waiting to get onto a train.
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/
#ifndef QUEUE_FINAL_H
#define QUEUE_FINAL_H
#include "time_final.h"
#include "Passenger.h"
#include <string>

using namespace std;

/*struct Passenger{
	public:
		string destination;
		int startingTime;
		int waitTime1;
		int waitTime2;
		bool beenOnTrain;
		int totalTime;
};
Defined elsewhere.
*/

struct Node
{
      Passenger data;
      Node* next;    
};

class Queue
{
      private:
              Node* first;
              Node* last;
              int nOfPassengers;
              
      public:
             Queue();
	     //constructor
	     ~Queue();
	     //destructor
	     bool isEmpty();
	     //precondition: takes no arguments
	     //postcondition: returns a boolean value corresponding to the presence of passengers in the queue.
             void enqueue(Passenger item);
	     //precondition: valid passenger. //side note: I highly disagree with calling passengers "items." Passengers are 
					      //people too. :(
	     //postcondition: passenger is placed at the back of the queue.
             Passenger dequeue();
	     //precondition: nonempty queue.
	     //postcondition: returns the first passenger on the queue after taking him/her off of the queue.
	     int getnOfPassengers();
	     //precondition: no arguments taken
	     //postcondition: number of passengers in queue returned.
	     Node* find(int pos);
	     //preconditions: valid position
	     //postcondition: returns a pointer to the node at the position pos.
	     void increaseWaitTime();
	     //precondition: non-empty queues.
	     //postcondition: increases wait time for all people in the queues.
             
};

#endif
