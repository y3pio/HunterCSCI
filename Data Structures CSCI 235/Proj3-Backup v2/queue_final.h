#ifndef QUEUE_FINAL_H
#define QUEUE_FINAL_H
#include <string>
#include "time_final.h"
using namespace std;
struct Passenger{
	public:
		string destination;
		int startingTime;
		int waitTime1;
		int waitTime2;
		bool beenOnTrain;
		int totalTime;
		Passenger* next;
};

class Queue
{
	public:
		Queue();				//default constructors
		Queue(Queue& qSource);			//copy constructors
		Queue& operator=(Queue& qSource);	//assignment op overloading
		~Queue();				//destructor


		bool isEmpty();
        						//Precondition: No parameters needed.
        						//Postcondition: Returns true if queue is empty, false other wise.

		void enqueue(Passenger person);
							//Precondition: Takes in a structure of type passenger.
							//Postcondition: Converts it to a pointer and enqueues it onto the queue.

		Passenger dequeue();
							//Precondition: No parameters needed.
							//Postcondition: Dequeues the passenger at the front, and retunrs the VALUE (not the pointer) for the passenger.

        						//Not sure if we need this function, I coded it to the best of my knowledge
		//int peopleWaiting(int maxWait);

        	//int getFrontTime();
        						//Precondition: No parameters needed.
        						//Postcondition: Returns the wait time of the next person to be dequeued(first person in queue).

		int getnOfPassengers();			//Precondition: No parameters needed.
							//Postcondition: Returns the value of nOfPassengers;

		void increaseWaitTime();		//Precondition: none
							//Postcondition:increments the number of the appropriate waiting time. throws an error if the queue is empty. 

		Passenger* find(int);			//Precondition: valid index (checked in function)
							//Postcondition: returns a pointer to the passenger at position pos.


	private:
		Passenger*first;			//points to the first passenger on the queue
		Passenger*last;				//points to the last passenger on the queue
		int nOfPassengers;			//total # of passengers onthe queue
};

#endif
