#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class Item
{
	string code;
	string name;
	double rate;
	int qty;

public:
	//Parametrized constructor
	Item(string c="",string n="", double r=0.0,int q=0)
	{
		code=c;
		name=n;
		rate=r;
		qty=q;
	}

	//Setters
	//Function to change the rate of an item
	void setRate(double r)
	{
		rate=r;
	}
	//Function to set qquantity of an item
	void setQty(int q)
	{
		qty=q;
	}

	//Getters
	//Function to return quantity
	int getQty()
	{
		return qty;
	}
	//Fucntion to return rate
	double getRate()
	{
		return rate;
	}
	//Function to get the code of item
	string getCode()
	{
		return code;
	}
};

class ItemList
{
	Item list[100];
public:
	static int count;

public:
			//Function to check if an item code is already in the list
	int isPresent(string c)
	{
		int i,flag=0;
		for(i=0;i<count;i++)
		{
			if(list[i].getCode()==c)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			return i;
		else
			return -1;
	}
		//Function to add a new item
	void addItem(Item i)
	{
		if(isPresent(i.getCode())!=-1)
			cout<<"Item already present in list";
		else
		{
			list[count++]=i;
			cout<<"Item successfully added"<<endl;
		}
	}
		//Function to change the rate of item given the item code
	void changeRate(double r,string c)
	{	
		int i=isPresent(c);
		if(i!=-1)
		{
			if(list[i].getCode()==c)
			{
				list[i].setRate(r);
			}
		}
	}
		//Function to change quantity
	void changeQty(int q,string c)
	{	
		int i=isPresent(c);
		if(i!=-1)
		{
			if(list[i].getCode()==c)
			{
				list[i].setQty(q+list[i].getQty());
			}
		}
	}
		//Function to issue item
	void issueItem()
	{
		int q;
		string c;
		cout<<"Enter item code of item to be delivered"<<endl;
		cin>>c;
		int i=isPresent(c);
		if(i==-1)
			cout<<"Item is not present"<<endl;
		else
		{
			do
			{
				do
				{
					cout<<"Enter quantity of item to be delivered"<<endl;
					cin>>q;
					if(q<=0)
						cout<<"Invalid quantity"<<endl;
				}
				while(q<=0);
				if(list[i].getQty()<q)
					cout<<"Not enough quantity"<<endl;
			}
			while(list[i].getQty()<q);
			
			
			cout<<"Your total amount is "<<(list[i].getRate()*list[i].getQty())<<endl;
			list[i].setQty(list[i].getQty()-q);
			

		}
	}
		//Function to display price or quantity
	void display(string c)
	{
		int i=isPresent(c);
		if(i==-1)
			cout<<"Item is not present"<<endl;
		else
		{
			cout<<"The rate of the item is: "<<list[i].getRate()<<endl<<"The quantity of the item is: "<<list[i].getQty()<<endl; 
		}
	}

};
int ItemList::count=0;

int main()
{
	int ch;
	ItemList l1;
	string n,c;
	double r;
	int q,flag;
	do
	{
		cout<<"1. Add new item"<<endl<<"2. Issue item"<<endl<<"3. Update price of item"<<endl<<"4. Update quantity of item"<<endl<<"5. Check availability and price of an item"<<endl<<"6. Exit"<<endl<<"Enter choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				do
				{
					flag=0;
					cout<<"Enter item code of new item"<<endl;
					cin>>c;
					if(l1.isPresent(c)!=-1)
					{
						cout<<"Item already present"<<endl;
						flag=1;
					}
					else
					{
						cout<<"Enter name of new item"<<endl;
						cin>>n;
						do
						{
							cout<<"Enter rate of new item"<<endl;
							cin>>r;
							if(r<=0)
								cout<<"Invalid rate"<<endl;
						}
						while(r<=0);

						do
						{
							cout<<"Enter quantity of new item"<<endl;
							cin>>q;
							if(q<=0)
								cout<<"Invalid quantity"<<endl;
						}
						while(q<=0);

						Item i(c,n,r,q);
						l1.addItem(i);
					}
				}
				while(flag==1);
				break;
			}

			case 2:
			l1.issueItem();
			break;

			case 3:
			{
				cout<<"Enter item code of item"<<endl;
				cin>>c;
				if(l1.isPresent(c)==-1)
					cout<<"Item not present"<<endl;
				else
				{
					do
					{
						cout<<"Enter rate of new item"<<endl;
						cin>>r;
						if(r<=0)
							cout<<"Invalid rate"<<endl;
					}
					while(r<=0);
					l1.changeRate(r,c);
				}
			}
			break;

			case 4:
			{
				cout<<"Enter item code of item"<<endl;
				cin>>c;
				if(l1.isPresent(c)==-1)
					cout<<"Item not present"<<endl;
				else
				{

					do
					{
						cout<<"Enter extra quantity of item to be added"<<endl;
						cin>>q;
						if(q<=0)
							cout<<"Invalid input"<<endl;
					}
					while(q<=0);
					l1.changeQty(q,c);
				}
				break;
			}

			case 5:
			{
				cout<<"Enter item code of item"<<endl;
				cin>>c;
				l1.display(c);
				break;
			}

			case 6:
			cout<<"Exitting"<<endl;
			exit(0);

			default:
			cout<<"Invalid choice"<<endl;
		}
	}
	while(ch!=6);
	return 0;
}