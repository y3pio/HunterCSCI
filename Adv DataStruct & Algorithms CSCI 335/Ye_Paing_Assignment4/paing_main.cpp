#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{

    BinomialQueue<string, int> BQueue;
    HashTable<string> myHash;
    int insertCount=0;
    ifstream myfile;
    string word, line;
    int lineNum=1;
    myfile.open("word.txt");
    //myfile.open("words.txt"); //Swap for real and test

    while(myfile)
    {
        getline(myfile, line); //Get the line
        istringstream iss(line);
        while(getline(iss, word, ' '))
        {
            //cout << word << endl;
            //cout << "ECHO" << endl;
            for(int i=0; i<word.length(); i++)
            {
                word[i]=tolower(word[i]);
            }
            for(int i=0; i<word.length(); i++)
            {
                if(!isalpha(word[i]))
                {
                    word.erase(i,1);
                    i--;
                }
            }

            //If it is in hash and word is not empty, find it and update the line list
            if(myHash.contains(word) && word.length()>0)
                myHash.updateLine(word, lineNum);

            //Else if it is not in hash, and word is not empty, insert it.
            else if(!myHash.contains(word) && word.length()>0)
            {
                myHash.insertNode(word, lineNum, BQueue.insert(word, lineNum));
                insertCount++;
            }

        };
        //cout << word << endl;
        //cout << word << endl;
        lineNum++;
    }
    myfile.close();

    /*cout << "Words inserted: " << insertCount << endl;
    BQueue.findRoot();
    cin.get();*/

    //TESTING BLOCK ALPHA

    //NO CLUE HOW THE PERCOLATE.
    //WTFFFFFFFFFFFFFFFFFFASDFWQ#$@#R@!#F#$T

    //TESTING BLOCK 2 PERCOLATE
    /*BQueue.setRootNull();
    for(int i=0; i<10; i++)
    {
        cout << "PRINTING ALL ROOTS!" << endl;
        BQueue.findRoot();
        //cout << myHash.find("a")->parentPointer << endl;
        cout << "\n#TEST PERCOLATE:";
        cin >> word;

        if(myHash.contains(word))
        {

            while(myHash.find(word)->parentPointer!=NULL)
            {

            //Temp to hold temp binomialNode for swap
            string tempElement=myHash.find(word)->element;
            list<int> tempKey=myHash.find(word)->key;
            //x and y string to hold original words that are swapped to swap pointers
            string x = myHash.find(word)->element;
            string y = myHash.find(word)->parentPointer->element;

                //Current word's parents element/key become current word's element/keys
                myHash.find(word)->element=myHash.find(word)->parentPointer->element;
                myHash.find(word)->key=myHash.find(word)->parentPointer->key;
                //Need to swap pointers too??
                //myHash.find(word)->leftChild=myHash.find(word)->parentPointer->leftChild;
                //myHash.find(word)->nextSibling=myHash.find(word)->parentPointer->nextSibling;

                myHash.find(word)->parentPointer->element=tempElement;
                myHash.find(word)->parentPointer->key=tempKey;

                myHash.swapNodePointer(x,y);

                //cout << "nextWord : " << myHash.find(word)->parentPointer->element <<  endl;

            }
            //cout << myHash.find("you")->parentPointer->element << endl;
        cout << endl;
        }
    }*/

    //TESTING BLOCK 1 TREE TRAVERSAL
    /*for(int i=0; i<20; i++)
    {
        cout << "MIN:" << BQueue.findMin() << endl;
        cout << "#TEST:";
        cin >> word;
        if(!myHash.contains(word))
            cout << "Word not found!" << endl;

        else if(myHash.find(word)->parentPointer==NULL)
            cout << "POINTS TO NULL!!" << endl;

        else
        {
                if(myHash.find(word)->parentPointer!=NULL)
                    cout << "\nTEST PARENT PTR: " << myHash.find(word)->parentPointer->element;
                if(myHash.find(word)->leftChild!=NULL)
                    cout << "\nCHILD: " << myHash.find(word)->leftChild->element;
                if(myHash.find(word)->nextSibling!=NULL)
                    cout << "\nSIBLING: " << myHash.find(word)->nextSibling->element;
        }
        cout << endl << endl;
    }*/


    //BQueue.insert("hello", 3);
    //BQueue.insert("apple", 100);
    //BQueue.insert("banana",2);
    cout << "Part (1) -Impliment Queue and Hash Pointers" << endl;
    cout << "All words will be switched to lower case." << endl;
    cout << "All non alpha characters will be removed. (i.e it's -> its)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Binomial Queue and Hash Table created successfully!!" << endl;
    cout << "\nPress enter to continue..." << endl;
    cin.get();
    cout << endl;

    cout << "Part (2) -Total count" << endl;
    cout << "Out putting the total number of comparisons and assignments" << endl;
    cout << "-----------------------------------------------------------" << endl;
    BQueue.printCount();
    cout << "\nPress enter to continue..." << endl;
    cin.get();

    cout << endl;

    cout << "Part (3) -Test deleteMin()" << endl;
    cout << "Testing deleteMin(). Deleting the first 10 Minimum Nodes." << endl;
    cout << "---------------------------------------------------------" << endl;
    for(int i=0; i<10; i++)
    {
        cout << "Min[" << i << "]:" << setw(10) << left << BQueue.findMin() << "  ";
        myHash.remove(BQueue.findMin());
        BQueue.printMinRows();
        BQueue.deleteMin();
    }

    BQueue.setRootNull(); //Set the current root's parents to NULL each time

    cout << "\n*NOTE* The deleted words above will no longer be "
         << "\n*NOTE* in the hash table or the binomial queue!! " << endl;

    cout << "\nPress enter to continue..." << endl;
    cin.get();

    cout << endl;
    cout << "Part (4) -Test find() function" << endl;
    cout << "Testing find(). Find pointer to node via hash table.            " << endl;
    cout << "Input is case insensitive. All words hashed/heaped as lower case" << endl;
    cout << "All non alpha characters have been removed. (i.e it's -> its)" << endl;
    cout << "----------------------------------------------------------------" << endl;

    bool repeat=true;
    while(repeat)
    {
        cout << "Enter a word to find:";
        cin >> word;
        if(myHash.contains(word))
        {
            list<int> temp;
            temp=myHash.find(word)->key;
            cout << "Found Key(" << myHash.find(word)->element << ")" << endl;
            cout << "On lines:";
            while(!temp.empty())
            {
                cout << temp.front() << " ";
                temp.pop_front();
            };
            cout << endl;
        }
        else if(!myHash.contains(word))
        {
            cout << "Key(" << word << ") not found!" << endl;
        }
        cout << "\nWould you like to do another search?(y/n):";
        cin >> word;
        if(word=="n")
            repeat=false;

        cout << endl;
    }

    BQueue.setRootNull(); //Set the current root's parents to NULL each time

    cout << endl;
    cout << "Part (5) -Test remove() function" << endl;
    cout << "Words previously removed are no longer in the binomial queue.   " << endl;
    cout << "Input is case insensitive. All words hashed/heaped as lower case" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for(int i=0; i<5; i++) //Doing 5 remove calls
    {
        cout << "Enter a word to remove:";
        cin >> word;
        //If it's in the hash, do the percolate
        if(myHash.contains(word))
        {
            while(myHash.find(word)->parentPointer!=NULL)
            {

                //Temp to hold current node for swap
                string tempElement=myHash.find(word)->element;
                list<int> tempKey=myHash.find(word)->key;

                //x and y string to hold original words that are swapped to swap pointers
                string x = myHash.find(word)->element;
                string y = myHash.find(word)->parentPointer->element;

                //Current word's parents element/key become current word's element/keys
                myHash.find(word)->element=myHash.find(word)->parentPointer->element;
                myHash.find(word)->key=myHash.find(word)->parentPointer->key;

                //Parent get current info stored in temp
                myHash.find(word)->parentPointer->element=tempElement;
                myHash.find(word)->parentPointer->key=tempKey;

                //Swap the two word's pointers in the Hash Table.
                myHash.swapNodePointer(x,y);

            }

            //Function below will print out all the root nodes.
            //BQueue.findRoot();

            //Remove the percolated node
            BQueue.removeRoot(word);
            //Set the new root parents to NULL
            BQueue.setRootNull();
            //Remove the removed word from Hash Table
            myHash.remove(word);
            cout << "Key(" << word << ") removed!!" << endl;
        }
        else if(!myHash.contains(word))
        {
            cout << "Key(" << word << ") not found!" << endl;
            cout << "No delete done." << endl;
        }
        cout << endl;
    }

    BQueue.setRootNull();

    cout << endl;
    cout << "Part (6) -Faster merge() function" << endl;
    cout << "Insert words to the binomial queue/hash table.   " << endl;
    cout << "All inputs will be converted to lower case. Default line # '-1' " << endl;
    cout << "----------------------------------------------------------------" << endl;

    myfile.open("word.txt");
    lineNum=0;
    word="";
    line="";
    BinomialQueue<string, int> FasterBQ;
    HashTable<string> FasterHash;
    while(myfile)
    {
        getline(myfile, line); //Get the line
        istringstream iss(line);
        while(getline(iss, word, ' '))
        {
            //cout << word << endl;
            //cout << "ECHO" << endl;
            for(int i=0; i<word.length(); i++)
            {
                word[i]=tolower(word[i]);
            }
            for(int i=0; i<word.length(); i++)
            {
                if(!isalpha(word[i]))
                {
                    word.erase(i,1);
                    i--;
                }
            }

            //If it is in hash and word is not empty, find it and update the line list
            if(FasterHash.contains(word) && word.length()>0)
                FasterHash.updateLine(word, lineNum);

            //Else if it is not in hash, and word is not empty, insert it.
            else if(!FasterHash.contains(word) && word.length()>0)
            {
                FasterHash.insertNode(word, lineNum, FasterBQ.insertFast(word, lineNum));
                insertCount++;
            }

        };
        //cout << word << endl;
        //cout << word << endl;
        lineNum++;
    }
    myfile.close();
    FasterBQ.printCount();


    exit(0); //<-Hope I don't get points taken off for this.
}
