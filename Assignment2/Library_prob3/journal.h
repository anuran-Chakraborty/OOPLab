#include<iostream>
#include<fstream>
#include<cstring>
#include"date.h"

using namespace std;

//Class to store journal details
class Journal
{
	int id;
	char name[32];
	Date doi;
	int vol;
	int qty;

public:
	//Constructor
	Journal(int i=0,string n="",Date d=Date(),int v=0,int q=0)
	{
		id=i;
		strcpy(name,n.c_str());
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
		qty--;
	}

	//Function to return a journal
	void return_j()
	{
		qty++;
	}

	//Function to display journal details
	void display_j()
	{
		cout<<id<<"\t"<<name<<"\t"<<doi<<"\t"<<vol<<"\t"<<qty<<endl;
	}

	//Function to insert a new journal into the journal list
	void insert_j()
	{
		ofstream file;
		file.open("journallist.dat",ios::out|ios::app|ios::binary);
		file.write((char*)this,sizeof(*this));
		file.close();
	}

};