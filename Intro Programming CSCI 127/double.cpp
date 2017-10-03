#include <iostream>
using namespace std;

int main()
{
int x,y;
int counter;
char ans;
double sum, avg;
cout << "Enter numbers to calculate the average: " << endl;
cin >> x >> y;


sum = x+y;
avg = sum/2;

cout << "The average is " << avg << endl;
return 0;
}
