/**********************************************************************
 Title:         : paing_lab06_extracredit.cpp
 Author         : Ye Paing
 Created on     : 3/12/12
 Description    : Lab06 for CSCI136
 Purpose        : Simluates a duel program based on  given probability
		  for 3 shooters/targets for 10000 simulated duels.
 Usage          : ./paing_lab06_extracredit.exe
 Build with     : g++ paing_lab06_extracredit.cpp -o paing_lab06_extracredit.exe
 Modification   : Added loop to simulate 10000 duels.
		  Added a modified 10000 duels loop where Aaron misses.
 **********************************************************************/
//Preprocessor directive. cstdlib & ctime included for random # gen.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void aaronShoots(bool aaron, bool& bob, bool& charlie); //Aaron's shooting funtcion 1/3
//Precondition:Takes in bool values(1 for alive, 0 for dead) for all 3 shooters.
//Postcondition:Based on Aaron's shot(hit/miss) will change target's (Bob/Charlie) alive/dead bool values.

void bobShoots(bool& aaron, bool bob, bool& charlie); //Bob's shooting function 1/2
//Precondition:Takes in bool values(1 for alive, 0 for dead) for all 3 shooters.
//Postcondition:Based on Bob's shot(hit/miss) will change target's (Aaron/Charlie) alive/dead bool values.

void charlieShoots(bool& aaron, bool& bob, bool charlie); //Charlie's shooting function 1/1
//Precondition:Takes in bool values(1 for alive, 0 for dead) for all 3 shooters.
//Postcondition:Will always change Bob and Aaron's alive/dead value to 0 as Charlie always hits.

int main()
{
srand(time(0)); //Random seeding.
int index=0, acounter=0, bcounter=0, ccounter=0; //index is for loop counter, (a-c)counter are counters for (A)aron, (B)ob, (C)harlie
do{

	bool aaron=1, bob=1, charlie=1; //They are all 1(alive) at the start.
	do{ //do-while loop will run as long as 2 of them are alive.

	//Aaron goes first.
	aaronShoots(aaron, bob, charlie);

	//Bob goes second
	bobShoots(aaron, bob, charlie);

	//Charlie goes last
	charlieShoots(aaron,bob,charlie);

	}while((aaron==1 && bob==1) || (aaron==1 && charlie==1) || (bob==1 && charlie==1)); //loop while any 2 of them are alive at the same time.
	
	//if else statement to add to win counter.
	if(aaron==1)
	acounter++; //adds to Aaron's counter if Aaron == 1(alive)

	else if(bob==1)
	bcounter++; //adds to Bob's counter if Bob == 1(alive)

	else if(charlie==1)
	ccounter++; //adds to Charlie's counter if Charlie == 1(alive)

	index++; //Adds index to bring loop to an end.

}while(index<10000); //Loop runs from 0-9999 (10000) times.

//Output the result for 10000 duels.
cout << "\n==========================================="
     << "\nResults for 10000 simulated duels!!"
     << "\n==========================================="
     << "\nAaron won [" << acounter << "/10000 times or " << (static_cast<double>(acounter)/100) << "%"
     << "\nBob won [" << bcounter << "/10000 times or " << (static_cast<double>(bcounter)/100) << "%"
     << "\nCharlie won [" << ccounter << "/10000 times or " << (static_cast<double>(ccounter)/100) << "%"
     << "\n===========================================" << endl;

//RESETS ALL COUNTERS/INDEX FOR MODIFIED LOOP FOR AARON
index=0, acounter=0, bcounter=0, ccounter=0;
do{

	bool aaron=1, bob=1, charlie=1; //They are all 1(alive) at the start.
	do{ //do-while loop will run as long as 2 of them are alive.

	//Bob goes first.
	bobShoots(aaron, bob, charlie);

	//Charlie goes second.
	charlieShoots(aaron,bob,charlie);

	//Aaron goes last.
	aaronShoots(aaron, bob, charlie);

	}while((aaron==1 && bob==1) || (aaron==1 && charlie==1) || (bob==1 && charlie==1)); //loop while any 2 of them are alive at the same time.
	
	//Same if/else statement to add to win counter.
	if(aaron==1)
	acounter++;

	else if(bob==1)
	bcounter++;

	else if(charlie==1)
	ccounter++;

	index++;

}while(index<10000);

//Output for Aaron's modified loop where he misses his first shot (or he goes last).
cout << "\nResults for 10000 simulated duels with Aaron missing his first shot." << endl;

cout << "\n==========================================="
     << "\nResults for 10000 simulated duels!!"
     << "\n==========================================="
     << "\nBob won [" << bcounter << "/10000 times or " << (static_cast<double>(bcounter)/100) << "%"
     << "\nCharlie won [" << ccounter << "/10000 times or " << (static_cast<double>(ccounter)/100) << "%"
     << "\nAaron won [" << acounter << "/10000 times or " << (static_cast<double>(acounter)/100) << "%"
     << "\n===========================================" << endl;

return 0;
}

//Functions start here.

void aaronShoots(bool aaron, bool& bob, bool& charlie) //Aaron 1/3
{
int shot=0;
	
	//If else statemens to check if both shooter and target is alive.

	if(aaron==1 && charlie==1) //Aaron shoots Charlie as he is the biggest threat.
	{
	   shot=rand()%3; //Mod 3 for 1/3 chance. Shot gets # 0-2
		if(shot==0) //0 means hit.
			charlie=0; //means charlie is dead
	}		

	else if(aaron==1 && bob==1) //Shoots bob next
	{
	   shot=rand()%3; //Same mod 3 for 1/3 chance.
		if(shot==0)
			bob=0; //if 0, bob is dead.
	}


}

void bobShoots(bool& aaron, bool bob, bool& charlie) //Bob 1/2
{
int shot=0;

	//If else statemens to check if both shooter and target is alive.

	if(bob==1 && charlie==1) //Bob shoots the biggest threat for him first which is Charlie.
	{
	   shot=rand()%2; //Mod 2 for 1/2 chance. either 0 or 1.
		if(shot==0) //0 for hit.
			charlie=0; //means Charlie is dead.
	}	

	else if(bob==1 && aaron==1)
	{
	   shot=rand()%2; //Same chance for shooting Aaron.
		if(shot==0)
			aaron=0; //Aaron is dead if 0.
	}

}

void charlieShoots(bool& aaron, bool& bob, bool charlie) //Charlie 1/1
{
int shot=0;

	//If else statemens to check if both shooter and target is alive.

	if(charlie==1 && bob==1) //Bob will be the most threat to Charlie.
	{
	   shot=rand()%1; //Mod 1 will always give 0. Can exclude this for Charlie's 1/1 ratio.
		if(shot==0)
			bob=0; //Bob is dead.
	}	

	else if(charlie==1 && aaron==1)
	{
	   shot=rand()%1;
		if(shot==0)
			aaron=0; //Aaron is dead.
	}
}
