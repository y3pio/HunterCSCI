/**********************************************************************
 Title:         : paing_lab11.cpp
 Author         : Ye Paing
 Created on     : 5/7/12
 Description    : main file for lab11
 Purpose        : To practice modifying strings
 Usage          : ./paing_lab10.exe
 Build with     : g++ paing_lab11.cpp paing_student.cpp
		  -o paing_lab11.exe
 Modification   : 
 **********************************************************************/
#include "paing_student.h"

int main(int argc,char * argv[])
{
	//Vector declaration for myStudents which holds student info.
	vector<Student> myStudents;
	//My string is a dummy vector to store geline inputs from file.
	vector<string> myString;
	//Various strings to do string minupulation with.
	string fileline, currentline, substring;
		
	ifstream myfile(argv[1]);	
	while(myfile)
	{
		getline(myfile, fileline);
		if(fileline.length()!=0)
		{
			myString.push_back(fileline);
		}
	}
	
	//This while loop runs the length of the input file to find substrings of tokens.
	int i=0;
	while(i<myString.size())
	{
		Student buffer;
		currentline=myString.at(i);
		int x=0, y=0, token=1;
		
		//Finding substrings within the length of the line.
		while(x < currentline.length() && y < currentline.length())
		{
			x=currentline.find_first_not_of(" ", y);
			y=currentline.find_first_of(" ", x);
			substring=currentline.substr(x,(y-x));

			//If statement to check alpha tokens.
			if(token==1 || token==2 || token==4)
			{
				for(int j=0; j<substring.length(); j++)
				{
					if(isalpha(substring[j]))
					buffer.setToken(substring, token);
				}
			}

			//If statement to check digit tokens
			else if(token==3 || token==5 || token==6)
			{
				for(int j=0; j<substring.length(); j++)
				{
					if(isdigit(substring[j]))
					buffer.setToken(substring, token);
				}
			}
			
			token++;
			
		}

		//After the buffer is build, it is push backed to the actual vector that will store student data.
		myStudents.push_back(buffer);
		i++;
	}
	//End token creation loop, close file.	
	myfile.close();
	
	/////////////////////////////////
	//MAIN MENU FOR EXTRA GOES HERE//
	/////////////////////////////////

	//Will loop the menu display until quit (option choice 4)
	int choice=0;
	while(choice!=4)
	{
		cout << "----------MAIN MENU----------"
	     	<< "\n1)Display students"
	     	<< "\n2)Delete a student"
		<< "\n3)Sort students"
	     	<< "\n4)Quit"
	     	<< "\nEnter choice:";
		cin >> choice;

		//Choice 1 simply displays
		if(choice==1)
		{
		cout << endl;
			for(int i=0; i<myStudents.size(); i++)
			{
				cout << i;
				for(int token=1; token<=6; token++)
				{
				cout << " " << myStudents[i].getToken(token) << " ";
				}
				cout << endl;
			}
		cout << endl << endl;
		}
		
		//Choice 2 asks for an entry to delete. Entries are numbered according to vector elements.
		else if(choice==2)
		{
		cout << endl;
			int entry=0;
			cout << "Select an entry to delete!!" << endl;
			for(int i=0; i<myStudents.size(); i++)
			{
				cout << i;
				for(int token=1; token<=6; token++)
				{
				cout << " " << myStudents[i].getToken(token) << " ";
				}
				cout << endl;
			}
			//User entry for request delete
			cout << "Enter a student to delete:"; cin >> entry;
			myStudents.erase(myStudents.begin()+entry);

		cout << endl << endl;
		}

		//Choice 3 for swapping (not yet done)
		else if(choice==3)
		{
		cout << endl;
			int entry=0;
			for(int i=0; i<myStudents.size(); i++)
			{
				cout << i;
				for(int token=1; token<=6; token++)
				{
				cout << " " << myStudents[i].getToken(token) << " ";
				}
				cout << endl;
			}
			cout << "How would you like to sort them?"
			     << "\n1)Last Name"
			     << "\n2)First Name"	
			     << "\n3)ID"	
			     << "\n4)Stats"	
			     << "\n5)GPA"	
			     << "\n6)Credit"
			     << "\nEnter a token to sort by:";
			cin  >> entry;

			for(int i=0; i<myStudents.size(); i++)
			{
				vector<Student> buffer(1);
				if(myStudents[i].getToken(entry) > myStudents[i+1].getToken(entry))
				{
					buffer[0]=myStudents[i];
					myStudents[i]=myStudents[i+1];
					myStudents[i+1]=buffer[0];
					i=0;
				}
				cout << "No need to swap this loop!!" << endl;
			}			
		cout << endl << endl;
		}

	}//While loop to quit menu

return 0;
}



