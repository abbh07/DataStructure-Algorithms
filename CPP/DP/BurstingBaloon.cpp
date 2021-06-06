#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int burst_baloon(int *cost, int n)
{
	vector< vector<int> > t(n,vector<int> (n));
	for(int l=1;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j = i+l-1;
			for(int k=i;k<=j;k++)
			{
				int left = 1;
				int right = 1;
				if(i != 0)
				{
					left = cost[i-1];
				}				
				if(j != n-1)
				{
					right = cost[j+1];
				}

				int before = 0;
				int after = 0;
				if(i != k)
				{
					before = t[i][k-1];
				}
				if(j != k)
				{
					after = t[k+1][j];
				}

				t[i][j] = max(t[i][j],before + left*cost[k]*right + after);
			}
		}
	}

	return t[0][n-1];
}

int main()
{
	int cost[] = {3,1,5,8};
	int n = sizeof(cost)/sizeof(cost[0]);
	cout<<burst_baloon(cost,n)<<"\n";
	return 0;
}