/**********************************************************************
 Title:         : paing_AddressBook.cpp
 Author         : Ye Paing
 Created on     : 5/14/2012
 Description    : Sourcefile for paing_AddressBook.h
 Purpose        : Function definitions for paing_AddressBook.h
 Usage          : ./paing_main.exe "NAME_OF_CSV_FILE.txt"
 Build with     : g++ paing_main.cpp paing_Addressbook.cpp
                  paing_Contact.cpp -o paing_main.exe
 Modification   :
 **********************************************************************/
#include "paing_AddressBook.h"

/////////////////////
//contactValidate()//
/////////////////////
bool AddressBook::contactValidate(int v)
{
    //first four field checker
    if(data[v].getToken(1)=="" && data[v].getToken(2)==""
    && data[v].getToken(3)=="" && data[v].getToken(4)=="")
    {
        data.erase(data.begin()+v);
        return 0;
    }

    if(data[v].getToken(1)!="")
    {
        for(int i=0; i<data[v].getToken(1).length(); i++) //last name
        {
            if(isalpha(data[v].getToken(1)[i])==0 && data[v].getToken(1)[i]!='-')
            {
                //cout << "Error LAST NAME--> " << data[v].getToken(1) << endl;
                data.erase(data.begin()+v);
                return 0;
            }
        }//lname forloop ends
    }

    if(data[v].getToken(4)!="")
    {
        for(int i=0; i<data[v].getToken(2).length(); i++) //first name
        {
            if(isalpha(data[v].getToken(2)[i])==0 && data[v].getToken(2)[i]!='-')
            {
                //cout << "Error FIRST NAME--> " << data[v].getToken(2) << endl;
                data.erase(data.begin()+v);
                return 0;
            }
        }//fname forloop ends
    }


    if(data[v].getToken(4)!="")//email address 1
    {
        int symbol=0;
        for(int i=0; i<data[v].getToken(4).length(); i++)
        {
            if(data[v].getToken(4)[i]=='@')
            symbol++;
        }

        if(data[v].getToken(4)[0]=='@' || symbol!=1)
        {
            //cout << "Error EMAIL ADDRESS 1--> " << data[v].getToken(4) << endl;
            data.erase(data.begin()+v);
            return 0;
        }
    }//email address 1 check ends

    if(data[v].getToken(4)!=""&& data[v].getToken(5)!="")//email address 2
    {
        int symbol=0;
        for(int i=0; i<data[v].getToken(5).length(); i++)
        {
            if(data[v].getToken(5)[i]=='@')
            symbol++;
        }

        if(data[v].getToken(5)[0]=='@' || symbol!=1)
        {
            //cout << "Error EMAIL ADDRESS 2--> " << data[v].getToken(5) << endl;
            data.erase(data.begin()+v);
            return 0;
        }
    }//email address 2 check ends

    if(data[v].getToken(6)!="")//phone number 1
    {
        for(int i=0; i<data[v].getToken(6).length(); i++)
        {
            if(isdigit(data[v].getToken(6)[i])==0 && data[v].getToken(6)[i]!='('
                &&  data[v].getToken(6)[i]!=')' && data[v].getToken(6)[i]!='-')
            {
                //cout << "Error PHONE NUMBER 1--> " << data[v].getToken(6) << endl;
                data.erase(data.begin()+v);
                return 0;
            }

        }
    }//phone number 1 check ends

    if(data[v].getToken(6)!="" && data[v].getToken(7)!="")//phone number 2
    {
        for(int i=0; i<data[v].getToken(7).length(); i++)
        {
            if(isdigit(data[v].getToken(7)[i])==0 && data[v].getToken(7)[i]!='('
                    &&  data[v].getToken(7)[i]!=')' && data[v].getToken(7)[i]!='-')
            {
                //cout << "Error PHONE NUMBER 2--> " << data[v].getToken(7) << endl;
                data.erase(data.begin()+v);
                return 0;
            }

        }
    }//phone number 2 check ends
    
return 1; // all is well
}

///////////////
//buildData()//
///////////////
void AddressBook::buildData(int vector, string entry, int token)
{
    data[vector].setToken(entry, token);
}

/////////////
//getData()//
/////////////
string AddressBook::getData(int vector, int token)
{
    return data[vector].getToken(token);
}

///////////////
//pushTitle()//
///////////////
void AddressBook::pushTitle()
{
    Contact buffer;
    data.push_back(buffer);
    data[0].setTitle();
}

///////////
//iPush()//
///////////
void AddressBook::iPush()
{
    Contact buffer;
    data.push_back(buffer);
}

/////////////////
//printDetail()//
/////////////////
void AddressBook::printDetail(int entry)
{
    cout << "\n----------------------DETAILED VIEW----------------------" << endl
         << data[0].getToken(1) << "    " << data[entry].getToken(1) << endl
         << data[0].getToken(2) << "   " << data[entry].getToken(2) << endl
         << data[0].getToken(3) << "     " << data[entry].getToken(3) << endl
         << data[0].getToken(4) << "      " << data[entry].getToken(4) << endl
         << data[0].getToken(5) << "      " << data[entry].getToken(5) << endl
         << data[0].getToken(6) << "      " << data[entry].getToken(6) << endl
         << data[0].getToken(7) << "      " << data[entry].getToken(7) << endl
         << data[0].getToken(8) << "      " << data[entry].getToken(8) << endl
         << data[0].getToken(9) << "      " << data[entry].getToken(9) << endl
         << data[0].getToken(10) << "     " << data[entry].getToken(10) << endl
         << data[0].getToken(11) << "        " << data[entry].getToken(11) << endl
         << "---------------------------------------------------------" << endl;
}

//////////////////
//printPreview()//
//////////////////
void AddressBook::printPreview()
{
    cout << "-----------------------------PREVIEW-------------------------------" << endl
         << "#  Last:        First:       Nickname:    Email:       Phone:      " << endl;
    for(int i=1; i<data.size(); i++)
    {
        cout << i << "  "
             << left << setw(13) << data[i].getToken(1).substr(0,12)
             << left << setw(13) << data[i].getToken(2).substr(0,12)
             << left << setw(13) << data[i].getToken(3).substr(0,12)
             << left << setw(13) << data[i].getToken(4).substr(0,12)
             << left << setw(13) << data[i].getToken(6).substr(0,12) << endl;
    }
}

///////////////
//functionA()//
///////////////
void AddressBook::functionA()
{
    Contact buffer;
    char input[140], empty[]="";
    //Program will only take the first 140 characters of the user input.
    
    cin.ignore(1);
    //Ignore the \n character left in the stream used to select option A in main()

    cout << "Adding a new contact..." << endl
         << "Enter Last Name:";
    cin.getline(input, 140);
    buffer.setToken(input, 1);

    cout << "Enter First Name:";
    cin.getline(input, 140);
    buffer.setToken(input, 2);

    cout << "Enter Nickname:";
    cin.getline(input, 140);
    buffer.setToken(input, 3);

    cout << "Enter Email 1:";
    cin.getline(input, 140);
    buffer.setToken(input, 4);

    if(strcmp(input,empty)!=0)
    {
        cout << "Enter Email 2:";
        cin.getline(input, 140);
        buffer.setToken(input, 5);
    }

    else
        buffer.setToken(" ", 5);

    cout << "Enter Phone 1:";
    cin.getline(input, 140);
    buffer.setToken(input, 6);

    if(strcmp(input,empty)!=0)
    {
        cout << "Enter Phone 2:";
        cin.getline(input, 140);
        buffer.setToken(input, 7);
    }

    else
        buffer.setToken(" ", 7);

    cout << "Enter Address:";
    cin.getline(input, 140);
    buffer.setToken(input, 8);

    cout << "Enter Website:";
    cin.getline(input, 140);
    buffer.setToken(input, 9);

    cout << "Enter Birthday:";
    cin.getline(input, 140);
    buffer.setToken(input, 10);

    cout << "Enter Notes:";
    cin.getline(input, 140);
    buffer.setToken(input, 11);

    data.push_back(buffer);
}

///////////////
//functionD()//
///////////////
void AddressBook::functionD(int token)
{
    while(checkSortedList(token)==0)
    {
        for(int i=1; i<data.size()-1; i++)
        {
            if(data[i].getToken(token) > data[i+1].getToken(token))
            {
                Contact buffer[1];
                buffer[0]=data[i];
                data[i]=data[i+1];
                data[i+1]=buffer[0];
            }
        }
    }

}

///////////////
//functionF()//
///////////////
void AddressBook::functionF(int token, string keyword)
{
    cout << "Your search results for keyword:[" << keyword << "]" << endl;
    cout << "-----------------------------PREVIEW-------------------------------" << endl
         << "#  Last:        First:       Nickname:    Email:       Phone:      " << endl;
    for(int i=1; i<data.size(); i++)
    {
        int found=-1;
        found=data[i].getToken(token).rfind(keyword);

        if(found>=0)
        {
        cout << i << "  "
             << left << setw(13) << data[i].getToken(1).substr(0,12)
             << left << setw(13) << data[i].getToken(2).substr(0,12)
             << left << setw(13) << data[i].getToken(3).substr(0,12)
             << left << setw(13) << data[i].getToken(4).substr(0,12)
             << left << setw(13) << data[i].getToken(6).substr(0,12) << endl;
             found=-1;
        }
    }
}

///////////////
//functionR()//
///////////////
void AddressBook::functionR(int remove)
{
    data.erase(data.begin()+remove);
}

///////////////
//functionM()//
///////////////
void AddressBook::functionM(int index)
{
    Contact buffer;
    char input[140], empty[]="";
    cin.ignore(1);

    cout << "Enter Last Name:";
    cin.getline(input, 140);
    buffer.setToken(input, 1);

    cout << "Enter First Name:";
    cin.getline(input, 140);
    buffer.setToken(input, 2);

    cout << "Enter Nickname:";
    cin.getline(input, 140);
    buffer.setToken(input, 3);

    cout << "Enter Email 1:";
    cin.getline(input, 140);
    buffer.setToken(input, 4);

    if(strcmp(input,empty)!=0)
    {
        cout << "Enter Email 2:";
        cin.getline(input, 140);
        buffer.setToken(input, 5);
    }

    else
        buffer.setToken(" ", 5);

    cout << "Enter Phone 1:";
    cin.getline(input, 140);
    buffer.setToken(input, 6);

    if(strcmp(input,empty)!=0)
    {
        cout << "Enter Phone 2:";
        cin.getline(input, 140);
        buffer.setToken(input, 7);
    }

    else
        buffer.setToken(" ", 7);

    cout << "Enter Address:";
    cin.getline(input, 140);
    buffer.setToken(input, 8);

    cout << "Enter Website:";
    cin.getline(input, 140);
    buffer.setToken(input, 9);

    cout << "Enter Birthday:";
    cin.getline(input, 140);
    buffer.setToken(input, 10);

    cout << "Enter Notes:";
    cin.getline(input, 140);
    buffer.setToken(input, 11);

    data.push_back(buffer);

    if(contactValidate(data.size()-1)==1)
    {
        cout << "\nContact modified!!" << endl;
        data[index]=data[data.size()-1];
        data.pop_back();
    }

    else
    {
        cout << "\nInvalid modification, contact remains unchanged!" << endl;

    }
}

/////////////////////
//checkSortedList()//
/////////////////////
bool AddressBook::checkSortedList(int token)
{
    for(int i=1; i<data.size()-1; i++)
    {
        if(data[i].getToken(token) > data[i+1].getToken(token))
            return 0; //if this if statement passes, there is swap to be done, return 0.
    }
    return 1; //return 1 when there is no swap needs to be done.
}

////////////////
//vectorSize()//
////////////////
int AddressBook::vectorSize()
{
    return data.size();
}
