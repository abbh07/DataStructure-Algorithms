#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coin_change(int *coins, int total, int size)
{
	vector< vector<int> > t(size+1,vector<int> (total+1));

	for(int i=0;i<=size;i++)
	{
		t[i][0] = 1;
	}

	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=total;j++)
		{
			if(j<coins[i-1])
			{
				t[i][j] = t[i-1][j];
			}
			else
			{
				t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
			}
		}
	}

	return t[size][total];
}

int main()
{
	int coins[] = {1,2,3};
	int size = sizeof(coins)/sizeof(coins[0]);
	int total = 5;
	cout<<coin_change(coins,total,size)<<endl;
	return 0;
}