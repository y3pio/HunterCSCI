#include "Hash2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc!=3 || (atoi(argv[2])!=1 && atoi(argv[2])!=0))
    {
	cout << "Error arguement passed. Please run the program in the following way." << endl;
	cout << "Hash2Test <dictionary file> 0 //For quadradic probing" << endl;
	cout << "Hash2Test <dictionary file> 1 //For double hashing" << endl;
	exit(1); 
    }

    const int T = nextPrime(25143*2);
    HashTable<string> H(T);
    ifstream myfile;
    myfile.open(argv[1]);
    if(myfile.fail())
    {
	cout << "Failed opening file..Exiting program!" << endl;
	exit(1);
    }
    string word;
    while(!myfile.eof())
    {
        getline(myfile,word);
        for(int i=0; i<word.length(); i++)
        {
            word[i]=tolower(word[i]);
        }
	if(atoi(argv[2])==1)//do double hash
            H.insert(word);
	else if(atoi(argv[2])==0)//do quadradic hash
	    H.insert2(word);
    }
    if(atoi(argv[2])==1)
        H.printResults();
    else if(atoi(argv[2])==0)
	H.printResults2();
    return 0;
}


