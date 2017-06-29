/*
Given an array A[] of n numbers and another number x, determine whether or not there exist two elements in A whose sum is exactly x.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>

using namespace std;

bool getele(vector<int> &v, int n, int x)
{
    unordered_set<int> m;
    for(int i=0;i<n;i++)
    {
        m.insert(v[i]);
    }
    bool res = false;
    for(int i=0;i<n;i++)
    {
        int dual = x - v[i];
        if(m.count(dual) == 1)
        {
            res = true;
            break;
        }
    }
    return res;
}



int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        cin>>x;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        bool res = getele(v,n,x);
        if(res)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}