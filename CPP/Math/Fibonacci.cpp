#include <iostream>

using namespace std;

int fibonacci(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}

int mem[100];

int fibonacci_memoized(int n)
{
	if(n<=1)
		return mem[n];
	else
	{
		if(mem[n-1]==-1)
			mem[n-1] = fibonacci_memoized(n-1);
		if(mem[n-2]==-1)
			mem[n-2] = fibonacci_memoized(n-2);
		return mem[n-1]+mem[n-2];
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<100;i++)
	{
		mem[i] = -1;
	}
	mem[0] = 0;
	mem[1] = 1;
	cout<<fibonacci(n)<<endl;
	cout<<fibonacci_memoized(n)<<endl;
	return 0;
}
