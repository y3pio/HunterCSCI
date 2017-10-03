/**********************************************************************
 
 Title:         : paing_lab02.cpp
 Author         : Ye Paing
 Created on     : February 06, 2012
 Description    : C++ Program for lab02.
 Purpose        : To calculate user's name length.
 Usage          : Asks user for name, outputs various results.
 Build with     : g++ paing_lab02.cpp -o paing_lab02.exe
 Modification   :
 
 **********************************************************************/
//Preprocessor directives
#include <iostream>
#include <string>
using namespace std;

//main program start
int main()
{//***NOTE Naming scheme for constants are all CAPS**
double avgDouble = 5.8; //double data type for class avg
int avgInt = 6; //int data type for rounded class avg

string firstName, lastName, midName; //strings for user to input names.
int x,xth; //x for actual 0-n string, xth for user friendly 1-n display.
double yourAverage, userNameLength; //variables for average, name length.

//asks user for first name, puts length into userNameLength
cout << "Enter your first name:";
	cin >> firstName;
	userNameLength = firstName.length();

//asks user for number between 1-n(name length)
cout << "Enter a number between 1 and " << userNameLength << ":";
cin >> xth; //inputs to variable xth
	x = xth-1; //xth -1 since strings start at 0th place.
cout << "The character at position " << xth << " in your name is "
	<< firstName[x] << "." << endl;
//cout will display user friendly xth variable while calculating the correct place with x.

//setting decimal precision for calculations coming up.
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

//outputs average name length
cout << "The average name length of students in this class is of " 
	<< avgDouble << " characters." << endl;

//calculates your ratio to class avg.
yourAverage = userNameLength/avgDouble;
cout << "The ratio of your name length to the class average is: " 
<< yourAverage << endl;

//calculates ratio to ROUNDED class avg
yourAverage =  static_cast<double>(userNameLength)/(avgInt);
cout << "The ratio of your name length to the rounded class average is: " << yourAverage << endl;

//if/else branch for long,short,avg name. 1=average.
	if(yourAverage > 1)
	cout << "You have a long name!!" << endl;

	else if(yourAverage < 1)
	cout << "You have a short name!!" << endl;

	else
	cout << "You have an average length name!!" << endl;

//asks for last name.
cout << "Enter your last name:";
cin >> lastName;

//asks for mid, * if don't have one.
cout << "Enter your middle name(enter * if you don't have one):";
cin >> midName;

//if length of midname is not '*'
	if(midName[0]!='*'){
	cout << "Your initials are " << firstName[0] << ". " 			<< midName[0] << "." << lastName[0] << ". " << endl;
	}
//else no mid name.
	else{
	cout << "Your initials are " << firstName[0] << ". " 
	<< lastName[0] << "." << endl;
	}

//if/else calculations for midname or no midname
		if(midName[0]!='*')
		userNameLength = firstName.length() + lastName.length() 		+ midName.length();

		else
		userNameLength = firstName.length() + lastName.length();

//out puts total length of your entire name.
cout << "The total length of your full name is " << userNameLength 
	<< " characters." << endl;

//avg calculations for midname or no midname.
	if(midName[0]!='*')
	userNameLength = static_cast<double>(userNameLength)/3;

	else
	userNameLength = static_cast<double>(userNameLength)/2;

//final average output of your name length.
cout << "The average length of your full name is: " << userNameLength << endl;

return 0;
}
