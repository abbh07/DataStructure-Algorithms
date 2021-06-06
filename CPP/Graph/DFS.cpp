#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int m = 6;
const int n = 6;

void dfs(int adj[m][n], bool visited[], int index)
{
	visited[index] = true;
	cout<<index<<" ";
	for(int i=0;i<n;i++)
	{
		if(adj[index][i]==1 && !visited[i])
		{
			dfs(adj,visited,i);
		}
	}
}

int main()
{
	int adj_matrix[m][n] = {{0,1,1,0,0,0},{1,0,1,1,1,0},{1,1,0,1,0,0},{0,1,1,0,0,0},{0,1,0,0,0,1},{0,0,0,0,1,0}};
	bool visited[m] = {false};
	dfs(adj_matrix, visited,0);
	cout<<endl; 
	return 0;
}