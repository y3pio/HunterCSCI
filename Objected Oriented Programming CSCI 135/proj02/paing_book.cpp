#include "paing_book.h"

/////////////////
//LINE COUNTER!//
/////////////////
void book::countLines(char * filename, int argvNumber)
{
    ifstream myfile(filename);
    if(!myfile)
    {
        cout << "Unable to locate/open file. Exit code 1." << endl;
        exit(1);
    }

    int i=0;
    string line;
    while(!myfile.eof())
    {
        getline(myfile, line);
        i++;
    }

    if(argvNumber==1)
    {
        maxlines=i;
    }
    else if(argvNumber==2)
    {
        maxrequestlines=i;
    }

    myfile.close();

}

//////////////////////////////////////
//2D ARRAY BUILDER, BUILDS BY TOKENS//
//////////////////////////////////////
void book::buildArray(char * filename)
{
    ifstream myfile(filename);
    if(!myfile)
    {
        cout << "Unable to locate/open file. Exit code 1." << endl;
        exit(1);
    }

    while(myfile)
    {
        int lines=0;
        for(lines=0; lines<maxlines; lines++)
        {

            int words=0;
            for(words=0; words<6; words++)
            {
                myfile >> arrayholdings[lines][words];
            }
        }
    }
    myfile.close();
}

////////////////////////////
//1D ARRAY, BUILDS BY LINE//
////////////////////////////
void book::buildLine(char * filename)
{
    ifstream myfile(filename);
    if(!myfile)
    {
        cout << "Unable to locate/open file. Exit code 1." << endl;
        exit(1);
    }

    while(myfile)
    {
        for(int i=0; i<maxlines; i++)
        {
            getline(myfile, lineholdings[i]);
        }
    }
    myfile.close();
}

////////////////////////////////
//BUILD ARRAY FOR BOOK REQUEST//
////////////////////////////////
void book::buildRequest(char * filename)
{
    ifstream myfile(filename);
    if(!myfile)
    {
        cout << "Unable to locate/open file. Exit code 1." << endl;
        exit(1);
    }

    while(myfile)
    {
        for(int i=0; i<maxrequestlines; i++)
        {
            getline(myfile, requestholdings[i]);
        }
    }
    myfile.close();

}

///////////////////////
//SEARCH ALGORITHM   //
//HOPE THIS WORKS >.<//
///////////////////////
void book::searchRequest()
{
    for(int i=0; i<=maxrequestlines-1; i++)
    {
        bool found=0;
        for(int j=0; j<=maxlines; j++)
        {
            if(requestholdings[i]==arrayholdings[j][0])
            {
                requestholdings[i] += ' ' + arrayholdings[j][3] + ' ' + arrayholdings[j][5];
                found=1;
            }
        }

        if(found==0)
        {
            //Direct string addition not working??
            string unavailable = " unavailable";
            requestholdings[i] += unavailable;
        }
    }
}


////////////////////////////
//SORTING ALGORITHM       //
//HOPE THIS WORKS! TOO =[ //
////////////////////////////
void book::sortList(int token)
{
    //Checks if list is sorted.
    while(checkSortedList(token)==0)
    {
        for(int i=0; i<maxlines; i++)
        {
            if(arrayholdings[i][token] > arrayholdings[i+1][token])
            {

                //Buffer as a temp place holder 0 for token swap, 1 for line swap.
                //[line #] [token #], change token # to compare name,genre.
                string buffer[5]; //pick a decent size (>1??) # to store temp array strings.

                //bool checksortedlist() check by token thus..
                //Swap of token in 2D arrayholdings[][]...
                //must parallel the actual line swap in lineholdings[]!!

                //copy to buffer
                buffer[0]=arrayholdings[i][token];
                buffer[1]=lineholdings[i];

                //swap
                arrayholdings[i][token] = arrayholdings[i+1][token];
                lineholdings[i] = lineholdings[i+1];

                //recopy from buffer
                arrayholdings[i+1][token] = buffer[0];
                lineholdings[i+1] = buffer[1];
            }
        }
    }
}

/////////////////////////////////////////
//MERGE SORT ALGORITHM??? IDK          //
//IF THIS WORKS I CAN GO TO BED ZzZzZzZ//
/////////////////////////////////////////
void book::mergeSort(int firsttoken, int secondtoken)
{
    //Checks if list is sorted by first token
    while(checkSortedList(firsttoken)==0)
    {
        for(int i=0; i<maxlines; i++)
        {
            if(arrayholdings[i][firsttoken] > arrayholdings[i+1][firsttoken])
            {
                //Buffer as a temp place holder 0 for token swap, 1 for line swap.
                //[line #] [token #], change token # to compare name,genre.
                string buffer[5]; //pick a decent size (>4) # to store 2 sets of temp array strings.

                //bool checksortedlist() check by token thus..
                //Swap of first token in 2D arrayholdings[][]...
                //must parallel the actual line swap in lineholdings[]!!
                //copy to buffer
                buffer[0]=arrayholdings[i][firsttoken];
                buffer[1]=lineholdings[i];
                //swap
                arrayholdings[i][firsttoken] = arrayholdings[i+1][firsttoken];
                lineholdings[i] = lineholdings[i+1];
                //recopy from buffer
                arrayholdings[i+1][firsttoken] = buffer[0];
                lineholdings[i+1] = buffer[1];

                //Same as above but swap the value of the 2nd token ONLY in 2d Array as 1D is already swapped.

                //copy to buffer, can reuse buffer
                buffer[0]=arrayholdings[i][secondtoken];
                //swap
                arrayholdings[i][secondtoken] = arrayholdings[i+1][secondtoken];
                //recopy from buffer
                arrayholdings[i+1][secondtoken] = buffer[0];
            }

        }
    }//while loop ends for first token

    //Checks if list is sorted by second token
    while(checkSortedList(secondtoken)==0)
    {
        for(int i=0; i<maxlines; i++)
        {
            if(arrayholdings[i][secondtoken] > arrayholdings[i+1][secondtoken])
            {
                //Buffer as a temp place holder 0 for token swap, 1 for line swap.
                //[line #] [token #], change token # to compare name,genre.
                string buffer[5]; //pick a decent size (>4) # to store 2 sets of temp array strings.

                //bool checksortedlist() check by token thus..
                //Swap of first token in 2D arrayholdings[][]...
                //must parallel the actual line swap in lineholdings[]!!
                //copy to buffer
                buffer[0]=arrayholdings[i][secondtoken];
                buffer[1]=lineholdings[i];
                //swap
                arrayholdings[i][secondtoken] = arrayholdings[i+1][secondtoken];
                lineholdings[i] = lineholdings[i+1];
                //recopy from buffer
                arrayholdings[i+1][secondtoken] = buffer[0];
                lineholdings[i+1] = buffer[1];
            }
        }
    }//2nd while loop ends for sorting by 2nd token.

}//merge sort function ends.

///////////////////////
//SORTED LIST CHECKER//
///////////////////////
bool book::checkSortedList(int token)
{
    for(int i=0; i<maxlines; i++)
    {
            if(arrayholdings[i][token] > arrayholdings[i+1][token])
                return 0; //if this if statement passes, there is swap to be done.
    }
    return 1; //1 when there is no swap needs to be done.
}

//////////////////////////////////////////
//WRITE RESULTS TO PUBLIC ARRAY FOR MAIN//
//////////////////////////////////////////
void book::getResults(int task)
{
    if(task==1 || task==2)
    {
        int i=0;
        for(int i=0; i<=maxlines; i++)
        {
            resultHoldings[i] = lineholdings[i];
        }
    }

    else if(task==3)
    {
        int i=0;
        for(int i=0; i<=maxlines; i++)
        {
            resultHoldings[i] = requestholdings[i];
        }
    }
}
