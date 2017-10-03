#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H

#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include "dsexceptions.h"
#include "HashTable.h"
using namespace std;

// Binomial queue class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x, y )    --> Insert x element with y key
// deleteMin( )           --> Return and remove smallest item
// Comparable findMin( )  --> Return smallest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void merge( rhs )      --> Absorb rhs into this heap
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable, typename Value>
class BinomialQueue
{
  public:
  struct BinomialNode
    {
        Comparable    element;
        list<Value>       key;
        BinomialNode *leftChild;
        BinomialNode *nextSibling;
        BinomialNode *parentPointer;

        BinomialNode( const Comparable & theElement, const Value & theKey,
                        BinomialNode *lt, BinomialNode *rt, BinomialNode *pt )
          : element( theElement ), leftChild( lt ), nextSibling( rt ), parentPointer( pt )
          {key.push_back(theKey);}
    };

    BinomialQueue( ) : theTrees( DEFAULT_TREES )
    {
        for( int i = 0; i < theTrees.size( ); i++ )
            theTrees[ i ] = NULL;
        currentSize = 0;
        comparisonCount = 0;
        assignmentCount = 0;
        wordCount =0;
    }

    BinomialQueue( const Comparable & item, const Value & key ) : theTrees( 1 ), currentSize( 1 )
      { theTrees[ 0 ] = new BinomialNode( item, key, NULL, NULL, NULL ); }
                            //BinomialNode constructor (item, key, leftPtr, childPtr, parentPtr)

    BinomialQueue( const BinomialQueue & rhs ) : currentSize( 0 )
      { *this = rhs; }

    ~BinomialQueue( )
      { makeEmpty( ); }

    /**
     * Return true if empty; false otherwise.
     */
    bool isEmpty( ) const
      { return currentSize == 0; }

    /**
     * Returns minimum item.
     * Throws UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        //cout << left << setw(2) << theTrees[findMinIndex()] -> key << " ";
        return theTrees[ findMinIndex( ) ] -> element;
    }

    void printMinRows()
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        cout << "Lines: ";
        list<Value> temp=theTrees[ findMinIndex( ) ] -> key;

        while(!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop_front();
        }

        cout << endl;
    }

    /**
     * Insert item x into the priority queue; allows duplicates.
     */
    BinomialNode* insert( const Comparable & x, const Value y )
      { BinomialQueue tmp( x, y ); BinomialNode* reTemp=tmp.theTrees[0]; merge( tmp );
        wordCount++; return reTemp;}

    ////////////////////////////////////////////////
    //FASTER INSERT FOR PART 6, CALLS FASTER MERGE//
    ////////////////////////////////////////////////
    BinomialNode* insertFast( const Comparable & x, const Value y )
      { BinomialQueue tmp( x, y ); BinomialNode* reTemp=tmp.theTrees[0]; mergeFast( tmp );
        wordCount++; return reTemp;}

    /**
     * Remove the smallest item from the priority queue.
     * Throws UnderflowException if empty.
     */
    void deleteMin( )
    {
        Comparable x;
        deleteMin( x );
    }

    /**
     * Remove the minimum item and place it in minItem.
     * Throws UnderflowException if empty.
     */
    void deleteMin( Comparable & minItem )
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        int minIndex = findMinIndex( );
        minItem = theTrees[ minIndex ]->element;

        BinomialNode *oldRoot = theTrees[ minIndex ];
        BinomialNode *deletedTree = oldRoot->leftChild;
        delete oldRoot;

        // Construct H''
        BinomialQueue deletedQueue;
        deletedQueue.theTrees.resize( minIndex + 1 );
        deletedQueue.currentSize = ( 1 << minIndex ) - 1;
        for( int j = minIndex - 1; j >= 0; j-- )
        {
            deletedQueue.theTrees[ j ] = deletedTree;
            deletedTree = deletedTree->nextSibling;
            deletedQueue.theTrees[ j ]->nextSibling = NULL;
        }

        // Construct H'
        theTrees[ minIndex ] = NULL;
        currentSize -= deletedQueue.currentSize + 1;

        merge( deletedQueue );
    }

    bool removeRoot( Comparable & minItem )
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        int minIndex=-1;
        for(int i=0; i<theTrees.size(); i++)
            if(theTrees[i]!=NULL && theTrees[i]->element==minItem)
                minIndex=i;
        if(minIndex==-1)
            return false;

        minItem = theTrees[ minIndex ]->element;

        BinomialNode *oldRoot = theTrees[ minIndex ];
        BinomialNode *deletedTree = oldRoot->leftChild;
        delete oldRoot;

        // Construct H''
        BinomialQueue deletedQueue;
        deletedQueue.theTrees.resize( minIndex + 1 );
        deletedQueue.currentSize = ( 1 << minIndex ) - 1;
        for( int j = minIndex - 1; j >= 0; j-- )
        {
            deletedQueue.theTrees[ j ] = deletedTree;
            deletedTree = deletedTree->nextSibling;
            deletedQueue.theTrees[ j ]->nextSibling = NULL;
        }

        // Construct H'
        theTrees[ minIndex ] = NULL;
        currentSize -= deletedQueue.currentSize + 1;

        merge( deletedQueue );
        return true;
    }

    /**
     * Make the priority queue logically empty.
     */
    void makeEmpty( )
    {
        currentSize = 0;
        for( int i = 0; i < theTrees.size( ); i++ )
            makeEmpty( theTrees[ i ] );
    }

    /**
     * Merge rhs into the priority queue.
     * rhs becomes empty. rhs must be different from this.
     * Exercise 6.35 needed to make this operation more efficient.
     */
    void merge( BinomialQueue & rhs )
    {
        if( this == &rhs )    // Avoid aliasing problems
            return;

        currentSize += rhs.currentSize;

        if( currentSize > capacity( ) )
        {
            //One assignment
            int oldNumTrees = theTrees.size( );
            assignmentCount++;

            //One assignment and one compare max()
            int newNumTrees = max( theTrees.size( ), rhs.theTrees.size( ) ) + 1;
            assignmentCount++;
            comparisonCount++;

            theTrees.resize( newNumTrees );
            for( int i = oldNumTrees; i < newNumTrees; i++ )
            {
                theTrees[ i ] = NULL;
                assignmentCount++;
            }
        }

        BinomialNode *carry = NULL;
        assignmentCount++;
        for( int i = 0, j = 1; j <= currentSize; i++, j *= 2 )
        {
            //One assignment
            BinomialNode *t1 = theTrees[ i ];
            assignmentCount++;

            //One assginment and one comparasion.
            BinomialNode *t2 = i < rhs.theTrees.size( ) ? rhs.theTrees[ i ] : NULL;
            assignmentCount++;
            comparisonCount++;

            //3 comparison +=3
            int whichCase = t1 == NULL ? 0 : 1;
            whichCase += t2 == NULL ? 0 : 2;
            whichCase += carry == NULL ? 0 : 4;
            comparisonCount+=3;

            switch( whichCase )
            {
              case 0: /* No trees */
              case 1: /* Only this */
                break;
              case 2: /* Only rhs */
                theTrees[ i ] = t2;
                assignmentCount++;
                rhs.theTrees[ i ] = NULL;
                break;
              case 4: /* Only carry */
                theTrees[ i ] = carry;
                assignmentCount++;
                carry = NULL;
                break;
              case 3: /* this and rhs */
                carry = combineTrees( t1, t2 );
                theTrees[ i ] = rhs.theTrees[ i ] = NULL;
                break;
              case 5: /* this and carry */
                carry = combineTrees( t1, carry );
                theTrees[ i ] = NULL;
                break;
              case 6: /* rhs and carry */
                carry = combineTrees( t2, carry );
                rhs.theTrees[ i ] = NULL;
                break;
              case 7: /* All three */
                theTrees[ i ] = carry;
                assignmentCount++;
                carry = combineTrees( t1, t2 );
                rhs.theTrees[ i ] = NULL;
                break;
            }
        }

        for( int k = 0; k < rhs.theTrees.size( ); k++ )
        {
            rhs.theTrees[ k ] = NULL;
            assignmentCount++;
        }
        rhs.currentSize = 0;

    }

    /////////////////////////
    //FASTER MERGE FUNCTION//
    /////////////////////////
    void mergeFast( BinomialQueue & rhs )
    {
        if( this == &rhs )    // Avoid aliasing problems
            return;

        currentSize += rhs.currentSize;

        if( currentSize > capacity( ) )
        {
            //One assignment
            int oldNumTrees = theTrees.size( );
            assignmentCount++;

            //One assignment and one compare max()
            int newNumTrees = max( theTrees.size( ), rhs.theTrees.size( ) ) + 1;
            assignmentCount++;
            comparisonCount++;

            theTrees.resize( newNumTrees );
            for( int i = oldNumTrees; i < newNumTrees; i++ )
            {
                theTrees[ i ] = NULL;
                assignmentCount++;
            }
        }

        BinomialNode *carry = NULL;
        assignmentCount++;

        for( int i = 0, j = 1; j <= currentSize; i++, j *= 2 )
        {
            //One assignment
            BinomialNode *t1 = theTrees[ i ];
            assignmentCount++;

            //One assginment and one comparasion.
            BinomialNode *t2 = i < rhs.theTrees.size( ) ? rhs.theTrees[ i ] : NULL;
            assignmentCount++;
            comparisonCount++;

            //3 comparison +=3
            int whichCase = t1 == NULL ? 0 : 1;
            whichCase += t2 == NULL ? 0 : 2;
            whichCase += carry == NULL ? 0 : 4;
            comparisonCount+=3;

            switch( whichCase )
            {
              case 0: /* No trees */
              case 1: /* Only this */
                break;
              case 2: /* Only rhs */
                theTrees[ i ] = t2;
                assignmentCount++;
                rhs.theTrees[ i ] = NULL;
                break;
              case 4: /* Only carry */
                theTrees[ i ] = carry;
                assignmentCount++;
                carry = NULL;
                break;
              case 3: /* this and rhs */
                carry = combineTrees( t1, t2 );
                theTrees[ i ] = rhs.theTrees[ i ] = NULL;
                break;
              case 5: /* this and carry */
                carry = combineTrees( t1, carry );
                theTrees[ i ] = NULL;
                break;
              case 6: /* rhs and carry */
                carry = combineTrees( t2, carry );
                rhs.theTrees[ i ] = NULL;
                break;
              case 7: /* All three */
                theTrees[ i ] = carry;
                assignmentCount++;
                carry = combineTrees( t1, t2 );
                rhs.theTrees[ i ] = NULL;
                break;
            }
            //Break out once it finds the first NULL since there is no way to produce a CARRY over.
            if(theTrees[i]==NULL)
                break;
        }

        for( int k = 0; k < rhs.theTrees.size( ); k++ )
        {
            rhs.theTrees[ k ] = NULL;
            assignmentCount++;
        }
        rhs.currentSize = 0;

    }



    const BinomialQueue & operator= ( const BinomialQueue & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            theTrees.resize( rhs.theTrees.size( ) );  // Just in case
            for( int i = 0; i < rhs.theTrees.size( ); i++ )
                theTrees[ i ] = clone( rhs.theTrees[ i ] );
            currentSize = rhs.currentSize;
        }
        return *this;
    }


    //PERCOLATE FUNCTION!
    bool percolateNode(BinomialNode * node)
    {
        if(node->parentPointer->element == findMin())
        {
            swap(node, node->parentPointer);
            return true;
        }

        cout << "Before:" << node->element << endl;
        swapNode(node, node->parentPointer);
        cout << "After:" << node->element << endl;

        if(node->parentPointer!=NULL)
            percolateNode(node->parentPointer);

    }

    void findRoot()
    {
        cout << "Tree Size:" << theTrees.size() << endl;
        for(int i=0; i<theTrees.size(); i++)
        {
            if(theTrees[i]!=NULL)
                cout << "[" << i << "] :" <<  theTrees[i]->element << endl;
            else
                cout << "[" << i << "] : NULL" << endl;
        }
    }

    //After deleteMin() is called the new roots have dangling parent pointers?
    void setRootNull()
    {
        for(int i=0; i<theTrees.size(); i++)
            if(theTrees[i]!=NULL)
                theTrees[i]->parentPointer=NULL;
    }

    void printCount()
    {
        cout << "Words inserted  : " << wordCount << endl;
        cout << "Comparison count: " << comparisonCount << endl;
        cout << "Assignment count: " << assignmentCount << endl;
    }
/////////////////////////////
//  PRIVATE DATA MEMBERS!! //
/////////////////////////////

  private:

    int comparisonCount;
    int assignmentCount;
    int wordCount;

    enum { DEFAULT_TREES = 1 };

    int currentSize;                  // Number of items in the priority queue
    vector<BinomialNode *> theTrees;  // An array of tree roots

    /**
     * Find index of tree containing the smallest item in the priority queue.
     * The priority queue must not be empty.
     * Return the index of tree containing the smallest item.
     */
    int findMinIndex( ) const
    {
        int i;
        int minIndex;

        for( i = 0; theTrees[ i ] == NULL; i++ )
            ;

        for( minIndex = i; i < theTrees.size( ); i++ )
            if( theTrees[ i ] != NULL &&
                theTrees[ i ]->element < theTrees[ minIndex ]->element )
                minIndex = i;

        return minIndex;
    }

    /**
     * Return the capacity.
     */
    int capacity( ) const
      { return ( 1 << theTrees.size( ) ) - 1; }

    /**
     * Return the result of merging equal-sized t1 and t2.
     */
    BinomialNode * combineTrees( BinomialNode *t1, BinomialNode *t2 )
    {
        comparisonCount++;
        if( t2->element < t1->element )
            return combineTrees( t2, t1 );


        t2->nextSibling = t1->leftChild;
        assignmentCount++;
        t1->leftChild = t2; //Points to child t2
        assignmentCount++;
        t2->parentPointer = t1; //Child should point back to parent.
        assignmentCount++;
        return t1;
    }

    /**
     * Make a binomial tree logically empty, and free memory.
     */
    void makeEmpty( BinomialNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->leftChild );
            makeEmpty( t->nextSibling );
            makeEmpty( t->parentPointer);
            delete t;
            t = NULL;
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinomialNode * clone( BinomialNode * t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new BinomialNode( t->element, t->key,
                                clone( t->leftChild ), clone( t->nextSibling ), clone (t->parentPointer));
    }
};

#endif
