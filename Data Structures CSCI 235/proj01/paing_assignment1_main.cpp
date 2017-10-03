/**********************************************************************
 Title:         : paing_assignment1_main.cpp
 Author         : Ye Paing
 Created on     : 9/4/2012
 Description    : Assignment 1 for CSCI235 Fall'12
 Purpose        : Searches two lists from the IMDB website
		  Search is based on user input movie/artist name
 Usage          : ./assignment1.exe
 Build with     : g++ paing_assignment1_main.cpp -o assignment1.exe
 Modification   : A LOT! So many variables to consider =(
 Comments	: Most of the operations/functions are repeating, 
		  with very little to no modifications. 
		  Will try to limit redundancy in commenting.
 **********************************************************************/
//Standard pre-processor directives
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

//Function prototypes

bool fileCheck();
//Precondition: No parameters needed, file name is coded directly into the function.
//Postcondition: Returns a true/false value. True=file check ok, False=no files found

void printMenu();
//Precondition: No parameters needed.
//Postcondition: Prints to screen the main menu interface.

void findMovie(string movie);
//Precondition: Takes in a name of a movie.
//Postcondition: Prints to screen the names of actors/actresses who starred in the movie.

//**The following two functions mirror each other. One for actors, one for actresses.**
void findActress(string name);
//Precondition: Takes in the name of an actress.
//Postcondition: Prints to screen the names of all costarring actress followed by actors..

void findActor(string name);
//Precondition: same as findActress() but for actors.
//Postcondition: same a findActress() but prints actors first then actresses.



//////////////////////////
//MAIN() DRIVER FUNCTION//
//////////////////////////
int main()
{
    //Runs filecheck to see if files are there.
    if(fileCheck()==false)//If files not found, print error message and end program.
    {
        cout << "ERROR! Unable to open \"actresses.2010.list\" or \"actors.2010.list\"" << endl;
	cout << "*Make sure that both files are located in the same directory as the source code." << endl;
        cout << "*Please check the spelling of the file names." << endl;
        cout << "*If you are on a UNIX system, please check your environmental variable $PATH." << endl;
	cout << "*If all else fails contact me at: ypaing[at]hunter[dot]cuny[dot]edu" << endl;
        exit (1);
    }
		
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    //Program Starts Here.(File check passed!)
    string choice, repeat;
    printMenu();
    do//do-while loop to run the program while user does not wish to exit.
    {
        string movie, name, list;
        do//do while look to ask user for the right choice(1-3) option.
        {
            getline(cin,choice);
            if(choice.length()>1 || choice[0]<49 || choice[0]>51)
            {
                cout << "Error input, please try again(1-3):";
            }
        }while(choice.length()>1 || choice[0]<49 || choice[0]>51);

        //Main menu switch.
        switch (choice[0])
        {
            case 49:// Run Option 1 here
		#ifdef _WIN32
    	        system("cls");
    	        #else
    	        system("clear");
    	        #endif
		cout << "(Leave blank to return to Main Menu)" << endl;
                cout << "Enter the name of the movie:"; 
                getline(cin, movie);
		if(movie.length()<1 || movie.find_first_not_of(" ")==string::npos)
		{
		    #ifdef _WIN32
    	            system("cls");
    	            #else
    	            system("clear");
    	            #endif
		    printMenu();
		    break;
		}
                cout << "---------------------------------------------" << endl;
                findMovie(movie);
                cout << "---------------------------------------------" << endl;
                cout << "Would you like to do another search?(y/n):";
		do//This do while loop asks for the right (y/n) answer
                {
                    getline(cin,repeat);
                    if(repeat.length()>1 || (repeat[0]!=121 && repeat[0]!=110)) //If repeat is not y/n or single character.
                    {
                        cout << "Error input, please try again!(y/n):";
                    }
                    else if(repeat[0]==121) //Repeat = yes
                    {
                        #ifdef _WIN32
    			system("cls");
    			#else
    			system("clear");
    			#endif
                        printMenu(); //Print a copy of the menu for next repeat.
                    }
                    else if(repeat[0]==110) //Repeat = no
                    {
			#ifdef _WIN32
    			system("cls");
    			#else
    			system("clear");
    			#endif
                        choice[0]=51; //Set choice to 3 to end the outer while loop.
                        cout << "\nGood Bye!" << endl;
                    }
                }while(repeat.length()>1 || (repeat[0]!=121 && repeat[0]!=110));
                break;
            
	    case 50://Run Option 2 here
		#ifdef _WIN32
    	        system("cls");
    	        #else
    	        system("clear");
    	        #endif
                cout << "---------------------------------------------" << endl;
                cout << "1)Actors List" << endl;
                cout << "2)Actresses List" << endl;
		cout << "3)Return to Main Menu" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "Which list would you like to search?(1-3):"; // Run Option 2 Here
                do//Do while loop to force 1/2 choice select.
                {
                    getline(cin,list);
                    if(list.length()>1 ||(list[0]<49 || list[0]>51))
                    {
                        cout << "Error input, please try again!(1-3):";
                    }
                }while(list.length()>1 ||(list[0]<49 || list[0]>51));
		//Actor/Actress choice select switch
                switch(list[0])
                {
                    case 49: //Choice list 1 = Find actors.
                        cout << "Enter the name of the actor:";
                        getline(cin,name);
                        cout << "---------------------------------------------" << endl;
                        findActor(name);
                        cout << "---------------------------------------------" << endl;
                        break;
				
                    case 50: //Choice list 2 = Find actress.
                        cout << "Enter the name of the actress:";
                        getline(cin,name);
                        cout << "---------------------------------------------" << endl;
                        findActress(name);
                        cout << "---------------------------------------------" << endl;
                        break;
		    case 51:
			#ifdef _WIN32
    	        	system("cls");
    	        	#else
    	        	system("clear");
    	        	#endif
			printMenu();
			break;
                }
                
		if(list[0]!=51)
		{
                    do//Same repeat check, asks user for y/n answer
                    {
		        cout << "Would you like to do another search?(y/n):";
                        getline(cin,repeat);
                        if(repeat.length()>1 || (repeat[0]!=121 && repeat[0]!=110))
                        {
                            cout << "Error input, please try again!(y/n):";
                        }
                        else if(repeat[0]==121)
                        {
                            #ifdef _WIN32
    	        	    system("cls");
    	        	    #else
    	        	    system("clear");
    	            	    #endif
                            printMenu();
                        }
                        else if(repeat[0]==110)
                        {
			    #ifdef _WIN32
    	        	    system("cls");
    	        	    #else
    	        	    system("clear");
    	        	    #endif
                            choice[0]=51;
                            cout << "\nGood Bye!" << endl;
                        }
                    }while(repeat.length()>1 || (repeat[0]!=121 && repeat[0]!=110));
		}
                break;

            case 51: //Exit option 3.
		#ifdef _WIN32
		system("cls");
		#else
		system("clear");
		#endif
                cout << "\nGood Bye!" << endl;
                break;

            default: //Default case should never be reached due to the do/while check prior to this switch
                     //But we should include it anyway since it's good practice. =)
                cout << "DEFAULT CASE SHOULD NEVER BE REACHED..." << endl;
                cout << "If you're reading this, kindly toss your computer out the window as it is broken..." << endl;
                cout << "Also Prof.Brizan is awesome!! =)" << endl; //Totally not sucking up for extra credit.
                break;
        }
    }while(choice[0]!=51);
    //Program Ends Here Yay! ^__^
    return 0;
}

///////////////////////////////////
//FUNCTION DEFINITIONS START HERE//
///////////////////////////////////

//That awkward moment when you wrote so much code that you almost forget how 1/2 of them works...=(

/////////////////////
//FILE OPEN CHECKER//
/////////////////////
bool fileCheck()

{
    ifstream myfile;
    myfile.open("actors.2010.list"); //Check actor file. Return false if fail to open.
    if(!myfile.is_open()) //If file is not open.
        return false;
    myfile.close();

    myfile.open("actresses.2010.list"); //Same as above but for actress file.
    if(!myfile.is_open())
        return false;
    myfile.close();
    return true; //Return true if both files DO NOT FAIL to open.
}

//////////////
//PRINT MENU//
//////////////
//Simple print menu function for user interface. =)
void printMenu()
{
    cout << "*********************************************" << endl;
    cout << "Welcome to the IMDB 2010 List Search" 	    << endl;
    cout << "*********************************************" << endl;
    cout << "Please select one of the following (1-3)" 	    << endl;
    cout << "1)Find a Movie" 				    << endl;
    cout << "2)Find an Actor/Actress" 			    << endl;
    cout << "3)Exit." 					    << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Enter choice(1-3):";

}

//////////////
//FIND MOVIE//
//////////////
void findMovie(string movie)
{
    //Opens actress files first
    ifstream myfile;
    myfile.open("actresses.2010.list");

    cout << "The following actresses starred " << movie << endl;
    while(!myfile.eof())
    {
            //cin.get(); //System pause for debugging
            //cout << currentline; //Print for above.

        string currentline, currentActor=" ", currentMovie=" ";
        do
        {
            getline(myfile, currentline);
            if(currentline[0]!='\t' && !currentline.empty())
            {
                //cout << " <<--<-ACTOR/ACTRESS NAME"; //Tracer code for debugging.
                if(currentline.find(",")!=string::npos &&
                   currentline.find("(", currentline.find(","))!=string::npos)
                {
                    int fnameLength=(currentline.find("(")-1)-(currentline.find(",")+2);
                    
			currentActor=currentline.substr(currentline.find(",")+2, fnameLength) + " " +
                                    currentline.substr(0, currentline.find(","));
                }
		else if(currentline.find(",")==string::npos && currentline.find("(")!=string::npos)
		{
		    currentActor=currentline.substr(0, currentline.find("(")-1);
		}
                else if(currentline.find(",")!=string::npos)
                {
                    currentActor=currentline.substr(currentline.find(",")+2) + " " +
                                    currentline.substr(0, currentline.find(","));
                }
                else
                    currentActor=currentline;
            }

            else if(currentline[0]=='\t')
            {
                //cout << " <<--<-MOVIE LINE" << endl; //Tracer code for debugging
                if(currentline[1]=='\"')
                {
                    currentMovie=currentline.substr(2, currentline.find("\"", 3)-2);
                }
                else
                {
                    currentMovie=currentline.substr(1, currentline.find("(", 2)-2);
                }
            }

            if(movie.compare(currentMovie)==0 && currentActor.length()>1)
            {
                cout << "* " << currentActor << endl;
                break; //Break out of current actor.
            }
            /*else if(currentline.empty())
            {
                cout << "<---ENTRY BREAK--->" << endl;
            }*/
        }while(!currentline.empty());
    }

    myfile.close();

    //Checking Actors in movie.

    myfile.open("actors.2010.list");

    cout << "\nThe following actors starred in " << movie << endl;
    while(!myfile.eof())
    {
            //cin.get(); //System pause for debugging
            //cout << currentline; //Print for above.

        string currentline, currentActor=" ", currentMovie=" ";
        do
        {
            getline(myfile, currentline);
            if(currentline[0]!='\t' && !currentline.empty())
            {
                //cout << " <<--<-ACTOR/ACTRESS NAME"; //Tracer code for debugging.
                if(currentline.find(",")!=string::npos &&
                   currentline.find("(", currentline.find(","))!=string::npos)
                {
                    int fnameLength=(currentline.find("(")-1)-(currentline.find(",")+2);
                    currentActor=currentline.substr(currentline.find(",")+2, fnameLength) + " " +
                                    currentline.substr(0, currentline.find(","));
                }
		else if(currentline.find(",")==string::npos && currentline.find("(")!=string::npos)
		{
		    currentActor=currentline.substr(0, currentline.find("(")-1);
		}
                else if(currentline.find(",")!=string::npos)
                {
                    currentActor=currentline.substr(currentline.find(",")+2) + " " +
                                    currentline.substr(0, currentline.find(","));
                }
                else
                    currentActor=currentline;
            }

            else if(currentline[0]=='\t')
            {
                //cout << " <<--<-MOVIE LINE" << endl; //Tracer code for debugging
                if(currentline[1]=='\"')
                {
                    currentMovie=currentline.substr(2, currentline.find("\"", 3)-2);
                }
                else
                {
                    currentMovie=currentline.substr(1, currentline.find("(", 2)-2);
                }
            }

            if(movie.compare(currentMovie)==0 && currentActor.length()>1)
            {
                cout << "* " << currentActor << endl;
                break; //Break out of current actor.
            }
            /*else if(currentline.empty())
            {
                cout << "<---ENTRY BREAK--->" << endl;
            }*/
        }while(!currentline.empty());
    }

    myfile.close();
}

////////////////
//FIND ACTRESS//
////////////////
void findActress(string name)
{
    ifstream myfile;
    myfile.open("actresses.2010.list");
    vector<string> movies;
    vector<string> actress;

    while(!myfile.eof())
    {
        string currentline, currentActor=" ", currentMovie=" ";
        getline(myfile, currentline);
        if(currentline[0]!='\t' && !currentline.empty())
        {
            //cout << " <<--<-ACTOR/ACTRESS NAME"; //Tracer code for debugging.
            if(currentline.find(",")!=string::npos &&
                   currentline.find("(", currentline.find(","))!=string::npos)
            {
                    int fnameLength=(currentline.find("(")-1)-(currentline.find(",")+2);
                    currentActor=currentline.substr(currentline.find(",")+2, fnameLength) + " " +
                                    currentline.substr(0, currentline.find(","));
            }
	    else if(currentline.find(",")==string::npos && currentline.find("(")!=string::npos)
	    {
		    currentActor=currentline.substr(0, currentline.find("(")-1);
	    }
            else if(currentline.find(",")!=string::npos)
            {
                currentActor=currentline.substr(currentline.find(",")+2) + " " +
                                currentline.substr(0, currentline.find(","));
            }
            else
                currentActor=currentline;
        }

        if(name.compare(currentActor)==0)
        {
            //cout << "ACTOR FOUND!!  " << i << endl;
            do
            {
                getline(myfile, currentline);
                if(currentline[0]=='\t')
                {
                    //cout << " <<--<-MOVIE LINE" << endl; //Tracer code for debugging
                    if(currentline[1]=='\"')
                    {
                        currentMovie=currentline.substr(2, currentline.find("\"", 3)-2);
                    }
                    else
                    {
                        currentMovie=currentline.substr(1, currentline.find("(", 2)-2);
                    }
                }
                if(movies.empty()==true || movies[movies.size()-1]!=currentMovie)
                    movies.push_back(currentMovie);

            }while(!currentline.empty());
            break;
        }
    }
    myfile.close();

    myfile.open("actresses.2010.list");
    string currentActor=" ", currentMovie=" ";
    while(!myfile.eof())
    {
        string currentline;
        getline(myfile, currentline);
        if(currentline[0]!='\t' && !currentline.empty())
        {
            //cout << " <<--<-ACTOR/ACTRESS NAME"; //Tracer code for debugging.
            if(currentline.find(",")!=string::npos &&
                   currentline.find("(", currentline.find(","))!=string::npos)
            {
                    int fnameLength=(currentline.find("(")-1)-(currentline.find(",")+2);
                    currentActor=currentline.substr(currentline.find(",")+2, fnameLength) + " " +
                                    currentline.substr(0, currentline.find(","));
            }
	    else if(currentline.find(",")==string::npos && currentline.find("(")!=string::npos)
	    {
		    currentActor=currentline.substr(0, currentline.find("(")-1);
	    }
            else if(currentline.find(",")!=string::npos)
            {
                currentActor=currentline.substr(currentline.find(",")+2) + " " +
                                currentline.substr(0, currentline.find(","));
            }
            else
                currentActor=currentline;
        }

        else if(currentline[0]=='\t')
            {
                //cout << " <<--<-MOVIE LINE" << endl; //Tracer code for debugging
                if(currentline[1]=='\"')
                {
                    currentMovie=currentline.substr(2, currentline.find("\"", 3)-2);
                }
                else
                {
                    currentMovie=currentline.substr(1, currentline.find("(", 2)-2);
                }

                for(int i=0; i<movies.size(); i++)
                {
                    if(movies[i]==currentMovie && currentActor!=name)
                    {
                        actress.push_back(currentActor);
                        break;
                    }
                }
            }
    }
    cout << "The following actresses costarred with " << name << "." << endl;
    for(int i=0; i<actress.size(); i++)
    {
        if(i==0 || actress[i]!=actress[i-1])
            cout << "* " << actress[i] << endl;
    }
    myfile.close();

    //Co-Star Actor search based on actress!
    vector<string> actor;
    myfile.open("actors.2010.list");
    currentActor=" ";
    currentMovie=" ";
    while(!myfile.eof())
    {
        string currentline;
        getline(myfile, currentline);
        if(currentline[0]!='\t' && !currentline.empty())
        {
            //cout << " <<--<-ACTOR/ACTRESS NAME"; //Tracer code for debugging.
            if(currentline.find(",")!=string::npos &&
                   currentline.find("(", currentline.find(","))!=string::npos)
            {
                    int fnameLength=(currentline.find("(")-1)-(currentline.find(",")+2);
                    currentActor=currentline.substr(currentline.find(",")+2, fnameLength) + " " +
                                    currentline.substr(0, currentline.find(","));
            }
	    else if(currentline.find(",")==string::npos && currentline.find("(")!=string::npos)
	    {
		    currentActor=currentline.substr(0, currentline.find("(")-1);
	    }
            else if(currentline.find(",")!=string::npos)
            {
                currentActor=currentline.substr(currentline.find(",")+2) + " " +
                                currentline.substr(0, currentline.find(","));
            }
            else
                currentActor=currentline;
        }

        else if(currentline[0]=='\t')
            {
                //cout << " <<--<-MOVIE LINE" << endl; //Tracer code for debugging
                if(currentline[1]=='\"')
                {
                    currentMovie=currentline.substr(2, currentline.find("\"", 3)-2);
                }
                else
                {
                    currentMovie=currentline.substr(1, currentline.find("(", 2)-2);
                }

                for(int i=0; i<movies.size(); i++)
                {
                    if(movies[i]==currentMovie && currentActor!=name)
                    {
                        actor.push_back(currentActor);
                        break;
                    }
                }
            }
    }
    cout << "\nThe following actors costarred with " << name << "." << endl;
    for(int i=0; i<actor.size(); i++)
    {
        if(i==0 || actor[i]!=actor[i-1])
            cout << "* " << actor[i] << endl;
    }
}

//////////////
//FIND ACTOR//
//////////////
void findActor(string name)
{
    ifstream myfile;
    myfile.open("actors.2010.list");
    vector<string> movies;
    vector<string> actor;

    while(!myfile.eof())
    {
        string currentline, currentActor=" ", currentMovie=" ";
        getline(myfile, currentline);
        if(currentline[0]!='\t' && !currentline.empty())
        {
            //cout << " <<--<-ACTOR/ACTRESS NAME"; //Tracer code for debugging.
            if(currentline.find(",")!=string::npos &&
                   currentline.find("(", currentline.find(","))!=string::npos)
            {
                    int fnameLength=(currentline.find("(")-1)-(currentline.find(",")+2);
                    currentActor=currentline.substr(currentline.find(",")+2, fnameLength) + " " +
                                    currentline.substr(0, currentline.find(","));
            }
	    else if(currentline.find(",")==string::npos && currentline.find("(")!=string::npos)
	    {
		    currentActor=currentline.substr(0, currentline.find("(")-1);
	    }
            else if(currentline.find(",")!=string::npos)
            {
                currentActor=currentline.substr(currentline.find(",")+2) + " " +
                                currentline.substr(0, currentline.find(","));
            }
            else
                currentActor=currentline;
        }

        if(name.compare(currentActor)==0)
        {
            //cout << "ACTOR FOUND!!  " << i << endl;
            do
            {
                getline(myfile, currentline);
                if(currentline[0]=='\t')
                {
                    //cout << " <<--<-MOVIE LINE" << endl; //Tracer code for debugging
                    if(currentline[1]=='\"')
                    {
                        currentMovie=currentline.substr(2, currentline.find("\"", 3)-2);
                    }
                    else
                    {
                        currentMovie=currentline.substr(1, currentline.find("(", 2)-2);
                    }
                }
                if(movies.empty()==true || movies[movies.size()-1]!=currentMovie)
                    movies.push_back(currentMovie);

            }while(!currentline.empty());
            break;
        }
    }
    myfile.close();

    myfile.open("actors.2010.list");
    string currentActor=" ", currentMovie=" ";
    while(!myfile.eof())
    {
        string currentline;
        getline(myfile, currentline);
        if(currentline[0]!='\t' && !currentline.empty())
        {
            //cout << " <<--<-ACTOR/ACTRESS NAME"; //Tracer code for debugging.
            if(currentline.find(",")!=string::npos &&
                   currentline.find("(", currentline.find(","))!=string::npos)
            {
                    int fnameLength=(currentline.find("(")-1)-(currentline.find(",")+2);
                    currentActor=currentline.substr(currentline.find(",")+2, fnameLength) + " " +
                                    currentline.substr(0, currentline.find(","));
            }
	    else if(currentline.find(",")==string::npos && currentline.find("(")!=string::npos)
	    {
		    currentActor=currentline.substr(0, currentline.find("(")-1);
	    }
            else if(currentline.find(",")!=string::npos)
            {
                currentActor=currentline.substr(currentline.find(",")+2) + " " +
                                currentline.substr(0, currentline.find(","));
            }
            else
                currentActor=currentline;
        }

        else if(currentline[0]=='\t')
            {
                //cout << " <<--<-MOVIE LINE" << endl; //Tracer code for debugging
                if(currentline[1]=='\"')
                {
                    currentMovie=currentline.substr(2, currentline.find("\"", 3)-2);
                }
                else
                {
                    currentMovie=currentline.substr(1, currentline.find("(", 2)-2);
                }

                for(int i=0; i<movies.size(); i++)
                {
                    if(movies[i]==currentMovie && currentActor!=name)
                    {
                        actor.push_back(currentActor);
                        break;
                    }
                }
            }
    }
    cout << "The following actors costarred with " << name << "." << endl;
    for(int i=0; i<actor.size(); i++)
    {
        if(i==0 || actor[i]!=actor[i-1])
            cout << "* " << actor[i] << endl;
    }
    myfile.close();

    //Co-star Actress search based on actor!
    myfile.open("actresses.2010.list");
    currentActor=" ";
    currentMovie=" ";
    vector<string> actress;
    while(!myfile.eof())
    {
        string currentline;
        getline(myfile, currentline);
        if(currentline[0]!='\t' && !currentline.empty())
        {
            //cout << " <<--<-ACTOR/ACTRESS NAME"; //Tracer code for debugging.
            if(currentline.find(",")!=string::npos &&
                   currentline.find("(", currentline.find(","))!=string::npos)
            {
                    int fnameLength=(currentline.find("(")-1)-(currentline.find(",")+2);
                    currentActor=currentline.substr(currentline.find(",")+2, fnameLength) + " " +
                                    currentline.substr(0, currentline.find(","));
            }
	    else if(currentline.find(",")==string::npos && currentline.find("(")!=string::npos)
	    {
		    currentActor=currentline.substr(0, currentline.find("(")-1);
	    }
            else if(currentline.find(",")!=string::npos)
            {
                currentActor=currentline.substr(currentline.find(",")+2) + " " +
                                currentline.substr(0, currentline.find(","));
            }
            else
                currentActor=currentline;
        }

        else if(currentline[0]=='\t')
            {
                //cout << " <<--<-MOVIE LINE" << endl; //Tracer code for debugging
                if(currentline[1]=='\"')
                {
                    currentMovie=currentline.substr(2, currentline.find("\"", 3)-2);
                }
                else
                {
                    currentMovie=currentline.substr(1, currentline.find("(", 2)-2);
                }

                for(int i=0; i<movies.size(); i++)
                {
                    if(movies[i]==currentMovie && currentActor!=name)
                    {
                        actress.push_back(currentActor);
                        break;
                    }
                }
            }
    }
    cout << "\nThe following actresses costarred with " << name << "." << endl;
    for(int i=0; i<actress.size(); i++)
    {
        if(i==0 || actress[i]!=actress[i-1])
            cout << "* " << actress[i] << endl;
    }
    myfile.close();
}
