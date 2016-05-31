#include <stdio.h>
#include <math.h>

int euclid(int a, int b)
{
	if(b == 0)
		return a;
	return euclid(b, a%b);
}

int main()
{
	printf("Enter two numbers\n");
	int a, b;
	scanf("%d%d", &a, &b);
	printf("GCD of the two numbers %d\n", euclid(a,b));
	return 0;
}

//lcm of two numbers = a*b/GCD(a,b);