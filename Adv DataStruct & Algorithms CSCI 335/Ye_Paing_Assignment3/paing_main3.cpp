#include "Hash3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc!=4 || (atoi(argv[3])!=1 && atoi(argv[3])!=0))
    {
	cout << "Error arguement passed. Please run the program in the following way." << endl;
	cout << "spellcheck <document file> <dictionary file> 0 //For spelling" << endl;
	cout << "spellcheck <document file> <dictionary file> 1 //For possible words" << endl;
	exit(1); 
    }

    const int T = nextPrime(25143*2);
    HashTable<string> H(T);
    ifstream myfile;
    myfile.open(argv[2]);
    if(myfile.fail())
    {
	cout << "Fail opening dictionary file. Exiting program" << endl;
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
    myfile.close();

    myfile.open(argv[1]);
    if(myfile.fail())
    {
	cout << "Fail opening document file. Exiting program" << endl;
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
        if(!H.contains(word))
        {
	    if(atoi(argv[3])==0)
            	cout << "Mispelled word: " << word << endl;

	    else if(atoi(argv[3])==1)
	    {
		    cout << "Mispelled word: " << word << endl;
		    //spellCheck(word);
		    string dropFirst, dropLast, addFront, addBack, swapWord;

		    dropFirst=word.substr(0,word.length()-1);
		    dropLast=word.substr(1,word.length());
		    cout << "\tPossible words:" << endl;
		    //cout << dropFirst << endl;
		    //cout << dropLast << endl;

		    //Check for drop first/last character word
		    if(H.contains(dropFirst))
		        cout << "\t-" << dropFirst << endl;
		    if(H.contains(dropLast))
		        cout << "\t-" << dropLast << endl;

		    //Check for add character to front/back
		    for(int i=97; i<123; i++)
		    {
		        char c(i);
		        addFront=c+word;
		        if(H.contains(addFront))
		            cout << "\t-" << addFront << endl;
			//cout << "FRONT " << endl;                
			//cout << addFront << " Length:" << addFront.length() << endl;
		        addBack=word+c;
		        if(H.contains(addBack))
		            cout << "\t-" << addBack << endl;
			//cout << "Echo back" << endl;
		        //cout << addBack << " Length:" << addBack.length() << endl;
		    }

		    for(int i=0; i<word.length()-1; i++)
		    {
		        swapWord=word;
		        swapWord[i]=word[i+1];
		        swapWord[i+1]=word[i];
		        //cout << swapWord << endl;
		        if(H.contains(swapWord))
		            cout << "\t-" << swapWord << endl;
		    }

	    }
            cout << endl;
        }

    }
    //cout << H.insert("a") << endl;
    //cout << H.insert("b") << endl;
    //cout << H.insert("c") << endl;
    //H.printResults();
    return 0;
}

