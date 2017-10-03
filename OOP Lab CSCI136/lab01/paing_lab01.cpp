/********************************************************************************
Title : paing_lab01.cpp
Author : Ye Paing
Created on : January 30, 2012
Description : Source code for lab01.
Purpose : Asks user for age input, outputs a short message.
Usage : Welcomes user??
Build with : g++ paing_lab01.cpp -o paing_lab01
Modifications : 1/30/2012, revised added this preamble.
*********************************************************************************/

#include <iostream> //preprocessor directives.
using namespace std;

int main()
{
int age; //initial age, safe to leave blank as user will define input.

cout << "Enter your age:"; //output asks user for age.
cin >> age; //user define value for age, regardless of previous value.

cout << "++++++++++++++++++++++++++++++++" //outputs greeting!
	"\nHello, you are " << age << " years old."
        "\nWelcome to CSci 136, section 002"
	"\n++++++++++++++++++++++++++++++++" << endl;

return 0; //end program
};
