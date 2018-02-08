#include<iostream>
// #include"transaction.h"
// #include"balance.h"
#include"date.h"
#include"balance.h"

using namespace std;

class BALANCE_LIST
{
	BALANCE list[100];
	int count;

public:
	BALANCE_LIST()
	{
		count=0;
	}
	//Function to get total number
	int getCount()
	{
		return count;
	}
	//Function to add new account
	void addAccount()
	{
		double amount;
		BALANCE b(10000+count);
		do
		{
			cout<<"Enter amount to deposit"<<endl;
			cin>>amount;
			if(amount<=0)
				cout<<"Invalid amount"<<endl;
		}
		while(amount<=0);
		b.setBalance(amount);
		Date d;
		b.setDate(d);
		cout<<"Your account details are "<<endl;
		b.show();
		list[count++]=b;
		cout<<"Account successfully added"<<endl;
	}

	//Function to check whether a ac_no is in list
	int getAcno(int ano)
	{
		int i,flag=0;
		for(i=0;i<count;i++)
		{
			if(list[i].get_ac_no()==ano)
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

	//For transaction
	int transactionWithAcno(int ano)
	{
		if(getAcno(ano)==-1)
		{
			cout<<"Invalid account number"<<endl;
			return 0;
		}
		TRANSACTION temp(ano);
		temp.transact(list[getAcno(ano)]);
		return 1;
	}

	//Get details of an account
	void dispDetails(int ano)
	{
		list[getAcno(ano)].show();
	}

};

int main()
{
	int ch,acno;
	BALANCE_LIST lst;
	do
	{
		cout<<"1. Add new account"<<endl<<"2. Transact with existing account"<<endl<<"3. Details of an account"<<endl<<"4. Exit"<<endl<<"Enter choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			lst.addAccount();
			break;

			case 2:
			if(lst.getCount()==0)
			{
				cout<<"Add some new account first"<<endl;
				break;
			}
			do
			{
				cout<<"Enter account number"<<endl;
				cin>>acno;
				if(lst.getAcno(acno)==-1)
					cout<<"Invalid account number..Re-enter"<<endl;
			}
			while(lst.getAcno(acno)==-1);
			lst.transactionWithAcno(acno);
			break;

			case 3:
			if(lst.getCount()==0)
			{
				cout<<"Add some new account first"<<endl;
				break;
			}
			do
			{
				cout<<"Enter account number"<<endl;
				cin>>acno;
				if(lst.getAcno(acno)==-1)
					cout<<"Invalid account number..Re-enter"<<endl;
			}
			while(lst.getAcno(acno)==-1);
			lst.dispDetails(acno);
			break;

			case 4:
			cout<<"Quitting"<<endl;
			exit(0);

			default:
			cout<<"Invalid choice"<<endl;
		}
		

	}
	while(ch!=4);
}