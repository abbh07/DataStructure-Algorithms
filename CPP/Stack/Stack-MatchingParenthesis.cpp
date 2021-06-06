#include <iostream>
#include <cstdio>
#include <cstring>
#define LIMIT 10
using namespace std;

class stack{
private:
    int item;
    char s[LIMIT];
    int top;
public:
    stack(){top=-1;}
    void push(char item);
    char pop();

};

void stack::push(char item)
{
    if(top==LIMIT-1)
        cout<<"Stack Overflow!"<<endl;
    else
        {
            top+=1;
            s[top]=item;
        }
}

char stack::pop()
{
    if(top==-1)
    return -1;
    else
    return s[top--];
}

int main()
{
    stack s;
    char item;
    char arr[10];
    cout<<"Enter a string"<<endl;
    cin>>arr;
    int flag=1;
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='('||arr[i]=='['||arr[i]=='{')
            s.push(arr[i]);
        if(arr[i]==')'||arr[i]=='}'||arr[i]==']')
            {
                item=s.pop();
                if(item==-1)
                    {
                        flag=0;
                        break;
                    }
                else
                    {
                        if(arr[i]==')'&& item=='(')
                            continue;
                        if(arr[i]=='}'&& item=='{')
                            continue;
                        if(arr[i]==']'&& item=='[')
                            continue;
                        else
                            {
                                flag=0;
                                break;
                            }
                    }
            }
        if(arr[i]==arr[strlen(arr)-1] && s.pop()!=-1)
                {
                    flag=0;
                    break;

                }
        }
    if(flag==0)
        cout<<"Invalid string!"<<endl;
    else
        cout<<"Valid string!"<<endl;
    return 0;
}
