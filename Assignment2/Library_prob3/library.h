#include<iostream>
#include<fstream>

#include"student.h"
#include"faculty.h"
#include"book.h"
#include"journal.h"
#include"transactions.h"


using namespace std;
class Student;
class Faculty;
class Book;
class Journal;
class Transactions;

class Library
{
private:
	//Function to get the current student id
	int getMaxStudentId()
	{
		fstream file;
		file.open("studentlist.dat",ios::in|ios::binary);
		file.seekg(-sizeof(Student),ios::end);
		Student s;
		file.read((char*)&s,sizeof(Student));
		if(s.get_id_s()==0)
			return 100000;
		return (s.get_id_s()+1);

	}

	//Function to get the current faculty id
	int getMaxFacultyId()
	{
		fstream file;
		file.open("facultylist.dat",ios::in|ios::binary);
		file.seekg(-sizeof(Faculty),ios::end);
		Student s;
		file.read((char*)&s,sizeof(Faculty));
		if(s.get_id_f()==0)
			return 200000;
		return (s.get_id_s()+1);

	}

	//Function to get the current book id
	int getMaxBookId()
	{
		fstream file;
		file.open("booklist.dat",ios::in|ios::binary);
		file.seekg(-sizeof(Book),ios::end);
		Book s;
		file.read((char*)&s,sizeof(Book));
		if(s.get_id_f()==0)
			return 1000000;
		return (s.get_id_b()+1);

	}

	//Function to get the current journal id
	int getMaxJournalId()
	{
		fstream file;
		file.open("journallist.dat",ios::in|ios::binary);
		file.seekg(-sizeof(Journal),ios::end);
		Journal s;
		file.read((char*)&s,sizeof(Journal));
		if(s.get_id_j()==0)
			return 2000000;
		return (s.get_id_s()+1);

	}

	//Function to get the current transaction id
	int getMaxTransactionId()
	{
		fstream file;
		file.open("translist.dat",ios::in|ios::binary);
		file.seekg(-sizeof(Transactions),ios::end);
		Transactions t;
		file.read((char*)&t,sizeof(Transactions));
		if(t.get_id_t()==0)
			return 5000000;
		return (s.get_id_s()+1);

	}

	//Function to check if a student ID exists or not and return its position
	int findStudentById(int id)
	{
		if(id<=100000 || id>=getMaxStudentId())
		{
			cout<<"Invalid id"<<endl;
			return -1;
		}
		else
		{
			return (id-100000);
		}
	}

	//Function to check if a faculty ID exists or not and return its position
	int findFacultyById(int id)
	{
		if(id<=200000 || id>=getMaxFacultyId())
		{
			cout<<"Invalid id"<<endl;
			return -1;
		}
		else
		{
			return (id-200000);
		}
	}

	//Function to check if a book ID exists or not and return its position
	int findBookById(int id)
	{
		if(id<=1000000 || id>=getMaxBookId())
		{
			cout<<"Invalid id"<<endl;
			return -1;
		}
		else
		{
			return (id-1000000);
		}
	}

	//Function to check if a journal ID exists or not and return its position
	int findJournalById(int id)
	{
		if(id<=2000000 || id>=getMaxJournalId())
		{
			cout<<"Invalid id"<<endl;
			return -1;
		}
		else
		{
			return (id-2000000);
		}
	}


public:

	//ADDING NEW ENTITY
	//Function to add new student
	void addStudent()
	{
		string name;
		cout<<"Enter name of student"<<endl;
		cin>>name;
		Student s(getMaxStudentId(),name,0,{0,0});
		s.insert_s();
	}

	//Function to add new faculty
	void addFaculty()
	{
		cout<<"Enter name of faculty"<<endl;
		string name;
		cin>>name;
		Faculty s(getMaxFacultyId(),name);
		s.insert_f();
	}

	//Function to add new books
	void addBook()
	{
		string name;
		int qty;
		cout<<"Enter name of book"<<endl;
		cin>>name;
		do
		{
			cout<<"Enter quantity"<<endl;
			cin>>qty;
			if(qty<=0)
				cout<<"Invalid quantity"<<endl;
		}
		while(qty<=0);

		Book b(getMaxBookId(),name,qty);
		b.insert_b();
	}

	//Function to add new journal
	void addJournal()
	{
		string name;
		Date doi;
		int vol,qty;
		cout<<"Enter name of journal"<<endl;
		cin>>name;
		cout<<"Enter date of issue"<<endl;
		doi.getDate();
		do
		{
			cout<<"Enter quantity"<<endl;
			cin>>qty;
			if(qty<=0)
				cout<<"Invalid quantity"<<endl;
		}
		while(qty<=0);

		do
		{
			cout<<"Enter volume of journal"<<endl;
			cin>>vol;
			if(vol<=0)
				cout<<"Invalid"<<endl;
		}
		while(vol<=0);

		Journal j(getMaxJournalId(),name,doi,vol,qty);
		j.insert_j();
	}

	//Function to issue a book
	void issueBook()
	{
		int ch,id,offset,idb,cno;
		cout<<"1. Student"<<endl<<"2. Faculty"<<endl<<"Enter choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				//Fetching student details
				do
				{
					cout<<"Enter student id"<<endl;
					cin>>id;
				}
				while(findStudentById(id)==-1);
				offset=findStudentById(id);
				ifstream file1,file2;
				Student s;
				file1.open("studentlist.dat",ios::out|ios::in|ios::binary);
				file1.seekg((offset-1)*sizeof(s),ios::beg);
				file1.read((char*)&s,sizeof(s));

				do
				{
					cout<<"Enter card no"<<endl;
					cin>>cno;
					if(cno<1 || cno>2)
						cout<<"Invalid card no"<<endl;
				}
				while(cno<1 || cno>2);

				//Now fetching book details
				do
				{
					cout<<"Enter book id"<<endl;
					cin>>idb;
				}
				while(findBookById(idb)==-1);
				Book b;
				offset=findBookById(idb);
				file2.open("booklist.dat",ios::out|ios::in|ios::binary);
				file2.seekg((offset-1)*sizeof(b),ios::beg);
				file2.read((char*)&b,sizeof(b));
				file2.close();

				if(b.get_qty_b<=0)
				{
					cout<<"Sorry...out of copies"<<endl;
				}

				else
				{
					if(s.issue_s(cno,idb))
					{
						//Making changes to book file
						b.issue_b();
						file2.seekg(-sizeof(b),ios::cur);
						file2.write((char*)b,sizeof(b));

						//Making changes to student file
						file2.seekg(-sizeof(s),ios::cur);
						file2.write((char*)s,sizeof(s));

						//Creating a transaction
						Transactions t(getMaxTransactionId(),0,0,id,0);
						t.writeTrans();

					}

				}
				break;
			}

			case 2:
			{

				//Fetching faculty details
				do
				{
					cout<<"Enter faculty id"<<endl;
					cin>>id;
				}
				while(findFacultyById(id)==-1);
				offset=findFacultyById(id);
				ifstream file1,file2;
				Faculty s;
				file1.open("facultylist.dat",ios::out|ios::in|ios::binary);
				file1.seekg((offset-1)*sizeof(s),ios::beg);
				file1.read((char*)&s,sizeof(s));

				do
				{
					cout<<"Enter card no"<<endl;
					cin>>cno;
					if(cno<1 || cno>10)
						cout<<"Invalid card no"<<endl;
				}
				while(cno<1 || cno>10);

				//Now fetching book details
				do
				{
					cout<<"Enter book id"<<endl;
					cin>>idb;
				}
				while(findBookById(idb)==-1);
				Book b;
				offset=findBookById(idb);
				file2.open("booklist.dat",ios::out|ios::in|ios::binary);
				file2.seekg((offset-1)*sizeof(b),ios::beg);
				file2.read((char*)&b,sizeof(b));
				file2.close();

				if(b.get_qty_b<=0)
				{
					cout<<"Sorry...out of copies"<<endl;
				}

				else
				{
					if(s.issue_f(cno,idb))
					{
						//Making changes to book file
						b.issue_b();
						file2.seekg(-sizeof(b),ios::cur);
						file2.write((char*)b,sizeof(b));

						//Making changes to student file
						file2.seekg(-sizeof(s),ios::cur);
						file2.write((char*)s,sizeof(s));

						//Creating a transaction
						Transactions t(getMaxTransactionId(),0,1,id,0);
						t.writeTrans();

					}

				}
				break;
			}

			default:
			cout<<"Invalid choice"<<endl;

		}
	}

	//Function to issue a journal
	void issueJournal()
	{
		//Fetching faculty details
		do
		{
			cout<<"Enter faculty id"<<endl;
			cin>>id;
		}
		while(findFacultyById(id)==-1);
		offset=findFacultyById(id);
		ifstream file1,file2;
		Faculty s;
		file1.open("facultylist.dat",ios::out|ios::in|ios::binary);
		file1.seekg((offset-1)*sizeof(s),ios::beg);
		file1.read((char*)&s,sizeof(s));

		do
		{
			cout<<"Enter card no"<<endl;
			cin>>cno;
			if(cno<1 || cno>10)
				cout<<"Invalid card no"<<endl;
		}
		while(cno<1 || cno>10);

				//Now fetching book details
		do
		{
			cout<<"Enter book id"<<endl;
			cin>>idb;
		}
		while(findBookById(idb)==-1);
		Journal j;
		offset=findBookById(idb);
		file2.open("journallist.dat",ios::out|ios::in|ios::binary);
		file2.seekg((offset-1)*sizeof(j),ios::beg);
		file2.read((char*)&j,sizeof(j));
		file2.close();

		if(j.get_qty_j<=0)
		{
			cout<<"Sorry...out of copies"<<endl;
		}

		else
		{
			if(s.issue_f(cno,idb))
			{
				//Making changes to book file
				j.issue_j();
				file2.seekg(-sizeof(j),ios::cur);
				file2.write((char*)j,sizeof(j));

				//Making changes to faculty file
				file2.seekg(-sizeof(s),ios::cur);
				file2.write((char*)s,sizeof(s));

				//Creating a transaction
				Transactions t(getMaxTransactionId(),1,1,id,0);
				t.writeTrans();

			}

		}
	}

	//Funcction to return book

}