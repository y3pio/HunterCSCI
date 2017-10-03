#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "dsexceptions.h"
#include <iostream>    // For NULL
#include <iomanip>
using namespace std;

// AvlTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// void updateValue(x, y) --> Find node with x comparable and update value with y.
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable, typename Value>
class AvlTree
{
  public:
    AvlTree( ) : root( NULL )
      { }
    AvlTree( const AvlTree & rhs ) : root( NULL )
    {
        *this = rhs;
        reCount=0;
        sCount=0;
        dCount=0;
        noCount=0;
    }

    ~AvlTree( )
    {
        makeEmpty( );
    }

    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == NULL;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insertInt( const Comparable & x, const Value &y )
    {
        insertInt( x, y, root );
    }

    void insertList( const Comparable &x, int y)
    {
        insertList( x, y, root );
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x)
    {
        lazyDelete(x);
    }

    /**
     * Deep copy.
     */
    const AvlTree & operator=( const AvlTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

    //////////////////////////////////////
    //PROJECT ADDED FUNCTIONS START HERE//
    //////////////////////////////////////

    void updateValue(const Comparable & x, Value data)
    {
        if(isEmpty())
            throw UnderflowException();

        else
            findNode(x, root)->info=data;
    }

    int IPL()
    {
        return internalPathLength(root, 0);
    }

    void find(string x)
    {

        if(findWord(x,root)!=NULL)
        {
            cout << "Word:" << findWord(x,root)->element << endl;
            cout << "At line:";
            for(int i=0; i<findWord(x,root)->info.size(); i++)
            {
                cout << findWord(x,root)->info.front() << " ";
                findWord(x,root)->info.push_back(findWord(x,root)->info.front());
                findWord(x,root)->info.pop_front();
            }
            cout << endl;
        }
	else if(findWord(x,root)==NULL)
	    cout << "Word not found!" << endl;
    }

    int getCount(char c)
    {
        if(c=='r')
            return reCount;
        else if(c=='n')
            return noCount;
        else if(c=='s')
            return sCount;
        else if(c=='d')
            return dCount;
    }

    void resetCount()
    {
        reCount=0;
        sCount=0;
        dCount=0;
        noCount=0;
    }
///////////
//PRIVATE//
///////////


  private:
    struct AvlNode
    {
        Comparable element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;
        Value info;
        bool flag;

        AvlNode( const Comparable & theElement, AvlNode *lt,
                                                AvlNode *rt, int h = 0 )
          : element( theElement ), left( lt ), right( rt ), height( h ) { }
    };

    AvlNode *root;

    int reCount; //recursive counter for insert
    int noCount; //node counter
    int sCount;  //single rotation counter
    int dCount;  //double rotation counter
    //////////////////////////////////////
    //PROJECT ADDED FUNCTIONS START HERE//
    //////////////////////////////////////

/*     AvlNode* findNode( const Comparable & x, AvlNode *t )
    {
        if( t == NULL  )
            return NULL;
        else if( x < t->element )
            return findNode( x, t->left );
        else if( t->element < x )
            return findNode( x, t->right );
        else
            return *this;    // Match
    }*/

    AvlNode* findNode( const Comparable & x, AvlNode *t ) const
    {
        //cout << "ECHO SEG FAULT!!" << endl;
        //cout << t->element << endl;
        if( t == NULL )
            return NULL;
        else if( x < t->element )
            return findNode( x, t->left );
        else if( t->element < x )
            return findNode( x, t->right );
        else if( t->element == x)
            return t;    // Match
    }

    void printLevelOrder()
    {
        if(isEmpty())
            throw UnderflowException();

        for(int i=0; i<=root->height; i++)
        {
            printNodeLevel(root,i);
        }
    }

    void printNodeLevel(AvlNode *t, int x)
    {
        if(t==NULL)
            cout << "NULL" << endl;
        else if(t!=NULL && root->height-t->height==x)
        {
            cout << t->element << " " << t->info << endl;
        }
        else
        {
            printNodeLevel(t->left,x);
            printNodeLevel(t->right,x);
        }
    }

    int internalPathLength(AvlNode* t, int sum)
    {
        if(isEmpty())
            throw UnderflowException();

        if(t==NULL)
            return 0;

        if(t->left==NULL && t->right==NULL && t->flag==true) //If it's a leaf
            return sum;

        if((t->left!=NULL || t->right!=NULL) && t->flag==true) //If it's a middle node, calculate through.
            return sum+internalPathLength(t->left, sum+1) + internalPathLength(t->right, sum+1);

        if((t->left!=NULL || t->right!=NULL) && t->flag==false) //If it's invalid middle node, do not change +1 to sum.
            return sum+internalPathLength(t->left, sum) + internalPathLength(t->right, sum);
    }

    void lazyDelete( const Comparable & x)
    {

        if(findNode(x,root)!=NULL)
            findNode(x,root)->flag=false;
    }

    ////////////////////////////////
    //PROJECT FUNCTIONS END HERE!!//
    ////////////////////////////////

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insertInt( const Comparable & x,const Value &y, AvlNode * & t )
    {
        if( t == NULL )
        {
            t = new AvlNode( x, NULL, NULL );
            t->info=y;
            t->flag=true;
        }
        else if( x < t->element )
        {
            insertInt( x, y, t->left );
            if( height( t->left ) - height( t->right ) == 2 )
                if( x < t->left->element )
                    rotateWithLeftChild( t );
                else
                    doubleWithLeftChild( t );
        }
        else if( t->element < x )
        {
            insertInt( x, y, t->right );
            if( height( t->right ) - height( t->left ) == 2 )
                if( t->right->element < x )
                    rotateWithRightChild( t );
                else
                    doubleWithRightChild( t );
        }
        else
            ;  // Duplicate; do nothing
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    //////////////////////////////
    //INSERT FOR LIST TYPE VALUE//
    //////////////////////////////
    void insertList( const Comparable & x,int y, AvlNode * & t )
    {
        reCount++;
        if( t == NULL )
        {
            t = new AvlNode( x, NULL, NULL );
            t->info.push_back(y);
            t->flag=true;
            noCount++;
        }
        else if( x < t->element )
        {
            insertList( x, y, t->left );
            if( height( t->left ) - height( t->right ) == 2 )
                if( x < t->left->element )
		{
                    sCount++;
                    rotateWithLeftChild( t );
		}
                else
		{
		    dCount++;
                    doubleWithLeftChild( t );
		}
        }
        else if( t->element < x )
        {
            insertList( x, y, t->right );
            if( height( t->right ) - height( t->left ) == 2 )
                if( t->right->element < x )
		{
		    sCount++;
                    rotateWithRightChild( t );
		}
                else
		{
		    dCount++;
                    doubleWithRightChild( t );\
		}
        }
        else
            ;  // Duplicate; do nothing
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    AvlNode * findMin( AvlNode *t ) const
    {
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    AvlNode * findMax( AvlNode *t ) const
    {
        if( t != NULL )
            while( t->right != NULL )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }

//Find word function
    AvlNode* findWord( const Comparable & x, AvlNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else if( x < t->element )
            return findWord( x, t->left );
        else if( t->element < x )
            return findWord( x, t->right );
        else
            return t;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        while( t != NULL )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( AvlNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( AvlNode *t ) const
    {
        if( t != NULL )
        {
            printTree( t->left );
            //if(t->flag==true)
                cout << "Element:" << left << setw(20) << t->element << "Flag:" << t->flag << endl;
            printTree( t->right );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    AvlNode * clone( AvlNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new AvlNode( t->element, clone( t->left ), clone( t->right ), t->height );
    }
        // Avl manipulations
    /**
     * Return the height of node t or -1 if NULL.
     */
    int height( AvlNode *t ) const
    {
        return t == NULL ? -1 : t->height;
    }

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild( AvlNode * & k2 )
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild( AvlNode * & k1 )
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild( AvlNode * & k3 )
    {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }

    /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
    void doubleWithRightChild( AvlNode * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }
};

#endif
