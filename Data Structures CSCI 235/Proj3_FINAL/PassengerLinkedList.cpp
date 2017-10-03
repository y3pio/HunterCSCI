/************************************************************************
 Title         : PassengerLinkedList.cpp
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : Defines the functions for PassengerLinkedList
 Purpose       : cars on trains are portrayed as PassengerLinkedLists, 
		 so these functions define hoe passengers get on and off of
		 trains.
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/

#include "PassengerLinkedList.h"
#include <iostream>
using namespace std;
#include <string>

PassengerLinkedList::PassengerLinkedList(){
    size=0;
    head=new ListNode();
}

PassengerLinkedList::~PassengerLinkedList()
{
	while(!isEmpty())
		remove(1);
}

ListNode* PassengerLinkedList::find(int pos){
    if(pos<1 || pos>size){
        return NULL;
    }
    else {
        ListNode * temp = head;
        for(int i=1; i<pos; i++){
            temp = temp -> next;
        }
        return temp;
    }
}


bool PassengerLinkedList::isEmpty(){
    if(size==0)
        return true;
    return false;
}

int PassengerLinkedList::getLength(){
    return size;
}

void PassengerLinkedList::insert(int pos, Passenger item){
    if(pos<1 || pos >size+1)
        throw 1;
    ListNode * current = new ListNode();
    current->data = item;
    if(pos==1){
        current->next=head;
        head=current;
        size++;
    }
    else{
        ListNode * prev = find(pos-1);
        current -> next = prev -> next;
        prev -> next = current;
        size ++;
    }
}

Passenger PassengerLinkedList::remove(int pos){
    if(pos<1 || pos>size)
        throw 1;
    Passenger data;
    ListNode*current;
    if(pos==1){
        current=head;
        head=head->next;
    }
    else{
        ListNode*prev = find(pos-1);
        current=prev->next;
        prev->next=current->next;
    }
    data = current->data;
    delete current;
    current = NULL;
    size--;
    return data;
}

Passenger PassengerLinkedList::retrieve(int pos){
    ListNode* current=find(pos);
    return current -> data;
}

Passenger PassengerLinkedList::findPass(int pos)
{
    //kind of a redundant version of retreive.
    if(pos<1 || pos>size)
        throw 1;
    Passenger data;
    ListNode*current;
    if(pos==1){
        current=head;
    }
    else{
        ListNode*prev = find(pos-1);
        current=prev->next;
    }
    data = current->data;
    return data;
}
