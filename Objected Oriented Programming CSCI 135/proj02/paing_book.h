#ifndef PAING_BOOK_H
#define PAING_BOOK_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class book
{
    public:
            int maxlines;
            int maxrequestlines;

            void countLines(char * filename, int argvNumber);
            void buildArray(char * filename);
            void buildLine(char * filename);
            void buildRequest(char * filename);

            void mergeSort(int firsttoken, int secondtoken);
            void sortList(int token);
            bool checkSortedList(int token);
            void searchRequest();

            void getResults(int task);
            string resultHoldings[100];

    private:

            string arrayholdings[100][6];
            string lineholdings[100];
            string requestholdings[100];
};

#endif
