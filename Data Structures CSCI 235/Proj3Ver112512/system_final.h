#ifndef SYSTEM_FINAL_H
#define SYSTEM_FINAL_H
#include "station_final.h"
#include "train_final.h"
#include "time_final.h"

class System 
{
    private:
        Station A1;
        Station A2;
        Station A3;
        Station A4;
        Station A5;
        Station B1;
        Station B2;
        Station B3R, B3B;
        Station B4;
        Station B5;
        Train* sRTrack[12];
        Train* nRTrack[12];
	Train* exSRTrack[15];// express track  
	Train* exNRTrack[15];// express track
	Train* exSBTrack[5];// express track
	Train* exNBTrack[9];// express track
        Train* sBTrack[9];
        Train* nBTrack[9];
        void moveBlueNorthTrains();
        void moveBlueSouthTrains();
        void moveRedNorthTrains();
        void moveRedSouthTrains();
		

        int NumberOfTrainsForR;//!!!changed to R insted of A
        int NumberOfTrainsForB;

  

    public:
        System();
	//precondition:
	//post-condition:create a system that has four trains in the starting station
  
        void setNameForStations();
	//precondition:
	//post-condition:gives the station their name as a string
	                  
        void sendNewTrain(string station);
	//precondition: the function take a string that specify in which station to create the new train
	//post-condition:only if the specified station is one of the edge stations a new train will be created, the train
			// will be created only if the specified station will be empty from traines

        void moveTrains();
	//precondition: 
	//post-condition:move all the trains in the system in a timely manner 
	
	void sendExpress(char direction, char color);
	//precondition:the function takes two char that specify the direction and the line color.
	//Post-conditions: an express train is set on the express track, according to the information provided

	void moveExRS();
	//precondition:
	//post-conditions:the function moves the trains on the express track for fourteen min until it reaches the B3R station where it loads
			  //passengers from the queue to the train and continue on the local track.the train will keep circulating in the local loop
	
	void moveExBS();
	//precondition:
	//post-conditions:the function moves the trains on the express track for four min until it reaches the B3B station where it load
			  //passengers from the queue to the train and continue on the local track.the train will keep circulating in the local loop
	
	void moveExBN();
	//precondition:
	//post-conditions:the function moves the trains on the express track for eight min until it reaches the B3B station where it load
			  //passengers from the queue to the train and continue on the local track.the train will keep circulating in the local loop
	
	void moveExRN();
	//precondition:
	//post-conditions:the function moves the trains on the express track for fourteen min until it reaches the B3R station where it load
			  //passengers from the queue to the train and continue on the local track.the train will keep circulating in the local loop


        void transferB3(char trainLine,char direction);
		//Precondition: given a train line color and direction (track) it's on.
		//Postcondition: will transfer all passengers needing to transfer at B3 interchange.
		//				**CALL ONLY WHEN TRAIN IS AT B3** Haven't tested it enough to see
		//              if there will be a bug if called elsewhere or when no trains are in station.
		
	//Kevin's additional functions.
	void callPassAndQueue(int aVolume, int bVolume, int dest);
	void passAndQueue(int destination, int people, string station);
	void randomQueue(string station, char direction, Passenger* person);
};

#endif
