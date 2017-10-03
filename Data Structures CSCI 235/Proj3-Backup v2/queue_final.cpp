#include "queue_final.h"
#include "time_final.h"

///////////////////////////////////////////////////
//Constructors, copy Constructors and Overloading//
///////////////////////////////////////////////////
Queue::Queue()
{
	first=NULL;
	last=NULL;
	nOfPassengers=0;
};

Queue::Queue(Queue& qSource)
{
	first=qSource.first;
	last=qSource.last;
	nOfPassengers=qSource.nOfPassengers;
};


Queue& Queue::operator=(Queue& qSource)
{
	if(this==&qSource)
		return *this;

	first=qSource.first;
	last=qSource.last;
	nOfPassengers=qSource.nOfPassengers;

	return *this;
};

Queue::~Queue()
{
	while(!isEmpty())
	{
		dequeue();
	}
};

/////////////
//Functions//
/////////////

bool Queue::isEmpty()
{
	return(nOfPassengers==0);
}

void Queue::enqueue(Passenger person) // person is already defined properly? and thus just set to list??
{
    Passenger *newPass = new Passenger;
    *newPass=person;
    newPass->next=NULL;
    if(nOfPassengers==0)
    {
        first=newPass;
        last=first;
    }

    else
    {
        last->next=newPass;
        last=newPass;
    }
    nOfPassengers++;
}

//Dequeue passengers
Passenger Queue::dequeue()
{
    if(isEmpty())
        throw 1;
    Passenger * temp = new Passenger;
    temp=first;
    first->next=first;
    temp->next=NULL;
    
    //Create a passenger variable and assign value of temp.
    //Then return variable and delete temp pointer to avoid memory leak.
    Passenger reTemp=*temp;
    delete temp;	
    nOfPassengers--;
    return reTemp; //Returns the value of temp as opposed to the reference&

}

int Queue::getnOfPassengers()
{
	return nOfPassengers;
}

void Queue::increaseWaitTime()
{
	if(isEmpty())
		throw "bananas";
	Passenger* curr;
	for(int i = 1; i<=nOfPassengers; i++){
		curr = find(i);
		if(!curr->beenOnTrain)
			curr->waitTime1++;
		else
			curr->waitTime2++;
	}
}

Passenger* Queue::find(int pos)
{
	if(pos<1 || pos>nOfPassengers)
		throw "something";
	Passenger* curr = first;
	for(int i = 2; i<=pos; i++)
		curr=curr->next;
	return curr;
}


//Not sure if this is what it is intended for the function to do??
/*int Queue::peopleWaiting(int maxWait)
{
	int count=0;
	Passenger*temp=first;
	for(int i=0; i<nOfPassengers; i++)
	{
		if(temp->waitTime>=maxWait)
			count++;
		temp=temp->next;
	}
	delete temp;
	return count;
};

int Queue::getFrontTime()
{
    return first->waitTime;
};*/
