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
	return 0;
}