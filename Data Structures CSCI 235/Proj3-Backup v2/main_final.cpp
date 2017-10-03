#include "queue_final.h"
#include "train_final.h"
#include "time_final.h"
#include "system_final.h"
#include "station_final.h"

#include "Properties.hpp" //This is Prof.Brizan's file, include the hpp and cpp in the final version.

//#include <EVERYTHING> :include ALL the directives! =O
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
using namespace std;

struct PassStat
{
	public:
	    int passA;
	    int passB;
	    int dest;
};


void setStat(Properties*, PassStat[]);
//Precondition: takes in the Properties singleton object which holds the prop values using the map STL.
//Postcondition: set passStat[] structure array with the int values from the prop file


/////////////////////
//Main Start Here!!//
/////////////////////

int g_Min = 352;
int main()// (int argc, char* argv[]) Input command line arguements?? Hardcode file name for testing/debugging for now?
{
	srand(time(0)); //Need to seed time here?
	PassStat hour[24]; //initialize this array with all 0's for all struct data members.
	Properties*prop=Properties::getInstance(); //Create the singleton.
	prop->readPropertyFile("a3.prop"); //Hard coded for now, use command line arguements later.
									   //Filenotfound exception is already implimented inside Properties class (THANK YOU BRIZAN!)
	
	setStat(prop, hour); //Given all the property values as strings inside prop object, set them to int and push them into hour[] structure.
	
	//cout << hour[6].passA << endl;//TEST
	/******************************************
	//Start the primary sub routine here.**!!//
	******************************************/
	System train_system;
	train_system.setNameForStations();
	for(int i = g_Min; i<=1416; i++){
		train_system.moveTrains();
		/*if(g_Min == 359)
		{
			//cout << "Gmin for 359 -- " << g_Min << endl;
			train_system.sendNewTrain("A1");
			train_system.sendNewTrain("B5");
		}*/
		//for loop to create passengers
		if(i>=360 && i < 1380)
		{
			//cout << "Gmin for 360 - 1380::" << g_Min << endl;
			try{
				train_system.callPassAndQueue(hour[(g_Min/60)].passA, hour[(g_Min/60)].passB, hour[(g_Min/60)].dest);
			}catch(...){cout << "PassAndQueueError\n"; return 1;};
		}
	g_Min++;
	}
	return 0;
}

/////////////////////////////////////////////
//Main's function definitions start here..///
/////////////////////////////////////////////
void setStat(Properties *prop, PassStat stat[])
{
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
            //cout << getA << endl << getB << endl << getD << endl << endl;
            stat[i].passA =atoi(getA.c_str());
            stat[i].passB =atoi(getB.c_str());
            stat[i].dest  =atoi(getD.c_str());
        }
    }
};
