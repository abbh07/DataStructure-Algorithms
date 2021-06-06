//O(V + E logV)
/*
4 5
1 0 1
2 1 2
3 0 2
4 0 3
5 2 3
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100;
int nodes, edges;
vector<bool> visited(MAX,false);
vector<int> dis(MAX,100000);

void dijkstras(vector< pair<int,int> > adj[], int vertex)
{
	dis[vertex] = 0;
	priority_queue < pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > > q;
	q.push(make_pair(0,vertex));//Source vertex
	pair<int,int> p;

	while(!q.empty())
	{
		p = q.top();
		q.pop();
		int x = p.second;
		int cost = p.first;
		if(visited[x])
			continue;
		visited[x] = true;
		for(int i=0;i<adj[x].size();i++)
		{
			int e = adj[x][i].second;
			int c = adj[x][i].first;
			if(dis[x] + c < dis[e])
			{
				dis[e] = dis[x] + c;
				q.push(make_pair(dis[e],e));
			}
		}
	}
}

int main()
{
	cin>>nodes>>edges;
	vector< pair<int,int> > adj[MAX];
	int x, y, cost;
	for(int i=0;i<edges;i++)
	{
		cin>>cost>>x>>y;
		adj[x].push_back(make_pair(cost,y));
		adj[y].push_back(make_pair(cost,x));
	}
	dijkstras(adj,0);
	for(int i=0;i<nodes;i++)
	{
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	return 0;
}