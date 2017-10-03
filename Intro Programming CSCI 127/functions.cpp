#include <iostream>
using namespace std;

//function prototyping
int product(int,int);
int max(int,int);
void printNumber(int);
void printHello(void);
double average(int,int);

int main()
{
int x,y,answer;
//cout << "Enter 2 integers to calculate." << endl;
//cin >> x >> y;

//answer = product(x,y);
//answer = max(x,y);
//answer = average(x,y);

//if(answer==0)
//cout << x << " and " << y << " are equal." << endl;

//else
//cout << "The greater number is: " << answer << endl;
cout << "Enter an integer to print: ";
cin >> x;

printNumber(x);
printHello();

return 0;
}

void printNumber(int x)
{
cout << x << endl;
}

void printHello()
{
cout << "Hello World" << endl;
}

//int product(int x, int y)
//{
//return x*y;
//}

//int max(int x, int y)
//{
//	if(x>y)
//	return x;

//	else if(y>x)
//	return y;

//	else
//	return 0;
//}

//double average(int x, int y)
//{
//return (x+y)/2;
//}
