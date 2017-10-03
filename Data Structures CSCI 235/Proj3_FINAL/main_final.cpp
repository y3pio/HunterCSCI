/************************************************************************
 Title         : main_final.cpp
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : creates the train system and runs all aspects of the 
		 simulation
 Purpose       : to simulate a train system running throughout the day.
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/




#include "queue_final.h"
#include "train_final.h"
#include "time_final.h"
#include "system_final.h"
#include "station_final.h"

#include "Properties.hpp" //This is Prof.Brizan's file, include the hpp and cpp in the final version.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
using namespace std;

/* This is a struct used to keep track of data grabbed from the properties file.*/
struct PassStat
{
	public:
	    int passA;
	    //maximum number of passengers to be created in A stations
	    int passB;
	    //maximum number of passengers to be created in B stations
	    int dest;
	    //percentage of likelyhood that a person will be destined for a B station.
};


void setStat(Properties*, PassStat[]);
//Precondition: takes in the Properties singleton object which holds the prop values using the map STL.
//Postcondition: set passStat[] structure array with the int values from the prop file


/////////////////////
//Main Start Here!!//
/////////////////////

int g_Min = 352; // used to keep track of time
int nOfRedTrains=2; //used to keep track of number of red line trains
int nOfBlueTrains=2;//used to keep track of number of blue line trains
int loadCounter=0;
int main(int argc,char* argv[])
{
	if(argc != 2) //make sure one (and only one) properties file is passed.
	{
		cerr << "ERROR!\n";
		cerr << "Usage: " << argv[0] << " <properties file>" << endl;
		return(1);
	}
	cout << "Running Simulation.";
	srand(time(0));
	PassStat hour[24]; //initialize this array with all 0's for all struct data members.
	Properties*prop=Properties::getInstance(); //Create the singleton.
	prop->readPropertyFile(argv[1]); //Hard coded for now, use command line arguements later.
									   //Filenotfound exception is already implimented inside Properties class (THANK YOU BRIZAN!)
	setStat(prop, hour); //Given all the property values as strings inside prop object, set them to int and push them into hour[] structure.
	
	/******************************************
	//Start the primary sub routine here.**!!//
	******************************************/
	
	System systemOne;
	systemOne.setNameForStations();
	for(g_Min; g_Min<=1460; g_Min++) //Has to end until no passengers left
	{
		if(g_Min>=360 && g_Min<1380) //Has to end at 1380 for creating passenger
			systemOne.callPassAndQueue(hour[g_Min/60].passA, hour[g_Min/60].passB, hour[g_Min/60].dest);
		if(g_Min%20 == 0)
			cout << "."; // prints a pretty loading screen with dots.
		if(g_Min==352)
		{
			//send new trains so people don't wait too long.
			systemOne.sendNewTrain('b',4);
			systemOne.sendNewTrain('b',21);
			systemOne.sendNewTrain('r',31); //A4
			systemOne.sendNewTrain('r',6);
			systemOne.sendNewTrain('r',23); //B3R
			systemOne.sendNewTrain('r',14);
			systemOne.sendNewTrain('r',21); //B4
			systemOne.sendNewTrain('r',16);
			systemOne.sendNewTrain('r',35); //A2
			systemOne.sendNewTrain('r',2);
			systemOne.sendNewTrain('r',10); //T
		}
		//Move trains throughout the system.
		systemOne.moveTrains('r',38,18,37);
		systemOne.moveTrains('b',26,12,25);
	
		systemOne.increaseWaitTime();//increase the wait time of all people in the queues in each station.

		/*if(g_Min%60==0)
		{
			#ifdef _WIN32
			system("cls");
			#else
			system("clear");
			#endif
			
			cout << "Running Simulation";
			for(int i=0; i<=loadCounter; i++)
				cout << ".";
			loadCounter++;
		}*///only works on windws
	}

	cout << "\nTotal red trains:" << nOfRedTrains << endl;
	cout << "Total blue trains:" << nOfBlueTrains << endl;
	cout << "Data output to file \"output1.txt\" in source folder." << endl;

	return 0;
}

/////////////////////////////////////////////
//Main's function definitions start here..///
/////////////////////////////////////////////
void setStat(Properties *prop, PassStat stat[])
{
    //reads the properties file and sets the values into the members of stat, which are of struct PassStat (commented above).
    string getA, getB, getD;
    for(int i=0; i<24; i++)
    {
        if(i<10)
        {
            getA="0"+static_cast<ostringstream*>( &(ostringstream() << i) )->str()+".passengers.volume.A ";
            getB="0"+static_cast<ostringstream*>( &(ostringstream() << i) )->str()+".passengers.volume.B ";
            getD="0"+static_cast<ostringstream*>( &(ostringstream() << i) )->str()+".passengers.destination.B ";
        }
        else
        {
            getA=static_cast<ostringstream*>( &(ostringstream() << i) )->str()+".passengers.volume.A ";
            getB=static_cast<ostringstream*>( &(ostringstream() << i) )->str()+".passengers.volume.B ";
            getD=static_cast<ostringstream*>( &(ostringstream() << i) )->str()+".passengers.destination.B ";
        }
        getA=prop->getProperty(getA);
        getB=prop->getProperty(getB);
        getD=prop->getProperty(getD);
        if(getA!=""&&getB!=""&&getD!="")
        {
            stat[i].passA =atoi(getA.c_str());
            stat[i].passB =atoi(getB.c_str());
            stat[i].dest  =atoi(getD.c_str());
        }
    }
};

