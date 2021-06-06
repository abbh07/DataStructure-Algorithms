#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int val = 1;
	cout<<"Pascal's Triangle:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<(2*n-1)/2;j++)
		{
			cout<<" ";
		}
		for(int j=0;j<=i;j++)
		{
			if(j == 0 || j == i)
			{
				val = 1;
			}
			else
			{
				val = val*(i-j+1)/j;
			}
			cout<<val<<" ";
		}
		cout<<endl;
	}
	return 0;
}