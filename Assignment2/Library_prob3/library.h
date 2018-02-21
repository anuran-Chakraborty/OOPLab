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
			return 1000000;
		return (s.get_id_s()+1);

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
		cout<<"Enter date off issue"<<endl;
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
	}

}