#include "train_final.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "time_final.h"
#include <iostream>
using namespace std;

/* HEY, THESE ARE YOUR RESPONSIBILITIES:
	**QUEUE FUNCTION TO INCREMENT WAIT TIME - check
	**FUNCTION THAT RECORDS TRAVEL TIME(SEE UNLOAD) - check
	**OUTPUT TO FILE WAIT TIME AND TOTAL TRAVEL TIME - check
*/
	

//srand(time()); done in main


Train::Train()
{}

Train::Train(string location, char direction, char line){
	if((direction != 'N' && direction != 'S' && direction != 'n' & direction != 's') || (line != 'r' && line != 'R' && line != 'b' && line != 'B'))
		throw "error";
	car1 = NULL;
	car2 = NULL;
	car3 = NULL;
	numberInCar1 = 0;
	numberInCar2 = 0;
	numberInCar3 = 0;
	this->location = location;
	this->direction = direction;
	this->line = line;
	startingTime = g_Min;
}

Train::~Train(){
	while(car1 != NULL)
		delete remove(1, 1);
	while(car2 != NULL)
		delete remove(2, 1);
	while(car3 != NULL)
		delete remove(3, 1);
}

Train::Train(const Train& anotherTrain){
	//insert code here
}

Passenger* Train::find(int carNum, int pos){
	if(pos<1 || ((pos > numberInCar1 && carNum == 1) || (pos > numberInCar2 && carNum == 2) || (pos > numberInCar3 && carNum == 3)) || carNum<1 || carNum>3)
		return NULL;
	Passenger* temp;
	switch(carNum)
	{
		case 1:
			temp = car1;
			break;
		case 2:
			temp = car2;
			break;
		case 3:
			temp = car3;
			break;
		default:
			return NULL;
			break;
	}
	for(int i = 2; i <= pos; i++)
		temp = temp->next;
	return temp;	
}

Passenger* Train::remove(int carNum, int pos)
{
	Passenger* passenger;
	if(pos != 1){
		Passenger* prev = this->find(carNum, pos-1);
		passenger = prev->next;
		prev->next = passenger->next;
	}
		switch(carNum){
		case 1:
			if(pos == 1){
				passenger = this->car1;
				this->car1 = car1->next;
				return passenger;
			}
			this->numberInCar1--;
			break;
		case 2:
			if(pos == 1){
				passenger = this->car2;
				this->car2 = car2->next;
				return passenger;
			}
			this->numberInCar2--;
			break;
		case 3:
			if(pos == 1){
				passenger = this->car3;
				this->car3 = car3->next;
				return passenger;
			}
			this->numberInCar3--;
			break;
		default:
			throw "aggrivated programmer";
			break;
	}
	return passenger;
}

void Train::load(Passenger passenger, int carNum){
	switch(carNum){
		case 1:
			if(car1 == NULL)
				car1 = &passenger;
			else{
				if(numberInCar1 >= 64)
					throw "egg sandwhich";
				passenger.next = car1;
				car1 = &passenger;
			}
			numberInCar1++;
			break;
		case 2:
			if(car2 == NULL)
				car2 = &passenger;
			else{
				if(numberInCar2 >= 64)
					throw "chinese potato cake";
				passenger.next = car2;
				car2 = &passenger;
			}
			numberInCar2++;
			break;
		case 3:
			if(car3 == NULL)
				car3 = &passenger;
			else{
				if(numberInCar3 >= 64)
					throw "healthy food";
				passenger.next = car3;
				car3 = &passenger;
			}
			numberInCar3++;
			break;
		default:
			throw "frustrating mta worker";
	}
}

void Train::unload(){
	/*if(MIN % 18 == 0)
		startingTime = MIN;*/
	//Please adjust function to print waitTime and calculate and print totalTime
	ofstream outFile;
	outFile.open("output.txt", ios::out | ios::app);
	if(numberInCar1 > 0)
	{
		for(int i = 1; i < numberInCar1; i++){
			Passenger* curr = find(1, i);
			if(curr->destination == location){
				outFile << curr -> waitTime1 << endl;
				outFile << curr -> waitTime2 << endl;
				curr->totalTime = g_Min-curr->startingTime;
				outFile << curr -> totalTime << endl;
				outFile << endl;
				delete remove(1, i);
				i--;
			}
		}
	}
	if(numberInCar2 > 0)
	{
		for(int i = 1; i < numberInCar2; i++){
			Passenger* curr = find(1, i);
			if(curr->destination == location){
				outFile << curr -> waitTime1 << endl;
				outFile << curr -> waitTime2 << endl;
				curr->totalTime = g_Min-curr->startingTime;
				outFile << curr -> totalTime << endl;
				outFile << endl;
				delete remove(2, i);
				i--;
			}
		}
	}
	if(numberInCar3 > 0)
	{
		for(int i = 1; i < numberInCar3; i++){
			Passenger* curr = find(3, i);
			if(curr->destination == location){
				outFile << curr -> waitTime1 << endl;
				outFile << curr -> waitTime2 << endl;
				curr->totalTime = g_Min-curr->startingTime;
				outFile << curr -> totalTime << endl;
				outFile << endl;
				delete remove(3, i);
				i--;
			}
		}
	}
	if(location == "B3R" || location == "B3B")
	{
		if(numberInCar1 > 0)
		{
			for(int i = 1; i < numberInCar1; i++){
				Passenger* curr = find(1, i);
				if(curr->destination == "B3"){
					outFile << curr -> waitTime1 << endl;
					outFile << curr -> waitTime2 << endl;
					curr->totalTime = g_Min-curr->startingTime;
					outFile << curr -> totalTime << endl;
					outFile << endl;
					delete remove(1, i);
					i--;
				}
			}
		}
		if(numberInCar2 > 0)
		{
			for(int i = 1; i < numberInCar2; i++){
				Passenger* curr = find(1, i);
				if(curr->destination == "B3"){
					outFile << curr -> waitTime1 << endl;
					outFile << curr -> waitTime2 << endl;
					curr -> totalTime = g_Min - curr->startingTime;
					outFile << curr -> totalTime << endl;
					outFile << endl;					
					delete remove(2, i);
					i--;
				}
			}
		}
		if(numberInCar3 > 0)
		{
			for(int i = 1; i < numberInCar3; i++){
				Passenger* curr = find(3, i);
				if(curr->destination == "B3"){
					outFile << curr -> waitTime1 << endl;
					outFile << curr -> waitTime2 << endl;
					curr -> totalTime = g_Min - curr->startingTime;
					outFile << curr -> totalTime << endl;
					outFile << endl;
					delete remove(3, i);
					i--;
				}
			}
		}
	}
	outFile.flush();
	outFile.close();
}
	
char Train::getLine(){
	return line;
}

char Train::getDirection(){
	return direction;
}

string Train::getLocation(){
	return location;
}

void Train::setDirection(char direction){
	if(direction == 'n' || direction == 's' || direction == 'N' || direction == 'S')
		this->direction=direction;
	else{
		//cout << "happiness and sunshine thrown\n";
		throw "happiness and sunshine";
	}
}

void Train::setLocation(string location){
	this->location=location;
} 

void Train::setStartingTime(int minutes){
	startingTime=minutes;
}

int Train::getStartingTime(){
	return startingTime;
}

int Train::getNumberInCar(int carNumber){
	if(carNumber != 1 && carNumber != 2 && carNumber != 3){
		cout << "fit thrown \n";
		throw "frustrated fit";
	}
	if(carNumber == 1)
		return numberInCar1;
	if(carNumber == 2)
		return numberInCar2;
	return numberInCar3;
}

/*void System::callPassAndQueue(int aVolume, int bVolume, int dest){
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
		Passenger passenger();
		passenger.startingTime=MIN;
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
	switch(station){
		case "A1":
			A1.randomQueue(direction, person);
			break;
		case "A2":
			A2.randomQueue(direction, person);
			break;
		case "A3":
			A3.randomQueue(direction, person);
			break;
		case "A4":
			A4.randomQueue(direction, person);
			break;
		case "A5":
			A5.randomQueue(direction, person);
			break;
		case "B1":
			B1.randomQueue(direction, person);
			break;
		case "B2":
			B2.randomQueue(direction, person);
			break;
		case "B3":
			if(person.destination[0] == 'A' && person.destination[1] == '5')
				B3B.randomQueue('S', person);
			else if(person.destination[0] == 'A' && person.desination[1] < '5')
				B3R.randomQueue('N', person);
			else if(person.destination[0] == 'B' && person.destination[1] > '3')
				B3R.randomQueue('S', person);
			else if(person.desination[0] == 'B' && person.destination[1] < '3')
				B3B.randomQueue('N', person);
			break;
		case "B4":
			B4.randomQueue(direction, person);
			break;
		case "B5":
			B5.randomQueue(direction, person);
			break;
		default:
			throw "ninja stars";
	}
}

void Station::randomQueue(char direction, Passenger person){
	if(direction == 'S' || direction == 's')
		southQueue[rand() % 12].enqueue(person);
	else if(direction == 'N' || direction == 'n')
		northQueue[rand() % 12].enqueue(person);
}

void Queue::increaseWaitTime(int whichWaitTime){
	if(whichWaitTime != 1 && whichWaitTime != 2)
		throw "enraged fit";
	Passenger* curr;	
	for(int i = 1; i<=nOfPassengers; i++){
		curr = find(i);
		if(whichWaitTime == 1)
			curr->waitTime1++;
		else
			curr->waitTime2++;
	}
}

Passenger* Queue::find(int pos){
	if(pos<1 || pos>nOfPassengers)
		throw "something";
	Passenger* curr = first;
	for(int i = 2; i<=pos; i++)
		curr=curr->next;
	return curr;
}*/
			
