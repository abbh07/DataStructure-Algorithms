#include <iostream>
#define Limit 20

using namespace std;

class stack
{
    private:
        char item;
        int top;
        char s[Limit];

    public:

        stack()
        {top=-1;}
        char pop()
        {
            if(top==-1)
                return -1;
            else
                return s[top--];
        }

        void push(char item)
        {
            if(top==Limit-1)
                cout<<"Stack Overflow!"<<endl;
            else
                {
                    top+=1;
                    s[top]=item;
                }
        }

        void checkPalindrome(char str[])
        {
            for(int i=0;str[i]!='\0';i++)
                push(str[i]);
            for(int i=0;str[i]!='\0';i++)
            {
                if(str[i]!=pop())
                    break;

            }
            if(top==-1)
            cout<<"The entered string is a Palindrome"<<endl;
            else
            cout<<"The entered string is not a Palindrome"<<endl;
        }
};

int main()
{
    char arr[Limit];
    cout<<"Enter a string:"<<endl;
    cin>>arr;
    stack s;
    s.checkPalindrome(arr);
    return 0;
}
