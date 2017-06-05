#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//T(n) = summation(T(i-1) * T(n-i)) for all i>=1 and i<=n

//Exponential time complexity
int catalan_recursive(int n)
{
	if(n<=1)
		return 1;
	int res = 0;
	for(int i=1;i<=n;i++)
	{
		res += catalan_recursive(i-1)*catalan_recursive(n-i);
	}
	return res;
}

//O(n^2) using dp(memoization)
int catalan_dp(int n)
{
	vector<int> res(n+1,0);
	res[0] = res[1] = 1;
	for(int i = 2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			res[i] += res[j-1]*res[i-j];
		}
	}
	return res[n];
}

//O(n)
//T(n) = multiplication((n+k)/k) for all k>=2 and k<=n 
int catalan_optimized(int n)
{
	if(n<=1)
		return 1;
	int res1 = 1;
	int res2 = 1;
	for(int k=2;k<=n;k++)
	{
		res1 *= (n+k);
		res2 *= k; 
	}
	return res1/res2;
}

int main()
{
	cout<<"Catalan Series:\n";
	for(int i=0;i<=7;i++)
	{
		cout<<catalan_optimized(i)<<" ";
	}
	cout<<endl;
	return 0;
}