/*
5 5
0 0 0 0 X
X 0 X X X
X 0 X 0 X
X X X X X
0 0 X X X
o/p:
3
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_sub_square(vector< vector<char> > &v, int r, int c)
{
	vector< vector< pair<int,int> > > t(r,vector<pair<int,int> >(c));
	//first - vertical contiguous X's
	//second - horizontal contiguous X's
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(v[i][j] == 'X')
			{
				if(i==0 && j==0)
				{
					t[i][j].first = 1;
					t[i][j].second = 1;
				}
				else if(i==0)
				{
					t[i][j].first = 1;
					t[i][j].second = t[i][j-1].second + 1;
				}
				else if(j==0)
				{
					t[i][j].first = t[i-1][j].first + 1;
					t[i][j].second = 1;
				}
				else
				{
					t[i][j].first = t[i-1][j].first + 1;
					t[i][j].second = t[i][j-1].second + 1;
				}
			}
		}
	}

	int maxval = 0;
	for(int i = r-1;i>=0;i--)
	{
		for(int j = c-1;j>=0;j--)
		{
			if(t[i][j].first == 0 || t[i][j].first == 1 || t[i][j].second == 1)
			{
				continue;
			}
			int minval = min(t[i][j].first,t[i][j].second);
			int k = 0;
			for(k=minval;k>1;k--)
			{
				if(t[i][j-k+1].first >= k && t[i-k+1][j].second >=k)
				{
					break;
				}
			}
			if(maxval < k)
			{
				maxval = k;
			}
		}
	}

	return maxval;
}

int main()
{	
	int r;
	cin>>r;
	int c;
	cin>>c;
	vector< vector<char> > v(r,vector<char>(c));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>v[i][j];
		}
	}
	cout<<get_sub_square(v,r,c)<<"\n";
	return 0;
}