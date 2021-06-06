/*
4 6
1 0 0 1 1 1
1 0 1 1 0 1
0 1 1 1 1 1
0 0 1 1 1 1
o/p = 8
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int maximum_histogram(vector<int> &hist)
{
	int n = hist.size();
	int i = 0;
	int area;
	int maxarea = INT_MIN;
	stack<int> s;
	while(i < n)
	{
		if(s.empty() || hist[i] >= hist[s.top()])
		{
			s.push(i++);
		}
		else
		{
			int t = s.top();
			s.pop();
			if(s.empty())
			{
				area = hist[t] * i;
			}
			else
			{
				area = hist[t] * (i-s.top()-1);
			}
			if(area > maxarea)
			{
				maxarea = area;
			}
		}
	}
	while(!s.empty())
	{
		int t = s.top();
		s.pop();
		if(s.empty())
		{
			area = hist[t] * i;
		}
		else
		{
			area = hist[t] * (i-s.top()-1);
		}
		if(area > maxarea)
		{
			maxarea = area;
		}
	}

	return maxarea;
}

//O(r * c * c)
int maximum_rectangle_1s(vector< vector<int> > &v, int r, int c)
{
	vector<int> hist(c);
	int area;
	int maxarea = INT_MIN;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(v[i][j] == 0)
			{
				hist[j] = 0;
			}
			else
			{
				hist[j] += v[i][j];
			}
		}
		area = maximum_histogram(hist);
		if(area > maxarea)
		{
			maxarea = area;
		}
	}

	return maxarea;
}

int main()
{
	int r;
	cin>>r;
	int c;
	cin>>c;
	vector< vector<int> > v(r,vector<int>(c));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>v[i][j];
		}
	}
	cout<<maximum_rectangle_1s(v,r,c)<<"\n";
	return 0;
}