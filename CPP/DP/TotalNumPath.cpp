//Total number of paths from top left to bottom right in a 2D matrix
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int m = 4;
const int n = 4;

int total_path(int cost[m][n])
{
	vector< vector<int> > t(m,vector<int>(n));
	for(int i=0;i<m;i++)
	{
		t[i][0] = 1;
	}
	for(int i=0;i<n;i++)
	{
		t[0][i] = 1;
	}

	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			t[i][j] = t[i-1][j] + t[i][j-1];
		}
	}

	return t[m-1][n-1];
}

int main()
{
	int cost_matrix[m][n] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<total_path(cost_matrix)<<endl;
	return 0;
}