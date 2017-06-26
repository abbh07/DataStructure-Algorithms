/*
4 5
2 1 -3 -4 5
0 6 3 4 1
2 -2 -1 4 -5
-3 3 1 0 3
o/p:
18
6 3 4 
-2 -1 4 
3 1 0
*/

//2D Kadane
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct kadaneResult
{
	int maxsum;
	int start;
	int end;
}res;

struct result
{
	int maxsum;
	int left;
	int right;
	int top;
	int bottom;
}finalResult;

void kadane(vector<int> &t)
{
	res.maxsum = INT_MIN;
	res.start = -1;
	res.end = -1;
	int sum = 0;
	int currentStart = 0;
	for(int i=0;i<t.size();i++)
	{
		sum += t[i];
		if(sum < 0)
		{
			sum = 0;
			currentStart = i+1;
		}
		if(sum > res.maxsum)
		{
			res.maxsum = sum;
			res.start = currentStart;
			res.end = i;
		}
	}
}

//O(col*col*row)
int max_sum_submatrix(vector< vector<int> > &v, int r, int c)
{
	finalResult.maxsum = INT_MIN;
	finalResult.left = 0;
	finalResult.right = 0;
	finalResult.top = 0;
	finalResult.bottom = 0;
	vector<int> temp(r);
	for(int left = 0;left < c;left++)
	{
		for(int i=0;i<r;i++)
		{
			temp[i] = 0;
		}
		for(int right = left;right<c;right++)
		{
			for(int i=0;i<r;i++)
			{
				temp[i] += v[i][right];
			}
			kadane(temp);
			if(res.maxsum > finalResult.maxsum)
			{
				finalResult.maxsum = res.maxsum;
				finalResult.left = left;
				finalResult.right = right;
				finalResult.top = res.start;
				finalResult.bottom = res.end;
			}
		}
	}
	return finalResult.maxsum;
}

int main()
{
	int m;
	cin>>m;
	int n;
	cin>>n;
	vector< vector<int> > v(m,vector<int>(n));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[i][j];
		}
	}
	cout<<max_sum_submatrix(v,m,n)<<"\n";
	int l = finalResult.left;
	int r = finalResult.right;
	int t = finalResult.top;
	int b = finalResult.bottom;

	for(int i=t;i<=b;i++)
	{
		for(int j=l;j<=r;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}