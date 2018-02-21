#include<iostream>
#include<fstream>

using namespace std;


class Student
{
	int id;
	string name;
	int noOfBooks;
	int issue_books[2];

public:
	//Constructor
	Student(int i=0,string n="",int no=0,int b[]={0,0})
	{
		id=i;
		name=n;
		noOfBooks=no;
		issue_books=b;
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
		if(issue_books[card_no]==0)
		{
			issue_books[card_no]=b_id;
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
		if(issue_books[card_no]!=0)
		{
			issue_books[card_no]=0;
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
		cout<<id<<"\t"<<name<<"\t";
	}

	//Function to insert a new student into list
	void insert_s()
	{
		ofstream file;
		file.open("studentlist.dat",ios::out|ios::app|ios::bin);
		file.write((char*)this,sizeof(*this));
		file.close();
	}

};