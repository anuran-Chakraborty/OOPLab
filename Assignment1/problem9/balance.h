#ifndef BALANCEH
#define BALANCEH

#include<iostream>
#include"transaction.h"
using namespace std;
//Class for balance
class TRANSACTION;

class BALANCE
{
	int ac_no;
	Date last_update;
	double balance;
	TRANSACTION t[100];

public:
	BALANCE(int ano=0)
	{
		ac_no=ano;
		Date d;
		last_update=d;
		balance=0.0;
	}

	//Function to set balance
	void setBalance(double b)
	{
		balance=b;
	}
	//Function to get balance
	double getBalance()
	{
		return balance;
	}
	//Fucntion to set date
	void setDate(Date dd)
	{
		last_update=dd;
	}
	//Function to get account no
	int get_ac_no()
	{
		return ac_no;
	}
	//function to show details
	void show()
	{
		cout<<endl<<"Account number: "<<ac_no<<endl<<"Date of last update: "<<last_update<<"Balance: "<<balance<<endl<<endl;
	}


};
#endif