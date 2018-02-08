#ifndef TRANSACTIONH
#define TRANSACTIONH

#include<iostream>
#include"balance.h"
using namespace std;
//Class to define a transaction
class BALANCE;
class TRANSACTION
{
	int ac_no;
	int type;//1- withdrawal 0-deposit
	Date d;
	double amount;

public:
	TRANSACTION(int ano=0)
	{
		ac_no=ano;
		type=-1;
		amount=0.0;
		Date dt;
		d=dt;
	}

	void transact(BALANCE& b)
	{
		do
		{
			cout<<"Enter type of transaction"<<endl<<"0. Deposit"<<endl<<"1. Withdrawal"<<endl;
			cin>>type;
			if(type!=0 && type!=1)
				cout<<"Invalid choice"<<endl;
		}
		while(type!=0 && type!=1);

		do
		{
			cout<<"Enter amount"<<endl;
			cin>>amount;
			if(amount<=0)
				cout<<"Invalid amount"<<endl;
		}
		while(amount<=0);

		if(type==0)
			deposit(b,amount);
		else
			withdraw(b,amount);
	}

	//Function to withdraw
	void withdraw(BALANCE& b,double amt)
	{
		if(b.getBalance()<amt)
			cout<<"Insufficient balance"<<endl;
		else
		{
			Date d;
			b.setBalance(b.getBalance()-amt);
			b.setDate(d);
			amount=amt;
			cout<<"Withdrawal successfull"<<endl;
			cout<<"==============================="<<endl;
			display();
			cout<<"==============================="<<endl;
		}
	}

	//Function to deposit
	void deposit(BALANCE& b, double amt)
	{
		Date d;
		b.setBalance(b.getBalance()+amt);
		b.setDate(d);
		amount=amt;
		cout<<"Deposit successfull"<<endl;
		cout<<"==============================="<<endl;
		display();
		cout<<"==============================="<<endl;
	}

	//Function to display a transaction
	void display()
	{
		cout<<"TRANSACTION DETAILS"<<endl;
		string ty=(type==0)?"Deposit":"Withdrawal";
		cout<<"Account number: "<<ac_no<<endl<<"Date: "<<d<<"Type: "<<ty<<endl<<"Amount: "<<amount<<endl;
	}

};

#endif