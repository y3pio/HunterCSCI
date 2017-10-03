//Using while loops to enter month.
//11-21-11

#include <iostream>
using namespace std;

int main()
{
int month;
string name[12];

	do
	{cout << "Enter a number of a month from 1-12 ";
	cin >> month;
	}while(month<1 || month>12);

name[12]={"Janurary"};


cout << "You've entered the number " << month << " for the month " << name[month] << "." << endl;

return 0;
}
