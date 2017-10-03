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

void Student::setToken(string data, int token)
{
	if(token==1)
	studentfname=data;

	else if(token==2)
	studentlname=data;

	else if(token==3)
	studentid=data;

	else if(token==4)
	studentstats=data;

	else if(token==5)
	studentgpa=data;

	else if(token==6)
	studentcredit=data;	
}

string Student::getToken(int token)
{
	if(token==1)
	return studentfname;

	else if(token==2)
	return studentlname;

	else if(token==3)
	return studentid;

	else if(token==4)
	return studentstats;

	else if(token==5)
	return studentgpa;

	else if(token==6)
	return studentcredit;	
}
