#include <stdio.h>



int fibonacci (int n)
{
	if(n <= 2)
	{
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_iterative(int n)
{
	int prev = 1,current = 1, next = 1;
	for(int i = 3; i <= n; i++)
	{
		next = current + prev;
		prev = current;
		current = next;
	}
	return next;
}


int main()
{
	
	for(int i = 0 ; i < 10; i++)
	{
		printf("recursive:%d\n",fibonacci(i));
		printf("iterative:%d\n",fibonacci_iterative(i));
 	}
	return 0;
}