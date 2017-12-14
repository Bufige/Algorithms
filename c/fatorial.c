#include <stdio.h>



int factorial(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	return n * factorial(n-1);
}

int factorial_iterative(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	int rtn = 1;
	for(; n > 1; n--)
	{
		rtn *= n;
	}
	return rtn;
}

int main()
{
	
	for(int i = 0 ; i < 10; i++)
	{
		printf("recursive:%d\n",factorial(i));
		printf("iterative:%d\n",factorial_iterative(i));
 	}
	return 0;
}