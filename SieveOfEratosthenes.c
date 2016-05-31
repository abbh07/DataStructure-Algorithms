#include <stdio.h>
#include <math.h>

int* sieve(int n, int prime[])
{
	//int prime[n+1];
	prime[0] = prime[1] = 0;
	int i;
	for(i = 2;i<=n;i++)
		prime[i] = 1;
	int m = sqrt(n);
	int j;
	for(i=2;i<=m;i++)
	{
		if(prime[i])
		{
			for(j = i*i;j<=n;j+=i)
			{
				prime[j] = 0;
			}
		}
	}

	return prime;

}

int main()
{
	printf("Enter a number\n");
	int n;
	scanf("%d", &n);
	int prime[n+1];
	int *arr = sieve(n, prime);
	printf("Prime numbers upto n\n");
	int i;
	for(i=0;i<=n;i++)
	{
		if(arr[i])
			printf("%d\t", i);
	}
	printf("\n");
	return 0;
}