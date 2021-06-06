#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(int *v, int l)
{
	vector<int> t(l,1);
	for(int i=1;i<l;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(v[j] < v[i])
			{
				t[i] = max(t[i],t[j]+1);
			}
		}
	}
	int res = *max_element(t.begin(),t.end());
	return res;
}

int main()
{
	int v[] = {3,4,-1,0,6,2,3};
	cout<<lis(v,7)<<endl;
	return 0;
}