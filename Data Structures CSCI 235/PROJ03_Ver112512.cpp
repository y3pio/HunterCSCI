//Find function for new Queue using queue nodes
Node* Queue::find(int pos)
{
	if(pos<1 || pos>nOfPassengers)
		throw "ErrorFindQueue"
	else
	{
		QueueNode* temp=head;
		for(int i=1; i<pos; i++)
		{
			temp = temp->next;
		}
		return temp;
	}
}

//Increase wait time for Queue using queue nodes
void Queue::IncreaseWaitTime()
{
	if(!isEmpty())
	{
		
	}	
}

//NOTES FOR STATION
//Start from the bottom;
