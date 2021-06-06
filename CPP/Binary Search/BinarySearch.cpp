#include <iostream>

using namespace std;
int bsearch(int arr[],int,int);

int main()
{
    int nsize;
    cout<<"Enter the size of the array "<<endl;
    cin>>nsize;
    int *pnarray=new int [nsize];
    cout<<"Enter the elements of the array in ascending order "<<endl;
    for(int i=0;i<nsize;i++)
        cin>>pnarray[i];
    int target;
    cout<<"Enter the element to be searched"<<endl;
    cin>>target;
    int result=bsearch(pnarray,nsize,target);
    if(result==1)
        cout<<"Element not found!!"<<endl;
    else
    {
        cout<<"The element found at position "<<endl;
        cout<<result;
    }
    delete [] pnarray;

    return 0;
}

int bsearch(int pnarray[],int nsize,int target)
{
    int nmin=0;
    int nmax=nsize-1;
    int guess = (nmin + nmax)/2;
    int flag=0;
    while(pnarray[guess]!=target)
    {
        if(pnarray[guess]<target)
            nmin = guess + 1;
        if(pnarray[guess]>target)
            nmax = guess - 1;
        guess=(nmin+nmax)/2;
        if(nmax<nmin)
            {
                flag=1;
                break;
            }
    }
    if(flag==1)
        return 1;
    else
        return (guess);

}
