/************************************************************************
 Title         : system_final.cpp
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : defines the train system's functions
 Purpose       : system takes care of all processes including moving
		 trains and making sure passengers transfer accordingly
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#include "system_final.h"
#include "station_final.h"
#include "time_final.h"
#include <stdio.h>

#include <iostream>
using namespace std;

System::System()
{
	//populates the array for the red line system
	for(int i=0; i<38; i++)
	{
		Station* cStation = new Station();
		redLines[i].aTrain=NULL;
		redLines[i].aStation=NULL;

		if((i%2==0 && i<=6) || (i%2==0 && i>=14 && i<=18))
			redLines[i].aStation=cStation;

		else if((i%2==1 && i>=19 && i<=23) || (i%2==1 && i>=31))
			redLines[i].aStation=cStation; 
	}

	//populates the array for the blue line system
	for(int i=0; i<26; i++)
	{
		Station* cStation = new Station();
		blueLines[i].aTrain=NULL;
		blueLines[i].aStation=NULL;

		if((i%2==0 && i<=4) || (i==12))
			blueLines[i].aStation=cStation;

		else if((i%2==1 && i==13) || (i%2==1 && i<=25 && i>=21))
			blueLines[i].aStation=cStation;
	}
	
	//creates 4 initial trains to traverse the system.
	Train* toA1= new Train("A1",'S','R');
	Train* toA5= new Train("A5",'N','B'); 
	Train* toB1= new Train("B1",'S','B');
	Train* toB5= new Train("B5",'N','R'); 

	//sets the created trains into the appropriate stations.
	redLines[0].aStation->setTrain(toA1);
	redLines[19].aStation->setTrain(toB5);

	blueLines[0].aStation->setTrain(toB1);
	blueLines[13].aStation->setTrain(toA5);
}

void System::moveTrains(char line, int j, int south, int north)
{
	systemTrack* track=(line=='r' ? redLines:blueLines);
	for(int i=0; i<j; i++)
	{
		//Track to station
		if((track)[i].aTrain!=NULL && (track)[i].aTrain->getMoved()==false && (track)[i].aStation==NULL && (track)[i+1].aStation!=NULL 
			&& (track)[i+1].aStation->getTrain()==NULL)
		{
			(track)[i+1].aStation->setTrain((track)[i].aTrain);
			(track)[i].aTrain=NULL;
			(track)[i+1].aStation->getTrain()->setLocation((track)[i+1].aStation->getStationName());

			(track)[i+1].aStation->getTrain()->unload();//Unloading HERE!!

			if(line=='r')
			{
				if(i+1==14||i+1==23)
				{
					transferB3(line,i+1);
				}
			}

			else if(line=='b')
			{
				if(i+1==4||i+1==21)
				{
					transferB3(line,i+1);
				}
			}

			(track)[i+1].aStation->fromQueueToTrain(); //Loading HERE!!
			(track)[i+1].aStation->getTrain()->setMoved(true);//shows that the train has been moved this minute.
		}
		
		//Station to track
		else if((track)[i].aStation!=NULL && (track)[i].aStation->getTrain()!=NULL && (track)[i].aStation->getTrain()->getMoved()==false 
			&& (track)[i+1].aTrain==NULL && (track)[i+1].aStation==NULL)
		{
			(track)[i+1].aTrain=(track)[i].aStation->getTrain();
			(track)[i].aStation->setTrain(NULL);
			(track)[i+1].aTrain->setLocation("T");
			(track)[i+1].aTrain->setMoved(true);
		}		

		//Track to track
		else if((track)[i].aStation==NULL && (track)[i].aTrain!=NULL && (track)[i].aTrain->getMoved()==false && (track)[i+1].aTrain==NULL 
			&& (track)[i+1].aStation==NULL)
		{

			(track)[i+1].aTrain=(track)[i].aTrain;
			(track)[i].aTrain=NULL;
			(track)[i+1].aTrain->setLocation("T");
			(track)[i+1].aTrain->setMoved(true);
		}

		//Special edge station case A1 and B5
		else if(i==south && (track)[i].aStation!=NULL && (track)[i].aStation->getTrain()!=NULL 
			&& (track)[i].aStation->getTrain()->getMoved()==false && (track)[i+1].aStation!=NULL && (track)[i+1].aStation->getTrain()==NULL)
		{
			(track)[i+1].aStation->setTrain((track)[i].aStation->getTrain());
			(track)[i].aStation->setTrain(NULL);
			(track)[i+1].aStation->getTrain()->unload();
			(track)[i+1].aStation->fromQueueToTrain();//Loading HERE!!!
			(track)[i+1].aStation->getTrain()->setMoved(true);
		}

		else if(i==north && (track)[i].aStation!=NULL && (track)[i].aStation->getTrain()!=NULL 
			&& (track)[i].aStation->getTrain()->getMoved()==false && (track)[0].aStation!=NULL && (track)[0].aStation->getTrain()==NULL)
		{
			(track)[0].aStation->setTrain((track)[i].aStation->getTrain());
			(track)[i].aStation->setTrain(NULL);
			(track)[0].aStation->getTrain()->unload(); //Unloading
			(track)[0].aStation->fromQueueToTrain(); //Loading
			(track)[0].aStation->getTrain()->setMoved(true);
		}
	}

	setMoved(line, j, false);

};

void System::setNameForStations()
{
	//South bound
	redLines[0].aStation->setStationName("A1");
	redLines[2].aStation->setStationName("A2");
	redLines[4].aStation->setStationName("A3");
	redLines[6].aStation->setStationName("A4");
	redLines[14].aStation->setStationName("B3R");
	redLines[16].aStation->setStationName("B4");
	redLines[18].aStation->setStationName("B5");

	blueLines[0].aStation->setStationName("B1");
	blueLines[2].aStation->setStationName("B2");
	blueLines[4].aStation->setStationName("B3B");
	blueLines[12].aStation->setStationName("A5");


	//North bound
	redLines[37].aStation->setStationName("A1");
	redLines[35].aStation->setStationName("A2");
	redLines[33].aStation->setStationName("A3");
	redLines[31].aStation->setStationName("A4");
	redLines[23].aStation->setStationName("B3R");
	redLines[21].aStation->setStationName("B4");
	redLines[19].aStation->setStationName("B5");

	blueLines[25].aStation->setStationName("B1");
	blueLines[23].aStation->setStationName("B2");
	blueLines[21].aStation->setStationName("B3B");
	blueLines[13].aStation->setStationName("A5");

}

void System::setMoved(char line, int j, bool condition)
{//This function sets the appropriate track to a status of moved or not yet moved (using boolean representation)
	systemTrack* track=(line=='r' ? redLines:blueLines);//A conditional operator, how fancy.
	for(int i=0; i<j; i++)
	{
		if((track)[i].aTrain!=NULL)
			(track)[i].aTrain->setMoved(condition);

		if((track)[i].aStation!=NULL && (track)[i].aStation->getTrain()!=NULL)
			(track)[i].aStation->getTrain()->setMoved(condition);
			
	}
}

void System::sendNewTrain(char line, int index)
{
	//This function sends a new train to the specified station. The station is specified by the line and the index.
	systemTrack* track=(line=='r' ? redLines:blueLines);
	
	if((track)[index].aTrain==NULL && (track)[index].aStation==NULL)
	{
		(track)[index].aTrain=new Train("T",'s',line);
		if(line=='r')
			nOfRedTrains++;
		else
			nOfBlueTrains++;
	}

	else if((track)[index].aTrain==NULL && (track)[index].aStation!=NULL && (track)[index].aStation->getTrain()==NULL)
	{
		string stationName=(track)[index].aStation->getStationName();
		(track)[index].aStation->setTrain(new Train(stationName,'s',line));
		if(line=='b')
			nOfBlueTrains++;
		else
			nOfRedTrains++;
	}
		
}

void System::transferB3(char trainLine,int index)
{
	//If train line is red, transfer on station B3R (B3 Red)
	if(trainLine=='r' || trainLine=='R')
	{
		Passenger transfer;
		//Do passenger routing while B3R.fromTrainToQueue() is returning a transfer passenger on the direction it's being called.
		do
		{
			//transfer hold transfer passenger getting off from the train coming in the direction at B3R
			transfer=redLines[index].aStation->fromTrainToQueue();
			//Branching statements for transfer passengers getting off from red line to go to blue stations.
			//Blue stations are(not including B3): B1, B2 are north, A5 is south of the B3 transfer point.

			if((transfer.destination=="B1" || transfer.destination=="B2")) //If case for stations north side.
			{
				//Convert transfer to non pointer passenger variable
				//Send passenger variable to B3 BLUE , NORTH queue
				blueLines[21].aStation->randomQueue(transfer);
			}

			else if(transfer.destination=="A5")				//Else if case for stations south side.
			{
				//Send passenger to B3 BLUE, SOUTH queue
				blueLines[4].aStation->randomQueue(transfer);			
			}
		}while(transfer.destination != "-1");//while there are transfer passengers at B3R on the direction line.//delete transfer after transferring passengers are done.
	}

	//If train line is blue, transfer on station B3B (B3 Red), same as above for red line but for blue line
	if(trainLine=='b' || trainLine=='B')
	{
		Passenger transfer;
		do
		{				
			transfer=blueLines[index].aStation->fromTrainToQueue();

			if((transfer.destination=="A1" || transfer.destination=="A2" || transfer.destination=="A3" ||
			   transfer.destination=="A4"))//If case for stations north side
			{
				//Convert transfer to non pointer passenger variable
				//Send passenger variable to B3 RED, NORTH queue
				redLines[23].aStation->randomQueue(transfer);
			}
			else if((transfer.destination=="B4" || transfer.destination=="B5"))//else if case for stations south side.
			{
				//Do same as above but send passenger to B3 RED, SOUTH queue
				
				redLines[14].aStation->randomQueue(transfer);
			}
		}while(transfer.destination != "-1");
	}
}

void System::passAndQueue(int bDestination, int people, string station)
{
	if(bDestination < 1 || bDestination > 100)
		throw "an error";

	string aDestinations[5] = {"A1", "A2", "A3", "A4", "A5"}; /*possible stations for a destination*/
	string bDestinations[5] = {"B1", "B2", "B3", "B4", "B5"};
	for(int i = 0; i < people; i++)
	{/* this for loop creates as many people as specified for the current station.*/
		Passenger person;

		person.startingTime = g_Min;
		person.startingStation=station;
		person.beenOnTrain = false;
		person.waitTime1 = 0;
		person.waitTime2 = 0;
		person.totalTime = 0;
		int random = rand() % 100;
		string dest;
		if(random < bDestination)//If random < bDestination, then the destination is a b station. Else, it's an A station.
		{
			do
			{
				dest = bDestinations[rand() % 5];
			}while(dest == station);
		}
		
		else
		{
			do
			{
				dest = aDestinations[rand() % 5];
			}while(dest == station);
		}
		person.destination = dest;//set the destination to the passenger.
		if(station[0] == 'A')
		{
			//place the person in a random queue based on the station they're created in.
			//A stations
			if(station == "A1")
				redLines[0].aStation->randomQueue(person);
			else if(station == "A5")
				blueLines[13].aStation->randomQueue(person);
			else if(station == "A2" && (person.destination[0] == 'B' || person.destination[1] > '2'))
				redLines[2].aStation->randomQueue(person);
			else if(station == "A2" && (person.destination[0] == 'A' && person.destination [1] < '2'))
				redLines[35].aStation->randomQueue(person);
			else if(station == "A3" && (person.destination[0] == 'B' || person.destination[1] > '3'))
				redLines[4].aStation->randomQueue(person);
			else if(station == "A3" && (person.destination[0] == 'A' && person.destination[1] < '3'))
				redLines[33].aStation->randomQueue(person);
			else if(station == "A4" && (person.destination[0] == 'B' || person.destination[1] > '4'))
				redLines[6].aStation->randomQueue(person);
			else if(station == "A4" && (person.destination[0] == 'A' && person.destination[1] < '4'))
				redLines[31].aStation->randomQueue(person);
		}
		
		else
		{
			//B stations.
			if(station == "B1")
				blueLines[0].aStation->randomQueue(person);
			else if(station == "B5")
				redLines[19].aStation->randomQueue(person);
			else if(station == "B3" && (person.destination[0] == 'B' && person.destination[1] > '3'))
				redLines[14].aStation->randomQueue(person);
			else if(station == "B3" && (person.destination[0] == 'A' && person.destination[1] != '5'))
				redLines[23].aStation->randomQueue(person);
			else if(station == "B3" && (person.destination == "A5"))
				blueLines[4].aStation->randomQueue(person);
			else if(station == "B3" && (person.destination[0] == 'B' && person.destination[1] < '3'))
				blueLines[21].aStation->randomQueue(person);
			else if(station == "B4" && (person.destination=="B5"))
				redLines[16].aStation->randomQueue(person);
			else if(station == "B4" && (person.destination[0] == 'A' || person.destination[1] < '4'))
				redLines[21].aStation->randomQueue(person);
			else if(station == "B2" && (person.destination[0] == 'A' || person.destination[1] > '2'))
				blueLines[2].aStation->randomQueue(person);
			else if(station == "B2" && (person.destination == "B1"))
				blueLines[23].aStation->randomQueue(person);
		}
	}
}

void System::callPassAndQueue(int aVolume, int bVolume, int dest)
{
	//Calls passAndQueue for all stations, using randomly generated numbers within the specified limits.
	passAndQueue(dest, rand() % (aVolume+1), "A1");
	passAndQueue(dest, rand() % (aVolume+1), "A2");
	passAndQueue(dest, rand() % (aVolume+1), "A3");
	passAndQueue(dest, rand() % (aVolume+1), "A4");
	passAndQueue(dest, rand() % (aVolume+1), "A5");

	passAndQueue(dest, rand() % (bVolume+1), "B1");
	passAndQueue(dest, rand() % (bVolume+1), "B2");
	passAndQueue(dest, rand() % (bVolume+1), "B3");
	passAndQueue(dest, rand() % (bVolume+1), "B4");
	passAndQueue(dest, rand() % (bVolume+1), "B5");
}

void System::increaseWaitTime()
{
	//Red lines south bound
	redLines[0].aStation->incrementWaitTime();
	redLines[2].aStation->incrementWaitTime();
	redLines[4].aStation->incrementWaitTime();
	redLines[6].aStation->incrementWaitTime();
	redLines[14].aStation->incrementWaitTime();
	redLines[16].aStation->incrementWaitTime();

	//Red lines north bound
	redLines[19].aStation->incrementWaitTime();
	redLines[21].aStation->incrementWaitTime();
	redLines[23].aStation->incrementWaitTime();
	redLines[31].aStation->incrementWaitTime();
	redLines[33].aStation->incrementWaitTime();
	redLines[35].aStation->incrementWaitTime();

	//Blue lines south bound
	blueLines[0].aStation->incrementWaitTime();
	blueLines[2].aStation->incrementWaitTime();
	blueLines[4].aStation->incrementWaitTime();

	//Blue lines north bound
	blueLines[13].aStation->incrementWaitTime();
	blueLines[21].aStation->incrementWaitTime();
	blueLines[23].aStation->incrementWaitTime();
};

