#include<iostream>
#include<fstream>

using namespace std;

//Class to store each transaction
class Transactions
{
	int id;
	int itemType;// 0-books 1-journal
	int issuer; // 0-Student 1-teacher
	int issuerId;
	int type; // 0-issue 1-return
	Date d;


	public:
		//Constructor
		Transactions(int i=0,int it=-1,int iss=-1,int iid=0,int t=-1)
		{
			id=i;
			itemType=it;
			issuer=iss;
			issuerId=iid;
			type=t;
			d.getCurrentDate();
		}

		int get_id_t()
		{
			return id;
		}

		//function to write transactions to a file
		void writeTrans()
		{
			fstream file;
			file.open("translist.dat",ios::out|ios::app|ios::binary);
			file.write((char*)this,sizeof(*this));
			file.close();
		}

		//Function to display transaction
		void displayTrans()
		{
			cout<<"Id: "<<id<<endl<<"Item type: ";

			if(itemType==0)
				cout<<"Book"<<endl;
			else
				cout<<"Journal"<<endl;

			if(issuer==0)
				cout<<"Issued to: Student "<<issuerId<<endl;
			else
				cout<<"Issued to: Faculty "<<issuerId<<endl;
			cout<<"Date :"<<d<<endl;
		}
};