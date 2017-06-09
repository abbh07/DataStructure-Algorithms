#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int m = 3;
const int n = 4;

int min_cost_path(int cost_matrix[m][n])
{
	int t[m][n];
	t[0][0] = cost_matrix[0][0];
	for(int i=1;i<m;i++)
	{
		t[i][0] = cost_matrix[i][0] + cost_matrix[i-1][0];
	}
	for(int i=1;i<n;i++)
	{
		t[0][i] = cost_matrix[0][i] + cost_matrix[0][i-1];
	}

	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			t[i][j] = cost_matrix[i][j] + min(t[i-1][j], t[i][j-1]);
		}
	}

	return t[m-1][n-1];
}

int main()
{
	int cost_matrix[m][n] = {{1,3,5,8},{4,2,1,7},{4,3,2,3}};
	cout<<min_cost_path(cost_matrix)<<endl;
}