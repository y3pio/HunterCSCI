/**********************************************************************
 Title:         : paing_assignment1_main.cpp
 Author         : Ye Paing
 Created on     : 2/14/2013
 Description    : Assignment 1 for CSCI 335 Spring'13
 Purpose        : To build our own Matrix STL
 Usage          : ./assignment1.exe OR with makefile: "make all"
 Build with     : g++ paing_* -o paing.exe
 Modification   : -
 Comments	: -
 **********************************************************************/

#include "paing_matrix.h"
#include <iostream>

using namespace std;


void TestingMatrix(){
    matrix<int> a, b, c; //Three empty matrices are created
    cout << a.numrows() << " " << a.numcols() << endl; // yields 0 0
    cin >> a; // User types [3 3 1 2 3 6 5 4 9 8 10]
    // This will create a 3 by 3 matrix
    // The first input is the number of rows, and the
    // second is the number of columns.
    // The rest are the values inserted row by row
    cout << a; // Output should be
    // [1 2 3
    // 6 5 4
    // 9 8 10]
    cin >> b; // User types [3 2 9 1 2 3 4 5]
    cout << b; // Output should be
    // [9 1
    // 2 3
    // 4 5]
    c=a*b; // c is the product of a and b
    cout << c << endl; // The output should be:
    // [25 22
    // 80 41
    // 137 83]
    cout << b+c << endl; // Output is the sum of b and c:
    // [34 23
    // 82 44
    // 141 88]
    matrix<int> d(5*b); // d is initialized to 5*b
    cout << d << endl; //The output should be
    //[45 5
    // 10 15
    // 20 25]
    d += c;
    cout << d << endl; //The output should be
    //[70 27
    // 90 56
    // 157 108]
    cout << a[0][0] << endl; //Should printout 1
    cout << a[1][2] << endl; //Should printout 4
    d = a + b; //This should cause an exception that you //are able to handle; The sizes of a and b don’t agree.
}//End of TestingMatrix() function


int main()
{
    TestingMatrix();//Run Prof.Stamos' test function.

    return 0;
}
