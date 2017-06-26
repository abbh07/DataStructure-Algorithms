/*
6   
1 3 5
2 5 6
4 6 5
6 7 4
5 8 11
7 9 2
o/p = 17
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator (const pair < pair<int,int>,int > &x, const pair < pair<int,int>,int > &y)
{
	return x.first.second < y.first.second;
}

int weighted_job_scheduling(vector< pair< pair<int,int>,int > > &v, int n)
{
	//Sorting by end time
	sort(v.begin(),v.end(),comparator);
	vector<int> t(n);
	for(int i=0;i<n;i++)
	{
		t[i] = v[i].second;
	}

	for(int i = 1;i < n;i++)
	{
		for(int j = 0;j < i;j++)
		{
			if(v[j].first.second <= v[i].first.first)
			{
				t[i] = max(t[i],t[j]+v[i].second);
			}
		}
	}
	return *max_element(t.begin(),t.end());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector< pair < pair<int,int>,int > > v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first.first;//Start time
		cin>>v[i].first.second;//End time
		cin>>v[i].second;//Weight
	}
	cout<<weighted_job_scheduling(v,n)<<"\n";
	return 0;
}