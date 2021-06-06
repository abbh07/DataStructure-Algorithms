//https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation
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

int nextPermutation(int n)
{
    vector<int> v;
    while(n)
    {
        v.push_back(n%10);
        n /= 10;
    }
    reverse(v.begin(),v.end());
    int s = v.size();
    int k = s-2;
    bool flag = false;
    while(k >= 0)
    {
        if(v[k] < v[k+1])
        {
            flag = true;
            break;
        }
        k--;
    }
    if(!flag)
    {
        return -1;
    }
    int l = s-1;
    while(k < l)
    {
        if(v[k] < v[l])
        {
            break;
        }
        l--;
    }
    swap(v[k],v[l]);
    vector<int>::iterator it1 = v.begin() + k + 1;
    vector<int>::iterator it2 = v.end();
    reverse(it1,it2);
    int next = 0;
    int p = 1;
    for(int i=s-1;i>=0;i--)
    {
        next = next + v[i]*p;
        p *= 10;
    }
    return next;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int res = nextPermutation(n);
        if(res != -1)
        {
            cout<<res<<"\n";
        }
        else
        {
            cout<<"not possible"<<"\n";
        }
    }
    return 0;
}