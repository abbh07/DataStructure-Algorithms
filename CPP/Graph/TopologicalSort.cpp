#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int nodes = 5;
vector<int> res;
vector<bool> visited(nodes,false);

void topo_sort_bfs(int adj[][nodes])
{
	vector<int> in_degree(nodes,0);
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(adj[i][j])
			{
				in_degree[j]++;
			}
		}
	}

	queue<int> q;
	int vertex;

	for(int i=0;i<nodes;i++)
	{
		if(in_degree[i] == 0 && !visited[i])
		{
			q.push(i);
			visited[i] = true;
		}

		while(!q.empty())
		{
			vertex = q.front();
			q.pop();
			cout<<vertex<<" ";

			for(int j=0;j<nodes;j++)
			{
				if(adj[vertex][j] && !visited[j])
				{
					in_degree[j]--;
					if(in_degree[j] == 0)
					{
						q.push(j);
						visited[j] = true;
					}
				}
			}

		}

	}
	cout<<endl;

} 

void topo_sort_dfs(int adj[][nodes], int vertex)
{
	visited[vertex] = true;
	for(int i=0;i<nodes;i++)
	{
		if(adj[vertex][i] && !visited[i])
		{
			topo_sort_dfs(adj,i);
		}
	}
	res.push_back(vertex);
}

int main()
{
	int adj[][nodes] = {{0,1,1,0,0},{0,0,1,1,0},{0,0,0,1,1},{0,0,0,0,0},{0,0,0,0,0}};
	//topo_sort_bfs(adj);
	topo_sort_dfs(adj,0);
	reverse(res.begin(),res.end());
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}