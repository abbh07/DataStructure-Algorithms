#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void permute(int *a, int l)
{
    sort(a,a+l);
    do {
       for(int i=0;i<l;i++)
       cout << a[i];
       cout<<endl;
    } while (next_permutation(a, a+l));
}

int main()
{
    int a[] = {1,2,3,4};
    int l = (sizeof(a)/sizeof(*a));
    permute(a,l);
    return 0;
}
