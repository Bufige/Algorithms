#include <iostream>



int gcd(int n1, int n2)
{
	int tmp, a,b;
	a = n1 > n2 ? n1 : n2;
	b = n1 > n2 ? n2 : n1;
	while(a != 0)
	{
		tmp = a;
		a = b % a;
		b = tmp;
	}
	return b;
}

int main()
{
	int array[] = {3,10,25,14,44,33,59,100,94,3,5,6,9};

	for(int i = 0, n = 12; i < n; i++,n--)
	{
		std::cout << "gcd(" << array[i] << "," << array[n] << ") = " << gcd(array[i],array[n]) << std::endl;
	}
	return 0;
}