#include <iostream>
using namespace std;

int main()
{
int number, min, max, counter;
double average, sum;

//min=2147483648;
//max=-2147483648;
counter=0;

cout << "Please enter a number: "; //assigns initial min/max value
cin >> number;

min=number;
max=number;
sum=sum+number;

//while loop
	while(counter<9)
	{
		cout << "Please enter a number: ";
		cin >> number;
		
		if(number>=max)
		max=number;

		if(number<=min)
		min=number;

		sum=sum+number;
		counter++;	
	}
	average=sum/10;

//output

cout << "The minimum is: " << min << endl;
cout << "The maximum is: " << max << endl;
cout << "The sum is: " << sum << endl;
cout << "The average is: " << average << endl;

return 0;
}
