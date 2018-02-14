#include<iostream>

using namespace std;

//Class to define a node
class Node
{
	int value;
	int priority;
	Node* next;

public:
	//Constructor
	Node(int v=0,int p=0)
	{
		value=v;
		priority=p;
		next=NULL;
	}
	//Function to display a node
	void displayNode()
	{
		cout<<"Value: "<<value<<"\tPriority: "<<priority<<endl;
	}
	friend class priorityQueue;
};


class priorityQueue
{
	Node* head;

public:
	priorityQueue()
	{
		head=NULL;
	}

	//Function to push an element
	void enqueue(int v,int p)
	{
		Node* n;
		n=new Node;
		n->value=v;
		n->priority=p;
		//If head has lower priority
		if(head!=NULL)
		{
			if(head->priority<p)
			{
				n->next=head;
				head=n;
			}
			else
			{
				Node* temp=head;
				while((temp->next!=NULL) && (temp->next->priority)>=p)
				{
					temp=temp->next;
				}
				n->next=temp->next;
				temp->next=n;
			}
		}
		else
		{
			head=n;
		}

	}

	//Function to pop an element
	void dequeue()
	{
		Node* temp=head;
		cout<<"Node being deleted is: ";
		temp->displayNode();
		head=head->next;
		free(temp);
	}

	//Function to see the head element
	int peek()
	{
		return head->value;
	}

	//Function to display the entire queue
	void display()
	{
		Node* temp;
		temp=head;
		cout<<"==================================================\n";
		while(temp!=NULL)
		{
			temp->displayNode();
			temp=temp->next;
		}
		cout<<"===================================================\n";
	}
};

int main()
{
	int ch,c=0;
	int v,p;
	priorityQueue queue;
	do
	{
		cout<<"1. Enter elements into priority queue"<<endl<<"2. Pop highest priority element"<<endl<<"3. Display entire queue"<<endl<<"4. Exit"<<endl<<"Enter choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			cout<<"Enter a value and its priority"<<endl;
			cin>>v;
			cin>>p;
			c++;
			queue.enqueue(v,p);
			break;

			case 2:
			if(c==0)
			{
				cout<<"Queue empty"<<endl;
				break;
			}
			queue.dequeue();
			c--;
			break;

			case 3:			
			if(c==0)
			{
				cout<<"Queue empty"<<endl;
				break;
			}
			queue.display();
			break;

			case 4:
			cout<<"Exitting"<<endl;
			break;

			default:
			cout<<"Invalid choice"<<endl;

		}
		
	}
	while(ch!=4);
	return 0;
}

