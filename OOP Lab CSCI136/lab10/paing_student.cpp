/**********************************************************************
 Title:         : paing_student.cpp
 Author         : Ye Paing
 Created on     : 4/23/2012
 Description    : implimentation file for lab10's header
 Purpose        : defines the functions
 Usage          : -
 Build with     : g++ paing_lab10.cpp paing_student.cpp -o
                  paing_lab10.exe
 Modification   : Revised version 1. 6:30pm
 **********************************************************************/
#include "paing_student.h"
//Constructor functions

//First constructor with only 3 parameter.
student::student(string fname, string lname, string idnumber)
{
    //If statement to check if id length is not empty or greater than 9.
    if(idnumber.length() > 9 || idnumber.length()==0)
    {
        cout << "Error id number input. Exit code 1." << endl;
        exit(1);
    }
    
    //Everything else gets initialized default.
    else
    {
        studentfname=fname;
        studentlname=lname;
        studentid=idnumber;
        studentstats='F';
        studentgpa=0.00;
        studentcredits=0;
    }
    
}

//Second parameter with added full/part time status parameter.
student::student(string fname, string lname, string idnumber, char status)
{
    //Same check as above.
    if(idnumber.length() > 9 || idnumber.length()==0)
    {
        cout << "Error id number input. Exit code 1." << endl;
        exit(1);
    }
    
    //This checks if status is neither F nor P (both upper and lower)
    //Meaning the class was initialized with something other than full/part time status
    else if(status!='F' && status!='f' && status!='P' && status!='p')
    {
        cout << "Error status input. Exit code 1." << endl;
        exit(1);
    }
    
    //Here only gpa and credits get initialized with default 0 values
    else
    {
        studentfname=fname;
        studentlname=lname;
        studentid=idnumber;
        studentstats=status;
        studentgpa=0.00;
        studentcredits=0;
    }
}

//Constructor that takes all 6 paramater, 1 for each private member data.
student::student(string fname, string lname, string idnumber, char status, double gpa, int credits)
{
    //Same as previous 2.
    if(idnumber.length() > 9 || idnumber.length()==0)
    {
        cout << "Error id number input. Exit code 1." << endl;
        exit(1);
    }
    
    //Same as previous.
    else if(status!='F' && status!='f' && status!='P' && status!='p')
    {
        cout << "Error status input. Exit code 1." << endl;
        exit(1);
    }
    
    //Checks if gpa is higher than a 4.0 or lower than 0.
    else if(gpa > 4.00 || gpa < 0.00)
    {
        cout << "Error gpa input. Exit code 1." << endl;
        exit(1);
    }
    
    //Checks if credit earned is not negative.
    else if(credits < 0)
    {
        cout << "Error credit input. Exit code 1." << endl;
        exit(1);
    }
    
    //Everthing gets constructed with this constructor.
    else
    {
        studentfname=fname;
        studentlname=lname;
        studentid=idnumber;
        studentstats=status;
        studentgpa=gpa;
        studentcredits=credits;
    }
    
}

//Set functions
//These functions allow the user to change private member data for the objects.
//Most of these are bool functions to be used in main with a while loop that keeps asking for the right input.

//Sets a new GPA for the student.
bool student::setGPA(double gpa)
{
    //Checks if the new gpa is within range.
    //Returns false if it is not in range.
    if(gpa > 4.00 || gpa < 0.00)
    {
        cout << "Error gpa input." << endl;
        return false;
    }
    
    //Sets new gpa and outputs the new gpa to screen.
    //Precision set to 2 places for gpa.
    else
    {
        studentgpa=gpa;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "The students new gpa is now:" << gpa;
        return true;//Returns true to end the loop in main
    }
}

//Same structure as above, but for credits.
bool student::setCredits(int cred)
{
    //Check credits value range
    if(cred < 0)
    {
        cout << "Error credit input." << endl;
        return false;
    }
    
    //Adds credit to old credit if it's a valid amoung (greater than 0)
    else
    {
        cout << cred << " credits have been added to the student's total credits." << endl;
        studentcredits+=cred;
        return true;
    }
}

//Same structure as the previous 2. Sets student's new full/part time status.
bool student::setStatus(char stats)
{
    if(stats!='F' && stats!='f' && stats!='P' && stats!='p')
    {
        cout << "Error status input." << endl;
        return false;
    }
    
    else
    {
        //New F/P status set here.
        studentstats=stats;
        return true;
    }
}

//Get functions

//Returns student id #
string student::getID()
{
    return studentid; 
}

//Returns student's FULL name.
string student::getName()
{
    //This adds first name _Space_ last name to one single string.
    string fullname;
    fullname = studentfname + " " + studentlname;
    return fullname;
}

//Retunrs the student's full/part time status.
char student::getStatus()
{
    return studentstats;
}

