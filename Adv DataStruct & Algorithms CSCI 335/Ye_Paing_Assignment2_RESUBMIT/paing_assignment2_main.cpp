#include "AvlTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <cmath>
#include <list>

using namespace std;

bool integerChecker(string);
int stringConvertInt(string);

int main()
{
    int linecount=1;
    string input, choice;
    int intInput;

    AvlTree<int, int> myTestTree;

    //Ask user to insert/delete
    do
    {
        cout << "Enter command (insert/delete/exit):";
        cin >>choice;
        if(choice=="insert")
        {
            do
            {
                cout << "Enter an integer to input:";
                cin >> input;
                if(integerChecker(input)==false)
                    cout << "Error input, please try again." << endl;
                else
                    intInput=stringConvertInt(input);
            }while(integerChecker(input)==false);
            myTestTree.insertInt(intInput,intInput);
            myTestTree.printTree();
	    cout << "IPL:" << myTestTree.IPL() << endl;
        }

        else if(choice=="delete")
        {
            do
            {
                cout << "Enter an integer to delete:";
                cin >> input;
                if(integerChecker(input)==false)
                    cout << "Error input, please try again." << endl;
                else
                    intInput=stringConvertInt(input);
            }while(integerChecker(input)==false);
            myTestTree.remove(intInput);
            myTestTree.printTree();
            cout << "IPL:" << myTestTree.IPL() << endl;
        }

        else if(choice=="exit")
        {
            cout << "Moving to part 2, press enter to continue..";
            cin.get();
            cin.ignore();
        }

        else
            cout << "Error input, please try again!" << endl;

        /*myTestTree.insertInt(intInput,intInput);
        myTestTree.printTree();

        cout << "DELETING" << endl;
        myTestTree.remove(2);
        //myTestTree.updateValue(1,2);
        myTestTree.printTree();
        cout << "IPL:" << myTestTree.IPL() <<endl;*/
    }while(choice!="exit");

    /////////
    //Part2//
    /////////

    AvlTree<string, list<int> > myStringTree;
    myStringTree.resetCount();
    ifstream doctxt("DocumentHW2.txt");
    while(!doctxt.eof())
    {
        string currentline, word;
        getline(doctxt, currentline);
        stringstream strstream;
        strstream.clear();
        strstream.str(currentline);
        while(!strstream.eof())
        {
            strstream >> word;
            for(int i=0; i<word.length(); i++)
            {
                if(!isalpha(word[i]))
                {
                       word=word.substr(0,i);
                }

            }
            //if(word.length()!=0)
            //cout << word << endl;

            if(word.length()!=0)
                myStringTree.insertList(word, linecount);
        }
        /*
        string word
        string line
        getline(cin, word)
        while(!reader.eof())
        stringstream reader(word)
        reader >> line
        */

        //cout << currentline << endl;
        //cin.get();
        //Line count ++ here
        linecount ++;
    }
    doctxt.close();

    myStringTree.printTree();
    cout << "IPL:                      " << myStringTree.IPL() << endl;
    cout << "Average Recursive Count:  " << myStringTree.getCount('r')/myStringTree.getCount('n') << endl;
    cout << "Number of nodes:          " << myStringTree.getCount('n') << endl;
    cout << "Average Single rotations: " << myStringTree.getCount('n')/myStringTree.getCount('s') << endl;
    cout << "Average Double rotations: " << myStringTree.getCount('n')/myStringTree.getCount('d') << endl;

    do
    {
        cout << "\nEnter a word to search for(type \"exit1\" when you're done):";
        cin >>input;
        myStringTree.find(input);
    }while(input!="exit1");

    cout << "Press enter to continue to delete phase...";
    cin.get();
    cin.ignore();

    ifstream wordtxt("wordsHW2.txt");
    while(!wordtxt.eof())
    {
	string word;
        int line=1;
	if(line%2==1)
	    getline(wordtxt,word);

        myStringTree.remove(word);
        line++;
    }

    myStringTree.printTree();
    cout << "IPL:                      " << myStringTree.IPL() << endl;
    cout << "Average Recursive Count:  " << myStringTree.getCount('r')/myStringTree.getCount('n') << endl;
    cout << "Number of nodes:          " << myStringTree.getCount('n') << endl;
    cout << "Average Single rotations: " << myStringTree.getCount('n')/myStringTree.getCount('s') << endl;
    cout << "Average Double rotations: " << myStringTree.getCount('n')/myStringTree.getCount('d') << endl;

    return 0;
}

bool integerChecker(string raw)
{
    for(int i=0; i<raw.length(); i++)
    {
        if(raw[i]<48 || raw[i]>57)
            return false;
    }
    return true;
};

int stringConvertInt(string raw)
{
    int sum=0, power=0;
    power=raw.length()-1;
    for(int i=0; i<raw.length(); i++)
    {
        sum=sum+(pow(10,power)*(raw[i]-48));
        power--;
    }
    return sum;
};
