#include<iostream>

using namespace std;

int factorialRecursive(int n)
{
	if(n==0)
		return 1;
	return n*factorialRecursive(n-1);
}

int factorialIterative(int n)
{
	int res = 1;

	for(int i=1;i<=n;i++)
	{
		res *= i; 
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	cout<<"Factorial Recursive: "<<factorialRecursive(n)<<endl;
	cout<<"Factorial Iterative: "<<factorialIterative(n)<<endl;
	return 0;
}
