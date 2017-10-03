#include <iostream>
#include <string>
using namespace std;

string name;
char choice;
int main()
{

cout << "What is your name?: ";
getline(cin,name);

cout << "Hello " << name << endl;
do{
cout << "Please enter a or b: ";
cin >> choice;

if(choice=='a' || choice== 'A')
cout << "You've entered " << choice << endl;

else if(choice=='b' || choice== 'B')
cout << "You've entered " << choice << endl;

}while(choice !='a' && choice != 'b' && choice != 'A' && choice!= 'B');

return 0;
}
