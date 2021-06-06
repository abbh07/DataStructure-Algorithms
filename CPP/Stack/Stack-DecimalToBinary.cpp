#include <iostream>
#define Limit 20
using namespace std;

class stack
{
    private:
        int item;
        int arr[Limit];
        int top;
    public:
        stack(){top=-1;}

        void push(int item)
        {
            if(top==Limit-1)
            cout<<"Stack Overflow!"<<endl;
            else
            {
                top+=1;
                arr[top]=item;
            }
        }

        int pop()
        {
            if(top==-1)
            return -1;
            else
            return arr[top--];
        }

        void decBin(int n)
        {
            while(n>0)
            {
                push(n%2);
                n=n/2;
            }
            while(top>-1)
            {
                cout<<pop();
            }
        }
};

int main()
{
    int dec;
    cout<<"Enter a number in decimal to convert to binary:"<<endl;
    cin>>dec;
    stack s;
    s.decBin(dec);
    return 0;
}
