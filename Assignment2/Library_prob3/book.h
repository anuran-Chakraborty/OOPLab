#include<iostream>
#include<fstream>

using namespace std;

class Book
{
	int id;
	string name;
	int qty;

public:
	//Constructor
	Book(int i=0,string s="",int q=0)
	{
		id=i;
		name=s;
		qty=q;
	}

	//Function to get id
	int get_id_b()
	{
		return id;
	}

	//Function to get quantity
	int get_qty_b()
	{
		return qty;
	}

	//Function to issue a book
	void issue_b()
	{
		qty--;
	}

	//Function to return a book
	void return_b()
	{
		qty++;
	}

	//Function to insert a book into the book list
	void insert_b()
	{
		ofstream file;
		file.open("booklist.dat",ios::out|ios::app|ios::binary);
		file.write((char*)this,sizeof(*this));
		file.close();
	}

	//Function to display details of book
	void display_b()
	{
		cout<<id<<"\t"<<name<<"\t"<<qty<<endl;
	}

};