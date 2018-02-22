

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
                
                file.seekg(0, ios::end);
                int length = file.tellg();
		file.seekg(length-sizeof(Student),ios::beg);
                
                int bss[2]={0,0};
		Student s(bss);
		file.read((char*)&s,sizeof(Student));
                s.display_s();
                file.close();
		if(s.get_id_s()==0)
			return 100000;
		return (s.get_id_s()+1);

	}

	//Function to get the current faculty id
	int getMaxFacultyId()
	{
		fstream file;
		file.open("facultylist.dat",ios::in|ios::binary|ios::out);
                cout<<"c2"<<endl;
		
                file.seekg(0, ios::end);
                int length = file.tellg();
		file.seekg(length-sizeof(Faculty),ios::beg);
                
                int bs[10]={0,0,0,0,0,0,0,0,0,0};
		Faculty s(bs);
		file.read((char*)&s,sizeof(Faculty));
                file.close();
		if(s.get_id_f()==0)
			return 200000;
		return (s.get_id_f()+1);
                file.close();

	}

	//Function to get the current book id
	int getMaxBookId()
	{
		fstream file;
		file.open("booklist.dat",ios::in|ios::binary);
		
                file.seekg(0, ios::end);
                int length = file.tellg();
		file.seekg(length-sizeof(Book),ios::beg);
                
		Book s;
		file.read((char*)&s,sizeof(Book));
		if(s.get_id_b()==0)
			return 1000000;
		return (s.get_id_b()+1);

	}

	//Function to get the current journal id
	int getMaxJournalId()
	{
		fstream file;
		file.open("journallist.dat",ios::in|ios::binary);
		
                file.seekg(0, ios::end);
                int length = file.tellg();
		file.seekg(length-sizeof(Journal),ios::beg);
                
		Journal s;
		file.read((char*)&s,sizeof(Journal));
                file.close();
		if(s.get_id_j()==0)
			return 2000000;
		return (s.get_id_j()+1);

	}

	//Function to get the current transaction id
	int getMaxTransactionId()
	{
		fstream file;
		file.open("translist.dat",ios::in|ios::binary|ios::out);
		              
                file.seekg(0, ios::end);
                int length = file.tellg();
		file.seekg(length-sizeof(Transactions),ios::beg);
                
		Transactions t;
		file.read((char*)&t,sizeof(Transactions));
                file.close();
		if(t.get_id_t()==0)
			return 5000000;
		return (t.get_id_t()+1);
                file.close();

	}

	//Function to check if a student ID exists or not and return its position
	int findStudentById(int id)
	{
		if(id<100000 || id>=getMaxStudentId())
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
		if(id<200000 || id>=getMaxFacultyId())
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
		if(id<1000000 || id>=getMaxBookId())
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
		if(id<2000000 || id>=getMaxJournalId())
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
               
                int bss[2]={0,0};
		Student s(bss,getMaxStudentId(),name,0);
                s.display_s();
		s.insert_s();
	}

	//Function to add new faculty
	void addFaculty()
	{
		cout<<"Enter name of faculty"<<endl;
		string name;
		cin>>name;
		int bs[10]={0,0,0,0,0,0,0,0,0,0};
                cout<<"c1"<<endl;
                Faculty s(bs,getMaxFacultyId(),name);
                
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
        
        //Function to add quantity of book
        void addQuantityBook()
        {
            int qty=0,idb,offset_b;
            fstream file2;
            do
            {
                    cout<<"Enter book id"<<endl;
                    cin>>idb;
            }
            while(findBookById(idb)==-1);
            
            do
            {
                    cout<<"Enter quantity extra"<<endl;
                    cin>>qty;
                    
                    if(qty<=0)
                        cout<<"Invalid"<<endl;
            }
            while(qty<=0);
            
            Book b;
            offset_b=findBookById(idb);
            file2.open("booklist.dat",ios::out|ios::in|ios::binary);
            file2.seekg((offset_b)*sizeof(b),ios::beg);
            file2.read((char*)&b,sizeof(b));
            b.inc_qty_b(qty);
            file2.seekg((offset_b)*sizeof(b),ios::beg);
            file2.write((char*)&b,sizeof(b));
            file2.close();
            
            
        }

	//Function to issue a book
	void issueBook()
	{
		int ch,id,offset_s,offset_b,offset,idb,cno;
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
				offset_s=findStudentById(id);
				fstream file1,file2;
                                int bss[2]={0,0};
				Student s(bss);
                                
				file1.open("studentlist.dat",ios::out|ios::in|ios::binary);
				file1.seekg((offset_s)*sizeof(s),ios::beg);
				file1.read((char*)&s,sizeof(s));
                                
                                cout<<"#######"<<endl;
                                s.display_s();
                                cout<<"#######"<<endl;
                                
                             

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
				offset_b=findBookById(idb);
				file2.open("booklist.dat",ios::out|ios::in|ios::binary);
				file2.seekg((offset_b)*sizeof(b),ios::beg);
                                file2.seekp((offset_b)*sizeof(b),ios::beg);
				file2.read((char*)&b,sizeof(b));
                                
                                cout<<"#######"<<endl;
                                b.display_b();
                                cout<<"#######"<<endl;
                                
                                //cout<<"tellp"<<file2.tellp()<<" "<<offset<<endl;

				if(b.get_qty_b()<=0)
				{
					cout<<"Sorry...out of copies"<<endl;
				}

				else
				{
					if(s.issue_s(cno,idb))
					{
						//Making changes to book file
						b.issue_b();
						file2.seekg((offset_b)*sizeof(b),ios::beg);
						file2.write((char*)&b,sizeof(b));

						//Making changes to student file
						file1.seekg((offset_s)*sizeof(s),ios::beg);
						file1.write((char*)&s,sizeof(s));

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
				offset_s=findFacultyById(id);
				fstream file1,file2;
                                int bs[10]={0,0,0,0,0,0,0,0,0,0};
				Faculty s(bs);
				file1.open("facultylist.dat",ios::out|ios::in|ios::binary);
				file1.seekg((offset_s)*sizeof(s),ios::beg);
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
				offset_b=findBookById(idb);
				file2.open("booklist.dat",ios::out|ios::in|ios::binary);
				file2.seekg((offset_b)*sizeof(b),ios::beg);
                                file2.seekp((offset_b)*sizeof(b),ios::beg);
				file2.read((char*)&b,sizeof(b));
				file2.close();

				if(b.get_qty_b()<=0)
				{
					cout<<"Sorry...out of copies"<<endl;
				}

				else
				{
					if(s.issue_f(cno,idb))
					{
						//Making changes to book file
						b.issue_b();
						file2.seekp((offset_b)*sizeof(b),ios::beg);
						file2.write((char*)&b,sizeof(b));

						//Making changes to student file
						file1.seekg((offset_s)*sizeof(s),ios::beg);
						file1.write((char*)&s,sizeof(s));

						//Creating a transaction
						Transactions t(getMaxTransactionId(),0,1,id,0);
						t.writeTrans();

					}

				}
                                file2.close();
                                file1.close();
				break;
			}

			default:
			cout<<"Invalid choice"<<endl;

		}
                
	}

	//Function to issue a journal
	void issueJournal()
	{
                int id,offset,cno,idb;
		//Fetching faculty details
		do
		{
			cout<<"Enter faculty id"<<endl;
			cin>>id;
		}
		while(findFacultyById(id)==-1);
		offset=findFacultyById(id);
		fstream file1,file2;
                int bs[10]={0,0,0,0,0,0,0,0,0,0};
		Faculty s(bs);
		file1.open("facultylist.dat",ios::out|ios::in|ios::binary);
		file1.seekg((offset)*sizeof(s),ios::beg);
                file1.seekp((offset)*sizeof(s),ios::beg);
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
		file2.seekg((offset)*sizeof(j),ios::beg);
                file2.seekp((offset)*sizeof(j),ios::beg);
		file2.read((char*)&j,sizeof(j));

		if(j.get_qty_j()<=0)
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
				file2.write((char*)&j,sizeof(j));

				//Making changes to faculty file
				file1.seekg(-sizeof(s),ios::cur);
				file1.write((char*)&s,sizeof(s));

				//Creating a transaction
				Transactions t(getMaxTransactionId(),1,1,id,0);
				t.writeTrans();

			}

		}
                file2.close();
                file1.close();
	}

	//Function to return book
	void returnBook()
	{

		int ch,id,offset_s,offset_b,idb,cno;
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
				offset_s=findStudentById(id);
				fstream file1,file2;
                                int bss[2]={0,0};
				Student s(bss);
				file1.open("studentlist.dat",ios::out|ios::in|ios::binary);
				file1.seekg((offset_s)*sizeof(s),ios::beg);
				file1.read((char*)&s,sizeof(s));

				do
				{
					cout<<"Enter card no"<<endl;
					cin>>cno;
					if(cno<1 || cno>2)
						cout<<"Invalid card no"<<endl;
				}
				while(cno<1 || cno>2);

				Book b;
				//If no books are issued on this card then return
				if(s[cno-1]==0)
					return;

				offset_b=findBookById(s[cno-1]);
				file2.open("booklist.dat",ios::out|ios::in|ios::binary);
				file2.seekg((offset_b)*sizeof(b),ios::beg);
                                file2.seekp((offset_b)*sizeof(b),ios::beg);
				file2.read((char*)&b,sizeof(b));


				//Making changes to book file
				b.return_b();
				file2.seekg((offset_b)*sizeof(b),ios::beg);
				file2.write((char*)&b,sizeof(b));

				//Making changes to student file
				s.return_s(cno);
				file1.seekg((offset_s)*sizeof(s),ios::beg);
				file1.write((char*)&s,sizeof(s));

				//Creating a transaction
				Transactions t(getMaxTransactionId(),0,0,id,1);
				t.writeTrans();

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
				offset_s=findFacultyById(id);
				fstream file1,file2;
                                int bs[10]={0,0,0,0,0,0,0,0,0,0};
				Faculty s(bs);
				file1.open("facultylist.dat",ios::out|ios::in|ios::binary);
				file1.seekg((offset_s)*sizeof(s),ios::beg);
				file1.read((char*)&s,sizeof(s));

				do
				{
					cout<<"Enter card no"<<endl;
					cin>>cno;
					if(cno<1 || cno>10)
						cout<<"Invalid card no"<<endl;
				}
				while(cno<1 || cno>10);

				Book b;
				//If no books are issued on this card then return
				if(s[cno]==0)
					return;

				offset_b=findBookById(s[cno]);
				file2.open("journallist.dat",ios::out|ios::in|ios::binary);
				file2.seekg((offset_b)*sizeof(b),ios::beg);
				file2.read((char*)&b,sizeof(b));


				//Making changes to book file
				b.return_b();
				file2.seekg((offset_b)*sizeof(b),ios::beg);
				file2.write((char*)&b,sizeof(b));

				//Making changes to student file
				s.return_f(cno);
				file1.seekg((offset_s)*sizeof(s),ios::beg);
				file1.write((char*)&s,sizeof(s));

				//Creating a transaction
				Transactions t(getMaxTransactionId(),0,1,id,1);
				t.writeTrans();
                                
                                file2.close();
                                file1.close();

				break;
			}

			default:
			cout<<"Invalid choice"<<endl;

		}
                
	}

	//Function to return journal
	void returnJournal()
	{
                int id,offset,cno,ibd;
		//Fetching faculty details
		do
		{
			cout<<"Enter faculty id"<<endl;
			cin>>id;
		}
		while(findFacultyById(id)==-1);
		offset=findFacultyById(id);
		fstream file1,file2;
                int bs[10]={0,0,0,0,0,0,0,0,0,0};
		Faculty f(bs);
		file1.open("facultylist.dat",ios::out|ios::in|ios::binary);
		file1.seekg((offset-1)*sizeof(f),ios::beg);
		file1.read((char*)&f,sizeof(f));

		do
		{
			cout<<"Enter card no"<<endl;
			cin>>cno;
			if(cno<1 || cno>10)
				cout<<"Invalid card no"<<endl;
		}
		while(cno<1 || cno>10);

		Journal j;
		//If no books are issued on this card then return
		if(f[cno]==0)
			return;

		offset=findBookById(f[cno]);
		file2.open("journallist.dat",ios::out|ios::in|ios::binary);
		file2.seekg((offset-1)*sizeof(j),ios::beg);
		file2.read((char*)&j,sizeof(j));


		//Making changes to book file
		j.return_j();
		file2.seekg(-sizeof(j),ios::cur);
		file2.write((char*)&j,sizeof(j));

		//Making changes to student file
		f.return_f(cno);
		file1.seekg(-sizeof(f),ios::cur);
		file1.write((char*)&f,sizeof(f));

		//Creating a transaction
		Transactions t(getMaxTransactionId(),0,1,id,1);
		t.writeTrans();
                
                file2.close();
                file1.close();
	}
        
        //Function to display all students
        void dispStudents()
        {
            fstream file;
            file.open("studentlist.dat",ios::in|ios::binary);
            int bss[2]={0,0};
            Student s(bss);
            cout<<"====================================="<<endl;
            while(file.read((char*)&s,sizeof(s)))
            {
                if(file.eof())
                    break;
                
                s.display_s();
                
                
                
            }
            cout<<"====================================="<<endl;
        }
        
        //Function to display all faculty
        void dispFaculty()
        {
            fstream file;
            file.open("facultylist.dat",ios::in|ios::binary);
            int bss[10]={0,0,0,0,0,0,0,0,0,0};
            Faculty s(bss);
            cout<<"====================================="<<endl;
            while(file.read((char*)&s,sizeof(s)))
            {
                if(file.eof())
                    break;

                
                s.display_f();
                
                
                
            }
            cout<<"====================================="<<endl;
        }
        
        //Function to display all books
        void dispBooks()
        {
            fstream file;
            file.open("booklist.dat",ios::in|ios::binary);
            Book b;
            cout<<"====================================="<<endl;
            while(file.read((char*)&b,sizeof(b)))
            {
                if(file.eof())
                    break;
    
                
                b.display_b();
           
                
                
            }
            cout<<"====================================="<<endl;
        }
        
        //Function to display all journals
        void dispJournals()
        {
            fstream file;
            file.open("journallist.dat",ios::in|ios::binary);
            Journal b;
            
            cout<<"====================================="<<endl;
            while(file.read((char*)&b,sizeof(b)))
            {
                if(file.eof())
                    break;
                
                
                b.display_j();
                
                
                
            }
            cout<<"====================================="<<endl;
        }
        
        //Function to display all transactions
        void dispTrans()
        {
            fstream file;
            file.open("translist.dat",ios::in|ios::binary);
            Transactions b;
            cout<<"====================================="<<endl;
            while(file.read((char*)&b,sizeof(b)))
            {
                if(file.eof())
                    break;

                
                b.displayTrans();
            }
            cout<<"====================================="<<endl;
        }
};

