//Prims MST
//O((V+E) logV)
/*
4 5
1 0 1
2 1 2
3 0 2
4 0 3
5 2 3
o/p = 7
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100;
int nodes,edges;

//Adjacency list of cost and vertex
vector< pair<int,int> > adj[MAX];
bool visited[MAX];

int prims(int x)
{
	//Min Priority Queue
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
	int mincost = 0;
	pair<int,int> p;
	q.push(make_pair(0,x));
	int temp;
	while(!q.empty())
	{
		p = q.top();
		q.pop();
		x = p.second;
		//Check for loop
		if(visited[x])
			continue;
		mincost += p.first;
		visited[x] = true;
		for(int i=0;i<adj[x].size();i++)
		{
			temp = adj[x][i].second;
			if(!visited[temp])
			{
				q.push(adj[x][i]);
			}
		}
	}

	return mincost;
}

int main()
{
	cin>>nodes>>edges;
	int x,y,cost;

	for(int i=0;i<edges;i++)
	{
		cin>>cost>>x>>y;
		adj[x].push_back(make_pair(cost,y));
		adj[y].push_back(make_pair(cost,x));
	}
	//Prims starting from vertex 0
	cout<<prims(0)<<endl;
	return 0;
}