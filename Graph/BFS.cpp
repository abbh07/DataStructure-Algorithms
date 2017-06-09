#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int m = 6;
const int n = 6;

void bfs(int adj[m][n], bool visited[], int index)
{
	queue<int> q;
	visited[index] = true;
	q.push(index);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		cout<<node<<" ";
		for(int i=0;i<n;i++)
		{
			if(adj[node][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main()
{
	int adj_matrix[m][n] = {{0,1,1,0,0,0},{1,0,1,1,1,0},{1,1,0,1,0,0},{0,1,1,0,0,0},{0,1,0,0,0,1},{0,0,0,0,1,0}};
	bool visited[m] = {false};
	bfs(adj_matrix,visited,0);
	cout<<endl;
	return 0;
}