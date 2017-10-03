/**********************************************************************
 Title:         : paing_book.h
 Author         : Ye Paing
 Created on     : March 2012
 Description    : Header file for CSCI 135 Project2.
 Purpose        : Defines class book and its members.
 Usage          : #include "paing_book.h"
 Build with     : g++ paing_main.cpp paing_book.cpp -o paing_main.exe
 Modification   : About 12 cans of Redbulls' worth.
 **********************************************************************/
//Define headers, checks if it's defined.
#ifndef PAING_BOOK_H
#define PAING_BOOK_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//Objects created of this class will represent single book from holding file.
class book
{
    //Public functions to set/get the tokens (book info)
    public:
            void setToken(string, int);
            //Precondition: Takes a string and int(token number) and sets the string literal
            //              to that token.
            //Postcondition: Private class member token is set based on the int(token number)

            string getToken(int);
            //Precondition: Accepts an int to select which token to return.
            //Postcondition: Returns token specified by the int parameter.

    //Private members are tokens (book info). I labeled them 0-5
    private:
            string bookcode; //Token # 0
            string lastname; //Token # 1
            string firstname;//Token # 2
            string title;    //Token # 3
            string genre;    //Token # 4
            string status;   //Token $ 5
};

//Define ends.
#endif
