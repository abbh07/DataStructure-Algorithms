/*#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    vec.insert(vec.begin(),1);
    vec.erase (vec.end()-1);
    vec.erase (vec.begin());

    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
}
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
     int n,k,q,a;
     cin>>n>>k>>q;
     vector<int> vec;
     for(int i=0;i<n;i++)
         {
         cin>>a;
         vec.push_back(a);
     }
     int arr[q];
     for(int j=0;j<q;j++)
         cin>>arr[j];
     for(int m=0;m<k;m++)
         {
         vec.insert(vec.begin(),vec.back());
         vec.erase (vec.end()-1);
     }
     for(int p=0;p<q;p++)
        cout<<vec[arr[p]]<<" ";

    
    return 0;
}
