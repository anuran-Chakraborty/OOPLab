#include<iostream>
#include<string>

using namespace std;

class ItemList;
//Class which stores the details of each item
class Item
{
	string code;
	string name;
	double rate;
	int qty;

public:
		//Paramnetrized constructor
	Item(string c,string n, double r,int q)
	{
		code=c;
		name=n;
		rate=r;
		qty=q;
	}
	// 	//Function to change the rate of an item
	// void setRate(double r)
	// {
	// 	rate=r;
	// }
	// 	//Function to set qquantity of an item
	// void setQty(int q)
	// {
	// 	qty=q;
	// }
	// 	//Fucntion to return quantity
	// int getQty()
	// {
	// 	return qty;
	// }
	// 	//Fucntion to return rate
	// double getRate()
	// {
	// 	return rate;
	// }
	
	friend int ItemList::isPresent(string c);
	friend void ItemList::addItem(Item i);
	friend void ItemList::changeRate(double r,string c);
	friend void ItemList::issueItem();
	friend void ItemList::display(string c);

}

//Class to store an item list
class ItemList
{
	Item list[100];
	static int count;

public:
		//Function to check if an item code is already in the list
	int isPresent(string c);;
		//Function to add a new item
	void addItem(Item i);
		//Function to change the rate of item given the item code
	void changeRate(double r,string c);
	//Function to change quantity
	void changeQty(int q,string c);

	//Function to issue item
	void issueItem();

	//Function to display price or quantity
	void display(string c);


}
ItemList::count=0;

int ItemList::isPresent(string c)
{
	int i,flag=0;
	for(i=0;i<count;i++)
	{
		if(list[i].code==c)
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
void ItemList::addItem(Item i)
{
	if(isPresent(i.code)!=-1)
		cout<<"Item already present in list";
	else
	{
		list[count++]=i;
		cout<<"Item successfully added"<<endl;
	}
}
		//Function to change the rate of item given the item code
void ItemList::changeRate(double r,string c)
{	
	int i=isPresent(c);
	if(i!=-1)
	{
		if(list[i].code==c)
		{
			list[i].rate=r;
		}
	}
}

	//Function to change quantity
void ItemList::changeQty(int q,string c)
{	
	int i=isPresent(c);
	if(i!=-1)
	{
		if(list[i].code==c)
		{
			list[i].qty=q;
		}
	}
}

	//Function to issue item
void ItemList::issueItem()
{
	int q;
	string c;
	cout<<"Enter item code of item to be delivered"<<endl;
	cin>>c;
	int i=isPresent(c);
	if(i==-1)
		cout<<"Item is not present";
	else
	{
		cout<<"Enter qunatity of item to be delivered"<<endl;
		cin>>q;
		if(list[i].qty<q)
			cout<<"Not enough quantity"<<endl;
		else
		{
			cout<<"Your total amount is "<<(list[i].rate*list[i].qty)<<endl;
			list[i].qty-=q;
		}

	}
}

	//Function to display price or quantity
void ItemList::display(string c)
{
	int i=isPresent(c);
	if(i==-1)
		cout<<"Item is not present"<<endl;
	else
	{
		cout<<"The rate of the item is: "<<list[i].rate<<endl<<"The quantity of the item is: "<<list[i].qty<<endl; 
	}
}


void main()
{
	int ch;
	ItemList l1;
	string c n,c;
	double r;
	int q;
	do
	{
		cout<<"1. Add new item"<<endl<<"2. Issue item"<<endl<<"3. Update price of item"<<endl<<"4. Update quantity of item"<<endl<<"5. Check availability and price of an item"<<endl<<"6. Exit"<<endl<<"Enter choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"Enter item code of new item"<<endl;
			cin>>c;
			cout<<"Enter name of new item"<<endl;
			cin>>n;
			cout<<"Enter rate of new item"<<endl;
			cin>>r;
			cout<<"Enter quantity of new item"<<endl;
			cin>>q;
			Item i(c,n,r,q);
			l1.addItem(i);

			break;

			case 2:
			issueItem();
			break;

			case 3:
			cout<<"Enter item code of item"<<endl;
			cin>>c;
			cout<<"Enter new rate of item"<<endl;
			cin>>r;
			changeRate(r,c);
			break;

			case 4:
			cout<<"Enter item code of item"<<endl;
			cin>>c;
			cout<<"Enter quantity of new item"<<endl;
			cin>>q;
			changeQty(c,q);
			break;

			case 5:
			cout<<"Enter item code of item"<<endl;
			cin>>c;
			display(c);

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