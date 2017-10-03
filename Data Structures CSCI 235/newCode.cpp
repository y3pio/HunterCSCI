struct systemTrack
{
	Train* aTrain;
	Station* aStation;
};

class System
{
	private:
		systemTrack redLines[38];
		systemTrack blueLines[26];
		int nOfRedTrains;
		int nOfBlueTrains;
	public:
		void System::setNameForStations();
		void moveRedTrains();
		void moveBlueTrains();
};

//System functions

System::System()
{
	//For red lines.
	for(int i=0; i<38; i++)
	{
		cStation = new Station();
		redLines[i].aTrain=NULL;

		if((i%2==0 && i<=6) || (i%2==0 && i>=14 && i<=18))
			redLines[i].aStation=cStation;

		else if((i%2==1 && i>=19 && <=23) || (i%2==1 && i>=31))
			redLines[i].aStation=cStation; 
	}

	//For blue lines.
	for(int i=0; i<26; i++)
	{
		cStation = new Station();
		blueLines[i].aTrain=NULL;

		if((i%2==0 && i<=4) || (i==12))
			blueLines[i].aStation=cStation;

		else if((i%2==1 && i==13) || (i%2==1 && i<=25 && i>=21)
			blueLines[i].aStation=cStation;
	}

	Train* toA1= new Train("A1",'S','R');
	Train* toA5= new Train("A5",'N','B'); 
	Train* toB1= new Train("B1",'S','B');
	Train* toB5= new Train("B5",'N','R'); 
	int nOfRedTrains=2;
	int nOfBlueTrains=2;

	redLines[0].aStation->setTrain(toA1);
	redLines[19].aStation-setTrain(toB5);

	blueLines[0].aStation-setTrain(toB1);
	blueLines[13].aStation-setTrain(toA5);
}

void System::moveTrains(char line, int j, int south, int north)
{
	systemTrack* track=(line=='r' ? redLines:blueLines);
	for(int i=0; i<j; i++)
	{
		//Track to station
		if((track)[i].aTrain!=NULL && (track)[i].aStation==NULL && (track)[i+1].aStation!=NULL && (track)[i+1].aStation->getTrain()==NULL)
		{
			(track)[i+1].aStation->setTrain((track)[i].aTrain);
			(track)[i].aTrain=NULL;
			(track)[i+1].aStation->getTrain()->setLocation((track)[i+1].aStation->getStationName());
		}
		
		//Station to track
		else if((track)[i].aStation!=NULL && (track)[i].aStation->getTrain()!=NULL && (track)[i+1].aTrain==NULL && (track)[i+1].aStation==NULL)
		{
			(track)[i+1].aTrain=(track)[i].aStation->getTrain();
			(track)[i].aStation->setTrain(NULL);
			(track)[i+1].aTrain->setLocation("T");
		}		

		//Track to track
		else if((track)[i].aStation==NULL && (track)[i].aTrain!=NULL && (track)[i+1].aTrain==NULL && (track)[i+1].aStation==NULL)
		{
			(track)[i+1].aTrain=(track)[i].aTrain;
			(track)[i].aTrain=NULL;
		}

		//Special edge station case A1 and B5
		else if(i==south && (track)[i].aStation!=NULL && (track)[i].aStation->getTrain()!=NULL && (track)[i+1].aStation!=NULL && (track)[i+1].aStation->getTrain()==NULL)
		{
			(track)[i+1].aStation->setTrain((track)[i].aStation->getTrain());
			(track)[i].aStation->setTrain(NULL);
		}

		else if(i==north && (track)[i].aStation!=NULL && (track)[i].aStation->getTrain()!=NULL && (track)[0].aStation!=NULL && (track)[0].aSTation->getTrain()==NULL)
		{
			(track)[0].aStation->setTrain((track)[i].aStation->getTrain());
			(track)[i].aStation->setTrain(NULL);
		}
	}
};

void System::setNameForStations()
{
	//South bound
	redLines[0].aStation->setStationName("A1");
	redLines[2].aStation->setStationName("A2");
	redLines[4].aStation->setStationName("A3");
	redLines[6].aStation->setStationName("A4");
	redLines[14].aStation->setStationName("B3R"); //B3R ? B3B?
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
	redLines[23].aStation->setStationName("B3R"); //B3R ? B3B?
	redLines[21].aStation->setStationName("B4");
	redLines[19].aStation->setStationName("B5");

	blueLines[25].aStation->setStationName("B1");
	blueLines[23].aStation->setStationName("B2");
	blueLines[21].aStation->setStationName("B3B");
	blueLines[13].aStation->setStationName("A5");


}


///////////////////////////////////////
// STATION MODIFICATION BELOW HERE!! //
///////////////////////////////////////
class Station
{
	private:
		string stationName;
		Train* aTrain;
		Queue aQueue[12];

	public:
		Station();
		Station(Train* train);

		void setTrain(Train* train);
		Train* getTrain();

		void setStationName(string name);
		string getStationName();
		
		
}

//Station functions

Station::Station()
{
	stationName="";
	aTrain=NULL;
}

void Station::setTrain(Train* train)
{
	aTrain=train;
}

Train* getTrain()
{
	return aTrain;
}

void Station::setStationName(string name)
{
	stationName=name;
}

string Station::getStationName()
{
	return stationName;
}

