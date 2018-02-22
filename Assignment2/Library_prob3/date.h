

#include<ctime>
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

	//Function to get current date
	void getCurrentDate()
	{
		time_t now = time(0);
		tm *ltm = localtime(&now);
		year=1900+ltm->tm_year;
		month=1 + ltm->tm_mon;
		day=ltm->tm_mday;
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

//		ostream& operator<<(ostream& o,Date& d)
//		{
//			o<<d.day<<"-"<<d.month<<"-"<<d.year;
//			return o;
//		}
//
//		ofstream& operator<<(ofstream& f,Date d)
//		{
//			f<<d.day<<"-"<<d.month<<"-"<<d.year;
//			return f;
//		}

