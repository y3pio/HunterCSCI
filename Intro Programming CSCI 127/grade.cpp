#include <iostream>
using namespace std;

int grade=0;

int main()
{
while(grade!=-1)
{
	/*do
	{
	cout << "Enter a grade from 0-100: ";
	cin >> grade;
	}while(grade<-1 || grade>100);*/

	cout << "Enter a grade from 0-100: ";
	cin >> grade;

		while(grade<-1 || grade>100)
	{
		cout << "Enter a grade from 0-100: ";
		cin >> grade;
	};	


	if (grade >= 95)
	cout << "A+" << endl;

	else if (grade >= 90)
	cout << "A" << endl;

	else if (grade >= 80)
	cout << "B" << endl;

	else if (grade >= 70)
	cout << "C" << endl;
	
	else if	(grade >=0)
	cout << "F" << endl;
	
	else if (grade==-1)
	cout << "Program Stop" << endl;

};

return 0;
}
