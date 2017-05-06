#include <iostream>
#include "add.h"
#include "mult.h"
#define MY_NAME "Aman"


using namespace std;

int main()
{

    int x,y;
    #ifdef MY_NAME
    cout<<"Hello, "<<MY_NAME;
    #endif
    #ifdef MY_SNAME
    cout<<" Chopra "<<endl;
    #endif // MY_SNAME
    #ifndef MY_SNAME
    cout<<" Chopra "<<endl;
    #endif // MY_SNAME
    cout<<"Enter two numbers "<<endl;
    cin>>x>>y;
    cout<<"Sum = ";
    cout<<add(x,y)<<endl;
    cout<<"Product = ";
    cout<<mult(x,y)<<endl;

    return 0;
}
