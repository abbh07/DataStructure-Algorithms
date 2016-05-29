#include <iostream>

using namespace std;

int main()
{
    int testCases;
    cin>>testCases;
    //Array to store input numbers
    int integers[100];
    for(int i=0;i<testCases;i++)
    {
        cin>>integers[i];
    }
    //Temporary Variable
    int tempVar;
    for(int i=0;i<testCases-1;i++)
    {
        for(int j=0;j<testCases-i-1;j++)
        {
            if(integers[j]>integers[j+1])
            {
                tempVar=integers[j];
                integers[j]=integers[j+1];
                integers[j+1]=tempVar;
            }


        }
    }
    for(int i=0;i<testCases;i++)
    {
        cout<<integers[i]<<endl;
    }
    return 0;
}
