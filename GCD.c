#include <stdio.h>
#include <math.h>

int GCD(int a, int b)
{
	int i;
	for(i = min(a,b);i>=1;i--)
	{
		if(a%i == 0 && b%i == 0)
			return i;
	}
}

int min(int a, int b)
{
	return (a<b)?a:b;
}

int main()
{
	printf("Enter two numbers\n");
	int a, b;
	scanf("%d%d", &a, &b);
	printf("GCD of the two numbers %d\n", GCD(a,b) );
	return 0;
}