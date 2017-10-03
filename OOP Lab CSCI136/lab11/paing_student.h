/**********************************************************************
 Title:         : paing_student.h
 Author         : Ye Paing
 Created on     : 4/23/2012
 Description    : header file for lab 10.
 Purpose        : declare class student and its members
 Usage          : -
 Build with     : -
 Modification   : Revised version 1. 6:30pm
 **********************************************************************/
#ifndef PAING_STUDENT_H
#define PAING_STUDENT_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

class Student
{
	public:
		void setToken(string data, int token);
		//Precondition: Takes in a string and sets it to request token (1-6)
		//Postcondition: Token is set in private member data.

		string getToken(int token);
		//Precondition: opposite of setToken, it returns the request token (1-6)
		//Postconditn: returns the private member token as requested.
		
	private:
		string studentfname;
		string studentlname;
		string studentid;
		string studentstats;
		string studentgpa;
		string studentcredit;
		
};

#endif
