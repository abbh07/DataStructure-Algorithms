#include <iostream>

using namespace std;

int exponentiation_primitive(int x, int n)
{
	if(n==0)
		return 1;
	return x*exponentiation_primitive(x,n-1);
}

int exponentiation_optimized(int x, int n)
{
	if(n==0)
		return 1;
	if(n%2 == 0)
	{
		int val = exponentiation_optimized(x,n/2);
		return val*val;
	}
	return x*exponentiation_optimized(x,n-1);
}

int main()
{
	int x,n;
	cin>>x>>n;
	int result = exponentiation_primitive(x,n);
	cout<<result<<endl;
	result = exponentiation_optimized(x,n);
	cout<<result<<endl;
	return 0;
}
