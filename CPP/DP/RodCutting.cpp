#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Similar to unbounded knapsack
int cutting_rod_max_profit(int *rod, int *price, int len, int n)
{
	int t[n+1][len+1];
	for(int i=0;i<=len;i++)
	{
		t[0][i] = 0;
	}
	for(int i=0;i<=n;i++)
	{
		t[i][0] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(rod[i-1] <= j)
			{
				t[i][j] = max(t[i-1][j], price[i-1] + t[i][j - rod[i-1]]);
			}
			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][len];
}

int main()
{
	int len = 5;
	int rod[] = {1,2,3,4};
	int price[] = {2,5,7,8};
	int n = sizeof(rod)/sizeof(rod[0]);
	cout<<cutting_rod_max_profit(rod,price,len,n)<<"\n";
	return 0;
}