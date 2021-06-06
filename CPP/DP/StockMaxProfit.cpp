/*
Given an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Transactions cannot occur in parallel.
One transaction should complete before starting another transaction.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_profit(int *prices, int n, int k)
{
	vector< vector<int> > t(k+1,vector<int>(n+1));
	int maxdiff = 0;
	for(int i=1;i<=k;i++)
	{
		maxdiff = -prices[0];
		for(int j=1;j<=n;j++)
		{
			t[i][j] = max(t[i][j-1],prices[j-1] + maxdiff);
			maxdiff = max(maxdiff,t[i-1][j] - prices[j-1]);
		}
	}

	return t[k][n];
}

int main()
{
	int prices[] = {2,5,7,1,4,3,1,3};
	int k = 3;
	int n = sizeof(prices)/sizeof(prices[0]);
	cout<<max_profit(prices,n,k)<<"\n";
	return 0;
}