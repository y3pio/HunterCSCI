/**********************************************************************
 Title:         : paing_main.cpp
 Author         : Ye Paing
 Created on     : 5/14/2012
 Description    : Project 3 for CSCI 135, Address Book Simulator
 Purpose        : Perform string manipulation
 Usage          : ./paing_main.exe "NAME_OF_CSV_FILE.txt"
 Build with     : g++ paing_main.cpp paing_Addressbook.cpp
                  paing_Contact.cpp -o paing_main.exe
 Modification   :
 **********************************************************************/
#include "paing_AddressBook.h"

//Function prototype for main()
void displayMenu();
//Precondition: Non
//Postcondition: Outputs the main menu for the program.

bool checkOption(string opt);
//Precondition:takes in a string opt which is the user entered option.
//Postcondition:checks if it is a valid option selection. returns true/false.

////////////////////////
//MAIN() STARTS HERE!!//
////////////////////////
/*
**NOTE**
For all class member functions, check their respective header files
for the DETAILED (Post/Pre condition) description of the function.
*/
int main(int argc,char* argv[])//argv[1] will be the csv inputfile name.
{
 
 //If statement to check if an inputfile command line arguement is passed.
 if(argc<2)
 {
   cout << "\nError usage, please run the program in the following manner:" << endl;
   cout << argv[0] << " CSV_INPUT_FILE_NAME\n" << endl;
   exit(1); //Display usage and exit program if no command line arguement.
 }

//////////////////////////
//TOKEN EXTRACTION BLOCK//
//////////////////////////
 AddressBook bookOne;
 //Create AddressBook object bookOne
 bookOne.pushTitle();
 //This function pushes the title line into the contact vector at position 0.(i.e "First Name", "Last Name" etc...)
 /*Could probably leave this out by reading the first line of the given input file which also contains
 the title line.*/

 vector<string> myString;
 //myString will store text lines from csv inputfile argv[1]
 string fileline, currentline, substring;
 //fileline=line of file from text to be push back into myString
 //currentline=current line that is being looked at by token extraction algorithm
 //substring=token extracted to be pushed into the actual Addressbook Contact


    	//File extration is done here
	ifstream myfile(argv[1]);
	
	//Start extraction line by line if able to open file.
	if(myfile.is_open())
	{
		while(myfile)
		{
			getline(myfile, fileline);
			if(fileline.length()!=0)
			{
				myString.push_back(fileline);
			}
		}
    		myfile.close();
	}

	//Else if the file does not exist, asks user to double check that the files is in the directory.
	else
	{
		cout << "\n*WARNING* CSV File not found in directory. Please check for file:\"" << argv[1] << "\"\n" << endl;
		exit(1);		
	}

    //Token extraction loop/algorithm starts here.
    //Took me a while but I figured it out =)!
    for(int i=1; i<myString.size(); i++) //this for loop will run for the length of myString
    {
        bookOne.iPush();
        //iPush will pushback the vector to make room for the new incomming line.

        currentline=myString.at(i);
        //currentline will get each line from myString from first to end

        //x is left "
        //y is right "
        //token will count token # 1-11 for each field.
        int x=0, y=0, token=0;
        while(token<11)//The algorithm should keep looking for tokens until counter hits 11 tokens
        {
            //x starts looking for the first " from y (0 initially at the start of the string/loop)
            x=currentline.find_first_of("\"", y);
            //y will start looking for the next " starting from x+1
            y=currentline.find_first_of("\"",x+1);

            //This if check is not really needed but to be save, x" will always be less than y"
            if(x<y)
            {
                token++;
            }
            substring=currentline.substr(x+1,(y-x)-1);
            //substring is the token which will always be found at x+1 to y-1
            //to get the length, starting from x+1, it is (y-x)-1...(there are also other ways to calculate)
            bookOne.buildData(i,substring,token);
            //After token is extracted to substring, it is pushed to the address book with it's respective
            //token index counter "token"

            //This was the tricky part...took me a while to figure it out =P
            //y needs to get +1 to prevent x from finding y's " in the next loop. DUHHH!!
            //Also this can be done with a third variable to look for commas but this is more efficient/easier.
            y++;

        }

    }//for loop ends here bringing the extraction process to an end.

    //This loop will validate the newly built vector of contacts. (Start at 1 as 0 is the title line)
    for(int i=1; i<bookOne.vectorSize()-1; i++) //vectorsize returns the size the vector Contact data.
    {
        if(bookOne.contactValidate(i)==0)//this boolean function validates and DELETES invalid contacts.
        {
            bookOne.contactValidate(i);//calling the actual function DELETES invalid contacts (more detail in header file)
            i=1; //Thus bringing i back to 1 is needed to check for all invalid contacts in the new vector size.
        }
    }



/////////////////////
//MAIN OPTION BLOCK//
/////////////////////
 string option;
 //option is the variable for the menu option input from the user
 do{ //this do loop will run wile the option is not Q or q for quit.
    do{ //this do loop will run until a valid option is received from the user.
        displayMenu();
        cout << "Select an option:";
        cin >> option;
        //if the option is longer than 1 character. (can probably leave out >1 as function checks for length also)
        if(checkOption(option)==false || option.length()>1)
        {
            cout << "Invalid choice please try again.." << endl; //output invalid choice statement.
        }
    }while(checkOption(option)==false);

    //Program will get here only if option is valid.
    //Options are listed in order shown on project 3 description

        //////////////////////////////
        //OPTION [A] - Add a contact//
        //////////////////////////////
    if(option=="A" || option=="a")
    {
        //Function A uses push_back to add the new contact
        //Check AddressBook header/source file for more detail.
        bookOne.functionA();

        //if the new added push_back vector is valid (NOTE* if valid this function will NOT delete)
        if(bookOne.contactValidate(bookOne.vectorSize()-1)==1)
        {
            //Thus print detail should print the last entry added which is vector size-1;
            bookOne.printDetail(bookOne.vectorSize()-1);
            cout << "\n**New contact added to the end of the list at position " << bookOne.vectorSize()-1 << endl;
        }

        else //no need to call function again as the first if statement already called it and will delete if it's invalid.
        {    //will enter this else if it's deleted, in that case output the error message below.
            cout <<"\nInvalid contact..."
                 <<"\nPlease input valid/non space leading values for the first four fields." << endl;
        }
    }

        //////////////////////////////////////////
        //OPTION [D] - Display by sorted contact//
        //////////////////////////////////////////
    else if(option=="D" || option=="d")
    {
        //sort is the token # which it needs to be sorted by. (1-4 only)
        int sort=0;

        //do-while loop will run until a valid token choice is given.
        do{
            cout << "\nWhich field would you like to sort by?"
                << "\n1)Last Name"
                << "\n2)First Name"
                << "\n3)Nickname"
                << "\n4)Email 1"
                << "\n--------------"
                << "\nEnter Choice:";
            cin  >> sort;

            //if statement to reprompt user for valid choice
            if(sort<=0 || sort > 4)
            {
                cout << "**Error choice input, please enter choice 1-4." << endl;
            }
        }while(sort<=0 || sort > 4);

        //functionD sorts the contacts accordint to token sort
        //I used the same sorting method as my project 2!! =)
        //More in detail in AddressBook header/source file
        bookOne.functionD(sort);

        //Print preview the newly sorted contacts
        bookOne.printPreview();
    }

        ///////////////////////////////////////////
        //OPTION [C] - Display details of contact//
        ///////////////////////////////////////////
    else if(option=="C" || option=="c")
    {
        //Simply print out the details of the desired contact entry.
        int entry=0;
        bookOne.printPreview();
        do{//do-while loop to keep the entry selection within bounds of the valid vector.
            cout << "Which entry # would you like to view in detail?:";
            cin >> entry;
            if(entry<0 || entry>bookOne.vectorSize()-1)
            {
                cout << "\n**Error entry #, please try again.." << endl;
            }
        }while(entry<0 || entry>bookOne.vectorSize()-1);
        //printDetail will print the details of the desired entry.
        bookOne.printDetail(entry);

    }

        /////////////////////////////////
        //OPTION [R] - Remove a contact//
        /////////////////////////////////
    else if(option=="R" || option=="r")
    {
        //Removes the desired contact in vector<Object> data
        int remove=0;
        char confirm=' ';
        bookOne.printPreview();
        do{//do-while loop to keep selection within vounds of the valid vector.
            cout << "Which entry # would you like to remove?:";
            cin >> remove;
            if(remove<1 || remove >= bookOne.vectorSize())
            {
                cout << "\n**Error index input, please enter index # 1-" << bookOne.vectorSize()-1 << "!!\n" << endl;
            }
        }while(remove<1 || remove >= bookOne.vectorSize());

        //Print details of the desired contact to be removed
        bookOne.printDetail(remove);
        do{//do-while loop to make sure a y/n answer is given
            cout << "Would you like to remove this contact?(y/n):";
            cin >> confirm;
            if(confirm!='y' && confirm!='Y' && confirm!='n' && confirm!='N')
            {
                cout << "Please enter (y/Y) for yes and (n/N) for no!!" << endl << endl;
            }
        }while(confirm!='y' && confirm!='Y' && confirm!='n' && confirm!='N');

        //confirmation of deletion with Y/y
        if(confirm=='Y' || confirm=='y')
        {
            bookOne.functionR(remove);
            cout << "Contact removed!!" << endl;
        }
        //else it is N/n, no changes will be made.
        else
        {
            cout << "No changes were made!" << endl;
        }
    }

        ////////////////////////////////////////
        //OPTION [F] - Find contact matching..//
        ////////////////////////////////////////
    else if(option=="F" || option=="f")
    {
        string keyword;
        //keyword will store the desired string the user wants to find
        int token=0;
        //token will be the field the user wants to look in (1-4)

        cout << "\nEnter a keyword to find matching contacts(Case Sensetive):";
        cin >> keyword;
        do{//do-while loop to keep the desired field in vaild choice (1-4)
            cout << "\nWhich field would you like to search in?"
                 << "\n1)Last Name"
                 << "\n2)First Name"
                 << "\n3)Nickname"
                 << "\n4)Email 1"
                 << "\n--------------"
                 << "\nEnter Choice:";
            cin >> token;
            if(token<=0 || token > 4)
            {
                cout << "**Error choice input, please enter choice 1-4." << endl;
            }
        }while(token<=0 || token > 4);

        //functionF searches for matching string provided by keyword in field designated by token
        //More in detail in the AddressBook header/source file.
        bookOne.functionF(token, keyword);
    }

        /////////////////////////////////////////////////
        //OPTION [M] - Modify a contact. (Extra Credit)//
        /////////////////////////////////////////////////
    else if(option=="M" || option=="m")
    {
        int modify=0;
        //modify is the contact vector that the user wishes to modify, start from vector 1 - vector.size()-1
        cout << endl;
        //Prints a preview to let user select index of contect to modify.
        bookOne.printPreview();
        do{//do-while loop to keep index selection from user in bounds.
            cout << "Which entry # would you like to modify?:";
            cin >> modify;
            if(modify<1 || modify >= bookOne.vectorSize())
            {
                cout << "\n**Error index input, please enter index # 1-" << bookOne.vectorSize()-1 << "!!\n" << endl;
            }
        }while(modify<1 || modify >= bookOne.vectorSize());
        cout << "Enter new valid data for the ocntact...\n" << endl;
        //functionM will modify the desired contact and ask for new data for all the field.
        //almost the same function as functionA for adding contacts.
        //More detail in AddressBook header/source file.
        bookOne.functionM(modify);
    }

        /////////////////////////////////////////////////////
        //OPTION [E] - Export to a CSV file. (Extra Credit)//
        /////////////////////////////////////////////////////
    else if(option=="E" || option=="e")
    {
        string filename;
        //filename will take in the export file name provided by user.
        cout << "\nEnter the name of the file you wish to export this address book to:";
         cin >> filename;
        filename+=".txt"; //adds .txt file extension to make it readable.

        ofstream exportfile(filename.c_str());
        //turning filename into cstring so that ofstream can create a file.

        //nested for loop to run through every token in every vector.
        for(int v=0; v<bookOne.vectorSize(); v++)
        {
            for(int i=1; i<=11; i++)
            {
                exportfile << "\"" << bookOne.getData(v,i) << "\", ";
            }
            exportfile << endl;
        }

        //report output finishing successfully, close output file stream.
        cout << "\nAddress book exported to file:" << filename << endl;
        exportfile.close();
    }

 }while(option!="Q" && option!="q"); //outer do-while loop runs as long as option is not quit

     //Will get here only if option is to quit, in that case write the changes to the input file.
     ofstream exportfile(argv[1]); //open output file stream to argv[1]

     //nested for loops to extract tokens from vector.
     for(int v=0; v<bookOne.vectorSize(); v++)
     {
         for(int i=1; i<=11; i++)
         {
             //write to input file, making changes
             exportfile << "\"" << bookOne.getData(v,i) << "\", ";
         }
         exportfile << endl;
     }
     cout << "\nProgram exit. All changes to the addressbook file has been appended."
          << "\nGood bye!" << endl;
 return 0;
}//main() ends here, program terminate!! =)


////////////////////////
//MAIN()'s FUNCTIONS!!//
////////////////////////
void displayMenu()
{
    cout << "\n-----------------MAIN MENU-----------------"
         << "\n[A] add a contact to the address book"
         << "\n[D] display all contacts sorted by ..."
         << "\n[C] display details of contact"
         << "\n[R] remove contact"
         << "\n[F] find contacts matching ..."
         << "\n[M] modify contact"
         << "\n[E] export to csv format"
         << "\n[Q] quit the program"
         << "\n-------------------------------------------" << endl;
}

bool checkOption(string opt)
{
    //Checks if length is 1 and the proceed to check characters.
    if(opt.length()==1)
    {
        if(opt[0]=='A' || opt[0]=='a')
        return true;

        else if(opt[0]=='D' || opt[0]=='d')
        return true;

        else if(opt[0]=='C' || opt[0]=='c')
        return true;

        else if(opt[0]=='R' || opt[0]=='r')
        return true;

        else if(opt[0]=='F' || opt[0]=='f')
        return true;

        else if(opt[0]=='M' || opt[0]=='m')
        return true;

        else if(opt[0]=='E' || opt[0]=='e')
        return true;

        else if(opt[0]=='Q' || opt[0]=='q')
        return true;

        else return false; //if the option letters aren't found, return false.
    }
    else if(opt.length()!=1) //if length is not 1, return false.
    return false;
}
