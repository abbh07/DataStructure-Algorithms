/*
3
5
6 -3 -10 0 2
6
2 3 4 5 -1 0 
10
8 -2 -2 0 8 0 -6 -8 -6 -1
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_product_subarray(vector<int> &v, int n)
{
    vector<int> maxproduct(n);
    vector<int> minproduct(n);
    maxproduct[0] = minproduct[0] = v[0];
    int result = v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i] > 0)
        {
            maxproduct[i] = max(v[i], maxproduct[i-1]*v[i]);
            minproduct[i] = min(v[i], minproduct[i-1]*v[i]);
        }
        else
        {
            maxproduct[i] = max(v[i], minproduct[i-1]*v[i]);
            minproduct[i] = min(v[i], maxproduct[i-1]*v[i]);
        }
        result = max(result, maxproduct[i]);
    }
    return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        cout<<max_product_subarray(v,n)<<endl;
    }
    return 0;
}