//Ye Paing
//CSCI 127 Project 1
#include <iostream>
using namespace std;

//function declaration
void printMenu();
void printBalance(double);

int main()
{
//variable declaration
char option;
double withdrawl, deposite;
double balance=5000.00;
    
    //welcome statement, initial balance print, initial option select
    cout << "Welcome!!" << endl;
    printBalance(balance);    
    printMenu();
    cout << "Enter your option here: ";
    cin >> option;
    
    //invalid option while loop
    while(option!='d' && option!='D' && option!='w' && option!='W' && option!='b' && option!='B' && option!='q' && option!='Q')
    {
        cout << "\nInvalid option, please try again.." << endl;
        printMenu();
        cout << "Enter your option here: ";
        cin >> option;
    }
    
    //main while loop. will run if user does not 'q'
    while(option!='q' && option!='Q')
        {
            
            //deposite block
            if (option=='D' || option=='d') 
            {
                cout << "Please enter the amount you wish to deposite: ";
                cin >> deposite;
                while (deposite<=0) 
                    {
                    cout << "Invalid amount, please enter a positive amount: ";
                    cin >> deposite;
                    }
                balance=balance+deposite;
                cout << "Your transaction is complete! " << endl;
                printBalance(balance);
            }
            
            //withdrawl block
            else if (option=='W' || option=='w')
            {
                cout << "Please enter the amount you wish to withdraw: ";
                cin >> withdrawl;
                while (withdrawl<0 || withdrawl>balance)
                    {
                    cout << "Invalid amount, please enter a positive amount no greater than your balance: ";
                    cin >> withdrawl;
                    }
                balance=balance-withdrawl;
                cout << "Your transaction is complete!" << endl;
                printBalance(balance);
            }
            
            //print balance block
            else if (option=='B' || option=='b')
            {
                printBalance(balance);
            }
            
            //asks for new option
            printMenu();
            cout << "Enter your option here: ";
            cin >> option;
            
            //invalid loop for main loop
            while(option!='d' && option!='D' && option!='w' && option!='W' && option!='b' && option!='B' && option!='q' && option!='Q')
            {
                cout << "\nInvalid option, please try again.." << endl;
                printMenu();
                cout << "Enter your option here: ";
                cin >> option;
            }

        }
    //print after user ends loop with 'q'
    cout << "\nGoodbye!" << endl;     
    
    return 0;
}
//end main

//function for printing the menu
void printMenu()
{
    cout<< endl
        << " ========================================= " << endl
        << "|             Menu Options                |" << endl
        << "|-----------------------------------------|" << endl
        << "|+ Enter (D) or (d) to deposite.          |" << endl
        << "|+ Enter (W) or (w) to withdrawl.         |" << endl
        << "|+ Enter (B) or (b) to check your balance.|" << endl
        << "|+ Enter (Q) or (q) to quit.              |" << endl
        << " ========================================= " << endl;
}

//function for printing the balance
void printBalance(double bal) 
{
    cout<< endl
        << "-----------------------------------------"       << endl
        << "Your current balance is $" << bal << " dollars." << endl
        << "-----------------------------------------"       << endl;    
}