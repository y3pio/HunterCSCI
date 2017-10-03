#include <iostream>
using namespace std;

bool function(int);

int main()
{
int number;

cout << "Enter number to calculate: ";
cin >> number;


	if(function(number)==true)
	cout << "The number is odd." << endl;

	else
	cout << "The number is even." << endl;

return 0;
}

bool function(int n)
{
	if(n%2==0)
	return false;

	else
	return true;

}
