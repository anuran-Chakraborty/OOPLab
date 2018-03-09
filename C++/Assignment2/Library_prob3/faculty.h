#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class Faculty
{
	int id;
	char name[32];
	int noOfBooks;
	int issue_bj[10];

public:
	//Constructor
	Faculty(int bj[10],int i=0,string n="",int no=0)
	{
		id=i;
                
//		char* nm=new char[n.length()+1];
                strcpy(name,n.c_str());
                
		noOfBooks=no;
		int j;
                for(j=0;j<10;j++)
                    issue_bj[j]=bj[j];
	}
	//Function to return id
	int get_id_f()
	{
		return id;
	}

	//Function to get quantity
	int get_noOfBooks_f()
	{
		return noOfBooks;
	}

	//Function to issue a book/journal
	int issue_f(int card_no,int b_id)
	{
		if(noOfBooks==10)
		{
			cout<<"You have books issued on all cards..unable to issue"<<endl;
                        return 0;
		}
		else
		{
			if(issue_bj[card_no]!=0)
			{
				cout<<"You have books issued on this card..unable to issue"<<endl;
                                return 0;
			}
			else
			{
				issue_bj[card_no]=b_id;
				noOfBooks++;
                                return 1;
			}

		}
	}

	//Function to return a book
	void return_f(int card_no)
	{
		if(issue_bj[card_no]==0)
		{
			cout<<"No books issued to you on this card"<<endl;
		}
		else
		{
			issue_bj[card_no]=0;
			noOfBooks--;
		}
	}		

	//Function to display student details
	void display_f()
	{
		cout<<id<<"\t"<<name<<"\t"<<noOfBooks<<"\t";
                for(int i=0;i<10;i++)
                    cout<<issue_bj[i]<<"\t";
                cout<<endl;
	}

	//Function to insert a new faculty into list
	void insert_f()
	{
		ofstream file;
		file.open("facultylist.dat",ios::in|ios::out|ios::app|ios::binary);
		file.write((char*)this,sizeof(*this));
		file.close();
	}

	int operator[](int i)
	{
		return issue_bj[i];
	}

};