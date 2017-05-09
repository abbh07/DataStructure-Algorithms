#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int gcd_iterative(int a, int b)
{
	while(a!=0)
	{
		int rem = b%a;
		b = a;
		a = rem;
	}
	return b;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	cout<<gcd_iterative(a,b)<<endl;
	return 0;
}

//lcm of two numbers = a*b/GCD(a,b);