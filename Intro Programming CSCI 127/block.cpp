//11-21-11 CSCI 127 Block Count

#include <iostream>
using namespace std;

int main()
{
int level, sum=0;

cout << "How high is your pyramid? ";
cin >> level;

//	if(level>0)
//	{
		while(level>=1)
		{
		sum=sum+(level*level);
		level--;
		}
//	}

/*	else if(level<0)
	{
		while(level<=-1)
		{
		sum=sum+(level*level);
		level++;
		}
	}*/

cout << "You will need " << sum << " blocks." << endl;

return 0;
}
