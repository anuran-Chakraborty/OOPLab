#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class Book
{
	int id;
	char name[51];
	int qty;

public:
	//Constructor
	Book(int i=0,string n="",int q=0)
	{
		id=i;
		strcpy(name,n.c_str());
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

        //Function to increase qty
        void inc_qty_b(int q)
        {
            qty+=q;
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