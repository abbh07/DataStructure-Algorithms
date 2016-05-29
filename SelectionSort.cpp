/*Selection sort performs the following steps:
1) Starting at index 0, search the entire array to find the smallest value
2) Swap the smallest value found with the value at index 0
3) Repeat steps 1 & 2 starting from the next index*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arLimit;
    cout<<"Enter the number of elements for the array "<<endl;
    cin>>arLimit;
    int anArray[30];
    cout<<"Enter the elements of the array "<<endl;
    for(int startIndex=0;startIndex<arLimit;startIndex++)
        cin>>anArray[startIndex];
    cout<<"The array you entered is "<<endl;
    for(int startIndex=0;startIndex<arLimit;startIndex++)
        cout<<anArray[startIndex]<<endl;
    for(int startIndex=0;startIndex<arLimit;startIndex++)
    {
        for(int currentIndex=startIndex+1;currentIndex<arLimit;currentIndex++)
        {
            if(anArray[currentIndex]<anArray[startIndex])
                swap(anArray[currentIndex],anArray[startIndex]);
        }
    }
    cout<<"The array after applying selection sort is "<<endl;
    for(int startIndex=0;startIndex<arLimit;startIndex++)
        cout<<anArray[startIndex]<<endl;

    return 0;
}
