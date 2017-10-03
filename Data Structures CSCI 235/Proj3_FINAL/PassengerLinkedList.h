/************************************************************************
 Title         : PassengerLinkedList.h
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : declares the class PassengerLinkedList
 Purpose       : cars on trains are portrayed as PassengerLinkedLists, 
		 so these functions define hoe passengers get on and off of
		 trains.
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#ifndef _CS235_LINKEDLIST_H_
#define _CS235_LINKEDLIST_H_
#include <string>
#include "Passenger.h"
using namespace std;
/*struct Passenger
{
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
struct ListNode
{
        Passenger data;
        ListNode* next;
};

class PassengerLinkedList {
	private:
		int size;
		ListNode* head;
		ListNode* find(int pos);



	public:
        	PassengerLinkedList();
		//Default constructor.
		bool isEmpty ();
		//precondition: takes no arguments
		//postcondition: returns a boolean value corresponding to the lack of passengers in the LinkedList.
		int  getLength ();
		//precondition: takes no arguments.
		//postcondition: returns the number of passengers in the linked list.
		void insert (int pos, Passenger item);
		//preconditions: position in bounds and passenger valid with valid destination (which is not checked here)
		//postcondition: places the passenger into position pos.
		Passenger remove (int pos);
		//precondition: valid position in the LinkedList.
		//postcondition: removes and destroys this passenger.
		Passenger retrieve (int pos);
		//precondition: valid position in the LinkedList.
		//postcondition: removes this passenger withouot destroying him/her.
		Passenger findPass(int pos);
		//basically a redundant retreive.
		~PassengerLinkedList();
		//cleans up.
};
#endif
