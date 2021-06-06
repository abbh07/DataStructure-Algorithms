// https://www.hackerrank.com/challenges/maximum-element

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin>>n;
    int q;
    stack<int> aux;
    for(int i=0;i<n;i++)
    {
        cin>>q;
        if(q == 1)
        {
            int num;
            cin>>num;
            s.push(num);
            if(aux.empty())
            aux.push(num);
            else
            {
                if(num>aux.top())
                {
                    aux.push(num);
                }
                else
                {
                    aux.push(aux.top());
                }
            }
        }
        else if(q == 2)
        {
            s.pop();
            aux.pop();
        }
        else if(q == 3)
        {
            cout<<aux.top()<<endl;
        }
    }
    return 0;
}
