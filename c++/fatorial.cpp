#include <iostream>



std::size_t factorial(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	return n * factorial(n-1);
}

std::size_t factorial_iterative(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	std::size_t rtn = 1;
	for(; n > 1; n--)
	{
		rtn *= n;
	}
	return rtn;
}

int main()
{
	std::cin.tie(NULL); std::cout.sync_with_stdio(false);
	for(int i = 0 ; i < 10; i++)
	{
		std::cout << "recursive:" << factorial(i) << std::endl;
		std::cout << "iterative:" << factorial_iterative(i) << std::endl;
 	}
	return 0;
}