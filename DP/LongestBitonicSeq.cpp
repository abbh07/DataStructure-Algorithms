//Longest Bitonic Sequence
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_bitonic_seq(int *seq, int n)
{
	//Calculate Longest Increasing Subsequence from left to right
	vector<int> t1(n,1);
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(seq[j] < seq[i])
			{
				t1[i] = max(t1[i],t1[j]+1);
			}
		}
	}

	//Calcualte LIS from right to left
	vector<int> t2(n,1);
	for(int i=n-2;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(seq[j]<seq[i])
			{
				t2[i] = max(t2[i], t2[j]+1);
			}
		}
	}

	//Add both the vectors and subtract 1 
	vector<int> combined(n);
	for(int i=0;i<n;i++)
	{
		combined[i] = t1[i] + t2[i] - 1;
	}
	
	int max_ele = *max_element(combined.begin(),combined.end());
	return max_ele;
}

int main()
{
	int seq[] = {2,-1,4,3,5,-1,3,2};
	int n = 8;
	cout<<longest_bitonic_seq(seq,n)<<endl;
	return 0;
}