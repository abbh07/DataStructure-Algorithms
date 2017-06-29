/*
Given an array A[] of n numbers and another number x, determine whether or not there exist three elements in A[] whose sum is exactly x.
Expected time complexity is O(n^2).
*/
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

bool checkSum(vector<int> &v, int n, int x)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
    }
    bool res = false;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int s = v[i] + v[j];
            m[v[i]]--;
            m[v[j]]--;
            if(m[x-s] >= 1)
            {
                res = true;
                break;
            }
            m[v[i]]++;
            m[v[j]]++;
        }
        if(res)
        {
            break;
        }
    }
    return res;
}

int main()
{
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
        cout<<checkSum(v,n,x)<<"\n";
    }
    return 0;
}