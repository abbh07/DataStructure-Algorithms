#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comparator
{
    bool operator()(int i,int j)
    {
        return i>j;
    }
};

priority_queue<int, vector<int>, comparator> minheap;
priority_queue<int, vector<int> > maxheap;

void insert(int num)
{
    if(maxheap.empty() || num < maxheap.top())
    {
        maxheap.push(num);
    }
    else
    {
        minheap.push(num);
    }
}

void rebalance()
{
    int diff = maxheap.size() - minheap.size();
    if( diff >= 2)
    {
        minheap.push(maxheap.top());
        maxheap.pop();
    }
    else if( diff <= -2)
    {
        maxheap.push(minheap.top());
        minheap.pop();
    }
}

double getMedian()
{
    double median;
    if(maxheap.size() == minheap.size())
    {
        median = ((double)minheap.top() + maxheap.top())/2;
    }
    else if(maxheap.size() > minheap.size())
    {
        median = maxheap.top();
    }
    else if(minheap.size() > maxheap.size())
    {
        median = minheap.top();
    }
    return median;
}

int main()
{
    int n;
    scanf("%d",&n);
    int num;
    while(n--)
    {
        scanf("%d",&num);
        insert(num);
        rebalance();
        double med = getMedian();
        printf("%.1f\n",med);
    }
    return 0;
}