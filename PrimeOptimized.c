#include<stdio.h>
#include<math.h>

int isPrime(int n);

int main()
{
	printf("Enter a number\n");
	int n;
	scanf("%d", &n);
	if(isPrime(n))
		printf("The entered number is prime\n");
	else
		printf("The entered number is not prime\n");
	return 0;
}

int isPrime(int n)
{
	if(n<=1)
		return 0;
	if(n == 2)
		return 1;
	if(n%2 == 0)
		return 0;
	int m = sqrt(n);
	int i;
	for(i=3;i<=m;i+=2)
	{
		if(n%i == 0)
		return 0;
	}
	return 1;
}

