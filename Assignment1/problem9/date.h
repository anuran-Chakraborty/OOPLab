#include<iostream>
#include<ctime>

using namespace std;
//Class to create date type
class Date
{
	int day;
	int month;
	int year;

public:
	//Constructor
	Date()
	{
		time_t now = time(0);
		tm *ltm = localtime(&now);
		year=1900+ltm->tm_year;
		month=1 + ltm->tm_mon;
		day=ltm->tm_mday;
	}

	friend ostream & operator << (ostream& out,const Date& c);
};

//To display date
ostream & operator << (ostream &ost,const Date &c)
{
	ost<<c.day<<"-"<<c.month<<"-"<<c.year<<endl;
}
