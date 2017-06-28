#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> get_score(int *pots, int n)
{
	vector< vector< pair<int,int> > > t(n, vector< pair<int,int> > (n));
	for(int i=0;i<n;i++)
	{
		t[i][i].first = pots[i];
		t[i][i].second = 0;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j = i+l-1;
			if(t[i+1][j].second + pots[i] > t[i][j-1].second + pots[j])
			{
				t[i][j].first = t[i+1][j].second + pots[i];
				t[i][j].second = t[i+1][j].first;
			}
			else
			{
				t[i][j].first =  t[i][j-1].second + pots[j];
				t[i][j].second = t[i][j-1].first;
			}
		}
	}
	return t[0][n-1];
}

int main()
{
	int pots[] = {3,9,1,2};
	int n = sizeof(pots)/sizeof(pots[0]);
	pair<int,int> p = get_score(pots,n);
	cout<<p.first<<" "<<p.second<<"\n";
	return 0;
}