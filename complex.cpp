#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Complex
{
	int real;
	int img;

public:
		//Constructor
	Complex(int r=0,int i=0)
	{
		real=r;
		img=i;
	}

	//Overloading addition operator
	Complex operator +(Complex c2)
	{
		Complex t;
		t.real=real+c2.real;
		t.img=img+c2.img;
		return t;
	}

	//Overloading subtraction operator
	Complex operator -(Complex c2)
	{
		Complex t;
		t.real=real-c2.real;
		t.img=img-c2.img;
		return t;
	}

	//Overloading the input operator
	friend istream & operator >> (istream& in,Complex& c);
	//Overloading the out put operator
	friend ostream & operator << (ostream& out,const Complex& c);
};

istream & operator >> (istream &ist, Complex &c)
{
	cout<<"Enter real and imaginary parts one after the other"<<endl;
	ist>>c.real;
	ist>>c.img;
	return ist;
}

ostream & operator << (ostream &ost,const Complex &c)
{
	if(c.real==0)
	{
		if(c.img==0)
			cout<<"0"<<endl;
		else
			if(c.img<0)
				cout<<"-i"<<(-c.img)<<endl;
			else
				cout<<"i"<<c.img<<endl;
		}
		else
		{
			if(c.img==0)
				cout<<c.real<<endl;
			else
				if(c.img<0)
					cout<<c.real<<"-i"<<(-c.img)<<endl;
				else
					cout<<c.real<<"+i"<<c.img<<endl;
			}	
		}

		int main()
		{
			int ch;
			do
			{
				cout<<"1. Add 2 complex nummbers"<<endl<<"2. Subtract 2 complex numbers"<<endl<<"3. Exit"<<endl<<"Enter your choice"<<endl;
				Complex c1;
				Complex c2;
				Complex c3;
				cin>>ch;
				switch(ch)
				{
					case 1:
						cout<<"Enter two numbers"<<endl;
						cin>>c1;
						cin>>c2;
						c3=c1+c2;
						cout<<"The result is: ";
						cout<<c3;
						break;

					case 2:
						cout<<"Enter two numbers"<<endl;
						cin>>c1;
						cin>>c2;
						c3=c1-c2;
						cout<<"The result is: ";
						cout<<c3;
						break;
					case 3:
						cout<<"Exitting"<<endl;
						exit(0);

					default:
						cout<<"Invalid choice"<<endl;
				}
			}
			while(ch!=3);
			return 0;
		}