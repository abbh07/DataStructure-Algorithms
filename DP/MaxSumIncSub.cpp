//Maximum Sum Increasing Subsequence
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum_increasing_subsequence(int *seq, int n)
{
	vector<int> t(n);
	for(int i=0;i<n;i++)
	{
		t[i] = seq[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(seq[j] < seq[i])
			{
				t[i] = max(t[i], t[j]+seq[i]);
			}
		}
	}
	int max_sum = *max_element(t.begin(),t.end());
	return max_sum;
}

int main()
{
	int seq[] = {4,6,1,3,8,4,6};
	int n = 7;
	cout<<max_sum_increasing_subsequence(seq,n)<<endl;
}