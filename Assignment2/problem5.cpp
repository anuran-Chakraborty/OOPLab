#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<iterator>
#include<climits>
#include<functional>

using namespace std;

typedef pair<int,int> edge;

class Compare
{
public:
	bool operator()(const edge& e1,const edge& e2)
	{
		return (e1.second>=e2.second);
	}
};

class Graph
{
	int V;
	list<edge> *adjList;

public:
	//Constructor
	Graph(int v)
	{
		V=v;
		adjList=new list<edge> [V];
	}

	//Function to add edge
	void addEdge(int s,int d,int w)
	{
		adjList[s].push_back(make_pair(d,w));
		adjList[d].push_back(make_pair(s,w));
	}

	//Find MST
	void findMst()
	{
		//Declare priority queue
		priority_queue< edge,vector<edge>,Compare > prq;
		

		int src=0;
		vector<int> key(V,INT_MAX);
		vector<int> parent(V,-1);
		vector<bool> mstSet(V,false);

		prq.push(make_pair(0,src));
		key[src]=0;

		cout<<"chk2"<<endl;

		while(!prq.empty())
		{
			int u=prq.top().first;
			prq.pop();
			mstSet[u]=true;

			//For all vertices v adjacent to u 
			list<edge>::iterator i;
			for(i=adjList[u].begin();i!=adjList[u].end();i++)
			{
				int v=(*i).first;
				int wt=(*i).second;

				if(mstSet[v]==false && key[v] > wt)
				{
					key[v]=wt;
					prq.push(make_pair(v,key[v]));
					parent[v]=u;
				}
			}

		}


		//Print mst
		for(int i=1;i<V;i++)
		{
			cout<<(char)(parent[i]+'A')<<"-"<<(char)(i+'A')<<"\t"<<endl;
		}
	}

};

int main()
{
	int V;
	int wt;
	do
	{
		cout<<"Enter number of cities"<<endl;
		cin>>V;
		if(V<=0)
			cout<<"invalid input"<<endl;
	}
	while(V<=0);

	Graph g(V);

	cout<<"Enter weight of edge between ggiven vertices..0 or neagtive input indicates no edge"<<endl;
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(j>i)
			{
				cout<<"Enter weight of edge between vertex "<<(char)(i+'A')<<" and vertex "<<(char)(j+'A')<<": ";
				cin>>wt;
				if(wt>0)
				{
					g.addEdge(i,j,wt);
				}
			}
		}
	}
	cout<<"c1"<<endl;
	g.findMst();

	return 0;
}