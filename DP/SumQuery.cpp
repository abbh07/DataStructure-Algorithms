/*
4 4
2 0 -3 4
6 3 2 -1
5 4 7 3
2 -6 8 1
1 1
3 2
o/p:
18
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > build_sum_matrix(vector< vector<int> > &v, int r, int c)
{
	vector< vector<int> > t(r+1,vector<int> (c+1));
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			t[i][j] = t[i-1][j] + t[i][j-1] + v[i-1][j-1] - t[i-1][j-1];
		}
	}
	return t;
}

int getSum(vector< vector<int> > &t, int r1, int c1, int r2, int c2)
{
	r1++;
	c1++;
	r2++;
	c2++;
	int sum = t[r2][c2] - t[r1-1][c2] - t[r2][c1-1] + t[r1-1][c1-1];
	return sum;
}

int main()
{
	int r;
	cin>>r;
	int c;
	cin>>c;
	vector< vector<int> > v(r,vector<int> (c));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>v[i][j];
		}
	}
	vector< vector<int> > t = build_sum_matrix(v,r,c);
	int r1;
	int c1;
	int r2;
	int c2;
	cin>>r1>>c1>>r2>>c2;
	cout<<getSum(t,r1,c1,r2,c2)<<"\n";
	return 0;
}