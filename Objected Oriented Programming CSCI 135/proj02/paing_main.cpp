#include "paing_book.h"

//Global Constants - For testing/hard coding purpose

//int MAXROW=;
//int MAXREQUEST=;
//char * HOLDINGS_FILE_NAME="YOUR_FILE_NAME_HERE";
//char * REQUEST_FILE_NAME="YOUR_FILE_NAME_HERE";

int main(int argc, char * argv[])
{
    book taskone, tasktwo, taskthree;

        //******************//
        //--TASK O N E (1)--//
        //******************//

    //Run countLines for both files FIRST!!
    taskone.countLines(argv[1], 1);
    taskone.countLines(argv[2], 2);

    //Build array after rows are counted
    taskone.buildArray(argv[1]);
    taskone.buildLine(argv[1]);


    //Input #0-5 to  sortList() to sort according to tokens.
    //Token #: 0 = Sort by Book Code
    //         1 = Sort by Last Name
    //         2 = Sort by First Name
    //         3 = Sort by Title
    //         4 = Sort by Genre
    //         5 = Sort by Avaliablity
    taskone.sortList(1); //Task One requests sort by Last Name(1).

    //Write result of task 1 to file.
    taskone.getResults(1);
    ofstream myfile(argv[3]);
    myfile << "//////////////////////////////////////////////////////\n"
            << "//LIST OF BOOK HOLDINGS SORTED BY AUTHOR'S LAST NAME//\n"
            << "//////////////////////////////////////////////////////" << endl;
    for(int i=1; i<=taskone.maxlines; i++)
    {
        myfile << taskone.resultHoldings[i] << endl;
    }
    myfile.close();


        //******************//
        //--TASK T W O (2)--//
        //******************//

    tasktwo.countLines(argv[1], 1);
    tasktwo.countLines(argv[2], 2);

    tasktwo.buildLine(argv[1]);
    tasktwo.buildArray(argv[1]);

    //Input #0-5 to  mergeSort(first, second) to sort according to 2 tokens.
    // mergeSort(secondtoken to sort within, sorted list of firsttoken)
    //Token #: 0 = Sort by Book Code
    //         1 = Sort by Last Name
    //         2 = Sort by First Name
    //         3 = Sort by Title
    //         4 = Sort by Genre
    //         5 = Sort by Avaliablity
    tasktwo.mergeSort(1,4); //Task two requests sort by (1= lst name, within 4= genre)
                            //DO NOT** INPUT SAME TOKEN TWICE!

    //Write result of task 2 to file.
    tasktwo.getResults(2);
    myfile.open(argv[4]);
    myfile << "////////////////////////////////////////////////////////////\n"
            << "//LIST OF BOOK HOLDINGS SORTED BY GENRE + AUTHOR LAST NAME/\n"
            << "///////////////////////////////////////////////////////////" << endl;
    for(int i=1; i<=tasktwo.maxlines; i++)
    {
        myfile << tasktwo.resultHoldings[i] << endl;
    }
    myfile.close();


        //**********************//
        //--TASK T H R E E (3)--//
        //**********************//

    taskthree.countLines(argv[1], 1);
    taskthree.countLines(argv[2], 2);

    taskthree.buildArray(argv[1]);
    taskthree.buildRequest(argv[2]);

    //Run search AFTER arrays are built.
    taskthree.searchRequest();

    //Write result of task 3 to file.
    taskthree.getResults(3);
    myfile.open(argv[5]);
    myfile << "////////////////////////////\n"
            << "//STATUS OF REQUEST BOOKS//\n"
            << "///////////////////////////" << endl;
    for(int i=0; i<=taskthree.maxlines; i++)
    {
        myfile << taskthree.resultHoldings[i] << endl;
    }
    myfile.close();



return 0;
}
