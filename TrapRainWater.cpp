#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
#include <climits>

using namespace std;

int getTrappedWater(vector<int> &v, int n)
{
    int total = 0;
    vector<int> l(n);
    vector<int> r(n);
    l[0] = v[0];
    for(int i=1;i<n;i++)
    {
        l[i] = max(l[i-1],v[i]);
    }
    r[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        r[i] = max(r[i+1],v[i]);
    }
    for(int i=0;i<n;i++)
    {
        total += min(l[i],r[i]) - v[i];
    }
    return total;
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
        cout<<getTrappedWater(v,n)<<"\n";
    }
    return 0;
}