#include <iostream>
#include <vector>

using namespace std;

void print_spiral(vector< vector<int> > v, int m, int n)
{
	int top = 0, bottom = m-1;
	int left = 0, right = n-1;
	int dir = 0;
	while(top<=bottom && left<=right)
	{
		if(dir == 0)
		{
			for(int i=left;i<=right;i++)
			{
				cout<<v[top][i]<<" ";
			}
			top++;
			dir = 1;
		}
		else if(dir == 1)
		{
			for(int i=top;i<=bottom;i++)
			{
				cout<<v[i][right]<<" ";
			}
			right--;
			dir = 2;
		}
		else if(dir == 2)
		{
			for(int i=right;i>=left;i--)
			{
				cout<<v[bottom][i]<<" ";
			}
			bottom--;
			dir = 3;
		}
		else if(dir == 3)
		{
			for(int i = bottom;i>=top;i--)
			{
				cout<<v[i][left]<<" ";
			}
			left++;
			dir = 0;
		}
	}
	cout<<endl;
}

int main()
{
	int m,n;//rows,column
	cin>>m>>n;
	vector < vector<int> > v(m,vector<int> (n) );
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[i][j];
		}
	} 
	print_spiral(v,m,n);
	return 0;
}