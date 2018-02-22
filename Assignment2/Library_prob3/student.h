
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


class Student
{
	int id;
	char name[32];
	int noOfBooks;
	int issue_books[2];

public:
	//Constructor
	Student(int b[2],int i=0,string n="",int no=0)
	{
		id=i;
		strcpy(name,n.c_str());
		noOfBooks=no;
		issue_books[0]=b[0];
                issue_books[1]=b[1];
	}
	//Function to return id
	int get_id_s()
	{
		return id;
	}

	//Function to get quantity
	int get_noOfBooks_s()
	{
		return noOfBooks;
	}

	//Function to issue a book
	int issue_s(int card_no,int b_id)
	{
		if(issue_books[card_no-1]==0)
		{
			issue_books[card_no-1]=b_id;
			noOfBooks++;
			return 1;
		}
		else
		{
			cout<<"You have books issued on this card..unable to issue"<<endl;
			return 0;
		}
	}

	//Function to return a book
	void return_s(int card_no)
	{
		if(issue_books[card_no-1]!=0)
		{
			issue_books[card_no-1]=0;
			noOfBooks--;
		}
		else
		{
			cout<<"No books issued to you on this card"<<endl;
		}
	}		

	//Function to display student details
	void display_s()
	{
		cout<<id<<"\t"<<name<<"\t"<<"\t"<<noOfBooks<<"\t"<<issue_books[0]<<"\t"<<issue_books[1]<<endl;
	}

	//Function to insert a new student into list
	void insert_s()
	{
                fstream file;
		file.open("studentlist.dat",ios::app|ios::binary);
		file.write((char*)this,sizeof(*this));
		file.close();
	}

	int operator[](int i)
	{
		return issue_books[i];
	}

};

