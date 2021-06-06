#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getWays(int n, int m)
{
	int t[n+1];
	t[0] = t[1] = 1;
	for(int i=2;i<=n;i++)
	{
		t[i] = 0;
		for(int j=1;j<=m && j<=i;j++)
		{
			t[i] += t[i-j];
		}
	}
	return t[n];
}

int main()
{
	int n = 4; //ways to reach the 4th stair
	int m = 2; //the person can climb 1 stair or 2 stairs at a time
	cout<<getWays(n,m)<<"\n";
	return 0;
}