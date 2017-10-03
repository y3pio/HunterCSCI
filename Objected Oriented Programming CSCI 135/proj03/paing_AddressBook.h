/**********************************************************************
 Title:         : paing_AddressBook.h
 Author         : Ye Paing
 Created on     : 5/14/2012
 Description    : Header file for Class AddressBook
 Purpose        : Stores objects of class Contact and other functions
 Usage          :
 Build with     :
 Modification   :
 **********************************************************************/
#ifndef PAING_ADDRESSBOOK_H
#define PAING_ADDRESSBOOK_H
#include "paing_Contact.h"


class AddressBook
{
    public:
            bool contactValidate(int v);
            //PreCondition: Function is called whenever ALL contact objects need to be validated.
            //PostCondition: Checks if each element is a valid contact entry. Erase it if it's not.
	    //WARNING Calling this function WILL DELETE upon call if vector v is invalid, use with caution!

            void buildData(int vector, string entry, int token);
	    //PreCondition: Function takes in vector of contact to build, the string and its respective token (field).
	    //PostCondition: Builds the contact field. This function is mainly used in extracting tokens from CSV file.
	    //NOTE* This works as an accessor function.

            string getData(int vector, int token);
            //PreCondition: Takes in a vector (contact entry) its token (field).
            //PostCondition: Simply returns the desired contents of the field.
	    //NOTE* This works as an accessor function.

            void pushTitle();
	    //PreCondition: Used only at the start of the program.
            //PostCondition: This function is used mainly at the start of the progrma to push a "Title Line" to
	    //		     the start of the address book.
           
            void iPush();
	    //PreCondition: Used during the token extraction phase of the program. 
            //PostCondition: Pushes back a line based on index i which is basically the # of lines (contacts) extracted.

            void printDetail(int entry);
	    //PreCondition: Takes in integer entry which is the index of the vector in Contact
	    //PostCondition: Prints a detialed view of the desired contact based upon the given index (entry)

            void printPreview();
	    //PreCondition: Called whenever preview is needed to be display.
            //PostCondition: Simply displays the entire address book of contacts in preview view.

		//////////////////////////////////////////////////////////////////////////////////
		//Option Functions!!Some are not included as they are coded directly into main()//
		//////////////////////////////////////////////////////////////////////////////////
            void functionA();
	    //PreCondition: Call whenever option A is selected by user to add contact.
	    //PostCondition: Validates and adds user created contact. Does not add if contact is invalid.

            void functionD(int token);
	    //PreCondition: Takes in a token (field) to sort. (valid fields 1-4)
	    //PostCondition: Contact list is sorted and displayed in preview view.

            void functionR(int remove);
	    //PreCondition: Takes in contact index (int remove) to remove.
	    //PostCondition: Confirms y/n with user then removes (or not) accordingly.

            void functionF(int token, string keyword);
	    //PreCondition: Takes in a token (field) and keyword to look for within the desired field.
	    //PostCondition: Displays in preview view all the contact entry with fields that have matching keyword.

            void functionM(int index);
	    //PreCondition: Takes in an index (contact index) to modify.
	    //PostCondition: After validating new data from user, modifies index if data is valid, else no chage.

            bool checkSortedList(int token);
	    //PreCondition: Takes in a token (field) to check if entire vector list is sorted according to field.
	    //PostCondition: Returns 0 if sorting needs to be done, 1 if it's sorted.

            int vectorSize();
	    //PreCondition: Use this whenever you need to check contact vector size INSIDE OF MAIN()
	    //PostCondition: Returns the size of contact list stored in "vector<Contact> data"

    private:
            vector<Contact> data;
	    //Create the vector object to store contacts inside of the address book.

};

#endif
