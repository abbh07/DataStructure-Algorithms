//Exponential solution using backtracking
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool nqueen(int n, int row, vector< pair<int,int> > &p)
{
	if(n == row)
	{
		return true;
	}
	int col;
	for(col = 0;col<n;col++)
	{
		bool found_safe = true;
		for(int k=0;k<row;k++)
		{
			if(p[k].second == col || p[k].first - p[k].second == row-col || p[k].first + p[k].second == row+col)
			{
				found_safe = false;
			}
		}
		if(found_safe)
		{
			p[row].first = row;
			p[row].second = col;
			if(nqueen(n,row+1,p))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int n = 8;
	vector< pair<int,int> > p(n,make_pair(0,0));
	bool sol = nqueen(n,0,p);
	if(sol)
	{
		for(int i=0;i<n;i++)
		{
			cout<<p[i].first<<" "<<p[i].second<<endl;
		}
	}
	else
	{
		cout<<"No solution possible!"<<endl;
	}
	return 0;
}
