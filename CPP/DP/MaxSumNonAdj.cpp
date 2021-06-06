//Maximum Sum Non Adjacent Elements
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum_non_adjacent(int *seq, int n)
{
	int inclusive = seq[0];
	int exclusive = 0;
	int temp = 0;
	for(int i=1;i<n;i++)
	{
		temp = inclusive;
		inclusive = max(inclusive,exclusive+seq[i]);
		exclusive = temp;
	}
	return inclusive;
}

int main()
{
	int seq[] = {4,1,1,4,2,1};
	int n = 6;
	cout<<max_sum_non_adjacent(seq,n)<<endl;
	return 0;
}