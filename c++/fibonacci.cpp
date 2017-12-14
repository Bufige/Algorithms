#include <iostream>



std::size_t fibonacci (int n)
{
	if(n <= 2)
	{
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

std::size_t fibonacci_iterative(int n)
{
	std::size_t prev = 1,current = 1, next = 1;
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
	std::cin.tie(NULL); std::cout.sync_with_stdio(false);
	for(int i = 0 ; i < 10; i++)
	{
		std::cout << "recursive" <<  fibonacci(i) << std::endl;
		std::cout << "iterative" << fibonacci_iterative(i) << std::endl;
 	}
	return 0;
}