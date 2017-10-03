# include <iostream>
using namespace std;


struct Passenger
{

		string destination;
		int startingTime;
		int waitTime1;
		int waitTime2;
		bool beenOnTrain;
		int totalTime;
		
};




struct node
{
      Passenger data;
       node* next;
       
};


class queue
{
      private:
              node* first;
              node*last;
              int size;
              
      public:
             queue();
	     ~queue();
             void enqueue(Passenger item);
             Passenger dequeue();
             Passenger getFront();
             bool isEmpty();
	     node* find(int pos);
		
};

 
            
queue::queue()
{
                 first=NULL;
                 last=NULL;
                 size=0;
}

queue::~queue()
{
	while(!isEmpty())
	{
		dequeue();
	}

}
		
                              
void queue::enqueue(Passenger item)
{
    try{
     node* curr= new node;
     curr->data=item;
     curr->next=NULL;
     
     if(first==NULL)
     {
     
                    first=last=curr;
     }
     else
     {
         last->next=curr;
         last=curr;
         
     }
     size++;
     }
     catch(...)
     {
     }          
}

         
Passenger queue::dequeue()
{
     
     if(size==0)
     {
                throw -1;
     }
                     
      try{
                     node* curr;
                     Passenger item;
                     item=first->data;
                     curr=first;
                     first=first->next;
                     if(first==NULL)
                     {
                        last=NULL;
                     }
                     delete curr;
                     curr=NULL;
                     size--;
                     return item;
      }
      catch(...)
      {
                
      }
}


     
bool queue::isEmpty()
{
     if(first==NULL)
       return true;
     
     else
      return false;
}      

                        
Passenger queue::getFront()
{
                      if(isEmpty())
                        throw -1;
                        
                       return first->data;
}


node* queue::find(int pos)
{
	//if the position is grater than the size of the queue,
       // or less than 1 the position will be thrown to exceptions
       if(pos>size || pos<1)
       		throw pos;
          
	//Temp is pointing to were head points to- to the first position
        node* temp=first;
          
	for(int i=1; i<pos;i++)
        {
        	//temp is set to point on the next structure in line. 
                temp=temp->next;
        }
          
	//temp is pointing to the position desired 
        return temp;
}


	


main()
{

 	node* sarah;
	 Passenger ruth;
	  Passenger ettie;


		
		
      queue q;
     
      
      
     
                     cout<<"enter a destination "<<endl;
			cin>>ruth.destination;
			cout<<endl;
			cout<<"enter a startingTime"<<endl;
			cin>>ruth.startingTime;
			 cout<<"enter a destination "<<endl;
			cin>>ettie.destination;
			cout<<endl;
			cout<<"enter a startingTime"<<endl;
			cin>>ettie.startingTime;
			cout<<endl;
                     	cout<<endl;
                     	q.enqueue(ruth);
			q.enqueue(ettie);
                  
   
      
      while(!q.isEmpty())
      {
			
                       sarah=q.find(1);
			cout<<sarah->data.destination<<endl;
                         q.dequeue();
      }
      
                           
return 0;
}
