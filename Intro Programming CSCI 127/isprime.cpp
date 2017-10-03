#include <iostream>
using namespace std;

int isprime(int);

int main()
{
int n,prime;
cout << "Enter a number to calculate: ";
cin >> n;

prime=isprime(n);

if(prime==1)
cout << "The number is PRIME." << endl;

else
cout << "The number is NOT PRIME." << endl;

return 0;
}

int isprime(int n)
{
int i=2;

	while(i<n)
	{
	if(n%i==0)
	return 0;

	else
	i++;
	}

return 1;
};
