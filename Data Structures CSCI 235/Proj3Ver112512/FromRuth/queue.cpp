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


class Queue
{
      private:
              node* first;
              node* last;
              int size;
              
      public:
             Queue();
             void enqueue(Passenger item);
             Passenger dequeue();
             Passenger getFront();
             bool isEmpty();
};
 
            
Queue::Queue()
{
                 first=NULL;
                 last=NULL;
                 size=0;
}

                              
void Queue::enqueue(Passenger item)
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
     catch(...){}          
}

         
Passenger Queue::dequeue()
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

main()
{

 	Passenger sarah;
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
			
                       sarah=q.getFront();
			cout<<sarah.destination<<endl;
                         q.dequeue();
      }
      
                           
return 0;
}
