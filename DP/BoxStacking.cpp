/*
2
1 2 4
3 2 5
o/p = 11
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(pair< pair<int,int>, int > &a, pair< pair<int,int>, int > &b)
{
	return (a.first.first * a.first.second) > (b.first.first * b.first.second);
}

int get_max_height(vector< pair< pair<int,int>, int > > &v, int n)
{
	//Generating all 3*n permutations such that length is greater than width
	vector< pair< pair<int,int>, int > > t(3*n);
	int index = 0;
	for(int i=0;i<n;i++)
	{
		t[index].first.first = max(v[i].first.first,v[i].first.second);
		t[index].first.second = min(v[i].first.first,v[i].first.second);
		t[index].second = v[i].second;

		index++;

		t[index].first.first = max(v[i].first.second,v[i].second);
		t[index].first.second = min(v[i].first.second,v[i].second);
		t[index].second = v[i].first.first;

		index++;

		t[index].first.first = max(v[i].first.first,v[i].second);
		t[index].first.second = min(v[i].first.first,v[i].second);
		t[index].second = v[i].first.second;

		index++;
	} 

	//Sorting in descending order by length * width
	sort(t.begin(),t.end(),comparator);

	vector<int> height(3*n);

	for(int i=0;i<3*n;i++)
	{
		height[i] = t[i].second;
	}

	for(int i=1;i<3*n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(t[i].first.first < t[j].first.first && t[i].first.second < t[j].first.second)
			{
				height[i] = max(height[i],t[i].second + height[j]);
			}
		}
	}
	int maxHeight = *max_element(height.begin(),height.end());
	return maxHeight;
}

int main()
{
	int n;
	cin>>n;
	vector< pair< pair<int,int>, int > > v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first.first;//length
		cin>>v[i].first.second;//width
		cin>>v[i].second;//height
	}
	cout<<get_max_height(v,n)<<"\n";
	return 0;
}