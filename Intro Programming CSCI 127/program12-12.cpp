#include <iostream>
using namespace std;

void printMenu();

int main()
{
int number1, number2;
double answer;
char option;

cout << "Enter 2 integers to calculate." << endl;
cin >> number1 >> number2;

cout << "\nWhat would you like to do with these numbers?" << endl;
printMenu();

cout << "\nEnter your option here: ";
cin >> option;

while	(option!='a' && option!='A' && option!='m' && option!='M' && 
	option!='s' && option!='S' && option!='d' && option!='D')
	
	{
	cout << "\nInvalid choice please try again." << endl;
	printMenu();
	cout << "\nEnter your option here: ";
	cin >> option;
	}

	if(option=='a' || option=='A')
	{
	answer=number1+number2;
	cout << "\nThe sum is: " << answer << endl;
	}

	else if(option=='m' || option=='M')
	{
	answer=number1*number2;
	cout << "\nThe product is: " << answer << endl;
	}

	else if(option=='s' || option=='S')
	{
	answer=number1-number2;
	cout << "\nThe difference is: " << answer << endl;
	}

	else if(option=='d' || option=='D')
	{
	answer=(double)number1/number2;
	cout << "\nThe quotient is: " << answer << endl;
	}

return 0;
}

void printMenu()
{
cout 	<< "Enter a/A for addition." << endl
	<< "Enter m/M for multiplication." << endl
 	<< "Enter s/S for subtraction." << endl
 	<< "Enter d/D for division." << endl;
}
