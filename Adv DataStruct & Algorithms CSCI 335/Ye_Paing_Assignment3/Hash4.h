#ifndef HASH4_H
#define HASH4_H

#define PRIMEA 12049
#define PRIMEB 181
#define PRIMEC 70667

#include <vector>
#include <string>
#include <list>
#include <iostream>
using namespace std;

int nextPrime( int n );

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hash( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTable
{
  public:
    explicit HashTable( int size = 101 ) : buckets(size,0), array( nextPrime( size ) )
      { makeEmpty( );}

    bool contains( const HashedObj & x )
    {
        return isActive( findPos( x ) );
    }

    void makeEmpty( )
    {
        currentSize = 0;
        for( int i = 0; i < array.size( ); i++ )
            array[ i ].info = EMPTY;
        collisions=0;
        bucketNum=0;
        bucketMax=0;
    }


    //SPECIAL INSERT FUNCTION FOR PART 4
    bool insert(const HashedObj &x, string realWord)
    {
        //PREFIX IS IN THE DICTIONARY, IS A REAL WORD
        if(contains(x))
        {
            int currentPos=findPos(x);
            //cout << "contains:" << x << endl;
            if(x==realWord)
                array[currentPos].flag=true;

            array[currentPos].wordList.push_back(realWord);
        }

        //If not in hash, it's a prefix
        else if(!contains(x))
        {
            int currentPos=findPos(x);
            array[currentPos].element=x;
            array[currentPos].info=ACTIVE;
            if(x==realWord) //If the prefix is the actual word;
                array[currentPos].flag=true;
            else
            {
                array[currentPos].flag=false;
                array[currentPos].wordList.push_back(realWord);
            }

        }

        if( ++currentSize > array.size( ) / 2 )
            rehash( );

        return true;

    }

    void spellCheck2(const HashedObj &x)
    {
        int currentPos=findPos(x);
        if(contains(x))
        {
            if(array[currentPos].flag==false)
	    {
                cout << "Word: " << x << " -Key: F" << endl;
		    if(array[currentPos].wordList.empty())
		    {
		        cout << "\tReal words-" << endl;
		        cout << "\tN/A" << endl;
		    }

		    else if(!array[currentPos].wordList.empty())
		    {
		        cout << "\tReal words-" << endl;
		        for(list<string>::iterator it=array[currentPos].wordList.begin();
		            it != array[currentPos].wordList.end(); it++)
		            {
		                cout << "\t" << *it << endl;
		            }
		    }
	    }
        }
    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

    void printResults()
    {
        cout << "DOUBLE HASHING" << endl << endl;
        cout << "MAX COLLISIONS: " << collisions << endl;
        cout << "BUCKET NUMBER:  " << bucketNum << endl;
        cout << "BUCKET MAX:     " << bucketMax << endl;
    }

    enum EntryType { ACTIVE, EMPTY, DELETED };

  private:
    int collisions;
    int bucketNum;
    int bucketMax;
    vector<int> buckets;


    struct HashEntry
    {
        HashedObj element;
        EntryType info;
        bool flag;
        list<string> wordList;
    };

    vector<HashEntry> array;
    int currentSize;

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x )
    {
        int currentPos = GoodHashFunction( x ); //SWITCHED TO BAD HASH FUNCTION.
          // Assuming table is half-empty, and table length is prime,
          // this loop terminates
        int offset = hash2(currentPos);
        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            collisions++;
            buckets[currentPos]++;

            //Check if the collision count for current bucket is greatest
            if(buckets[currentPos]>bucketMax)
            {
                //If so update the bucket # and collision # fot that bucket.
                bucketMax=buckets[currentPos];
                bucketNum=currentPos;
            }

            //If collision, double hash and add offset.

            currentPos += offset;  // Compute ith probe

            //If position goes out of bound, reduce.
            while( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        //Return position to insert.
        return currentPos;
    }

    //Copy function for rehashing
    void copyTable(const HashedObj &x, EntryType state, bool flagState, list<string> list)
    {
        int currentPos=findPos(x);
        array[currentPos].element=x;
        array[currentPos].info=state;
        array[currentPos].flag=flagState;
        array[currentPos].wordList=list;
    }

    void rehash( )
    {
        bucketMax=0;
        bucketMax=0;
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        buckets.resize(array.size());
        for( int j = 0; j < array.size( ); j++ )
        {
            array[ j ].info = EMPTY;
            buckets[j]=0;
        }

            // Copy table over
        currentSize = 0;
        for( int i = 0; i < oldArray.size( ); i++ )
            if( oldArray[ i ].info == ACTIVE )
                copyTable( oldArray[ i ].element, oldArray[ i ].info, oldArray[ i ].flag, oldArray[ i ].wordList );
    }
    int myhash( const HashedObj & x ) const
    {
        int hashVal = hash( x );

        hashVal %= array.size( );
        if( hashVal < 0 )
            hashVal += array.size( );

        return hashVal;
    }


    ///////////////////////
    //GOOD HASH OVER HERE//
    ///////////////////////
    int GoodHashFunction(string word)
    {
        int sum = 37;
        int len = word.length();
        for(int i=0; i<len; i++)
            sum+=sum*PRIMEA + ((int)word[i]*PRIMEB) +PRIMEC;

        return sum % array.size(); /*Table Size - # of buckets*/
    }

    ///////////////
    //DOUBLE HASH//
    ///////////////
    int hash2(int x)
    {
        int r = nextPrime(25143);
        return r-(x%r) ;
    }


};


int hash( const string & key );
int hash( int key );


#endif
