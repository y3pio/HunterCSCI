/**********************************************************************
 Title:         : paing_main.cpp
 Author         : Ye Paing
 Created on     : March 2012
 Description    : Project 2 for CSCI 135
 Purpose        : Perform file I/O opearations
                  Sorts/Search text files.
 Usage          : .\paing_main.exe
                  Pass command line arguements in following order:
                  1) library_holdings.txt
                  2) book_requests.txt
                  3) NAME_OF_RESULT1.txt
                  4) NAME_OF_RESULT2.txt
                  5) NAME_OF_RESULT3.txt
 Build with     : g++ paing_main.cpp paing_book.cpp -o paing_maing.exe
 Modification   : ...A LOT!! =(
 **********************************************************************/
#include "paing_book.h"//Include header file for class book.

//Function Prototype

int countLines(char * filename);
//Precondition: Input a file name. Usually argv[1-2] to count lines in text file.
//Postcondition: Returns the number of lines in the file.

bool checkSortedList(book obj[], int maxline, int token);
//Precondition: Input an object array, max number of lines in object array.
//              And the token to check if it's sorted (0-5)
//Postcondition: Returns 0 if list still need sorting, 1 if it doesn't.

int main(int argc, char * argv[]) //Main, pointer argv[] from command line arguement.
{
    //Declare objects. holdings for book holdings, request for book requests, and buffer obj for swapping.
    //Array size initialized by line counter.
    book holdings[countLines(argv[1])], request[countLines(argv[2])], buffer[5];

    //Building holdings array.
    //Open holding file: argv[1]
    ifstream myfile(argv[1]);
    //Exit 1 if file is not found.
    if(!myfile)
    {
        cout << "Unable to locate/open file. Exit code 1." << endl;
        exit(1);
    }

    //While myfile is open. Might want to use !myfile.eof ??
    while(myfile)
    {
        //For loop to run the entire length of file.
        //From i=0 to i<the result of line count.
        for(int i=0; i<countLines(argv[1]); i++)
        {
            //j from 0 to 6 exclusive for 6 tokens.
            for(int j=0; j<6; j++)
            {
                //Inputs to buffer string token
                //Check implimentation file for member function definition.
                string token;
                myfile >> token;
                holdings[i].setToken(token, j);
            }
        }
    }
    myfile.close();//Closes myfile after array of holdings if built.

    //Same as above but for building the request object array.
    myfile.open(argv[2]);
        if(!myfile)
    {
        cout << "Unable to locate/open file. Exit code 1." << endl;
        exit(1);
    }
    while(myfile)
    {
        for(int i=0; i<countLines(argv[2]); i++)
        {
            string token;
            myfile >> token;
            request[i].setToken(token, 0);
        }
    }
    myfile.close();//Book request array finish building. Close myfile.

//////////////////////
//***--TASK ONE--***//
//////////////////////

    //Output stream resultfile to whatever name is given for argv[3]
    ofstream resultfile(argv[3]);

    //j is a semi-global variable for token that needs to be checked.
    //copy/paste this block and change j whenever sort check is needed.
    int j=1; //In this case j = 1 (check last name).

    //While loop will run as long as list is not in order according to token j.
    while(checkSortedList(holdings, countLines(argv[1]), 1)==0)
    {
        //I hope this sort works. >.<
        for(int i=0; i<countLines(argv[1])-1; i++)
        {
            if(holdings[i].getToken(j) > holdings[i+1].getToken(j))
            {
                book buffer[5];
                buffer[0] = holdings[i];
                holdings[i] = holdings[i+1];
                holdings[i+1] = buffer[0];

            }
        }
    }

    //Output to file the results for task one below.
    resultfile << "//////////////////////////////////////////////////////\n"
                << "//LIST OF BOOK HOLDINGS SORTED BY AUTHOR'S LAST NAME//\n"
                << "//////////////////////////////////////////////////////" << endl;
        for(int i=0; i<countLines(argv[1]); i++)
        {
            for(int j=0; j<6; j++)
            {
                resultfile << holdings[i].getToken(j) << " ";
            }
            resultfile << endl;
        }

    resultfile.close();//Close resultfile after outputting results.

//////////////////////
//***--TASK TWO--***//
//////////////////////

    //Opens filename based of argv[4] to output results for task 2
    resultfile.open(argv[4]);

    //Same sort as top, yes it did work! =D
    while(checkSortedList(holdings, countLines(argv[1]), 4)==0)
    {
        //Sorts by genre (token 4) first.
        j=4;
        for(int i=0; i<countLines(argv[1])-1; i++)
        {
            if(holdings[i].getToken(j) > holdings[i+1].getToken(j))
            {
                book buffer[5];
                buffer[0] = holdings[i];
                holdings[i] = holdings[i+1];
                holdings[i+1] = buffer[0];
            }
        }
    }

    //2nd sort based on sorted list by genre
    for(int i=0; i<countLines(argv[1])-1; i++)
    {
        //Checks if genre is equal to each other, and sorts accordingly.
        if(holdings[i].getToken(j) == holdings[i+1].getToken(j))
        {
            //Sorts by last name within the same genre
            j=1;
            //If this works I can go to bed...=)
            if(holdings[i].getToken(j) > holdings[i+1].getToken(j))
            {
                buffer[5];
                buffer[0] = holdings[i];
                holdings[i] = holdings[i+1];
                holdings[i+1] = buffer[0];
            }
        }
    }

    //Took a while to get it to work..=(
    //Writes the result of task 2 to output file...also I'm running out of Redbull.
    resultfile << "////////////////////////////////////////////////////////////\n"
                << "//LIST OF BOOK HOLDINGS SORTED BY GENRE + AUTHOR LAST NAME//\n"
                << "///////////////////////////////////////////////////////////" << endl;
        for(int i=0; i<countLines(argv[1]); i++)
        {
            for(int j=0; j<6; j++)
            {
                resultfile << holdings[i].getToken(j) << " ";
            }
            resultfile << endl;
        }

    resultfile.close();//Close file after output, open +1 can of Redbull.

////////////////////////
//***--TASK THREE--***//
////////////////////////

    //Open file for outputting results for task 3 based on argv[5]
    resultfile.open(argv[5]);

    //Searching algorithm, OK this seems easy enough...
    //This for loop will run the length of the request file
    for(int i=0; i<countLines(argv[2]); i++)
    {
        //Search holdings for requested book code.
        bool found=0; //bool found is always 0 (not found) at the START.

        //This for loop runs through the holdings list searching for requested book code.
        for(int j=0; j<countLines(argv[1]); j++)
        {
            //When code is found write title/status of the book to request tokens.
            if(request[i].getToken(0)==holdings[j].getToken(0))
            {
                request[i].setToken(holdings[j].getToken(3), 3);
                request[i].setToken(holdings[j].getToken(5), 5);
                found=1;
            }
        }

        //If bool found is still 0 here it means the code is not there.
        if(found==0)
        {
            //Write "unavailable" to it's ststus token.
            request[i].setToken("unavailable", 5);
        }
    }

    //WOW I can't believe that worked on the first run.
    //Same output format as the previous 2...I AM OFF TO BED!!!!WHEEEEEEEE!!!
    resultfile << "///////////////////////////\n"
               << "//STATUS OF REQUEST BOOKS//\n"
               << "///////////////////////////\n" << endl;
    for(int i=0; i<countLines(argv[2]); i++)
    {
        resultfile << request[i].getToken(0) << " "
                   << request[i].getToken(3) << " "
                   << request[i].getToken(5) << endl;
    }

    resultfile.close(); //Close file after it's done.

return 0;
}

//Function implimentation for main()'s functions.

//This is the line counter, it counts line..LOL
int countLines(char * filename)
{
    ifstream myfile(filename);
    int i=0;
    while(myfile)
    {
        string buffer;
        getline(myfile, buffer); //Using getline, will count line by line.
        i++; //Incriment linecounter.
    }
    return i;
}

//This function checks if a list is sorted.
bool checkSortedList(book obj[], int maxlines, int token)
{
    for(int i=0; i<maxlines-1; i++)
    {
            if(obj[i].getToken(token) > obj[i+1].getToken(token))
                return 0; //if this if statement passes, there is swap to be done, return 0.
    }
    return 1; //return 1 when there is no swap needs to be done.
}
