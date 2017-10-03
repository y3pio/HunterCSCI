/**********************************************************************
 Title:         : paing_lab05.cpp
 Author         : Ye Paing
 Created on     : 3/5/2012
 Description    : Program to play Pig with an automated computer
		  opponent.
 Purpose        : To practice the usage of random # generator.
 Usage          : ./paing_lab05.exe
 Build with     : g++ paing_lab05.cpp -o paing_lab05.exe
 Modification   : 
 **********************************************************************/
//Preprocessor directives, cstdlib and ctime included for random number generator
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int humanTurn(int humanTotalScore);
//Precondition: takes in total score of the user.
//Postcondition: returns the total roll from the user's turn. 0 if rolled 1.
int computerTurn(int computerTotalScore);
//Precondition: takes in total score of the computer.
//Postcondition: returns the total roll from the computer's turn. 0 if rolled 1.

int main()
{
srand(time(0)); //seeding random function with time.
int hScore=0, cScore=0; //hScore and cScore are actual total score for human and computer respectively.

	do //this do/while loop will run as long as both players have not reached 100
	{
		//Player's turn block.
		cout <<"\n---------------------"
		     << "\nIt is now your turn!" 
		     <<"\n---------------------" << endl;
		hScore = hScore + humanTurn(hScore); //adds returned total roll for turn to be added to score total.
		cout << "Your score is now [" << hScore << "]." << endl;

		//Computer's turn block.
		cout <<"\n---------------------------"
		     << "\nIt is now computer's turn!"
		     << "\n---------------------------" << endl;
		cScore = cScore + computerTurn(cScore); //same addition as seen in user's block.
		cout << "The computer's score is now (" << cScore << ")" << endl;

	}while(hScore<100 && cScore<100); //while loop will stop once score reaches past 100.

//Outputs the final score after someone has reached at least 100
cout << "\nFinal score is.."
     << "\nYour total: " << hScore
     << "\nThe computer's total: " << cScore << endl;

if(hScore > cScore)//output if user wins!! Yay!! =)
	{
	cout << "\n--------------------------------------"
	     << "\nCongratulations!! You've won the game!"
	     << "\n--------------------------------------\n" << endl;
	}

else if(cScore > hScore)//output if computer wins. The computer cheated >=(
	{
	cout << "\n--------------------------------------------------------"
	     << "\nComputer has scored at least 100. Better luck next time!"
	     << "\n--------------------------------------------------------\n" << endl;
	}

return 0;
}

//Function for human's turn.
int humanTurn(int humanTotalScore)
{
int roll=0, total=0; //roll is current roll. total is current turn's total.
char replay;	     //replay is expected to be either h/r for hold/roll.

cout << "Your total score is [" << humanTotalScore << "]" << endl; //output total score at start.

do{
	roll = (rand()%6)+1;
		if(roll>1) //if/else statement for rolls that are not 1.
		{	cout << "\nYou rolled [" << roll << "]" << endl;			     
			total = total+roll;
			cout << "Your total roll for this turn is: " << total << endl; //out puts total for turn.
			cout << "Would you like to roll or hold?(r/h)";

			cin >> replay; //gives user choice for replay if roll is not 1.
		}
		
		else if(roll == 1) //else statement for roll is 1
		{
			cout << "You rolled 1, your turn is over!" << endl;
			total=0; //total is reset to 0 if roll is 1.
			replay = 'h'; //replay is forced to hold to stop user from rolling again.
		}

  }while(replay!='h'); //replay loop will run while it is not 'h' for hold.
return total; //returns turn total to be added to score total.
};

//Function for computer's turn.
int computerTurn(int computerTotalScore)
{
int roll=0, total=0; //same variable structures as the user's function.
char replay;

cout << "--Computer rolling in progress--...." << endl;
do{
	roll = (rand()%6)+1;
		if(roll>1)
		{
			total = total+roll;
			if(total<20)	    
				replay='r'; //will replay roll as long as the turn total is less than 20
			else if(total>=20)
				replay='h'; //computer stops rolling once it's reached at least 20
		}
		//end computer's turn if it gets a roll of 1.
		else if(roll == 1) 
		{
			total=0;
			replay='h';
		}
  }while(replay!='h');
return total; //returns turn total to be added to score total.
}
