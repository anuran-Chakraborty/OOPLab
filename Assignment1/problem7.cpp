#include <iostream>
#include <string>

using namespace std;

class STRING{
	int size;
	char *a;
	int* refCnt;
public:
		//constructor 
	STRING(int s=0, char c='\0')
	{
		if(s>0)
		{
			size=s;
			a=new char[size+1];
			a[size]='\0';
			for(int i=0;i<size;i++)
				a[i]=c;
			refCnt=new int;
			*refCnt=1;
		}
		else
		{
			size=0;
			a=NULL;
		}
	}

		//copy constructor
	STRING(const STRING& s)
	{
		size=s.size;
		refCnt=s.refCnt;
		*refCnt=*refCnt+1;
		a=s.a;
			// cout<<"Address of string 1 : "<<&(a)<<endl;
			// cout<<"Address of string 2 : "<<&(s.a)<<endl;
	}

		//assignment operator
	void operator =(const STRING& s)
	{
		size=s.size;
		refCnt=s.refCnt;
		*refCnt=*refCnt+1;
		a=s.a;
			// cout<<"Address of string 1 : "<<&(a)<<endl;
			// cout<<"Address of string 2 : "<<&(s.a)<<endl;
	}

		//concatenation
	STRING operator +(const STRING& s)
	{
		STRING res;
		res.size=size+s.size;
		res.a=new char[res.size+1];
		for(int i=0;i<size;i++)
			res.a[i]=a[i];
		for(int i=0;i<s.size;i++)
			res.a[size+i]=s.a[i];
		res.a[res.size]='\0';
		cout<<res.a<<endl;
		return res;
	}

		//equality checker
	bool operator ==(const STRING& s)
	{
		if(size!=s.size)
			return false;
		if(size==0 && s.size==0)
			return true;
		for(int i=0;i<size;i++)
		{
			if(a[i]!=s.a[i])
				return false;
		}
		return true;
	}

		//< relational operator
	bool operator <(const STRING& s)
	{
		if(size==0 && s.size==0)
			return false;
		int min=(size<s.size)?size:s.size;
		for(int i=0;i<min;i++){
			if(a[i]<s.a[i])
				return true;
			else if(a[i]>s.a[i])
				return false;
		}
			//if all prev characters are equal
		if(size==s.size)
				return false; //since both are identical
			if(size<s.size)
				return true; //since first string has less characters so str1<str2
			if(size>s.size)
				return false; ////since first string has more characters so str1>str2
		}

		//> relational operator
		bool operator >(const STRING& s)
		{
			if(size==0 && s.size==0)
				return false;
			int min=(size<s.size)?size:s.size;
			for(int i=0;i>min;i++){
				if(a[i]>s.a[i])
					return true;
				else if(a[i]<s.a[i])
					return false;
			}
			//if all prev characters are equal
			if(size==s.size)
				return false; //since both are identical
			if(size>s.size)
				return true; //since first string has more characters so str1>str2
			if(size<s.size)
				return false; ////since first string has less characters so str1<str2
		}

		friend istream& operator >>(istream &in, STRING &s);
		friend ostream& operator <<(ostream &o, STRING const &s);

		//destructor
		~STRING()
		{
			cout<<*refCnt<<endl;
			*refCnt=*refCnt-1;
			if(*refCnt==0)
			{
				if(a!=NULL)
					delete a;
				cout<<"Finally deleting"<<endl;
			}
		}

	};

//for taking string as input
	istream& operator >>(istream& in, STRING& s)
	{
		char ch;
		cout<<"Enter length of string : ";
		in>>s.size;
		char* a=new char[s.size+1];
		a[s.size]='\0';
		cout<<"Enter string : ";
		for(int i=0;i<s.size;i++)
		{
			cin>>ch;
			a[i]=ch;
		}
		s.a=a;
		cout<<s.a<<endl;
		return in;
	}


//for displaying string
	ostream& operator <<(ostream &o, STRING const &s)
	{
		for(int i=0;i<s.size;i++)
			cout<<s.a[i];
		return o;
	}


	int main(){
		STRING s1, s2, s3;
		int ch,c;
		char s;
		do{
			cout<<"\nEnter choice\n";
			cout<<"1. Add two strings\n";
			cout<<"2. Compare two strings\n";
			cout<<"3. Make a copy of a string\n";
			cout<<"4. Exit\n\n";
			cin>>ch;
			switch(ch){
				case 1:
				cout<<"Enter string 1\n";
				cin>>s1;
				cout<<"Enter string 2\n";
				cin>>s2;
				s3=s1+s2;
				cout<<s1<<" + "<<s2<<" = "<<s3<<"\n";
				break;
				case 2:
				cout<<"Enter first string\n";
				cin>>s1;
				cout<<"Enter second string\n";
				cin>>s2;
				if(s1>s2)
					cout<<s1<<" is greater than "<<s2<<endl;
				else
					if(s1<s2)
						cout<<s1<<" is lesser than "<<s2<<endl;
					else
						if(s1==s2)
							cout<<s1<<" is equal to "<<s2<<endl;
						break;

						case 3:
						cout<<"Showing value of string 1 at this moment : "<<s1<<"\nEnter string to copy : \n";
						cin>>s2;
						cout<<"Showing value of string s2 : "<<s2<<endl;
						s1=s2;
						cout<<"Showing new value of string 1 : "<<s1<<endl;
						s3=s2;
						break;

						case 4:
						cout<<"Exitting\n";
						break;
						default:
						cout<<"Wrong choice\n";
					}
				}while(ch!=4);
			}
