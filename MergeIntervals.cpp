/*
4
6 8
2 4
5 7
1 3
o/p:
1 4
5 8
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//O(nlogn)
void merge_intervals(vector< pair<int,int> > &v, int n)
{
	//Sorting in ascending order by start time
	sort(v.begin(),v.end());
	int j = 0 ;
	for(int i=0;i<n;i++)
	{
		if(j != 0 && v[j-1].second >= v[i].first)
		{
			while(v[j-1].second >= v[i].first)
			{				
				v[j-1].second = max(v[j-1].second,v[i].second);
				v[j-1].first = min(v[j-1].first,v[i].first);
				j--;	
			}
		}
		else
		{
			v[j] = v[i];
		}
		j++;
	}

	for(int i=0;i<j;i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
}

int main()
{
	int n;
	cin>>n;
	vector< pair<int,int> > v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first;//start time
		cin>>v[i].second;//end time
	}
	merge_intervals(v,n);
	return 0;
}