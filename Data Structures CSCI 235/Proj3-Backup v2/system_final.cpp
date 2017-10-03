#include "system_final.h"
#include "station_final.h"
#include "time_final.h"

#include <iostream>
using namespace std;

System::System()
{
	Train* toA1= new Train("A1",'S','R');
	Train* toA5= new Train("A5",'N','B'); 
	Train* toB1= new Train("B1",'S','B');
	Train* toB5= new Train("B5",'N','R'); 
	NumberOfTrainsForR=2;
        NumberOfTrainsForB=2;

	A1.setSouthTrain(toA1);
	//Station A2;
	//Station A3;
	//Station A4;
	A5.setNorthTrain(toA5);
	B1.setSouthTrain(toB1);
	//Station B2;
	//Station B3R, B3B;
	//Station B4;
	B5.setNorthTrain(toB5);
	for(int i=0;i<12;i++)
	{
		sRTrack[i]=NULL;
		nRTrack[i]=NULL;
	}
	for(int i=0;i<9;i++)
	{
		sBTrack[i]=NULL;
		nBTrack[i]=NULL;
	}
	for(int i=0; i<15;i++)
	{
		
	 	exSRTrack[i]=NULL;
	}
	for(int i=0; i<15;i++)
	{
		exNRTrack[i]=NULL;
	}
	for(int i=0; i<5;i++)
	{
		exSBTrack[i]=NULL;
	}
	for(int i=0; i<9;i++)
	{
		 exNBTrack[i]=NULL;
	}
};

//!!set the system station names. we didn't have to use a function we had a direct access to station name bunt never mind
void System::setNameForStations()
{
	A1.setStationName("A1");
	A2.setStationName("A2");
	A3.setStationName("A3");
	A4.setStationName("A4");
	A5.setStationName("A5");
	B1.setStationName("B1");
	B2.setStationName("B2");
	B3R.setStationName("B3R"); //B3R ? B3B?
	B3B.setStationName("B3B");
	B4.setStationName("B4");
	B5.setStationName("B5");
};


void System::moveRedSouthTrains()//need to add from Train to queue and B3 transfer
{
	//cout << A1.getSouthTrain()->getStartingTime() << endl;
	if(A1.getSouthTrain()!=NULL && g_Min-A1.getSouthTrain()->getStartingTime()==0)
	{
		A1.fromQueueToTrain('s');
		A1.getSouthTrain()->setLocation("A1");
	}

	if(A1.getSouthTrain()!=NULL && g_Min-A1.getSouthTrain()->getStartingTime()==1)
	{
		sRTrack[0]=A1.getSouthTrain();
		//sRTrack[0]->setStationName(Track);??the station name need to be changed at every stations do i need to do it or there is a function? 
		A1.setSouthTrain(NULL);
		sRTrack[0]->setLocation("T");
	}
	if(sRTrack[0]!=NULL && g_Min-sRTrack[0]->getStartingTime()==2)
	{
		A2.setSouthTrain(sRTrack[0]);
		sRTrack[0]=NULL;
		
		A2.getSouthTrain()->setLocation("A2");

		A2.unloadTrain('s');
		A2.fromQueueToTrain('s');
	}
	if(A2.getSouthTrain()!=NULL && g_Min-A2.getSouthTrain()->getStartingTime()==3)
	{
		sRTrack[1]=A2.getSouthTrain();
		A2.setSouthTrain(NULL);
		sRTrack[1]->setLocation("T");
	}
	if(sRTrack[1]!=NULL && g_Min-sRTrack[1]->getStartingTime()==4)
	{
		A3.setSouthTrain(sRTrack[1]);
		sRTrack[1]=NULL;
		A3.getSouthTrain()->setLocation("A3");

		A3.unloadTrain('s');
		A3.fromQueueToTrain('s');
	}
	if(A3.getSouthTrain()!=NULL && g_Min-A3.getSouthTrain()->getStartingTime()==5)
	{
		sRTrack[2]=A3.getSouthTrain();
		A3.setSouthTrain(NULL);
		sRTrack[2]->setLocation("T");
	}
	if(sRTrack[2]!=NULL && g_Min-sRTrack[2]->getStartingTime()==6)
	{
		A4.setSouthTrain(sRTrack[2]);
		sRTrack[2]=NULL;
		A4.getSouthTrain()->setLocation("A4");

		A4.unloadTrain('s');
		A4.fromQueueToTrain('s');
	}
	if(A4.getSouthTrain()!=NULL && g_Min-A4.getSouthTrain()->getStartingTime()==7)
	{
		sRTrack[3]=A4.getSouthTrain();
		A4.setSouthTrain(NULL);
		sRTrack[3]->setLocation("T");
	}
	if(sRTrack[3]!=NULL && g_Min-sRTrack[3]->getStartingTime()==8)
	{
		sRTrack[4]=sRTrack[3];
		sRTrack[3]=NULL;
		sRTrack[4]->setLocation("T");
	}
	if(sRTrack[4]!=NULL && g_Min-sRTrack[4]->getStartingTime()==9)
	{
		sRTrack[5]=sRTrack[4];
		sRTrack[4]=NULL;
	}
	if(sRTrack[5]!=NULL && g_Min-sRTrack[5]->getStartingTime()==10)
	{
		sRTrack[6]=sRTrack[5];
		sRTrack[5]=NULL;
	}
	if(sRTrack[6]!=NULL && g_Min-sRTrack[6]->getStartingTime()==11)
	{
		sRTrack[7]=sBTrack[6];
		sRTrack[6]=NULL;
	}
	if(sRTrack[7]!=NULL && g_Min-sRTrack[7]->getStartingTime()==12)
	{
		sRTrack[8]=sRTrack[7];
		sRTrack[7]=NULL;
	}
	if(sRTrack[8]!=NULL && g_Min-sRTrack[8]->getStartingTime()==13)
	{
		sRTrack[9]=sRTrack[8];
		sRTrack[8]=NULL;
	}
	if(sRTrack[9]!=NULL && g_Min-sRTrack[9]->getStartingTime()==14)// need to incorporate B3transfer
	{
		B3R.setSouthTrain(sRTrack[9]);
		sRTrack[9]=NULL;
		B3R.getSouthTrain()->setLocation("B3R");

		B3R.unloadTrain('s'); //Unload all passengers going to B3R (or B3 in general, ask Kevin about unload)
		transferB3('r','s'); //Transfer all passenger on 'r' (red) train, 's' south bound
		B3R.fromQueueToTrain('s');
	}

	if(B3R.getSouthTrain()!=NULL && g_Min-B3R.getSouthTrain()->getStartingTime()==15)
	{
		sRTrack[10]=B3R.getSouthTrain();
		B3R.setSouthTrain(NULL);
		sRTrack[10]->setLocation("T");
	}
	if(sRTrack[10]!=NULL && g_Min-sRTrack[10]->getStartingTime()==16)
	{
		B4.setSouthTrain(sRTrack[10]);
		sRTrack[10]=NULL;
		B4.getSouthTrain()->setLocation("B4");

		B4.unloadTrain('s');
		B4.fromQueueToTrain('s');
	}
	if(B4.getSouthTrain()!=NULL && g_Min-B4.getSouthTrain()->getStartingTime()==17)
	{
		sRTrack[11]=B4.getSouthTrain();
		B4.setSouthTrain(NULL);
		sRTrack[11]->setLocation("T");
	}
	if(sRTrack[11]!=NULL && g_Min-sRTrack[11]->getStartingTime()==18)
	{
		B5.setSouthTrain(sRTrack[11]);
		sRTrack[11]=NULL;
		B5.getSouthTrain()->setLocation("B5");
		B5.getSouthTrain()->setStartingTime(g_Min); //SET STARTING TIME () to current min //???
		
		B5.unloadTrain('s'); //Unloaded before switching track, so unload train currently on 's' track.

		B5.setNorthTrain(B5.getSouthTrain());
		B5.setSouthTrain(NULL);//!!need to see when doing calculation that there is not conflicting train

		B5.getNorthTrain()->setDirection('N');
		B5.fromQueueToTrain('n');//!!this time char is going north not sure where it should be it depends on main
	}
	cout << "MRS success!\n";
}


void System::moveRedNorthTrains()//need to add from Train to queue and B3 transfer
{
	
	if(B5.getNorthTrain()!=NULL && g_Min-B5.getNorthTrain()->getStartingTime()==0)
	{
		B5.fromQueueToTrain('n');
		B5.getNorthTrain()->setLocation("B5");
	}

	if(B5.getNorthTrain()!=NULL && g_Min-B5.getNorthTrain()->getStartingTime()==1)
	{
		nRTrack[0]=B5.getNorthTrain();
		B5.setNorthTrain(NULL);
		nRTrack[0]->setLocation("T");
	}
	if(nRTrack[0]!=NULL && g_Min-nRTrack[0]->getStartingTime()==2)
	{
		B4.setNorthTrain(nRTrack[0]);
		nRTrack[0]=NULL;
		B4.getNorthTrain()->setLocation("B4");

		B4.unloadTrain('n');
		B4.fromQueueToTrain('n');

	}
	if(B4.getNorthTrain()!=NULL && g_Min-B4.getNorthTrain()->getStartingTime()==3)
	{
		nRTrack[1]=B4.getNorthTrain();
		B4.setNorthTrain(NULL);
		nRTrack[1]->setLocation("T");
	}
	if(nRTrack[1]!=NULL && g_Min-nRTrack[1]->getStartingTime()==4)// need to add B3transfer
	{
		
		B3R.setNorthTrain(nRTrack[1]);
		nRTrack[1]=NULL;
		B3R.getNorthTrain()->setLocation("B3R");
		
		B3R.unloadTrain('n');
		
		transferB3('r','n'); //transfer all transfer passenger on 'r' line 'n' bound
		//Again, need to add fromQueueToTrain() here?
		B3R.fromQueueToTrain('n');
		
	}
	if(B3R.getNorthTrain()!=NULL && g_Min-B3R.getNorthTrain()->getStartingTime()==5)
	{
		nRTrack[2]=B3R.getNorthTrain();
		B3R.setNorthTrain(NULL);
		nRTrack[2]->setLocation("T");
	}
	if(nRTrack[2]!=NULL && g_Min-nRTrack[2]->getStartingTime()==6)
	{
		nRTrack[3]=nRTrack[2];
		nRTrack[2]=NULL;
	}
	if(nRTrack[3]!=NULL && g_Min-nRTrack[3]->getStartingTime()==7)
	{
		nRTrack[4]=nRTrack[3];
		nRTrack[3]=NULL;
	}
	if(nRTrack[4]!=NULL && g_Min-nRTrack[4]->getStartingTime()==8)
	{
		nRTrack[5]=nRTrack[4];
		nRTrack[4]=NULL;
	}
	if(nRTrack[5]!=NULL && g_Min-nRTrack[5]->getStartingTime()==9)
	{
		nRTrack[6]=nRTrack[5];
		nRTrack[5]=NULL;
	}
	if(nRTrack[6]!=NULL && g_Min-nRTrack[6]->getStartingTime()==10)
	{
		cout << "********************************************************" << g_Min << endl;
		nRTrack[7]=nRTrack[6];
		nRTrack[6]=NULL;
	}
	//if(g_Min == 363)
	//	cout << "********************************************************" << g_Min - nRTrack[7]->getStartingTime()<< endl;
	if(nRTrack[7]!=NULL && g_Min-nRTrack[7]->getStartingTime()==11)
	{
		nRTrack[8]=nRTrack[7];
		nRTrack[7]=NULL;
	}
 	if(nRTrack[8]!=NULL && g_Min-nRTrack[8]->getStartingTime()==12)
	{
		A4.setNorthTrain(nRTrack[8]);
		nRTrack[8]=NULL;
		A4.getNorthTrain()->setLocation("A4");
		A4.unloadTrain('n');
		A4.fromQueueToTrain('n');
	}
	if(A4.getNorthTrain()!=NULL && g_Min-A4.getNorthTrain()->getStartingTime()==13)
	{

		nRTrack[9]=A4.getNorthTrain();
		A4.setNorthTrain(NULL);
		nRTrack[9]->setLocation("T");
	}
	if(nRTrack[9]!=NULL && g_Min-nRTrack[9]->getStartingTime()==14)
	{
		A3.setNorthTrain(nRTrack[9]);
		nRTrack[9]=NULL;
		A3.getNorthTrain()->setLocation("A3");		

		A3.unloadTrain('n');
		A3.fromQueueToTrain('n');
		
	}
	if(A3.getNorthTrain()!=NULL && g_Min-A3.getNorthTrain()->getStartingTime()==15)
	{
		nRTrack[10]=A3.getNorthTrain();
		A3.setNorthTrain(NULL);
		nRTrack[10]->setLocation("T");
	}
	if(nRTrack[10]!=NULL && g_Min-nRTrack[10]->getStartingTime()==16)
	{
		A2.setNorthTrain(nRTrack[10]);
		nRTrack[10]=NULL;
		A2.getNorthTrain()->setLocation("A2");	

		A2.unloadTrain('n');
		A2.fromQueueToTrain('n');
	}
	if(A2.getNorthTrain()!=NULL && g_Min-A2.getNorthTrain()->getStartingTime()==17)
	{
		nRTrack[11]=A2.getNorthTrain();
		A2.setNorthTrain(NULL);
		nRTrack[11]->setLocation("T");
	}
	if(nRTrack[11]!=NULL && g_Min-nRTrack[11]->getStartingTime()==18)
	{
		A1.setNorthTrain(nRTrack[11]);
		nRTrack[11]=NULL;
		A1.getNorthTrain()->setLocation("A1");		
		A1.unloadTrain('n'); //unload passengers on 'n' track before sending train back on 's' track

		A1.getNorthTrain()->setStartingTime(g_Min);
		A1.setSouthTrain(B5.getNorthTrain());
		A1.setNorthTrain(NULL);//!!need to see when doing calculation that there is not conflicting train

		A1.getSouthTrain()->setDirection('S');
		A4.fromQueueToTrain('s');
	}
	cout << "MRN success!\n";
}


void System::moveBlueSouthTrains()//need to add from Train to queue and B3 transfer
{
	if(B1.getSouthTrain()!=NULL && g_Min-B1.getSouthTrain()->getStartingTime()==0)
	{
		B1.fromQueueToTrain('s');
		B1.getSouthTrain()->setLocation("B1");	
	}
	if(B1.getSouthTrain()!=NULL && g_Min-B1.getSouthTrain()->getStartingTime()==1)
	{
		sBTrack[0]=B1.getSouthTrain();
		B1.setSouthTrain(NULL);
		sBTrack[0]->setLocation("T");
	}
	if(sBTrack[0]!=NULL && g_Min-sBTrack[0]->getStartingTime()==2)
	{
		B2.setSouthTrain(sBTrack[0]);
		sBTrack[0]=NULL;
		B2.getSouthTrain()->setLocation("B2");	

		B2.unloadTrain('s');
		B2.fromQueueToTrain('s');
	}
	if(B2.getSouthTrain()!=NULL && g_Min-B2.getSouthTrain()->getStartingTime()==3)
	{
		sBTrack[1]=B2.getSouthTrain();
		B2.setSouthTrain(NULL);
		sBTrack[1]->setLocation("T");
	}
	if(sBTrack[1]!=NULL && g_Min-sBTrack[1]->getStartingTime()==4)//add B3 transfer
	{
		B3B.setSouthTrain(sBTrack[1]);
		sBTrack[1]=NULL;
		B3B.getSouthTrain()->setLocation("B3B");	

		B3B.unloadTrain('s'); //Unload all B3 destination passengers on south bound blue train.
		transferB3('b','s'); //Transfer all passenger off 's' bound 'b' train.
		//Need fromQueueToTrain() here?
		B3B.fromQueueToTrain('s');
	}
	if(B3B.getSouthTrain()!=NULL && g_Min-B3B.getSouthTrain()->getStartingTime()==5)
	{
		sBTrack[2]=B3B.getSouthTrain();
		B3B.setSouthTrain(NULL);
		sBTrack[2]->setLocation("T");
	}
	if(sBTrack[2]!=NULL && g_Min-sBTrack[2]->getStartingTime()==6)
	{
		sBTrack[3]=sBTrack[2];
		sBTrack[2]=NULL;
	}
	if(sBTrack[3]!=NULL && g_Min-sBTrack[3]->getStartingTime()==7)
	{
		sBTrack[4]=sBTrack[3];
		sBTrack[3]=NULL;
	}
	if(sBTrack[4]!=NULL && g_Min-sBTrack[4]->getStartingTime()==8)
	{
		sBTrack[5]=sBTrack[4];
		sBTrack[4]=NULL;
	}
	if(sBTrack[5]!=NULL && g_Min-sBTrack[5]->getStartingTime()==9)
	{
		sBTrack[6]=sBTrack[5];
		sBTrack[5]=NULL;
	}
	if(sBTrack[6]!=NULL && g_Min-sBTrack[6]->getStartingTime()==10)
	{
		sBTrack[7]=sBTrack[6];
		sBTrack[6]=NULL;
	}
	if(sBTrack[7]!=NULL && g_Min-sBTrack[7]->getStartingTime()==11)
	{
		sBTrack[8]=sBTrack[7];
		sBTrack[7]=NULL;
	}
	if(sBTrack[8]!=NULL && g_Min-sBTrack[8]->getStartingTime()==12)
	{
		A5.setSouthTrain(sBTrack[8]);
		sBTrack[8]=NULL;
		A5.getSouthTrain()->setLocation("A5");
		A5.getSouthTrain()->setStartingTime(g_Min);

		A5.unloadTrain('s'); //Unload train before sending train in opposite direction

		A5.setNorthTrain(A5.getSouthTrain());
		A5.setSouthTrain(NULL);	

		A5.getNorthTrain()->setDirection('N');
		A5.fromQueueToTrain('n');
	}
	cout << "MBS success! " << g_Min << endl;
};

void System::moveBlueNorthTrains()//need to add from Train to queue and B3 transfer
{
	if(A5.getNorthTrain()!=NULL && g_Min-A5.getNorthTrain()->getStartingTime()==0)
	{
		cout << "Success1\n";
		A5.fromQueueToTrain('n');
		cout << "Success2\n";
		A5.getNorthTrain()->setLocation("A5");
		cout << "Success3\n";
	}
	if(A5.getNorthTrain()!=NULL && g_Min-A5.getNorthTrain()->getStartingTime()==1)
	{
		nBTrack[0]=A5.getNorthTrain();
		A5.setNorthTrain(NULL);
		nBTrack[0]->setLocation("T");
	}
	if(nBTrack[0]!=NULL && g_Min-nBTrack[0]->getStartingTime()==2)
	{
		nBTrack[1]=nBTrack[0];
		nBTrack[0]=NULL;
	}
	if(nBTrack[1]!=NULL && g_Min-nBTrack[1]->getStartingTime()==3)
	{
		nBTrack[2]=nBTrack[1];
		nBTrack[1]=NULL;
	}
	if(nBTrack[2]!=NULL && g_Min-nBTrack[2]->getStartingTime()==4)
	{
		nBTrack[3]=nBTrack[2];
		nBTrack[2]=NULL;
	}
	if(nBTrack[3]!=NULL && g_Min-nBTrack[3]->getStartingTime()==5)
	{
		nBTrack[4]=nBTrack[3];
		nBTrack[3]=NULL;
	}
	if(nBTrack[4]!=NULL && g_Min-nBTrack[4]->getStartingTime()==6)
	{
		nBTrack[5]=nBTrack[4];
		nBTrack[4]=NULL;
	}
	if(nBTrack[5]!=NULL && g_Min-nBTrack[5]->getStartingTime()==7)
	{
		nBTrack[6]=nBTrack[5];
		nBTrack[5]=NULL;
	}
	if(nBTrack[6]!=NULL && g_Min-nBTrack[6]->getStartingTime()==8)//add B3 transfer
	{
		B3B.setNorthTrain(nBTrack[6]);
		nBTrack[6]=NULL;
		B3B.getNorthTrain()->setLocation("B3B");

		B3B.unloadTrain('n'); //unload passenger destination B3 on north bound blue train.
		transferB3('b','n'); //Transfer all passengers on blue, north bound train.
		//Need from queueToTrain()??
		B3B.fromQueueToTrain('n');
	}
	if(B3B.getNorthTrain()!=NULL && g_Min-B3B.getNorthTrain()->getStartingTime()==9)
	{
		nBTrack[7]=B3B.getNorthTrain();
		B3B.setNorthTrain(NULL);
		nBTrack[7]->setLocation("T");
	}
	if(nBTrack[7]!=NULL && g_Min-nBTrack[7]->getStartingTime()==10)
	{
		B2.setNorthTrain(nBTrack[7]);
		nBTrack[7]=NULL;
		B2.getNorthTrain()->setLocation("B2");

		B2.unloadTrain('n');
		B2.fromQueueToTrain('n');
	}
	if(B2.getNorthTrain()!=NULL && g_Min-B2.getNorthTrain()->getStartingTime()==11)
	{
		nBTrack[8]=B2.getNorthTrain();
		B2.setNorthTrain(NULL);
		nBTrack[8]->setLocation("T");
	}
	if(nBTrack[8]!=NULL && g_Min-nBTrack[8]->getStartingTime()==12)
	{
		B1.setNorthTrain(nBTrack[8]);
		nBTrack[8]=NULL;
		B1.getNorthTrain()->setLocation("B1");
		B1.getNorthTrain()->setStartingTime(g_Min);

		B1.unloadTrain('n'); //Unload train before sending it off in the other direction.

		B1.setSouthTrain(B1.getNorthTrain());
		B1.setNorthTrain(NULL);

		B1.getSouthTrain()->setDirection('S');
		B1.fromQueueToTrain('s');
	}
	cout << "MBN success! " << g_Min << endl;
};

void System::moveTrains()
{
	//cout << "Gmin inside of system " << g_Min <<endl;
	moveBlueNorthTrains();
	moveBlueSouthTrains();
	moveRedNorthTrains();
	moveRedSouthTrains();
	cout << "moveTrains() called success at " << g_Min << endl;
};

void System::transferB3(char trainLine,char direction)
{
	//If train line is red, transfer on station B3R (B3 Red)
	if(trainLine=='r' || trainLine=='R')
	{
		Passenger* transfer;
		//Do passenger routing while B3R.fromTrainToQueue() is returning a transfer passenger on the direction it's being called.
		do
		{
			//transfer hold transfer passenger getting off from the train coming in the direction at B3R
			transfer=B3R.fromTrainToQueue(direction);
			//Branching statements for transfer passengers getting off from red line to go to blue stations.
			//Blue stations are(not including B3): B1, B2 are north, A5 is south of the B3 transfer point.

			if(transfer!=NULL && (transfer->destination=="B1" || transfer->destination=="B2")) //If case for stations north side.
			{
				//Convert transfer to non pointer passenger variable
				//Send passenger variable to B3 BLUE , NORTH queue
				Passenger varTransfer=*transfer;
				B3B.randomQueue('n', varTransfer);
			}

			else if(transfer != NULL && transfer->destination=="A5")				//Else if case for stations south side.
			{
				//Send passenger to B3 BLUE, SOUTH queue
				Passenger varTransfer=*transfer;
				B3B.randomQueue('s', varTransfer);
			}
		}while(transfer!=NULL);//while there are transfer passengers at B3R on the direction line.
		delete transfer;//delete transfer after transferring passengers are done.
	}

	//If train line is blue, transfer on station B3B (B3 Red), same as above for red line but for blue line
	if(trainLine=='b' || trainLine=='B')
	{
		Passenger* transfer;
		do
		{
					
			transfer=B3B.fromTrainToQueue(direction);
			if(transfer != NULL && (transfer->destination=="A1" || transfer->destination=="A2" || transfer->destination=="A3" ||
			   transfer->destination=="A4"))//If case for stations north side
			{
				//Convert transfer to non pointer passenger variable
				//Send passenger variable to B3 RED, NORTH queue
				Passenger varTransfer=*transfer;
				B3R.randomQueue('n', varTransfer);
			}
			else if(transfer != NULL && (transfer->destination=="B4" || transfer->destination=="B5"))//else if case for stations south side.
			{
				//Do same as above but send passenger to B3 RED, SOUTH queue
				Passenger varTransfer=*transfer;
				B3R.randomQueue('s', varTransfer);
			}
		}while(transfer!=NULL);
		delete transfer;
	}
};


void System::sendNewTrain(string station) 
{

	if(station!= "A1" && station!= "A5" && station!= "B1" && station!= "B5")
		throw "only edge stations";
	
	
	if(station=="A1" && A1.getSouthTrain()==NULL)
	{
		Train* curr= new Train("A1",'s','r');	//!! need to add acc and mutator fumction to station 	
		A1.setSouthTrain(curr);//!! need to creat set south train and set northtrain which accepts a pointer type train
		NumberOfTrainsForR++;
		
	}
	else if(station=="A5" && A5.getNorthTrain()==NULL)
	{
		Train* curr= new Train("A5",'n','b');		
		A5.setNorthTrain(curr);
		NumberOfTrainsForB++;
	}
	else if(station=="B1" && B1.getSouthTrain()==NULL)
	{
		Train* curr= new Train("B1",'s','b');		
		B1.setSouthTrain(curr);
		NumberOfTrainsForB++;
	}
	else if(station=="B5" && B5.getNorthTrain()==NULL)
	{
		Train* curr= new Train("B5",'n','r');		
		B5.setNorthTrain(curr);
		NumberOfTrainsForR++;
	}
				 
	
}

void System::sendExpress(char direction, char color)
{
	if(direction=='s'&& color=='r'&& exSRTrack[0]==NULL)
	{
		
		exSRTrack[0]=new Train("X",'s','r');
		NumberOfTrainsForR++;

	}
	if(direction=='n'&& color=='r' && exNRTrack[0]==NULL)
	{
		
		exNRTrack[0]=new Train("X",'n','r');
			NumberOfTrainsForR++;

	}
	if(direction=='s'&& color=='b'&& exSBTrack[0]==NULL)
	{
		
		exSBTrack[0]=new Train("X",'s','b');
		NumberOfTrainsForB++;


	}
	if(direction=='n'&& color=='b'&& exNBTrack[0]==NULL)
	{
		
		exNBTrack[0]=new Train("X",'n','b');
		NumberOfTrainsForB++;


	}
}
	
//moves the express red south train
void System::moveExRS()// to be continue move the express tracks along in the last min it verfy that B3 is NULL if not it stay in the ex track 
		// if not it become a local track. change station name accordingly while in express name is X
{
	if(exSRTrack[0]!=NULL && g_Min-exSRTrack[0]->getStartingTime()==1)
	{
		exSRTrack[1]=exSRTrack[0];
		exSRTrack[0]=NULL;
	}
	if(exSRTrack[1]!=NULL && g_Min-exSRTrack[1]->getStartingTime()==2)
	{
		exSRTrack[2]=exSRTrack[1];
		exSRTrack[1]=NULL;
	}
	if(exSRTrack[2]!=NULL && g_Min-exSRTrack[2]->getStartingTime()==3)
	{
		exSRTrack[3]=exSRTrack[2];
		exSRTrack[2]=NULL;
	}
	if(exSRTrack[3]!=NULL && g_Min-exSRTrack[3]->getStartingTime()==4)
	{
		exSRTrack[4]=exSRTrack[3];
		exSRTrack[3]=NULL;
	}
	if(exSRTrack[4]!=NULL && g_Min-exSRTrack[4]->getStartingTime()==5)
	{
		exSRTrack[5]=exSRTrack[4];
		exSRTrack[4]=NULL;
	}
	if(exSRTrack[5]!=NULL && g_Min-exSRTrack[5]->getStartingTime()==6)
	{
		exSRTrack[6]=exSRTrack[5];
		exSRTrack[5]=NULL;
	}
	if(exSRTrack[6]!=NULL && g_Min-exSRTrack[6]->getStartingTime()==7)
	{
		exSRTrack[7]=exSRTrack[6];
		exSRTrack[6]=NULL;
	}
	if(exSRTrack[7]!=NULL && g_Min-exSRTrack[7]->getStartingTime()==8)
	{
		exSRTrack[8]=exSRTrack[7];
		exSRTrack[7]=NULL;
	}
	if(exSRTrack[8]!=NULL && g_Min-exSRTrack[8]->getStartingTime()==9)
	{
		exSRTrack[9]=exSRTrack[8];
		exSRTrack[8]=NULL;
	}
	if(exSRTrack[9]!=NULL && g_Min-exSRTrack[9]->getStartingTime()==10)
	{
		exSRTrack[10]=exSRTrack[9];
		exSRTrack[9]=NULL;
	}
	if(exSRTrack[10]!=NULL && g_Min-exSRTrack[10]->getStartingTime()==11)
	{
		exSRTrack[11]=exSRTrack[10];
		exSRTrack[10]=NULL;
	}
	if(exSRTrack[11]!=NULL && g_Min-exSRTrack[11]->getStartingTime()==12)
	{
		exSRTrack[12]=exSRTrack[11];
		exSRTrack[11]=NULL;
	}
	if(exSRTrack[12]!=NULL && g_Min-exSRTrack[12]->getStartingTime()==13)
	{
		exSRTrack[13]=exSRTrack[12];
		exSRTrack[12]=NULL;
	}
	if(exSRTrack[13]!=NULL && g_Min-exSRTrack[13]->getStartingTime()==14)
	{
		if(B3R.getSouthTrain()==NULL)
		{
			B3R.setSouthTrain(exSRTrack[13]);
			exSRTrack[13]=NULL;
			B3R.getSouthTrain()->setLocation("B3R");
			B3R.fromQueueToTrain('s');
		}
		else
		{
			exSRTrack[14]=exSRTrack[13];//will wait a min to let let the train in station B3R leave
			exSRTrack[13]=NULL;
			exSRTrack[14]->setStartingTime(exSRTrack[14]->getStartingTime()+1);
		}
	}
	if(exSRTrack[14]!=NULL && g_Min-exSRTrack[14]->getStartingTime()==14 && B3R.getSouthTrain()==NULL)
	{
		
			B3R.setSouthTrain(exSRTrack[14]);
			exSRTrack[14]=NULL;
			B3R.getSouthTrain()->setLocation("B3R");
			B3R.fromQueueToTrain('s');
		
	}
}

void System::moveExRN()// to be continue move the express tracks along in the last min it verfy that B3 is NULL if not it stay in the ex track 
		// if not it become a local track. change station name accordingly while in express name is X
{
	if(exNRTrack[0]!=NULL && g_Min-exNRTrack[0]->getStartingTime()==1)
	{
		exNRTrack[1]=exNRTrack[0];
		exNRTrack[0]=NULL;
	}
	if(exNRTrack[1]!=NULL && g_Min-exNRTrack[1]->getStartingTime()==2)
	{
		exNRTrack[2]=exNRTrack[1];
		exNRTrack[1]=NULL;
	}
	if(exNRTrack[2]!=NULL && g_Min-exNRTrack[2]->getStartingTime()==3)
	{
		exNRTrack[3]=exNRTrack[2];
		exNRTrack[2]=NULL;
	}
	if(exNRTrack[3]!=NULL && g_Min-exNRTrack[3]->getStartingTime()==4)
	{
		exNRTrack[4]=exNRTrack[3];
		exNRTrack[3]=NULL;
	}
	if(exNRTrack[4]!=NULL && g_Min-exNRTrack[4]->getStartingTime()==5)
	{
		exNRTrack[5]=exNRTrack[4];
		exNRTrack[4]=NULL;
	}
	if(exNRTrack[5]!=NULL && g_Min-exNRTrack[5]->getStartingTime()==6)
	{
		exNRTrack[6]=exNRTrack[5];
		exNRTrack[5]=NULL;
	}
	if(exNRTrack[6]!=NULL && g_Min-exNRTrack[6]->getStartingTime()==7)
	{
		exNRTrack[7]=exNRTrack[6];
		exNRTrack[6]=NULL;
	}
	if(exNRTrack[7]!=NULL && g_Min-exNRTrack[7]->getStartingTime()==8)
	{
		exNRTrack[8]=exNRTrack[7];
		exNRTrack[7]=NULL;
	}
	if(exNRTrack[8]!=NULL && g_Min-exNRTrack[8]->getStartingTime()==9)
	{
		exNRTrack[9]=exNRTrack[8];
		exNRTrack[8]=NULL;
	}
	if(exNRTrack[9]!=NULL && g_Min-exNRTrack[9]->getStartingTime()==10)
	{
		exNRTrack[10]=exNRTrack[9];
		exNRTrack[9]=NULL;
	}
	if(exNRTrack[10]!=NULL && g_Min-exNRTrack[10]->getStartingTime()==11)
	{
		exNRTrack[11]=exNRTrack[10];
		exNRTrack[10]=NULL;
	}
	if(exNRTrack[11]!=NULL && g_Min-exNRTrack[11]->getStartingTime()==12)
	{
		exNRTrack[12]=exNRTrack[11];
		exNRTrack[11]=NULL;
	}
	if(exNRTrack[12]!=NULL && g_Min-exNRTrack[12]->getStartingTime()==13)
	{
		exNRTrack[13]=exNRTrack[12];
		exNRTrack[12]=NULL;
	}
	if(exNRTrack[13]!=NULL && g_Min-exNRTrack[13]->getStartingTime()==14)
	{
		if(B3R.getNorthTrain()==NULL)
		{
			B3R.setNorthTrain(exNRTrack[13]);
			exNRTrack[13]=NULL;
			B3R.getNorthTrain()->setLocation("B3R");
			B3R.fromQueueToTrain('n');
		}
		else
		{
			exNRTrack[14]=exNRTrack[13];//will wait a min to let let the train in station B3R leave
			exNRTrack[13]=NULL;
			exNRTrack[14]->setStartingTime(exNRTrack[14]->getStartingTime()+1);
		}
	}
	if(exNRTrack[14]!=NULL && g_Min-exNRTrack[14]->getStartingTime()==14 && B3R.getNorthTrain()==NULL)
	{
		
			B3R.setNorthTrain(exNRTrack[14]);
			exNRTrack[14]=NULL;
			B3R.getNorthTrain()->setLocation("B3R");
			B3R.fromQueueToTrain('n');
		
	}
}

// to be continue move the express tracks along in the last min it verfy that B3 is NULL if not it stay in the ex track 
		// if not it become a local track. change station name accordingly while in express name is X
void System::moveExBN()
{
	if(exNBTrack[0]!=NULL && g_Min-exNBTrack[0]->getStartingTime()==1)
	{
		exNBTrack[1]=exNBTrack[0];
		exNBTrack[0]=NULL;
	}
	if(exNBTrack[1]!=NULL && g_Min-exNBTrack[1]->getStartingTime()==2)
	{
		exNBTrack[2]=exNBTrack[1];
		exNBTrack[1]=NULL;
	}
	if(exNBTrack[2]!=NULL && g_Min-exNBTrack[2]->getStartingTime()==3)
	{
		exNBTrack[3]=exNBTrack[2];
		exNBTrack[2]=NULL;
	}
	if(exNBTrack[3]!=NULL && g_Min-exNBTrack[3]->getStartingTime()==4)
	{
		exNBTrack[4]=exNBTrack[3];
		exNBTrack[3]=NULL;
	}
	if(exNBTrack[4]!=NULL && g_Min-exNBTrack[4]->getStartingTime()==5)
	{
		exNBTrack[5]=exNBTrack[4];
		exNBTrack[4]=NULL;
	}
	if(exNBTrack[5]!=NULL && g_Min-exNBTrack[5]->getStartingTime()==6)
	{
		exNBTrack[6]=exNBTrack[5];
		exNBTrack[5]=NULL;
	}
	if(exNBTrack[6]!=NULL && g_Min-exNBTrack[6]->getStartingTime()==7)
	{
		exNBTrack[7]=exNBTrack[6];
		exNBTrack[6]=NULL;
	}
	if(exNBTrack[7]!=NULL && g_Min-exNBTrack[7]->getStartingTime()==8)
	{
		if(B3B.getNorthTrain()==NULL)
		{
			B3B.setNorthTrain(exNBTrack[7]);
			exNBTrack[7]=NULL;
			B3B.getNorthTrain()->setLocation("B3B");
			B3B.fromQueueToTrain('n');
		}	
		else
		{
			exNBTrack[8]=exNBTrack[7];//will wait a min to let let the train in station B3R leave
			exNBTrack[7]=NULL;
			exNBTrack[8]->setStartingTime(exNBTrack[8]->getStartingTime()+1);
		}
	}
	if(exNBTrack[8]!=NULL && g_Min-exNBTrack[8]->getStartingTime()==8 && B3B.getNorthTrain()==NULL)
	{
		
			B3B.setNorthTrain(exNBTrack[8]);
			exNBTrack[8]=NULL;
			B3B.getNorthTrain()->setLocation("B3B");
			B3B.fromQueueToTrain('n');
	}
}
void System::moveExBS()
{
	if(exSBTrack[0]!=NULL && g_Min-exSBTrack[0]->getStartingTime()==1)
	{
		exSBTrack[1]=exSBTrack[0];
		exSBTrack[0]=NULL;
	}
	if(exSBTrack[1]!=NULL && g_Min-exSBTrack[1]->getStartingTime()==2)
	{
		exSBTrack[2]=exSBTrack[1];
		exSBTrack[1]=NULL;
	}
	if(exSBTrack[2]!=NULL && g_Min-exSBTrack[2]->getStartingTime()==3)
	{
		exSBTrack[3]=exSBTrack[2];
		exSBTrack[2]=NULL;
	}
	if(exSBTrack[3]!=NULL && g_Min-exSBTrack[3]->getStartingTime()==4)
	{
	
		if(B3B.getSouthTrain()==NULL)
		{
			B3B.setSouthTrain(exSBTrack[3]);
			exSBTrack[3]=NULL;
			B3B.getSouthTrain()->setLocation("B3B");
			B3B.fromQueueToTrain('s');
		}	
		else
		{
			exSBTrack[4]=exSBTrack[3];//will wait a min to let let the train in station B3R leave
			exSBTrack[3]=NULL;
			exSBTrack[4]->setStartingTime(exSBTrack[4]->getStartingTime()+1);
		}
	}
	if(exSBTrack[4]!=NULL && g_Min-exSBTrack[8]->getStartingTime()==8 && B3B.getSouthTrain()==NULL)
	{
		
			B3B.setSouthTrain(exSBTrack[4]);
			exSBTrack[4]=NULL;
			B3B.getSouthTrain()->setLocation("B3B");
			B3B.fromQueueToTrain('s');
	}
}
		
		
//SYSTEM STARTS HERE!!


void System::callPassAndQueue(int aVolume, int bVolume, int dest){
	passAndQueue(dest, rand() % aVolume+1, "A1");
	passAndQueue(dest, rand() % aVolume+1, "A2");
	passAndQueue(dest, rand() % aVolume+1, "A3");
	passAndQueue(dest, rand() % aVolume+1, "A4");
	passAndQueue(dest, rand() % aVolume+1, "A5");
	passAndQueue(dest, rand() % bVolume+1, "B1");
	passAndQueue(dest, rand() % bVolume+1, "B2");
	passAndQueue(dest, rand() % bVolume+1, "B3");
	passAndQueue(dest, rand() % bVolume+1, "B4");
	passAndQueue(dest, rand() % bVolume+1, "B5");
}


void System::passAndQueue(int destination, int people, string station){
	string bDestinations[5] = {"B1", "B2", "B3", "B4", "B5"};
	string aDestinations[5] = {"A1", "A2", "A3", "A4", "A5"};
	for(int i = 0; i < people; i++){
		Passenger passenger;
		passenger.startingTime=g_Min;
	        passenger.beenOnTrain = false;
		string dest;
		int random = rand() % 100;
		if(random < destination)
		{
			do{
				dest = bDestinations[rand() % 5];
			}while(dest==station);
			passenger.destination = dest;
		}
		else
		{
			do{
				dest = aDestinations[rand() % 5];
			}while(dest==station);
			passenger.destination = dest;
		}
		if(station[0] == dest[0] && station[1] > dest[1])
			randomQueue(station, 'N', passenger);
		else if(station[0] ==  dest[0] && station[1] < dest[1])
			randomQueue(station, 'S', passenger);
		else if(station[0] == 'A' && dest[0] == 'B' && station[1] <= '4')
			randomQueue(station, 'S', passenger);
		else if(station[0] == 'A' && dest[0] == 'B' && station[1] > '4')
			randomQueue(station, 'N', passenger);
		else if(station[0] == 'B' && dest[0] == 'A' && station[1] <= '2')
			randomQueue(station, 'S', passenger);
		else if(station[0] == 'B' && dest[0] == 'A' && station[1] >= '3' && dest[1] <= '4')
			randomQueue(station, 'N', passenger);
		else if(station == "B3" && dest[0] == 'A' && dest[1] > '4');
			randomQueue(station, 'S', passenger);
	}
}


void System::randomQueue(string station, char direction, Passenger person){
	if(station == "A1")
		A1.randomQueue(direction, person);
	else if(station == "A2")
		A2.randomQueue(direction, person);
	else if(station == "A3")
		A3.randomQueue(direction, person);
	else if(station == "A4")
		A4.randomQueue(direction, person);
	else if(station == "A5")
		A5.randomQueue(direction, person);
	else if(station == "B1")
		B1.randomQueue(direction, person);
	else if(station == "B2")
		B2.randomQueue(direction, person);
	else if(station == "B3"){
		if(person.destination[0] == 'A' && person.destination[1] == '5')
			B3B.randomQueue('S', person);
		else if(person.destination[0] == 'A' && person.destination[1] < '5')
			B3R.randomQueue('N', person);
		else if(person.destination[0] == 'B' && person.destination[1] > '3')
			B3R.randomQueue('S', person);
		else if(person.destination[0] == 'B' && person.destination[1] < '3')
			B3B.randomQueue('N', person);
	}
	else if(station == "B4")
		B4.randomQueue(direction, person);
	else if(station == "B5")
		B5.randomQueue(direction, person);
	else
		throw "ninja stars";
}
