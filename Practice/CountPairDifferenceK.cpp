/*
Given an integer array and a non-negative integer k, count all distinct pairs with difference equal to k, i.e., A[ i ] - A[ j ] = k
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int getCount(vector<int> &v, int n, int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
    }
    int dual = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        dual = v[i]+k;
        if(dual == v[i])
        {
            int c = m[v[i]];
            if(c>=2)
            {
                cnt++;
                m[v[i]] -= 2;
            }
        }
        else
        {
            if(m.count(dual) == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
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
        int k;
        cin>>k;
        cout<<getCount(v,n,k)<<"\n";
    }
    return 0;
}