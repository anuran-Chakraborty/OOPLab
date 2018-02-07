#include<iostream>

using namespace std;

class ARRAY
{
	int size;
	int* arr;

public:
	//Parametrized constructor
	ARRAY(int s=0,int val=0)
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
		// size=len(array);
		// arr=new int[size];
		int i;
			//Initialise elements
		for(i=0;i<size;i++)
			arr[i]=array[i];

	}

	void operator =(const int* array)
	{	

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

	//Function to display array
	void display()
	{
		int i;
		for(i=0;i<size;i++)
			cout<<arr[i]<<" ";

	}

	friend ARRAY operator *(int n,ARRAY a);
	friend ostream & operator <<(ostream& ost,ARRAY& a);


};

ARRAY operator *(int n, ARRAY a)
{
	int i;
	ARRAY c(a.size,0);
	for(i=0;i<a.size;i++)
		c.arr[i]=n*a.arr[i];
	return c;
}

ostream & operator <<(ostream& ost,ARRAY& a)
{
	int i;
	for(i=0;i<a.size;i++)
		ost<<a.arr[i]<<" ";
	return ost;
}

int main()
{
	int ch,size=0,i,ind;
	int* arr1;
	int* arr2;
	ARRAY a1;
	ARRAY a2;
	do
	{
		cout<<"1. Enter 2 arrays"<<endl<<"2. Add the two arrays"<<endl<<"3. Multiply first array by scalar"<<endl<<"4. Get ith element of first array"<<endl<<"5.Exit"<<endl<<"Enter your choice"<<endl;
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
				arr1=new int[size];
				cout<<"Enter "<<size<<" elements into array"<<endl;

				for(i=0;i<size;i++)
				{
					cin>>arr1[i];
				}

				ARRAY c(size);
				c=arr1;
				a1=c;

				cout<<"Enter size of second array"<<endl;
				do
				{
					cin>>size;
					if(size<=0)
						cout<<"invalid input for size....enter a positive number"<<endl;
				}
				while(size<=0);
				arr2=new int[size];
				cout<<"Enter "<<size<<" elements into array"<<endl;

				for(i=0;i<size;i++)
				{
					cin>>arr2[i];
				}

				ARRAY d(size);
				d=arr2;
				a2=d;

				break;
			}

			case 2:
			
			{
				if(size==0)
				{
					cout<<"First enter two arrays"<<endl;
					break;
				}
				else
					if(a1.getSize()!=a2.getSize())
					{
						cout<<"Addition not possible"<<endl;
						break;
					}
					ARRAY c(a1.getSize(),0);
					c=a1+a2;
					cout<<"the sum array is ";
					cout<<c<<endl;
					break;
				}
				

				case 3:
				{
					if(size==0)
					{
						cout<<"First enter two arrays"<<endl;
						break;
					}
					int n;
					cout<<"Enter scalar"<<endl;
					cin>>n;
					ARRAY c(a1.getSize(),0);
					c=n*a1;
					cout<<"Doing "<<n<<"*a1 gives "<<endl;
					cout<<c<<endl;
					c=a1*n;
					cout<<"Doing a1*"<<n<<" gives"<<endl;
					cout<<c<<endl;
					break;
				}

				case 4:
				{
					if(size==0)
					{
						cout<<"First enter two arrays"<<endl;
						break;
					}
					do
					{
						cout<<"Enter index"<<endl;
						cin>>ind;
						if(ind>=a1.getSize() || ind<0)
							cout<<"Invalid index"<<endl;
					}
					while(ind>=a1.getSize() || ind<0);
					cout<<"The required element is "<<a1[ind]<<endl;
					break;
				}

				case 5:
				cout<<"Exitting"<<endl;
				exit(0);

				default:
				cout<<"Invalid choice"<<endl;
			}
		}
		while(ch!=5);
		return 0;
	}