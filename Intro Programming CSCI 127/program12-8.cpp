#include <iostream>
using namespace std;

/*int main()
{
int i=1, counter=0;
double sum=0, average;

while(i<=100)
{
	if(i%3==0 && i%7!=0)
	{
	sum=sum+i;
	counter++;
	}
	i++;
}

average=sum/counter; 

cout << "The sum of the numbers is: " << sum << endl;
cout << "The average of the numbers is: " << average << endl;

return 0;
}*/

int minimum(int,int,int);

int main()
{
int number1,number2,number3;

	cout << "Enter the first number to calculate: ";
	cin >> number1;

	cout << "Enter the second number: ";
	cin >> number2;

	cout << "Enter the last number: ";
	cin >> number3;

cout << "The smallest number is: " << minimum(number1,number2,number3) << endl;

return 0;
}

int minimum(int a, int b, int c)
{
	if(a<=b && a<=c)
	return a;

	else if(b<=a && b<=c)
	return b;

	else if(c<=a && c<=b)
	return c;

}
