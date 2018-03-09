#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class CoinToss
{
	int count;

public:
	CoinToss()
	{
		count=0;
	}

	//Function to toss coin
	void tossCoin()
	{
		int flip;
		int c=0;
		srand(time(NULL));

		do
		{
			flip=rand()%2; //Gives either 0 or 1
			if(flip)
			{
				cout<<"Heads\n";
				count++;
				c++;
			}
			else
			{
				cout<<"Tails\n";
				c=0;
			}
		}
		while(c<3);
	}

	//Function to display
	void display()
	{
		cout<<"It took "<<count<<" tosses to get 3 consecutive heads\n";
	}
};

int main()
{
	CoinToss ct;
	ct.tossCoin();
	ct.display();
	return 0;
}