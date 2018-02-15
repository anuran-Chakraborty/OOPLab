#include<iostream>
#include<fstream>

using namespace std;

//Class to create date type
class Date
{
	int day;
	int month;
	int year;

public:
	//Constructor
	Date(int d=1,int m=1,int y=1960)
	{
		day=d;
		month=m;
		year=y;
	}

	//Function to take date as input returns 1 if input is valid
	int getDate()
	{
		string d;
		cout<<"Enter date in dd-mm-yyyy format"<<endl;
		cin>>d;
		int dy,mn,yr;
		//Validating input
		if(d.length()!=10)
		{
			cout<<"Invalid date format"<<endl;
			return 0;
		}
		//If length is correct then check
		else
		{
			if(d[2]!='-' || d[5]!='-')
			{
				cout<<"Invalid date format"<<endl;
				return 0;
			}
			else
			{
				dy=10*(d[0]-'0')+(d[1]-'0');
				mn=10*(d[3]-'0')+(d[4]-'0');
				yr=1000*(d[6]-'0')+100*(d[7]-'0')+10*(d[8]-'0')+(d[9]-'0');
				//Validating hour
				Date dt(dy,mn,yr);
				if(!isValid(dt))
				{
					cout<<"Invalid date entered"<<endl;
					return 0;
				}
			}
		}
		day=dy;
		month=mn;
		year=yr;
		return 1;

	}

	//Function to check if date is valid or not
	int isValid(Date d)
	{
		//Validating correct date
		int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		if(isLeap(d.year))
			days[1]=29;
		if(d.month<1 || d.month>12)
			return 0;
		else
		{
			if(d.day<0 || d.day>days[d.month-1])
				return 0;
			else
			{
				//Checking whether the date is after the current date then invalid
				time_t now = time(0);
				tm *ltm = localtime(&now);
				int c_year=1900+ltm->tm_year;
				int c_month=1 + ltm->tm_mon;
				int c_day=ltm->tm_mday;
				//If input year is after current date
				if(d.year>c_year)
					return 0;
				//If input year is ok
				else
					if(d.year==c_year)
					{
					//If input year is equal to this year then check month
						if(d.month>c_month)
							return 0;
						else
							if(d.month==c_month)
							{
								if(d.day>c_day)
									return 0;
							}

						}
						return 1;
					}
				}




			}
	//Function to check if a year is a leap year or not
			int isLeap(int y)
			{
				if((y%100==0 & y%400==0) || (y%100!=0 && y%4==0))
					return 1;
				return 0;
			}

			friend ostream& operator<<(ostream& o,Date& d);
			friend ofstream& operator<<(ofstream& f,Date& d);
		};

ostream& operator<<(ostream& o,Date d)
{
	o<<d.day<<"-"<<d.month<<"-"<<d.year;
	return o;
}

ofstream& operator<<(ofstream& f,Date d)
{
	f<<d.day<<"-"<<d.month<<"-"<<d.year;
	return f;
}



class Book
{
	int id;
	string name;
	int qty;

public:
	//Constructor
	Book(int i,String s,int q=0)
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
		copies--;
	}

	//Function to return a book
	void return_b()
	{
		copies++;
	}

	//Function to insert a book into the book list
	void insert_b()
	{
		fstream f_booklist;
		f_booklist.open("booklist.txt",ios::app);
		f_booklist<<endl;
		f_booklist<<id<<endl<<name<<endl<<copies;
		f_booklist.close();
	}

	//Function to display details of book
	void display_b()
	{
		cout<<id<<"\t"<<name<<"\t"<<qty<<endl;
	}

};


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
		fstream f_jlist;
		f_jlist.open("journallist.txt",ios::app);
		f_jlist<<endl;
		f_jlist<<id<<endl<<name<<endl<<doi<<endl<<vol<<endl<<endl<<copies;
		f_jlist.close();
	}

};

class Student
{
	int id;
	string name;
	int noOfBooks;
	int issue_books[2];

public:
	//Constructor
	Student(int i,string n,int no=0,int b[])
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
	void issue_s(int card_no,int b_id)
	{
		if(issue_books[card_no]==0)
		{
			issue_books[card_no]=b_id;
			noOfBooks++;
		}
		else
		{
			cout<<"You have books issued on this card..unable to issue"<<endl;
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
		fstream f_slist;
		f_jlist.open("studentlist.txt",ios::app);
		f_jlist<<endl;
		f_jlist<<id<<endl<<name<<endl<<issue[0]<<" "<<issue[1]<<endl;
		f_jlist.close();
	}

};


class Faculty
{
	int id;
	string name;
	int noOfBooks;
	int issue_bj[10];

public:
	//Constructor
	Faculty(int i,string n,int no=0,int bj[])
	{
		id=i;
		name=n;
		noOfBooks=no;
		issued_bj=bj[];
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
	void issue_f(int card_no,int b_id)
	{
		if(noOfBooks==10)
		{
			cout<<"You have books issued on all cards..unable to issue"<<endl;
		}
		else
		{
			if(issue_bj[card_no]!=0)
			{
				cout<<"You have books issued on this card..unable to issue"<<endl;
			}
			else
			{
				issue_bj[card_no]=b_id;
				noOfBooks++;
			}

		}
	}

	//Function to return a book
	void return_f(int card_no)
	{
		if(issue_books[card_no]==0)
		{
			cout<<"No books issued to you on this card"<<endl;
		}
		else
		{
			issue_books[card_no]=0;
			noOfBooks--;
		}
	}		

	//Function to display student details
	void display_f()
	{
		cout<<id<<"\t"<<name<<"\t"<<endl;
	}

	//Function to insert a new faculty into list
	void insert_f()
	{
		fstream f_flist;
		f_flist.open("facultylist.txt",ios::app);
		f_flist<<endl;
		f_flist<<id<<endl<<name<<endl<<;
		for (int i = 0; i < 10; i++) 
		{
				f_flist << issued_books[i] << " ";
		}
		f_flist<<endl;
		f_flist.close();
	}

};
