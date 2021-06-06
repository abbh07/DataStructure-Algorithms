#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool subset_sum(vector<int> &v, int sum)
{
	int l = v.size();
	vector< vector<int> > T(l+1,vector<int> (sum+1));

	for(int i=0;i<=sum;i++)
	{
		T[0][i] = false;
	}

	for(int i=0;i<=l;i++)
	{
		T[i][0] = true;
	}

	for(int i=1;i<=l;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<v[i-1])
			{
				T[i][j] = T[i-1][j];
			}
			else
			{
				T[i][j] = T[i-1][j] || T[i-1][j-v[i-1]];
			}
		}
	}

	return T[l][sum];
}

int main()
{
	int n;
	cout<<"Enter the length of the vector:"<<endl;
	cin>>n;
	vector<int> v(n);
	cout<<"Enter the elements:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	cout<<"Enter the sum:"<<endl;
	int sum;
	cin>>sum;
	if(subset_sum(v,sum))
	{
		cout<<"Sum found!"<<endl;
	}
	else
	{
		cout<<"Sum not found!"<<endl;
	}
	return 0;
}