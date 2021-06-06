#include <iostream>

using namespace std;

int main()
{
    cout<<"First:\n";
    int a = 5;
    int *p = &a;
    cout<<a<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;
    cout<<&a<<endl;
    *p = 8;
    cout<<a<<endl;

    cout<<"Second:\n";
    cout<<p+1<<endl;
    cout<<*(p+1)<<endl;
    *(p+1) = 10;
    cout<<*(p+1)<<endl;
    int x = *(p+1);
    cout<<x<<endl;

    cout<<"Third:\n";
    int b = 1025;
    p = &b;
    cout<<sizeof(int)<<endl;
    cout<<*p<<endl;
    char *p0 = (char*) p;
    cout<<sizeof(char)<<endl;
    cout<<*p0<<endl;
    cout<<*(p0+1)<<endl;

    cout<<"Fourth:\n";
    x = 5;
    p = &x;
    *p = 6;
    int **q = &p;
    int ***r = &q;
    cout<<*p<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;
    cout<<**r<<endl;
    cout<<***r<<endl;
    ***r = 10;
    cout<<x<<endl;
    **q = *p + 2;
    cout<<x<<endl;

    cout<<"Sixth:\n";
    int A[] = {1,2,3,4,5};
    p = A;
    cout<<*(p+1)<<endl;
    p++;
    cout<<*(p+1)<<endl;
    cout<<&A[4]<<endl;
    cout<<A+4<<endl;
    cout<<A[4]<<endl;
    cout<<*(A+4)<<endl;

    return 0;
}