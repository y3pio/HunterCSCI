/**********************************************************************
 Title:         : paing_lab10.cpp
 Author         : Ye Paing
 Created on     : 4/23/2012
 Description    : main file for lab10
 Purpose        : To practice class/object usage
                  Also to practice OOP programming
 Usage          : ./paing_lab10.exe
 Build with     : g++ paing_lab10.cpp paing_student.cpp -o
                  paing_lab10.exe
 Modification   : Revised version 1. 6:30pm
 **********************************************************************/
#include "paing_student.h"

int main()
{
    //Object declaration
    //Construct in the following order:
    //("Firstname", "Lastname", "ID", 'status', GPA, credits)
    
    //Declaring objects with variou constructors.
    student bob("bob", "barker", "012345678"); //3 parameter constructor
    student steve("steve", "chi", "12345", 'f'); //4 parameter constructor
    student kevin("kegin", "gallagher", "09999999", 'F', 3.50, 120); //full constructor

    //Object Testing begins here---------
    //Various variables to use with set functions.
    int credits=0;
    double gpa=0;
    char status='F';
    
    //All 3 objects have default info output (firstname, lastname, id)
    //Various testing for class student is done on all three objects.
    //Feel free to add more and use the functions defined in the header file.
    
    
    //First block of code for object "bob".
    //Bob earns more credits/
    cout << "This is bob's initial info: " << bob.getName() << " " << bob.getID() << endl;
    do{
        cout << "How many credits did bob earn this semester?:";
        cin >> credits;
        
    }while(bob.setCredits(credits)==false);
    
    
    //Second block of code for "steve"
    //Steve becomes full/part time!!
    cout << "\nSteve's info is: " << steve.getName() << " " << steve.getID() << endl;
    do{
        cout << "Enter steve's new full/part time status (F/P):";
        cin >> status;
    }while(steve.setStatus(status)==false);
    cout << "Steve's student status is now: " << steve.getStatus() << endl;
    
    
    //Third block of code for "kevin"
    //Kevin gets a new gpa!
    cout << "\nKevin's student info: " << kevin.getName() << " " << kevin.getID() << endl;
    do{
        cout << "Enter kevin's new gpa:";
        cin >> gpa;
    }while(kevin.setGPA(gpa)==false);
    

return 0;
}
