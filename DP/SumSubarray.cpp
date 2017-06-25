#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

//Checks if a given sum subarray exists in the given array
void checkSum(vector<int> &v,int n,int s)
{
    unordered_map<int,int> m;
    int sum = 0;
    //m[0] = 1;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        sum += v[i];
        m[sum] = i+1;
        if(sum == s)
        {
            cout<<"1 "<<i+1<<"\n";
            flag = true;
            break;
        }
        if(m.count(sum-s) == 1)
        {
            cout<<m[sum-s]+1<<" "<<i+1<<"\n";
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout<<"-1"<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        checkSum(v,n,s);
    }
    return 0;
}