#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int getSum(int *cost, int l, int h)
{
	int sum = 0;
	for(int i=l;i<=h;i++)
	{
		sum += cost[i];
	}
	return sum;
}

//O(n^4)
int getOptimalSearchCost(int *nodes, int *cost, int n)
{
	int t[n][n];
	for(int i=0;i<n;i++)
	{
		t[i][i] = cost[i];
	}

	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j = i+l-1;
			int sum = getSum(cost,i,j);
			t[i][j] = INT_MAX;
			for(int k = i;k<=j;k++)
			{
				int val = sum + (k-1 < i ? 0 : t[i][k-1]) + (k+1 > j ? 0 : t[k+1][j]);
				if(val < t[i][j])
				{
					t[i][j] = val;
				}
			}
		}
	}

	return t[0][n-1];
}

int main()
{
	int nodes[] = {10,12,16,21};
	int cost[] = {4,2,6,3};
	int n = sizeof(nodes)/sizeof(nodes[0]);
	cout<<getOptimalSearchCost(nodes,cost,n)<<endl;
	return 0;
}