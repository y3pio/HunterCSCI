#include <iostream>
using namespace std;

int number,i=1;

int main()
{
cout << "Enter a positive number: ";
cin >> number;

	while(number<0)
	{
	cout << "Please enter a POSITIVE number: ";
	cin >> number;
	}

cout << "The factors of " << number << " are..." << endl;

	while(i<=number)
	{
		if(number%i == 0)
		cout << i << endl;
	
	i++;
	};

return 0;
}
