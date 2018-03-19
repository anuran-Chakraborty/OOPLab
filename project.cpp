#include<bits/stdc++>

using namespace std;

typedef list<string> edges;
class Graph
{
	vector<edges> v;

public:
	//Adding member is adding a vertex
	void add_member(string x)
	{
		vector<edges>::iterator it=v.end();
		it++;
		*it.push_back(x);
	}

	//Check if a name is there in a list
	vector<edges>::iterator isExisting(string x)
	{
		vector<edges>::iterator it;
		for(it=v.begin();it!=v.end();it++)
		{
			list<string>::iterator i=*it.begin();
			if(*i==x)
				return it;
		}
		return NULL;
	}
	//Adding followers is adding a vertex
	void follow(string x,string y)
	{
		if(!isExisting(x) || !isExisting(y))
			cout<<"Name does not exist"<<endl;
		else
		{
			vector<edges>::iterator it;
			for(it=v.begin();it!=v.end();it++)
			{
				list<string>::iterator i=*it.begin();
				if(*i==x)
				{
					*it.push_back(y);
					cout<<"Follower successfully added"<<endl;
					break;
				}
			}	
		}
	}

	//To find members who follow x
	void get_followers(string x)
	{
		if(!isExisting(x))
			cout<<"Name does not exist"<<endl;
		else
		{
			cout<<"Followers of "<<x<<" are: "
			vector<edges>::iterator it;
			for(it=v.begin();it!=v.end();it++)
			{
				list<string>::iterator i=*it.begin();
				if(*i==x)
				{	
					i++;
					for(;i!=*it.end();i++)
						cout<<*i<<"  ";
					break;
				}
			}	
		}
	}

	//Find members who follow both x and y
	void mutual_followers(string x,string y)
	{
		if(!isExisting(x) || !isExisting(y))
			cout<<"Name does not exist"<<endl;
		else
		if(x==y)
			cout<<"Same names not allowed"<<endl;
		else
		{
			int count=0;
			vector<edges>::iterator itx=isExisting(x);
			vector<edges>::iterator ity=isExisting(y);
			list<string>::iterator itxlist;
			list<string>::iterator itylist;

			cout<<"The mutual followers of "<<x<<" and "<<y<<" are: "
			for(itxlist=*itx.begin();itxlist!=*itx.end();)
			{
				itxlist++;
				itylist=*ity.begin();
				itylist++;
				for(;itylist!=*ity.end();itylist++)
				{
					if(*itylist==*itxlist)
					{
						cout<<*itylist<<" ";
						count++;
					}
				}
			}

			if(count==0)
				cout<<"No mutual followers"<<endl;
		}
	}

}

int main()
{
	Graph g;
	int c;
	string name;

	cout<<"1. ADD \n2. "

	return 0;
}