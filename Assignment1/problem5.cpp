#include<iostream>

using namespace std;

class ARRAY
{
	int size;
	int* arr;

public:
	//Parametrized constructor
	ARRAY(int s,int val=0)
	{
		if(s!=0)
		{
			size=s;
			arr=new int[size];
			int i;
			//Initialise elements
			for(i=0;i<size;i++)
				arr[i]=val;
		}
	}
	//Copy constructor
	ARRAY(const ARRAY& a)
	{
		size=a.size;
		arr=new int[a.size];

		//Copy elements
		int i;
		for(i=0;i<size;i++)
			arr[i]=a.arr[i];

	}
	//Constructor for initialisation with another array
	ARRAY(const int* array)
	{	
		size=(sizeof(array)/sizeof(*array));
		arr=new int[size];
		int i;
			//Initialise elements
		for(i=0;i<size;i++)
			arr[i]=array[i];

	}

	//to make a=b do the assignment
	void operator =(ARRAY a)
	{

		size=a.size;
		arr=new int[a.size];

		//Copy elements
		int i;
		for(i=0;i<size;i++)
			arr[i]=a.arr[i];
	}

	// to accept elements into array
	istream & operator >>(istream& ist,ARRAY& a)
	{
		cout<<"Enter "<<size<<" elements into array"<<endl;
		int i;
		for(i=0;i<size;i++)
			ist>>a.arr[i];
		return ist;
	}

	//to display ARRAY object
	ostream & operator <<(ostream& ost,ARRAY& a)
	{
		int i;
		for(i=0;i<size;i++)
			ost<<a.arr[i]<<" ";
		return ost;
	}

	//a+b will add the corresponding elements
	ARRAY operator +(ARRAY b)
	{
		//Validate
		ARRAY c(b.size,0);
		int i;
		for(i=0;i<size;i++)
			c.arr[i]=arr[i]+b.arr[i];
		return c;
	}

	//a[k] will return kth element
	int operator [](int i)
	{
		return arr[i];
	}

	//a*5 will multiply the elements with 5
	ARRAY operator *(int n)
	{
		int i;
		ARRAY c(size,0);
		for(i=0;i<size;i++)
			c.arr[i]=n*arr[i];
		return c;
	}

	//Function to get size of array
	int getSize()
	{
		return size;
	}

	friend ARRAY operator *(int n,ARRAY a);


};

ARRAY operator *(int n, ARRAY a)
{
	int i;
	ARRAY c(a.size,0);
	for(i=0;i<a.size;i++)
		c.arr[i]=n*a.arr[i];
	return c;
}

int main()
{
	int ch,size=0;
	do
	{
		cout<<"1. Enter 2 arrays"<<endl<<"2. Add the two arrays"<<endl<<"3. Multiply first array by scalar"<<endl<<"4.Exit"<<endl<<"Enter your choice"<<endl;
		Complex c1;
		Complex c2;
		Complex c3;
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter 2 arrays"<<endl;

			//Input for 2 arrays
				cout<<"Enter size of first array"<<endl;
				do
				{
					cin>>size;
					if(size<=0)
						cout<<"invalid input for size....enter a positive number"<<endl;
				}
				while(size<=0);
				ARRAY a1(size,0);
				cin>>a1;

			//Input for 2 arrays
				cout<<"Enter size of 2nd array"<<endl;
				do
				{
					cin>>size;
					if(size<=0)
						cout<<"invalid input for size....enter a positive number"<<endl;
				}
				while(size<=0);
				ARRAY a2(size,0);
				cin>>a2;
			}

			break;

			case 2:
			{
				if(size==0)
				{
					cout<<"First enter two arrays"<<endl;
					break;
				}
				else
					if(a1.getSize()!=a2.getSize)
					{
						cout<<"Addition not possible"<<endl;
						break;
					}
					ARRAY c(a1.getSize(),0);
					c=a1+a2;
					cout<<"the sum array is ";
					cout<<c;
					break;
				}

				case 3:
					int n;
					cout<<"Enter scalar"<<endl;
					cin>>n;
					ARRAY c(a1.getSize(),0);
					c=n*a1;
					cout<<"Doing "<<n<<"*a1 gives "<<endl;
					cout<<c;
					c=a1*n;
					cout<<"Doing a1*"<<n<<" gives"<<endl;
					cout<<c;

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