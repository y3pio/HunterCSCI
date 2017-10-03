#include "QuadraticProbing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[])
{
    if(argc<2)
    {
	cout << "Error arguement passed. Please run the program in the following way:" << endl;
	cout << "Hash1Test <dictionary file>" << endl;
	exit(1);
    }
    const int T = nextPrime(25143*2);
    HashTable<string> H(T);
    ifstream myfile;
    myfile.open(argv[1]);
    if(myfile.fail())
    {
	cout << "Failed opening file! Exiting program.." << endl;
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
        H.insert(word);
    }
    //cout << H.insert("a") << endl;
    //cout << H.insert("b") << endl;
    //cout << H.insert("c") << endl;
    H.printResults();
    return 0;
}
