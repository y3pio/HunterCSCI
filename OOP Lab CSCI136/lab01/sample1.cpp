
/**********************************************************************
 
 Title:         : sample1.cpp
 Author         : Tiziana Ligorio
 Created on     : January 20, 2012
 Description    : This is the first program in CSci 136.
                  It is a very simple example of I/O operations.
 Purpose        : Class example
 Usage          : sample1
 Build with     : g++ -o sample1.cpp sample1
 Modification   :
 
 **********************************************************************/

#include <iostream>
using namespace std;
int main( )
{
    char answer;
    cout << "Hello!\n" 
         << "Welcome to C++.\n"
	 << "Do you like programming? (y/n) ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
	cout << "Great! You will enjoy this lab!\n";
    } else {
	cout << "Too bad!\n";
    }

    return 0;
}
