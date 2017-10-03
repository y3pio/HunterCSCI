/**********************************************************************
 Title:         : paing_proj1
 Author         : Ye Paing
 Created on     : 02/11/2012
 Description    : Project1 for CSCI 135(Lecture)
 Purpose        : Used to compute various operations on DNA strands
 Usage          :
 Build with     : g++ paing_proj01.cpp -o paing_proj01.exe (on cslab18)
 Modification   : 2/13/2012 Completed
		  2/21/2012 Edit comment with pre/post conditions
***********************************************************************/
//pre processor directives
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//functions for option 1-3

int functionOne(string DNAone, int N);
//Precondition: input string must be valid ACGT, int N is a valid integer.
//Postcondition: will return int value of how many polyT sequences are in the DNA strand.
int functionTwo(string DNAone, string DNAtwo);
//Precondition: both strings must be valid ACGT strings.
//Postcondition: returns int value of how many mutations they are.
double functionThree(string DNAone, string DNAtwo);
//Precondition: both strings must be valid ACGT strings.
//Postcondition: returns the double value of the phylogenetic distance.

//additional functions for checking inputs/converting string to int.

bool dnaChecker(string checkDNA);
//Precondition: takes any valid strings.
//Postcondition: checks if string is ACGT, returns true/false.
bool integerChecker(string polyT);
//Precondition: takes in and valid strings.
//Postcondition: checks if string contains only '0-9'. returns true/false.
int stringConverter(string polyT);
//Precondition: Takes in already valid string polyT which contains '0-9'
//Postcondition: returns the converted integer value.

//START OF MAIN --------------------------------------------
int main()
{

int N=0; //int N will be converted from polyT     
string choice="", DNAone="", DNAtwo="", polyT=""; //accepts any valid string inputs

//menu-choice input print, while loop runs until user picks 4
do{
cout <<"\n---------------------"
    << "\nWelcome to the Menu!!"
    << "\n---------------------"
    << "\n1    Compute a poly-T sequence in a DNA strand."
    << "\n2    Compute the number of mutations between two DNA strands."
    << "\n3    Computer the phylogenetic distance between two DNA strands."
    << "\n4    Quit."
    << "\n\nEnter a choice number:";
        cin >> choice; //this is a string input.

//checks choice for single digit
if(choice.length()==1)
{
    //CHOICE 1
    if(choice[0]=='1') //only checks [0] as program only gets here if it's 1 digit.
    {
        cout << "\n-----------------------"
             << "\nYou've entered choice 1"
             << "\n-----------------------" << endl;

        do{ //this do while loop will run as long as DNAone, polyT entries are INVALID.
            //CHECK FUNCTIONS LOCATED AFTER main() FOR EXPLINATIONS
            cout << "Enter a DNA string(ACGT):";
                cin >> DNAone;
            cout << "Enter N number of poly-T to calculate:";
                cin >> polyT;
            if(dnaChecker(DNAone)==true && integerChecker(polyT)==true)
            {
            N = stringConverter(polyT);
                cout << "Your DNA sequence have ["
                << functionOne(DNAone, N)
                << "] number of poly-T sequence." << endl;
            }
            else if(dnaChecker(DNAone)==false || integerChecker(polyT)==false)
                {
                    cout << "\nInvalid input!! Please try again...\n" << endl;
                }
            }while(dnaChecker(DNAone)!=true || integerChecker(polyT)==false);
    }

    //CHOICE 2
    else if(choice[0]=='2')
    {
        cout << "\n-----------------------"
             << "\nYou've entered choice 2"
             << "\n-----------------------" << endl;
        do{ //this do while loop will run as long as DNAone, DNAtwo entries are INVALID.
            //CHECK FUNCTIONS LOCATED AFTER main() FOR EXPLINATIONS
            cout << "Enter the first DNA strand to compare(ACGT):";
            cin >> DNAone;
            cout << "Enter the second DNA strand to compare(ACGT):";
            cin >> DNAtwo;
            if(dnaChecker(DNAone)==true && dnaChecker(DNAtwo)==true)
            {
                cout << "Your two DNA strands have ["
                << functionTwo(DNAone, DNAtwo)
                << "] mutations in it." << endl;
            }
            else if(dnaChecker(DNAone)==false || dnaChecker(DNAtwo)==false)
            {
                cout << "\nInvalid input!! Please try again..\n" << endl;
            }
          }while(dnaChecker(DNAone)==false || dnaChecker(DNAtwo)==false);
    }

    //CHOICE 3
    else if(choice[0]=='3')
    {
        cout << "\n-----------------------"
             << "\nYou've entered choice 3"
             << "\n-----------------------" << endl;
        do{ //this do while loop will run as long as DNAone, DNAtwo entries are INVALID.
            //AND if the 2 DNA strands are not of equal length!!. (check while/else if statements below)
            //CHECK FUNCTIONS LOCATED AFTER main() FOR EXPLINATIONS
        cout << "Enter two DNA strands of equal length to compare."
             << "\nEnter first DNA strand:";
                cin >> DNAone;
        cout << "Enter second DNA strand:";
                cin >> DNAtwo;
        if(dnaChecker(DNAone)==true && dnaChecker(DNAtwo)==true && DNAone.length()==DNAtwo.length())
        {
            //precision set here for 2 decimal place output for the answer.
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(2);

            cout << "The phylogenetic distance between the two strands is ["
             << functionThree(DNAone, DNAtwo) << "]" << endl;
        }
        else if(dnaChecker(DNAone)==false || dnaChecker(DNAtwo)==false || DNAone.length()!=DNAtwo.length())
        {
            cout << "\nInvalid input!! Please try again..\n" << endl;
        }
          }while(dnaChecker(DNAone)==false || dnaChecker(DNAtwo)==false || DNAone.length()!=DNAtwo.length());
    }

    //CHOICE 4
    //display the message below upon exit.
    else if(choice[0]=='4')
    {
        cout << "\n-----------------------"
             << "\nYou've entered choice 4"
             << "\n-----------------------"
             << "\nGood bye!!" << endl;
    }
    //ERROR MESSAGE
    //for choice with single digits/chars that are not '1-4'
    else
        cout << "\n--------------------------------------"
             << "\nError, please enter choice number 1-4."
             << "\n--------------------------------------" << endl;
}
//ERROR MESSAGE
//for all other entries for choice
else if(choice.length()!=1)
    {
        cout << "\n--------------------------------------"
             << "\nError, please enter choice number 1-4."
             << "\n--------------------------------------" << endl;
    }

}while(choice[0]!='4'); //replay loop, quits with choice 4

return 0;
}
//END OF MAIN --------------------------------------------



//FUNCTIONS START HERE -----------------------------------

//functionOne for Option 1 calculating poly-T strings
int functionOne(string DNAone, int N)
{
//i = initalizer of for loop, count = current T string counter, answer = final answer.
int i=0, count=0, answer=0;

//for loop checks each entry in string DNAone.
//if the count ever reach user desired N polyT sequence, answer gets +1
for(i=0; i<DNAone.length(); i++){
    if(DNAone[i]=='T')
    {count++;
        if(count==N)
        answer++;
    }
    else if(DNAone[i]!='T')
    {
    //this is to bring the count back to 0 when T string breaks.
    //prevents T strings > N from being counted.
        count=0;
    }
}
return answer; //returns the total number of N poly-T strings
};

//functionTwo for Option 2 calculating mutations between 2 DNA strands
int functionTwo(string DNAone, string DNAtwo)
{
//no count variable needed here, mutation counts are added directly to answer;
int i=0, answer=0;

//check which string is longer to make sure blank entries are counted as mutations
//DNAone is longer or equal to DNAtwo
if(DNAone.length()>=DNAtwo.length())
{
//for loops check through each entry in the string for mutations.
    for(i=0; i<DNAone.length(); i++)
    {
        if(DNAone[i] != DNAtwo[i])
        answer++;
    }
}
//DNAtwo is longer than DNAone, non inclusive as it is included in >= above.
if(DNAone.length()<DNAtwo.length())
    for(i=0; i<DNAtwo.length(); i++)
    {
        if(DNAtwo[i] != DNAone[i])
        answer++;
    }
return answer;
}

//functionThree for Option 3 calculating phylogenitic distance.
double functionThree(string DNAone, string DNAtwo)
{
int i=0;
double answer=0, length=0;
length = DNAone.length();

//length is already validated to be equal
//performs mutation checks same way as functionTwo
    for(i=0; i<length; i++)
    {
        if(DNAone[i] != DNAtwo[i])
        answer++;
    };

//answer is divided by double. static cast double just to make sure it's definitly double.
answer = static_cast <double>(answer/length);
return answer;
}

//VALIDATION FUNCTIONS START HERE ---------------------------------------
//ACTG Checker, validates if given string is ACGT.
bool dnaChecker(string checkDNA)
{
int i=0;

//for loop checks if each entry is non of the following ACGT.
//&& opeartions will only cause if statement to pass if they are all true.
    for(i=0; i<checkDNA.length(); i++)
    {
        if(checkDNA[i]!='A' && checkDNA[i]!='C' && checkDNA[i]!='G' && checkDNA[i]!='T')
        {
            return false; //if it passes, there's an element in the string that is not ACGT
        }
    }
return true; //validates the string that all elements in the string are either A,C,G or T
}

//integer polyT Checker, this checks that the user entered an integer string.
bool integerChecker(string polyT)
{
int i=0;

//for loop checks each entry in the string is of characters of base 10 (0-9)
for(i=0; i<polyT.length(); i++)
    {
        if(polyT[i]!='0' && polyT[i]!='1' && polyT[i]!='2' && polyT[i]!='3' && polyT[i]!='4' &&
           polyT[i]!='5' && polyT[i]!='6' && polyT[i]!='7' && polyT[i]!='8' && polyT[i]!='9' )
           {
               return false; //returns false if it finds something other than 0-9 characters
           }
    }
return true; //validates that the string ONLY consists of entries that are '0-9'
}

//stringConverter functions, converts strings into integer.
//*ONLY TO BE USED ON VALID INTEGER STRING*, use function integerChecker() to validate strings.
//*side note*, this function uses pow function. make sure <cmath> library is included.
int stringConverter(string polyT)
{
//sum will be returned as the converted integer, power is used for calculations.
int i=0, sum=0, power = 0;
//SIDE NOTE* some compilers will not accept int entry into math 'pow' function. use float data type for variable "power" if that's the case.

/*calculations is done place wise on the integer string, from left to right.
Given a string length N, the left most integer's value is 10^(N-1)] * (base10 integer(0-9))
As place progress from left to right, power of 10 decreases by 1.
Example: length(1234) = 4, thus 1234 = (10^3)*[1] + (10^2)*[2] + (10^1)*[3] + (10^0)*[4]*/
power = polyT.length()-1; 

//for loop checks each entry in the string for 0-9 and calculates accordingly.
    for(i=0; i<polyT.length(); i++)
    {	
	if(polyT[i]=='0')
	{
    	  sum = sum + (pow(10,power) * 0);
    	}

	if(polyT[i]=='1')
	{
    	  sum = sum + (pow(10,power) * 1);
    	}

	if(polyT[i]=='2')
	{
    	  sum = sum + (pow(10,power) * 2);
    	}

	if(polyT[i]=='3')
	{
    	  sum = sum + (pow(10,power) * 3);
    	}

	if(polyT[i]=='4')
	{
    	  sum = sum + (pow(10,power) * 4);
    	}
	if(polyT[i]=='5')
	{
    	  sum = sum + (pow(10,power) * 5);
    	}

	if(polyT[i]=='6')
	{
    	  sum = sum + (pow(10,power) * 6);
    	}

	if(polyT[i]=='7')
	{
    	  sum = sum + (pow(10,power) * 7);
    	}

	if(polyT[i]=='8')
	{
    	  sum = sum + (pow(10,power) * 8);
    	}

	if(polyT[i]=='9')
	{
    	  sum = sum + (pow(10,power) * 9);
    	}

    power--;//power -1 each time as the loop progress right.
    }
     
return sum; //returns the converted integer value.
}

