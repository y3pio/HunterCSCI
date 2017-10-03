/**********************************************************************
 Title:         : paing_Contact.h
 Author         : Ye Paing
 Created on     : 5/14/2012
 Description    : Header file for Class Contact
 Purpose        : Stores private member data for all tokens
 Usage          :
 Build with     :
 Modification   :
 **********************************************************************/
#ifndef PAING_CONTACT_H
#define PAING_CONTACT_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;


class Contact
{
    public:
            void setTitle();
	    //PreCondition: Used by pushtitle function at the start of the program.
	    //PostCondition: Sets index 0 in contact as title line.
	    //NOTE This function should only be called once at the start of the program!

            string getToken(int token);
	    //PreCondition: Takes in integer token (field) to be returned.
	    //PostCondition: Returns the contents of private member data based on token #
	    //NOTE* This is an accessor function.

            void setToken(string data, int token);
	    //PreCondition: Takes in a string data and a token (field) to set the data to.
	    //PostCondition: Sets private member data value based on the desired token(field) with string data.
	    //NOTE* This is an accessor function.

    private:
	    //These are the contact fields which I labeled with token #1-11
            string lname;	//Token # 1
            string fname;	//Token # 2
            string nname;	//Token # 3
            string email1;	//Token # 4
            string email2;	//Token # 5
            string phone1;	//Token # 6
            string phone2;	//Token # 7
            string address;	//Token # 8
            string website;	//Token # 9
            string bday;	//Token # 10
            string notes;	//Token # 11
};

#endif
