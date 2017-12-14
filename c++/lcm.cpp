#include <iostream>



int lcm(int n1, int n2)
{
	int rmd, a,b;
	a = n1 > n2 ? n1 : n2;
	b = n1 > n2 ? n2 : n1;
	do
	{
		rmd = a % b;
		a = b;
		b = rmd;
	}
	while(rmd != 0);
	return (n1*n2)/a;
}

int main()
{
	int array[] = {10,25,14,44,33,59,100,94,3,5,6,9};

	for(int i = 0, n = 11; i < n; i++,n--)
	{
		std::cout << "lmc(" << array[i] << "," << array[n] << ") = " << lcm(array[i],array[n]) << std::endl;
	}
	return 0;
}