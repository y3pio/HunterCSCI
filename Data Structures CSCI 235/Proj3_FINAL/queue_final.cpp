/************************************************************************
 Title         : queue_final.cpp
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : defines the queue's functions
 Purpose       : Queues are used in each station to hold passengers
		 waiting to get onto a train.
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#include "queue_final.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////
//Constructors, copy Constructors and Overloading//
///////////////////////////////////////////////////
Queue::Queue()
{
	first=NULL;
	last=NULL;
	nOfPassengers=0;
};

Queue::~Queue()
{
	while(!isEmpty())
	{
		dequeue();
	}

}


/////////////
//Functions//
/////////////
//Is empty, returns true if queue is empty.
bool Queue::isEmpty()
{
	return(nOfPassengers==0);
}

//Enqueue a passenger.
void Queue::enqueue(Passenger person)
{
	Node* curr=new Node;
	curr->data=person;
	curr->next=NULL;
	if(first==NULL)
	{
		first=last=curr;
	}
	else
	{
		last->next=curr;
		last=curr;
	}
	nOfPassengers++;
}

//Dequeue a passenger, return variable Passenger
Passenger Queue::dequeue()
{
	if(isEmpty())
		throw "QueueException.EmptyQueueError";

	else
	{
		Node* curr;
		Passenger person;
		person=first->data;
		curr=first;
		first=first->next;
		if(first==NULL)
			last==NULL;
		delete curr;
		nOfPassengers--;
		return person;
	}
}

int Queue::getnOfPassengers()
{
	return nOfPassengers;
}

//Find function to find passengers on the queue (to be used by incriment wait time function)
//Returns the node pointer at which the passengers reside are in.
Node* Queue::find(int pos)
{
	//if the position is grater than the size of the queue,
       // or less than 1 the position will be thrown to exceptions
       if(pos>nOfPassengers || pos<1)
       		throw "ErrorFindQueue";
          
	//Temp is pointing to were head points to- to the first position
        Node* temp=first;
          
	for(int i=1; i<pos;i++)
        {
        	//temp is set to point on the next structure in line. 
                temp=temp->next;
        }
          
	//temp is pointing to the position desired 
        return temp;
}



//Increase wait time function to increase the wait time of all the passengers on the queue
void Queue::increaseWaitTime()
{
	if(!isEmpty())
	{
		for(int i=1; i<=nOfPassengers; i++)
		{
			if(find(i)->data.beenOnTrain==false)
				find(i)->data.waitTime1++;

			else if(find(i)->data.beenOnTrain==true)
			//This case means that the person is a transfer.
				find(i)->data.waitTime2++;
		}
	}
}


