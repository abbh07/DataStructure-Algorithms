#include <iostream>

using namespace std;

//x^n mod m
int modular_exponentiation(int x, int n, int m)
{
	if(n==0)
		return 1;
	if(n%2 == 0)
	{
		int val = modular_exponentiation(x,n/2,m);
		return (val*val)%m;
	}
	else
    {
        int val = modular_exponentiation(x, (n-1)/2, m);
        return ((x%m)*(val%m)*(val%m))%m;
    }
}

int main()
{
	int x,n,m;
	cin>>x>>n>>m;
	int result = modular_exponentiation(x,n,m);
	cout<<result<<endl;
	return 0;
}
