//Nov 22 2011
//Ye Paing CSCI 127

#include <iostream>
using namespace std;

int main()
{
int month=0; //initial month is 0, define variables.
double balance, interest, pay;

//asks user for input
cout << "What is the balance on the account?" << endl;
cin >> balance;
cout << "What is the annual interest rate?" << endl;
cin >> interest;

//interest for monthly. divide by 100 for percentage
interest=(interest/12)/100;

cout << "How much do you expect to pay monthly?" << endl;
cin >> pay;

//begin while loop while balance is not paid off
	while(balance!=0)
	{	//if balance is more than payment
		if(balance>=pay)
		{//balance = difference + (interest of difference)
		balance=(balance-pay)+((balance-pay)*interest);
		month++; // add month, outputs
		cout << "After month " << month << " balance = $" << balance 			<< endl;
		}
		//if balance is less than payment
		else if(balance<pay)
		{balance=0; //next month balance = 0, no interest calc'd
		month++; // add to month counter
		cout << "After month " << month << " balance = $" << balance 			<< endl;
		};	
	};

//final outpot for how many months it takes to pay off.
cout << "It takes " << month << " months to pay off the balance." << endl;

return 0;
}
