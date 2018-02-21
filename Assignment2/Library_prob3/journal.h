#include<iostream>
#include<fstream>

using namespace std;

//Class to store journal details
class Journal
{
	int id;
	string name;
	Date doi;
	int vol;
	int qty;

public:
	//Constructor
	Journal(int i,string n,Date d,int v,int q=0)
	{
		id=i;
		name=n;
		doi=d;
		vol=v;
		qty=q;
	}
	//Function to return id
	int get_id_j()
	{
		return id;
	}

	//Function to get quantity
	int get_qty_j()
	{
		return qty;
	}

	//Function to issue a journal
	void issue_j()
	{
		copies--;
	}

	//Function to return a journal
	void return_j()
	{
		copies++;
	}

	//Function to display journal details
	void display_j()
	{
		cout<<id<<"\t"<<name<<"\t"<<doi<<"\t"<<vol<<"\t"<<qty<<endl;
	}

	//Function to insert a new jornal into the journal list
	void insert_j()
	{
		ofstream file;
		file.open("journallist.dat",ios::out|ios::app|ios::bin);
		file.write((char*)this,sizeof(*this));
		file.close();
	}

};