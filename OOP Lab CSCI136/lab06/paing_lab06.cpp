/**********************************************************************
 Title:         : paing_lab06.cpp
 Author         : Ye Paing
 Created on     : 3/12/12
 Description    : Lab06 for CSCI136
 Purpose        : Simluates a duel program based on  given probability
		  for 3 shooters/targets.
 Usage          : ./paing_lab06.exe
 Build with     : g++ paing_lab06_.cpp -o paing_lab06.exe
 Modification   :
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
bool aaron=1, bob=1, charlie=1; //They are all 1(alive) at the start.

do{ //do-while loop will run as long as 2 of them are alive.

//Aaron goes first.
aaronShoots(aaron, bob, charlie);

//Bob goes second
bobShoots(aaron, bob, charlie);

//Charlie goes last
charlieShoots(aaron,bob,charlie);

}while((aaron==1 && bob==1) || (aaron==1 && charlie==1) || (bob==1 && charlie==1)); //loop while any 2 of them are alive at the same time.

//Output at the end for the person left alive.

if(aaron==1) //Aaron is alive.
	cout <<"\n====================================" 
	     <<"\nThe winner of the duel is: Aaron." 
	     <<"\n====================================\n" << endl;

else if(bob==1) //Bob is alive
	cout <<"\n====================================" 
	     <<"\nThe winner of the duel is: Bob." 
	     <<"\n====================================\n" << endl;

else if(charlie==1) //Charlie is alive
	cout <<"\n====================================" 
	     <<"\nThe winner of the duel is: Charlie." 
	     <<"\n====================================\n" << endl;

return 0;
}

//Functions start here.

void aaronShoots(bool aaron, bool& bob, bool& charlie) //Aaron 1/3
{
srand(time(0)); //Random seeding.
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
srand(time(0));
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
srand(time(0));
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
