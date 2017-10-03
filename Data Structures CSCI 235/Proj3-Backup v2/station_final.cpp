#include "station_final.h"
#include "time_final.h"
#include <iostream>
using namespace std;
Station::Station()
{
        
	stationName=" ";
	northTrain=NULL;
	southTrain=NULL;
	//northQueue[12];
	//southQueue[12];
        
}

Station::Station(Train* aTrain, char direction)
{ 

	
	stationName=" ";

	//if the direction is north the northTrain pointer will be set to the pointer that was sent as an argument
	//the southTrain pointer will be set ti=o NULL
	if(direction =='n')
	{
		northTrain= aTrain;
		southTrain=NULL;
	}
	//if the direction is south the southTrain pointer will be set to the pointer that was sent as an argument
	//the northTrain pointer will be set to NUll
	else if(direction=='s')
	{
		northTrain=NULL;
		southTrain= aTrain;
	}
          
}

/*Station::Station(Queue nQueue[], Queue sQueue[],int size, string sName)
{
         stationName=sName;
         northTrain=NULL;
         southTrain=NULL;
         northQueue=nQueue[size];
         southQueue=sQueue[size];
        
};*/

bool Station::emptyQueues(int start, int lessThan, char direction)//return false if all four queues are empty
{
	bool flag=false;
	

	//specify on which queues to search for passengers the south or north queues
	if(direction=='n')
	{
		for(int i=start;i<lessThan;i++)
		{
			//if the number of people in at least one queue from the four waiting for one specific care is not zero the
			// flag will be set to true
			if(northQueue[i].getnOfPassengers()!=0)
			{
				flag=true;
			}                                  
		}
	}

	//specify on which queues to search for passengers the south or north queues
	if(direction=='s')
	{
		for(int i=start;i<lessThan;i++)
		{
			if(southQueue[i].getnOfPassengers()!=0)
			{
				flag=true;
			}
		}
	}
     return flag;
}

void Station::fromQueueToTrain(char direction)
{
      //if the direction is south the people on the south queue will be loaded into the train
	if(direction=='s')
	{
		//While there is room in the car and there are passengers in at least one of the queues 
		while(southTrain->getNumberInCar(1)!=64 && emptyQueues(0,4,'s'))
		{
			if(southQueue[0].isEmpty()==false)
			{ 
				southTrain->load(southQueue[0].dequeue(),1);
			}
			if(southQueue[1].isEmpty()==false)
			{ 			
				southTrain->load(southQueue[1].dequeue(),1);
			}
			if(southQueue[2].isEmpty()==false) 
			{			
				southTrain->load(southQueue[2].dequeue(),1);
			}
			if(southQueue[3].isEmpty()==false)
			{ 			
				southTrain->load(southQueue[3].dequeue(),1);
			}
		}
		while(southTrain->getNumberInCar(2)!=64 && emptyQueues(4,8,'s'))
		{
			//The specified queue will dequeu the passenger to the load function of train
			//The passengers of the second four consecutive queues will be loaded to the second car     
			if(southQueue[4].isEmpty()==false)
			{ 			
				southTrain->load(southQueue[4].dequeue(),2);
			}
			if(southQueue[5].isEmpty()==false)
			{ 			
				southTrain->load(southQueue[5].dequeue(),2);
			}
			if(southQueue[6].isEmpty()==false)
			{ 			
				southTrain->load(southQueue[6].dequeue(),2);
			}
			if(southQueue[7].isEmpty()==false)
			{ 			
				southTrain->load(southQueue[7].dequeue(),2);
			}
		}
		while(southTrain->getNumberInCar(3)!=64 && emptyQueues(8,12,'s'))
		{
			if(southQueue[8].isEmpty()==false)
			{ 
				southTrain->load(southQueue[8].dequeue(),3);
			}
			if(southQueue[9].isEmpty()==false)
			{ 
				southTrain->load(southQueue[9].dequeue(),3);
			}
			if(southQueue[10].isEmpty()==false)
			{ 
				southTrain->load(southQueue[10].dequeue(),3);
			}
			if(southQueue[11].isEmpty()==false) 
			{
				southTrain->load(southQueue[11].dequeue(),3);
			}
		}
	}

	// if the direction is north th epeople in the north ttrack will be loaded into the train
	if(direction=='n')
	{
		////there is room on the care and there are// still passenger in the queu
		while(northTrain->getNumberInCar(1)!=64 && emptyQueues(0,4,'n'))
		{
			// if the queue is not empty dequeue the passanger into the train
			if(northQueue[0].isEmpty()==false)
			{ 
				northTrain->load(northQueue[0].dequeue(),1);
			}
			if(northQueue[1].isEmpty()==false)
			{
		
				northTrain->load(northQueue[1].dequeue(),1);
			}
			if(northQueue[2].isEmpty()==false)
			{			
				northTrain->load(northQueue[2].dequeue(),1);
			}
			if(northQueue[3].isEmpty()==false)
			{	
				northTrain->load(northQueue[3].dequeue(),1);
			}
		}

		////there is room on the care and there are// still passenger in the queu
		while(northTrain->getNumberInCar(2)!=64 && emptyQueues(4,8,'n'))
		{
			// if the queue is not empty dequeue the passanger into the train
			if(northQueue[4].isEmpty()==false)
			{
				northTrain->load(northQueue[4].dequeue(),2);
			}
			if(northQueue[5].isEmpty()==false)
			{			
				northTrain->load(northQueue[5].dequeue(),2);
			}
			if(northQueue[6].isEmpty()==false)
			{			
				northTrain->load(northQueue[6].dequeue(),2);
			}
			if(northQueue[7].isEmpty()==false)
			{
				northTrain->load(northQueue[7].dequeue(),2);
			}
		}
		while(northTrain->getNumberInCar(3)!=64 && emptyQueues(8,12,'n'))
		{
			if(northQueue[8].isEmpty()==false)
			{
				northTrain->load(northQueue[8].dequeue(),3);
			}
			if(northQueue[9].isEmpty()==false)
			{
				northTrain->load(northQueue[9].dequeue(),3);
			}
			if(northQueue[10].isEmpty()==false)
			{
				northTrain->load(northQueue[10].dequeue(),3);
			}
			if(northQueue[11].isEmpty()==false)
			{
				northTrain->load(northQueue[11].dequeue(),3);
			}
		}
	}
}

string Station::getStationName()
{
	return stationName;
}

void Station::setStationName(string name)
{
	stationName=name;
}				

Passenger* Station::fromTrainToQueue(char direction)
{
	Passenger* temp;
	
	//////////////////////////////////////////////////////////
	//If block to take transfer passenger off north train***//
	//////////////////////////////////////////////////////////
	if(direction=='n' || direction=='N')
	{
		//For loop for car#1 northTrain
		//Will run through all the passenger in the car to check for their destinations
		for(int i=1; i<=northTrain->getNumberInCar(1); i++)
		{
			temp=northTrain->find(1, i);
			//If the north train is on a Red line interchange
			if(stationName=="B3R" && temp != NULL && (temp->destination=="B1" || temp->destination=="B2" ||
				temp->destination=="A5")) //If the station is B3-RED && Passenger wants to go to BLUE stations
			{
					northTrain->remove(1,i); //Remove the passenger at Car 1, pos i
					return temp; 			//Return the temp pointer for the removed passenger to transferB3()
			}
			
			//Else if north train is on a blue line.
			else if(stationName=="B3B" && temp != NULL && (temp->destination=="A1" || temp->destination=="A2" ||
				temp->destination=="A3" || temp->destination=="A4" || temp->destination=="B4" ||
				temp->destination=="B5")) //If the station is B3-BLUE && Passenger wants to go to RED stations
			{
					northTrain->remove(1,i); //Car 1, at pos i
					return temp; //Return temp to transferB3()
			}				
		}
		
		//Same as above but for car #2 north train****
		for(int i=1; i<=northTrain->getNumberInCar(2); i++)
		{
			temp=northTrain->find(2, i);
			//If the north train is on a Red line interchange
			if(stationName=="B3R" && temp != NULL && (temp->destination=="B1" || temp->destination=="B2" ||
				temp->destination=="A5")) //If the station is B3-RED && Passenger wants to go to BLUE stations
			{
					northTrain->remove(2,i); //Remove the transfer passenter
					return temp; //Return temp to transferB3()
			}
			
			else if(stationName=="B3B" && temp != NULL && (temp->destination=="A1" || temp->destination=="A2" ||
				temp->destination=="A3" || temp->destination=="A4" || temp->destination=="B4" ||
				temp->destination=="B5")) //If the station is B3-BLUE && Passenger wants to go to RED stations
			{
					northTrain->remove(2,i); //Car 1, at pos i
					return temp; //Return temp to transferB3()
			}				
		}
		
		//North train car #3
		for(int i=1; i<=northTrain->getNumberInCar(3); i++)
		{
			temp=northTrain->find(3, i);
			//If the north train is on a Red line interchange
			if(stationName=="B3R" && temp != NULL && (temp->destination=="B1" || temp->destination=="B2" ||
				temp->destination=="A5")) //If the station is B3-RED && Passenger wants to go to BLUE stations
			{
					northTrain->remove(3,i); //Remove the transfer passenter
					return temp; //Return temp to transferB3()
			}
			
			else if(stationName=="B3B" && temp != NULL && (temp->destination=="A1" || temp->destination=="A2" ||
				temp->destination=="A3" || temp->destination=="A4" || temp->destination=="B4" ||
				temp->destination=="B5")) //If the station is B3-BLUE && Passenger wants to go to RED stations
			{
					northTrain->remove(3,i); //Car 1, at pos i
					return temp; //Return temp to transferB3()
			}				
		}
		delete temp;
	}//End transfer check for north train.
	
	///////////////////////////////////////
	//fromTrainToQueue for south train***//
	///////////////////////////////////////
	//Same as north but for south train.

	if(direction=='s' || direction=='S')
	{
		for(int i=1; i<=southTrain->getNumberInCar(1); i++)
		{
			temp=southTrain->find(1,i);
			if(stationName=="B3R" && temp != NULL && (temp->destination=="B1" || temp->destination=="B2" ||
				temp->destination=="A5"))
			{
				southTrain->remove(1,i);
				return temp;
			}
			
			else if(stationName=="B3B" && temp != NULL && (temp->destination=="A1" || temp->destination=="A2" ||
				temp->destination=="A3" || temp->destination=="A4" || temp->destination=="B4" ||
				temp->destination=="B5"))
			{
				southTrain->remove(1,i);
				return temp;
			}
		}
		
		for(int i=1; i<=southTrain->getNumberInCar(2); i++)
		{
			temp=southTrain->find(2,i);
			if(stationName=="B3R" && temp != NULL && (temp->destination=="B1" || temp->destination=="B2" ||
				temp->destination=="A5"))
			{
				southTrain->remove(2,i);
				return temp;
			}
			
			else if(stationName=="B3B" && temp != NULL && (temp->destination=="A1" || temp->destination=="A2" ||
				temp->destination=="A3" || temp->destination=="A4" || temp->destination=="B4" ||
				temp->destination=="B5"))
			{
				southTrain->remove(2,i);
				return temp;
			}
		}

		for(int i=1; i<=southTrain->getNumberInCar(3); i++)
		{
			temp=southTrain->find(3,i);
			if(stationName=="B3R" && temp != NULL && (temp->destination=="B1" || temp->destination=="B2" ||
				temp->destination=="A5"))
			{
				southTrain->remove(3,i);
				return temp;
			}
			
			else if(stationName=="B3B" && temp != NULL && (temp->destination=="A1" || temp->destination=="A2" ||
				temp->destination=="A3" || temp->destination=="A4" || temp->destination=="B4" ||
				temp->destination=="B5"))
			{
				southTrain->remove(3,i);
				return temp;
			}
		}
		delete temp;
	}	
	//Return NULL if there are no transfer passenger to unload.
	return NULL;
}

//Unload function to unload ALL passengers whose destination==current station
void Station::unloadTrain(char direction) //This function will take care of unloading passengers from the train.
								 //Train's unload() function will check if destination==current station
{
	if(direction=='n') //n if it's unloading the north train.
	{
		northTrain->unload();	  //delete temp to ensure dynamically alocatted passenger is deleted.
	}
	
	if(direction=='s')					  //same concept as north but for southTrain.
	{
		southTrain->unload();
	}
}

void Station::randomQueue(char direction, Passenger person){
	if(direction == 'S' || direction == 's')
		southQueue[rand() % 12].enqueue(person);
	else if(direction == 'N' || direction == 'n')
		northQueue[rand() % 12].enqueue(person);
}

void Station::setNorthTrain(Train* aTrain)
{
	northTrain=aTrain;
	cout << "North Train Set!" << g_Min << endl;
}
	
Train* Station::getNorthTrain()
{
	return northTrain;
}
	
void Station::setSouthTrain(Train* aTrain)
{
	southTrain=aTrain;
	cout << "South Train Set!" << g_Min << endl;
}
	
Train* Station::getSouthTrain()
{
	return southTrain;
}

void Station::incrementWaitTime(){
	for(int i = 0; i<12; i++)
	{
		northQueue[i].increaseWaitTime();
		southQueue[i].increaseWaitTime();
	}
}

