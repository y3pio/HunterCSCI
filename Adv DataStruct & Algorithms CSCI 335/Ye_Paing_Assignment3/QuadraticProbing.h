#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

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
    explicit HashTable( int size = 101 ) : buckets(50287,0), array( nextPrime( size ) )
      { makeEmpty( );}

    bool contains( const HashedObj & x ) const
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

    bool insert( const HashedObj & x )
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        array[ currentPos ] = HashEntry( x, ACTIVE );

            // Rehash; see Section 5.5
        if( ++currentSize > array.size( ) / 2 )
            rehash( );

        return true;
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
	cout << "BAD HASHING" << endl << endl;
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
        HashEntry * next;
        int entryCount;
        EntryType info;

        HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
          : element( e ), info( i ) {entryCount=0; next=NULL; }
    };

    vector<HashEntry> array;
    int currentSize;

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x )
    {
        int offset = 1;
        int currentPos = GoodHashFunction( x ); //SWITCHED TO BAD HASH FUNCTION.
          // Assuming table is half-empty, and table length is prime,
          // this loop terminates
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

            currentPos += offset;  // Compute ith probe
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
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
                insert( oldArray[ i ].element );
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
    //BAD HASH OVER HERE!//
    ///////////////////////
    int BadHashFunction(string word)
    {
        int sum = 0;
        int len = word.length();
        for(int i=0; i<len; i++)
            sum+=(int)word[i];

        return sum % array.size(); /*Table Size - # of buckets*/
    }

    ///////////////////////
    //GOOD HASH OVER HERE//
    ///////////////////////
    int GoodHashFunction(string word)
    {
        int sum = 0;
        int len = word.length();
        for(int i=0; i<len; i++)
            sum+=(int)word[i];

        return sum % array.size(); /*Table Size - # of buckets*/
    }


};


int hash( const string & key );
int hash( int key );


#endif
