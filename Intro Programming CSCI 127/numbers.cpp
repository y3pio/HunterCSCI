#include <iostream>
using namespace std;

long factFun(long x);
int main()
{
/*int x;
cout << "Enter a number: ";
cin >> x;
cout << "Answer is: " << factFun(x) << endl;*/
int x;
char ans;
do{
	do{
	cout << "Please enter a positive number: ";
	cin >> x;
	}while(x<0);
int c=1;
while(x!=0)	
	{
	c=c*x;
	x--;
	}
cout << "The factorial of this number is: " << c << endl;
cout << "Would you like to calculate another number?(y/n): ";
cin >> ans;
}while(ans!='n');

cout << "Good Bye!" << endl;
return 0;
}

/*//recursive function
long factFun(long x)
{
if(x==1)
return 1;

if(x>1)
	{
	x = x*factFun(x-1);
	return x;
	}
}*/

/*//using a while loop
long factFun(long x)
{
int c=1;
while(x!=0)
	{
	c=c*x;
	x--;
	}
return c;
}*/
