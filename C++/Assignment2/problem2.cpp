#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Pascal
{
	int n;

public:
	Pascal(int num=0)
	{
		n=num;
	}

	//Function to calculate c(n,k)
	int calc(int i,int j)
	{
		if(j==1 || j==i)
			return 1;
		else
			return calc(i-1,j-1)+calc(i-1,j);
	}

	//Function to display pascals triangle
	void display()
	{
		int i,j,spc=n-1;

		for(i=1;i<=n;i++)
		{
			//Printing spaces
			for(j=1;j<=spc;j++)
				cout<<" ";
			//Printing numbers
			for(j=1;j<=i;j++)
				cout<<calc(i,j)<<" ";
			cout<<endl;
			spc--;
		}
	}
};

int main()
{
	int num;
	do
	{
		cout<<"Enter number of rows"<<endl;
		cin>>num;
		if(num<=0)
			cout<<"Invalid input"<<endl;
	}
	while(num<0);
	Pascal p(num);
	p.display();
	return 0;

}