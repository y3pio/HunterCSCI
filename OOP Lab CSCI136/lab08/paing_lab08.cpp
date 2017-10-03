/**********************************************************************
 Title:         : paing_lab08.cpp
 Author         : Ye Paing
 Created on     : 3/26/2012
 Description    : CSCI 136 lab08
 Purpose        : Plays the game of Life
 Usage          : ./paing_lab08.cpp
 Build with     : g++ paing_lab08.cpp -o paing_lab.exe
 Modification   : First draft hand in @ 2:06pm 3/26/2012
 **********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int const COLUMN=80, ROW=22;

void initializeWorld(char world[][COLUMN], int ROW);
void displayWorld(const char world[][COLUMN], int ROW);
void generation(char world[][COLUMN], int ROW);
int checkNeighbor(char world[][COLUMN], int ROW, int i, int j);

int main()
{
 char world[ROW][COLUMN], loop;
 initializeWorld(world, ROW);

 do{
 	displayWorld(world, ROW);
	generation(world, ROW);

	cout << "Would you like to run another generation?(y/n):";
	cin >> loop;
   }while(loop== 'y' || loop== 'Y');
 return 0;
}

void initializeWorld(char world[][COLUMN], int ROW)
{
 	srand(time(0));
 	int chance;
 
	for(int i=0; i<ROW; i++)
	{
		for(int j=0; j<COLUMN; j++)
		{	
			chance = rand()%2;	

			if(chance==1)
				world[i][j]='*';

			else
				world[i][j]=' ';
		}

	}

}


void displayWorld(const char world[][COLUMN], int ROW)
{
	for(int i=0; i<ROW; i++)
	{
		for(int j=0; j<COLUMN; j++)
		{	
			cout << world[i][j];
		}
		cout << endl;
	}
}
void generation(char world[][COLUMN], int ROW)
{

 for(int i=0; i<ROW; i++)
 {
	for(int j=0; j<COLUMN; j++)
	{	
        	if(checkNeighbor(world, ROW, i,j)==1)
			world[i][j]='*';
        	else if(checkNeighbor(world, ROW, i,j)==0)
			world[i][j]=' ';
	}
 }
}

int checkNeighbor(char world[][COLUMN], int ROW, int i, int j)
{
 int lifecounter=0;
	if(world[i][j]=='*')
	{
		lifecounter=0;

		if(world[i][j+1]=='*')
		 lifecounter++;
		if(world[i][j-1]=='*')
		 lifecounter++;
		if(world[i+1][j-1]=='*')
		 lifecounter++;
		if(world[i+1][j]=='*')
		 lifecounter++;
		if(world[i+1][j+1]=='*')
		 lifecounter++;
		if(world[i-1][j-1]=='*')
		 lifecounter++;
		if(world[i-1][j]=='*')
		 lifecounter++;
		if(world[i-1][j+1]=='*')
		 lifecounter++;
		
		if(lifecounter==2 || lifecounter==3)
		 return 1;
		else if(lifecounter!=2 || lifecounter!=3)
		 return 0;
	}

	else if(world[i][j]==' ')
	{
		lifecounter=0;

		if(world[i][j+1]=='*')
		 lifecounter++;
		if(world[i][j-1]=='*')
		 lifecounter++;
		if(world[i+1][j-1]=='*')
		 lifecounter++;
		if(world[i+1][j]=='*')
		 lifecounter++;
		if(world[i+1][j+1]=='*')
		 lifecounter++;
		if(world[i-1][j-1]=='*')
		 lifecounter++;
		if(world[i-1][j]=='*')
		 lifecounter++;
		if(world[i-1][j+1]=='*')
		 lifecounter++;
		
		if(lifecounter==3)
		 return 1;

	}
}
