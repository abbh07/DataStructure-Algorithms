/*
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//O(n)
int zero_sum_subarray(vector<int> &v, int n)
{
    unordered_map<int,int> m;
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        sum += v[i];
        if(sum == 0)
        {
            cnt++;
        }
        if(m.count(sum) == 1)
        {
            cnt += m[sum];
        }
        m[sum]++;
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
        cout<<zero_sum_subarray(v,n)<<endl;
    }
    return 0;
}