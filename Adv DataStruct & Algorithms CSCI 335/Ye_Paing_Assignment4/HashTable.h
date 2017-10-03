#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define PRIMEA 12049
#define PRIMEB 181
#define PRIMEC 70667

#include "BinomialQueue.h"
#include <vector>
#include <string>
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
    template <typename Comparable, typename Value> friend struct BinomialNode;

    explicit HashTable( int size = 101 ) : array( nextPrime( size ) )
      { makeEmpty( ); }

    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }

    //FIND() Function for part (4) project 4
    BinomialQueue<string, int>::BinomialNode* find(const HashedObj &x)
    {
        return array[findPos(x)].nodePointer;
    }



    void makeEmpty( )
    {
        currentSize = 0;
        for( int i = 0; i < array.size( ); i++ )
            array[ i ].info = EMPTY;
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

    //INSERT A BINOMIAL NODE POINTER ALONG WITH HASH KEY
    bool insertNode(const HashedObj & x, const int &lineNumber, BinomialQueue<string, int>::BinomialNode* ptr)
    {
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        array[ currentPos ] = HashEntry( x, ACTIVE );
        array[ currentPos ].nodePointer=ptr;


            // Rehash; see Section 5.5
        if( ++currentSize > array.size( ) / 2 )
            rehash( );
            return true;
    }

    //UPDATE LINE FUNCTION, FINDS KEY THAT IS ALREADY IN HASH TABLE AND INSERT LINE
    void updateLine(const HashedObj & x, const int & lineNumber)
    {
        int currentPos = findPos(x);
        //If entry is there && not pushing back the same line #
        if(isActive(currentPos) && array[currentPos].nodePointer->key.back()!=lineNumber)
        {
            //DO PUSH BACK HERE.
            array[currentPos].nodePointer->key.push_back(lineNumber);
        }

    }
    //FUNCTION TO SWAP HASH POINTERS TO NODE AFTER PERCOLATE SWAP
    void swapNodePointer(const HashedObj &x, const HashedObj &y)
    {
        int node=findPos(x);
        int parent=findPos(y);

        BinomialQueue<string,int>::BinomialNode * temp;
        //Temp is the current word's pointer
        temp=array[node].nodePointer;
        //Current word's pointer gets parent's pointer
        array[node]. nodePointer=array[parent].nodePointer;
        //Parent gets current word's pointer
        array[parent].nodePointer=temp;

    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

    enum EntryType { ACTIVE, EMPTY, DELETED };

  private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;
        BinomialQueue<string, int>::BinomialNode* nodePointer;

        HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
          : element( e ), info( i ) { }
    };

    vector<HashEntry> array;
    int currentSize;

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x ) const
    {
        int currentPos = myhash( x );
        int offset = 1;

          // Assuming table is half-empty, and table length is prime,
          // this loop terminates
        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    void rehash( )
    {
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( int j = 0; j < array.size( ); j++ )
            array[ j ].info = EMPTY;

            // Copy table over
        currentSize = 0;
        for( int i = 0; i < oldArray.size( ); i++ )
            if( oldArray[ i ].info == ACTIVE )
            {
                BinomialQueue<string, int>::BinomialNode* temp;
                temp=oldArray[i].nodePointer;
                insert( oldArray[ i ].element);
                array[findPos(oldArray[i].element)].nodePointer=temp;

            }
    }

    int myhash( const HashedObj & x ) const
    {
        int hashVal = hash( x );

        hashVal %= array.size( );
        if( hashVal < 0 )
            hashVal += array.size( );

        for(int i=0; i<x.length(); i++)
            hashVal+=hashVal*PRIMEA + ((int)x[i]*PRIMEB) +PRIMEC;

        return hashVal % array.size();
    }

};



int hash( const string & key );
int hash( int key );

#endif
