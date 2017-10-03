/**********************************************************************
 Title:         : paing_lab03.cpp
 Author         : Ye Paing
 Created on     : 2/21/12
 Description    : CSCI136 lab03.
 Purpose        : Used to calculate GCContent, CpG island on a DNA
		  strand.
 Usage          : 
 Build with     : g++ paing_lab03.cpp -o paing_lab03.exe
 Modification   : 
 **********************************************************************/
//Pre-processor directives.
#include <iostream>
#include <string>
using namespace std;

double GCcontent(string Dna);
//Precondition: takes valid ACGT strings.
//Postcondition: returns GC content.

int CpGcounter(string Dna);
//Precondition: takes valid ACGT strings.
//Postcondition: returns CpG island count.

bool dnaChecker(string checkDNA);
//Precondition: takes any valid strings.
//Postcondition: checks if string is ACGT, returns true/false.

bool repeater(string answer);
//Precondition: takes valid yes/no string
//Postcondition: returns true/false falue for loop.

int main()
{
string Dna, answer; //variable answer is used for repeating yes/no

//This is the yes/no do-while loop
do{
//Asks user to enter a DNA strand
cout << "Enter a DNA strand:";
cin >> Dna;

	//This is the do-while loop to keep asking the user for valid
	//ACGT DNA strand.
	do{
	if(dnaChecker(Dna) == false)
	{
	cout << "Error input, DNA must consist of only ACGT/acgt."
		"\nPlease try again:";
	cin >> Dna;
	};
	}while(dnaChecker(Dna) == false);

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);

	cout << "The GCContent of this DNA strand is:" 
	<< GCcontent(Dna) << endl;
	cout << "The CpG island count of this DNA strand is: " 
	<< CpGcounter(Dna) << endl;

cout << "Would you like to analyze another DNA strand?(yes/no):";
cin >> answer; //Assumed that the user is compliant.

//Checks answer for 'yes' or 'no'. 
//function repeater() returns true for yes.
}while(repeater(answer)==true);

return 0;
}//Main ends here.

//Function starts here.

//Validates DNA strand for ACGT/acgt
bool dnaChecker(string checkDNA)
{
int i=0;

    for(i=0; i<checkDNA.length(); i++)
    {
    if(checkDNA[i]!='A' && checkDNA[i]!='C' && checkDNA[i]!='G' && checkDNA[i]!='T' && checkDNA[i]!='a' && checkDNA[i]!='c' && checkDNA[i]!='g' && checkDNA[i]!='t' ) //if string does NOT contain 'AaCcGgTt'
        {
            return false;
        }
    }
return true;
}

//Calculates GCcontent.
double GCcontent(string Dna)
{
int i=0;
double n=0, content=0, answer=0;

//For loop checks each entry/entry+1 in the string for 'CcGg'
for(i=0; i<Dna.length(); i++)
{
if(Dna[i]=='C' || Dna[i]=='G' || Dna[i]=='c' || Dna[i]=='g')
	content++; 
}
answer = content/Dna.length(); //Calculates answer (double).
return answer;
}

//Counts CpG islands.
int CpGcounter(string Dna)
{
int i=0, counter=0;

for(i=0; i<Dna.length(); i++)
{
//These if/elseif contains all possible C/G combination.
//If any of these combinations are hit, counter +1.
if(Dna[i]=='C' && Dna[i+1]=='G')
	counter++;
else if(Dna[i]=='c' && Dna[i+1]=='G')
	counter++;
else if(Dna[i]=='C' && Dna[i+1]=='g')
	counter++;
else if(Dna[i]=='c' && Dna[i+1]=='g')
	counter++;
}
return counter; //returns total count.
}

//Yes/No checker.
bool repeater(string answer)
{
int i=0;

//For loop checks if string is 'y' 'e' 's' = yes.
for(i=0; i<answer.length(); i++)
{
if(answer[i]=='y'&&answer[i+1]=='e'&& answer[i+2]=='s')
	return true;
}
return false;
}
