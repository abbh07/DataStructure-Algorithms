//Kruskal's Minimal Spanning Tree
//O(E logV)
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

using namespace std;

//Maximum 100 edges
const int MAX = 100;

//Disjoint set
int set[MAX];

int nodes, edges;

void initialize()
{
	for(int i=0;i<MAX;i++)
	{
		set[i] = i;
	}
}

int root(int x)
{
	while(set[x] != x)
	{
		set[x] = set[set[x]];
		x = set[x];
	}
	return x;
}

void disjoint_set_union(int x, int y)
{
	int p = root(x);
	int q = root(y);
	//Update the root of x to point to root of y
	set[p] = set[q];
}

int kruskal(pair<int, pair<int,int> > p[])
{
	int x,y,cost;
	int mincost = 0;
	for(int i=0;i<edges;i++)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;

		//Check if x and y do not form a cycle, include the edge in MST
		if(root(x) != root(y))
		{
			mincost += cost;
			disjoint_set_union(x,y);
		}
	}
	return mincost;
}

int main()
{
	pair<int, pair<int,int> > p[MAX];
	cin>>nodes>>edges;
	int x, y, cost;
	initialize();
	for(int i=0;i<edges;i++)
	{
		cin>>cost>>x>>y;
		p[i] = make_pair(cost,make_pair(x,y));
	}
	sort(p,p+edges);
	cout<<kruskal(p)<<endl;
	return 0;
}