#include "Hash4.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[])
{
    if(argc!=3)
    {
	cout << "Error arguement passed. Please run the program in the following way." << endl;
	cout << "spellcheck2 <document file> <dictionary file>" << endl;
	exit(1); 
    }
    cout << "/////////////////" << endl
         << "//  PROGRAM 4  //" << endl
         << "/////////////////" << endl;
    const int T = nextPrime(25143*2);
    HashTable<string> H(T);
    ifstream myfile;
    myfile.open(argv[2]);
    if(myfile.fail())
    {
	cout << "Failed opening dictionary file! Exiting program." << endl;
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
        for(int i=word.length(); i>=3 ; i--)
        {
            string newWord=word.substr(0,i);
            H.insert(newWord, word);
        }
    }

    myfile.close();

    myfile.open(argv[1]);
    if(myfile.fail())
    {
	cout << "Failed opening docuent file! Exiting program." << endl;
	exit(1);
    }
    word="";
    while(!myfile.eof())
    {
        getline(myfile, word);
        for(int i=0; i<word.length(); i++)
        {
            word[i]=tolower(word[i]);
        }

        H.spellCheck2(word);
        cout << endl;
    }
    //cout << H.insert("a") << endl;
    //cout << H.insert("b") << endl;
    //cout << H.insert("c") << endl;
    //H.printResults();
    return 0;
}

