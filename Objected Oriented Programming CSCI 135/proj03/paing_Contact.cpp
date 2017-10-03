/**********************************************************************
 Title:         : paing_Contact.cpp
 Author         : Ye Paing
 Created on     : 5/14/2012
 Description    : Source file paing_Contact.h
 Purpose        : Stores member functions definition for paing_Contact.h
 Usage          : ./paing_main.exe "NAME_OF_CSV_FILE.txt"
 Build with     : g++ paing_main.cpp paing_Addressbook.cpp
                  paing_Contact.cpp -o paing_main.exe
 Modification   :
 **********************************************************************/
#include "paing_Contact.h"

//////////////
//setTitle()//
//////////////
void Contact::setTitle()
{
    lname="Last Name:";
    fname="First Name:";
    nname="Nickname:";
    email1="Email 1:";
    email2="Email 2:";
    phone1="Phone 1:";
    phone2="Phone 2:";
    address="Address:";
    website="Website:";
    bday="Birthday:";
    notes="Notes:";

}

//////////////
//getToken()//
//////////////
string  Contact::getToken(int token)
{
    switch(token)
    {
        case 1:
        return lname;
        break;

        case 2:
        return fname;
        break;

        case 3:
        return nname;
        break;

        case 4:
        return email1;
        break;

        case 5:
        return email2;
        break;

        case 6:
        return phone1;
        break;

        case 7:
        return phone2;
        break;

        case 8:
        return address;
        break;

        case 9:
        return website;
        break;

        case 10:
        return bday;
        break;

        case 11:
        return notes;
        break;

        default:
        cout << "Token value ERROR!!" << endl;
        return 0;
        break;
    }
}

//////////////
//setToken()//
//////////////
void Contact::setToken(string data, int token)
{
    switch(token)
    {
        case 1:
        lname=data;
        break;

        case 2:
        fname=data;
        break;

        case 3:
        nname=data;
        break;

        case 4:
        email1=data;
        break;

        case 5:
        email2=data;
        break;

        case 6:
        phone1=data;
        break;

        case 7:
        phone2=data;
        break;

        case 8:
        address=data;
        break;

        case 9:
        website=data;
        break;

        case 10:
        bday=data;
        break;

        case 11:
        notes=data;
        break;

        default:
        cout << "Token value ERROR!!" << endl;
        break;
    }
}
