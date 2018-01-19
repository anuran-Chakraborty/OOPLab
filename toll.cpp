#include <iostream>
#include <cstdlib>

using namespace std;

class TollTax
{
	int cars;
	float totalToll;

public:
		//Constructor
	TollTax(int c=0,float tt=0.0)
	{
		cars=c;
		totalToll=tt;
	}

		//Method for receiving toll
	void receiveToll()
	{
		float toll;
		cout<<"Enter the toll tax amount to be collected"<<endl;
		cin>>toll;
		cout<<"Toll amount collected is "<<toll<<endl;
		totalToll+=toll;
		cars++;
	}

		//Function to display total number of cars passed
	void displayCars()
	{
		cout<<"The total number of cars that passed is : "<<cars<<endl;
	}

		//Function to display total toll collected
	void displayToll()
	{
		cout<<"The total toll tax collected is : "<<totalToll<<endl;
	}

};

int main()
{
	int ch;
	TollTax t1;
	do
	{
		cout<<"1. Receive toll"<<endl<<"2. Display total number of cars passed"<<endl<<"3. Display total toll collected"<<endl<<"4. Exit"<<endl<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			t1.receiveToll();
			break;

			case 2:
			t1.displayCars();
			break;

			case 3:
			t1.displayToll();
			break;

			case 4:
			cout<<"Exitting"<<endl;
			exit(0);

			default:
			cout<<"Invalid choice"<<endl;
		}
	}
	while(ch!=4);
	return 0;
}