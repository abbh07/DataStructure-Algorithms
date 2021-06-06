// https://www.hackerrank.com/challenges/largest-rectangle

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    stack<int> s;
    int top;
    int area = 0;
    int maxar = 0;
    int i;
    for(i=0;i<n;)
    {
        if(s.empty() || (arr[s.top()]<=arr[i]))
        {
            s.push(i++);
        }
        else
        {
           top = s.top();
           s.pop();
           if(s.empty())
           {
                area = arr[top]*i;
           }
           else
           {
                area = arr[top]*(i-1-s.top());
           }
           if(area>maxar)
           {
                maxar = area;
           }
        }
    }
    while((!s.empty()))
    {
        top = s.top();
        s.pop();
        if(s.empty())
        {
            area = arr[top]*i;
        }
        else
        {
            area = arr[top]*(i-1-s.top());
        }
        if(area>maxar)
        {
            maxar = area;
        }
    }
    cout<<maxar;
    return 0;
}
