//Program to find the prime factors of a number n
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int cnt = 0;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i == 0)
		{
			cnt = 0;
			while(n%i==0)
			{
				cnt++;
				n = n/i;
			}
			//Displaying prime factor and its count 
			cout<<i<<" : "<<cnt<<endl;	
		}		
	}
	if(n!=1)
		cout<<n<<" : "<<"1"<<endl;
	return 0;
}