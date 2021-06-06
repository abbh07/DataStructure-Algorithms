//O(v3)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int nodes = 4;

void floyd_warshall(int cost[][nodes])
{
	//DP
	for(int k=0;k<nodes;k++)
	{
		for(int i=0;i<nodes;i++)
		{
			for(int j=0;j<nodes;j++)
			{
				cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
			}
		}
	}
}

int main()
{
	int cost[nodes][nodes] = {{0,1,3,4},{1,0,2,100000},{3,2,0,5},{4,100000,5,0}};
	floyd_warshall(cost);
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			cout<<cost[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}