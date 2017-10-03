#ifndef QUEUE_FINAL_H
#define QUEUE_FINAL_H
#include "time_final.h"
#include <string>
using namespace std;

struct Passenger{
	public:
		string destination;
		int startingTime;
		int waitTime1;
		int waitTime2;
		bool beenOnTrain;
		int totalTime;
};

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
	     ~Queue();
	     bool isEmpty();
             void enqueue(Passenger item);
             Passenger dequeue();
	     int getnOfPassengers();
             
	     //Passenger getFront(); //No need for getFront()??
             
	     //To be implimented last
	     Node* find(int pos);
	     void increaseWaitTime();
             
};

#endif
