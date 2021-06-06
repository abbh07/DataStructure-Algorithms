#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int merge(int *v, int left, int mid, int right)
{
	int n1 = mid -left + 1;
	int n2 = right - mid;
	int L[n1];
	int R[n2];
	for(int i=0;i<n1;i++)
	{
		L[i] = v[left+i];
	}
	for(int i=0;i<n2;i++)
	{
		R[i] = v[mid+i+1];
	}
	int i = 0;
	int j = 0;
	int k = left;
	int inv_count = 0;

	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			v[k++] = L[i++];
		}
		else
		{
			v[k++] = R[j++];
			inv_count += (mid - (left+i) + 1); 
		}
	}

	while(i<n1)
	{
		v[k++] = L[i++];
	}

	while(j<n2)
	{
		v[k++] = R[j++];
	}

	return inv_count;
}

int merge_sort(int *v, int left, int right)
{
	int inv_count = 0;
	int mid = 0;
	if(right > left)
	{
		mid = left + (right-left)/2;
		inv_count += merge_sort(v,left,mid);
		inv_count += merge_sort(v,mid+1,right);
		inv_count += merge(v,left,mid,right);
	}
	return inv_count;
}

int main()
{
    int d;
    scanf("%d",&d);
    while(d--)
    {
        int n;
        scanf("%d",&n);
        int v[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
        }
        printf("%d\n", merge_sort(v,0,n-1));
    }
	return 0;
}