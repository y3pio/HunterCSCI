/**********************************************************************
 Title:         : paing_lab04.cpp
 Author         : Ye Paing
 Created on     : 2/27/12
 Description    : Lab04 CSCI136
 Purpose        : Program modifies strings received from user.
 Usage          : ./paing_lab04.exe
 Build with     : g++ paing_lab04.cpp -o paing.lab04.exe
 Modification   : modification to option 3.
		  checked for correct values / error output.
 **********************************************************************/
//Pre processor directives.
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int option, i=0, n=0, leg=0; 		      //i for index, n is for length for strings, leg is the length of the matrix leg.
string yourString, resultString, cleanString; //yourString is user string, resultString is result to output/compare, 
					      //cleanString does not contain "'", "." or ","
char c; //c character to draw in the matrix.

int main(){
do{//do loop repeats while option != 4.


	cout <<"\n-----------------------------------------------" 
     	<<"\nMain Menu - Please select one of the following."
     	<<"\n-----------------------------------------------"
     	<<"\n\n1) Enter a string to output it's reverse."
     	<<"\n2) Enter an integer 'n' and a char 'c' to print a n x 2n matrix of c's."
     	<<"\n3) Enter a string to check if it's a palindrome."
     	<<"\n4) Quit."
     	<<"\n\nEnter option #:";
	cin >> option;
	
	switch(option){
		case 1:
			cout <<"\n----------------------- "
		    	 <<"\nYou've entered option 1."
		     	<<"\n----------------------- " << endl;
		
			cout <<"Enter a string to reverse: ";
				cin >> yourString;
			//this block reverses the user's input string.
			n=yourString.length();
			resultString="";
			for(i=0; i<yourString.length(); i++)
			{	
				char last; //char last is a temporary place holder for the string during swap.
				last = yourString[n-1];
				resultString = resultString + last;
				n--;
			}
			cout << "The reverse of your string is [" << resultString << "]" << endl;
		break;

		case 2:

			cout <<"\n----------------------- "
			     <<"\nYou've entered option 2."
			     <<"\n----------------------- " << endl;

			cout <<"Enter a character 'c': ";		
				cin >> c;
			cout <<"Enter an integer n to create a nx2n Matrix of 'c' character: ";
				cin >> leg;
			//for loop to draw a nX2n (leg x 2leg) matrix of character C.
			for(i=0; i<leg; i++)
			{	
				for(int j=1; j<(2*leg); j++)
				{
					cout << c << " ";
				}
			cout << c << endl;
			}

		break;

		case 3:
			cout <<"\n----------------------- "
		     	<<"\nYou've entered option 3."
		     	<<"\n----------------------- " << endl;
		
			cout <<"Enter a string to check for palindrome: ";
			cin >> yourString;
			
			n=yourString.length();
			resultString="";
			//for loop to reverse the string.
			for(i=0; i<yourString.length(); i++)
			{	
				char last, first;
				last = yourString[n-1]; //last for reverse order
				first = yourString[i];	//first for regular order, cleanup of (' , .)
				
				//if statement to clean the original string of characters (' , .)
				if(first != '\'' && first !=',' && first != '.')
				{
					cleanString = cleanString + first;
				}
				//will reverse string and not include the characters (' , .)
				if(last != '\'' && last !=',' && last != '.')
				{
					resultString = resultString + last;
				};
			n--;
			}
		
			cout << "Your original string is: [" << yourString << "]" << endl;
			cout << "Your reverse string is: ["  << resultString << "]" << endl;
			
			//if else statement to compare if it's a palindrome or not.
			if(cleanString == resultString)
				cout << "Your string is a palindrome!" << endl;

			else if(cleanString != resultString)
				cout << "Your string is not a palindrome!" << endl;

		break;	
		
		//option 4 to quit.
		case 4:
			cout << "Good Bye!" << endl;
		break;		

		//default output for all other entries for option.
		default:
			cout << "Invalid choice" << endl;
		break;
	}

}while(option!=4); //while loop to repeat while user does not enter 4.

}
