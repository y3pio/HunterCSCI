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
using namespace std;

class student
{
	public:
		student(string fname, string lname, string idnumber);
		//Precondition: constructs object with first/last name and ID.
		//Postcondition: first/last name and ID set, all others set to default.

		student(string fname, string lname, string idnumber, char status);
		//Precondition: constructs object with first/last name and ID, status.
		//Postcondition: all other data members set to default.

		student(string fname, string lname, string idnumber, char status, double gpa, int credits);
		//Precondition: constructs object for all private members data.
		//Postcondition: all private member data set to user supplied value

		string getID();
		//Precondition: no parameters
		//Postcondition: return student ID.
		string getName();
		//Precondition: no parameters
		//Postcondition: return student first/last name.
		char getStatus();
		//Precondition: no parameters
		//Postcondition: returns student's status.

		bool setStatus(char stats);
		//Precondition: takes in the new status of students.
		//Postcondition: sets the new status of student, returns false if wrong value is given.
		bool setCredits(int cred);
		//Precondition: takes in new credits earned by student.
		//Postcondition: adds the new credits received, returns false if wrong value is given
		bool setGPA(double gpa);
		//Precondition: takes in new gpa for students.
		//Postcondition: updates the student's new gpa, returns fals if wrong value is given.
		
	private:
		string studentfname;
		string studentlname;
		string studentid;
		char studentstats;
		float studentgpa;
		int studentcredits;
		
};

#endif
