/*
Name: Anuran Chakraborty
Roll: 001610501020
Group: A1
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Time
{
	//Data members
	int hour;
	int min;
	int sec;
	string apm;

public:
		//Default construcutor
	Time()
	{
		hour=0;
		min=0;
		sec=0;
		apm="";
	}

		//Parameterized constructor
	Time(int h,int m,int s,string ap="")
	{
		hour=h;
		min=m;
		sec=s;
		apm=ap;
	}

	//Function to dsiplay convert from 12 hr to 24 hr
	Time convert24(Time t)
	{
		int th=t.hour;
		if(t.apm=="am" || t.apm=="AM")
		{
			if(hour==12)
				th=0;
		}
		else
		if(t.apm=="pm" || t.apm=="PM")
		{
			if(hour!=12)
				th+=12;
		}
		Time t2(th,t.min,t.sec);
		return t2;
	}

	//Function to display time in 24 hr to 12 hr
	Time convert12(Time t)
	{
		int th=t.hour;
		string ampm="";
		if(th>=12)
		{
			if(th>12)
				th-=12;
				ampm="pm";
		}
		else
		if(th==0)
		{
			th=12;
			ampm="am";
		}
		else
			ampm="am";

		Time t2(th,t.min,t.sec,ampm);
		return t2;

		}

		//Function to display a time object
		void display(Time t)
		{
			if(t.hour<10)
				cout<<"0"<<t.hour<<":";
			else
				cout<<t.hour<<":";
			if(t.min<10)
				cout<<"0"<<t.min<<":";
			else
				cout<<t.min<<":";
			if(t.sec<10)
				cout<<"0"<<t.sec;
			else
				cout<<t.sec;
			cout<<t.apm<<endl;

		}

		//Function to add minute to time
		Time add(Time t,int m)
		{
			int tmin=t.min+m;
			if(tmin>=60)
			{
				t.min=tmin%60;
				t.hour+=tmin/60;
			}
			t.hour%=24;
			Time t2(t.hour,tmin%60,t.sec);
			return t2;
		}

		//Function to take input
		int getData()
		{
			string intime;
			cout<<"Enter time in 00:00:00 or 00:00:00am : "<<endl;
			cin>>intime;
			int hr=0,minute=0,second=0;
			string ampm="";

			//Validating input
			if(intime.length()!=8 && intime.length()!=10)
			{
				cout<<"Invalid time format"<<endl;
				return 0;
			}

			//Validating for valid am or pm
			if(intime.length()==10)
			{
				if(intime[2]!=':' || intime[5]!=':')
				{
					cout<<"Invalid time format"<<endl;
					return 0;
				}

				//If time is given in 12 hr format
				ampm=intime[8];
				ampm+=intime[9];
				if(ampm!="am" && ampm!="pm")
				{
					cout<<"Invalid time format"<<endl;
					return 0;
				}
				else
				{
					hr=10*(intime[0]-'0')+(intime[1]-'0');
					minute=10*(intime[3]-'0')+(intime[4]-'0');
					second=10*(intime[6]-'0')+(intime[7]-'0');
					//Validating hour
					if(hr<=0 || hr>=12)
					{
						cout<<"Invalid time format"<<endl;
						return 0;
					}
					//Validating minute
					if(minute<=0 || minute>=60)
					{
						cout<<"Invalid time format"<<endl;
						return 0;
					}
					//Validating second
					if(second<=0 || second>=60)
					{
						cout<<"Invalid time format"<<endl;
						return 0;
					}

				}	
			}
			//Validating in 24-hour
			if(intime.length()==8)
			{
				if(intime[2]!=':' || intime[5]!=':')
				{
					cout<<"Invalid time format"<<endl;
					return 0;
				}

				hr=10*(intime[0]-'0')+(intime[1]-'0');
				minute=10*(intime[3]-'0')+(intime[4]-'0');
				second=10*(intime[6]-'0')+(intime[7]-'0');
				//Validating hour
				if(hr<0 || hr>23)
				{
					cout<<"Invalid time format"<<endl;
					return 0;
				}
				//Validating minute
				if(minute<0 || minute>=60)
				{
					cout<<"Invalid time format"<<endl;
					return 0;
				}
				//Validating second
				if(second<0 || second>=60)
				{
					cout<<"Invalid time format"<<endl;
					return 0;
				}

			}
			hour=hr;
			min=minute;
			sec=second;
			apm=ampm;
			return 1;

		}


	};

	int main()
	{
		Time t;
		Time t2;
		int ch;
		do
		{
			cout<<"1. Input time"<<endl<<"2. Get input time in 12 hr"<<endl<<"3. Get input time in 24 hr"<<endl<<"4. Add minutes to time"<<endl<<"5. Exit"<<endl<<"Enter choice"<<endl;
			int m=0,flag;
			cin>>ch;
			switch(ch)
			{
				case 1:
						do
						{
							flag=t.getData();
						}
						while(flag==0);
						break;

				case 2:
						t.display(t.convert12(t));
						break;

				case 3:
						t.display(t.convert24(t));
						break;

				case 4:
						cout<<"Enter minutes to add"<<endl;
						cin>>m;
						t2=(t.add(t,m));
						t2.display(t2);
						break;

				case 5:
						cout<<"Quitting"<<endl;
						exit(0);

				default:
						cout<<"Invalid choice"<<endl;
			}
		}
		while(ch!=5);
		return 0;

	}