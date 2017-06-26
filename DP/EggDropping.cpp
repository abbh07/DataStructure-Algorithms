#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int egg_drop_attempts(int eggs, int floors)
{
	int t[eggs+1][floors+1];
	for(int i=0;i<=floors;i++)
	{
		t[1][i] = i;
	}
	for(int i=2;i<=eggs;i++)
	{
		for(int j=1;j<=floors;j++)
		{
			t[i][j] = INT_MAX;
			for(int k=1;k<=j;k++)
			{
				int val = 1 + max(t[i-1][k-1],t[i][j-k]);
				if(val < t[i][j])
				{
					t[i][j] = val;
				}
			}
		}
	}

	return t[eggs][floors];
}

int main()
{
	int eggs = 2;
	int floors = 6;
	cout<<egg_drop_attempts(eggs,floors)<<"\n";
	return 0;
}