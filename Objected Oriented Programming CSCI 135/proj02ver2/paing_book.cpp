/**********************************************************************
 Title:         : paing_book.cpp
 Author         : Ye Paing
 Created on     : March 2012
 Description    : Implimentation file for paing_book.h (Project 2)
 Purpose        : Defines class member function.
 Usage          : Used by main?? O_o
 Build with     : g++ paing_main.cpp paing_book.cpp -o paing_main.exe
 Modification   : Lost count. Note to self: Read rules FIRST!!!
 **********************************************************************/
#include "paing_book.h"

//This function sets token for each object based on given int parameter.
//Pre/Post condition commented in header file.
void book::setToken(string data, int token)
{
    if(token==0)
        bookcode=data;

    else if(token==1)
        lastname=data;

    else if(token==2)
        firstname=data;

    else if(token==3)
        title=data;

    else if(token==4)
        genre=data;

    else if(token==5)
        status=data;
}

//Same as above but in reverse. Returns the request token based on int parameter.
//Pre/Post condition commented in header file.
string book::getToken(int token)
{
    if(token==0)
        return bookcode;

    else if(token==1)
        return lastname;

    else if(token==2)
        return firstname;

    else if(token==3)
        return title;

    else if(token==4)
        return genre;

    else if(token==5)
        return status;
}
