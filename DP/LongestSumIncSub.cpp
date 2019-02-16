#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_sum_inc_sub(int *v, int n)
{
    vector<int> s(v , v + n);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i] > v[j])
            {
                s[i] = max(s[i], s[j] + v[i]);
            }
        }
    }
    return *max_element(s.begin(), s.end());

}

int main()
{
    int v[] = {1,101,2,3,100,4,5};
    cout<<longest_sum_inc_sub(v, 7)<<endl;
    return 0;
}