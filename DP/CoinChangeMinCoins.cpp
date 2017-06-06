#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int coin_change(vector<int> &coin, int sum)
{
	int l = coin.size();
	vector<int> v(sum+1,INT_MAX);
	v[0] = 0;
	vector<int> r(sum+1,-1);
	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<l;j++)
		{
			if(coin[j] <= i)
			{
				if(v[i-coin[j]] != INT_MAX)
				{					
					v[i] = min(v[i], v[i-coin[j]] + 1);
					r[i] = j;	
				}
			}
		}
	}
	l = sum;
	if(r[sum] == -1)
	{
		cout<<"No solution!\n";
	}
	else
	{
		cout<<"Coins:\n";
		while(l != 0)
		{
			int j = r[l];
			cout<<coin[j]<<" ";
			l = l - coin[j];
		}
		cout<<endl;
	}
	return v[sum];
}

int main()
{
	int n;
	cout<<"Enter number of coins:"<<endl;
	cin>>n;
	vector<int> coin(n);
	cout<<"Enter the denominations:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	cout<<"Enter the sum:"<<endl;
	int total;
	cin>>total;
	int res = coin_change(coin,total);
	cout<<"Minimum number of coins required: "<<endl;
	cout<<res<<endl;
	return 0;
}