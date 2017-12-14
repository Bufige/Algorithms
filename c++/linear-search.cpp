#include <iostream>


int linear_search(int array[], int pos, int end, int data)
{
	for(int i = pos; i < end; i++)
	{
		if(array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

int resursive_linear_search(int array[], int pos, int end, int data)
{
	if(pos < end)
	{		
		return array[pos] == data ? pos : resursive_linear_search(array,pos+1,end,data);
	}
	return -1;
}


int main()
{
	std::cin.tie(NULL); std::cout.sync_with_stdio(false);

	int array[] = {1,2,4,8,16,32,64,128,256};
	

	int found = linear_search(array,0,9,256);
	std::cout << "linear:";
	if(found != -1)
		std::cout << "index:" << found;
	else
		std::cout << "not found";
	std::cout << std::endl;

	found = resursive_linear_search(array,0,9,256);
	std::cout << "resursive:";
	if(found != -1)
		std::cout << "index:" << found;
	else
		std::cout << "not found";
	std::cout << std::endl;
	return 0;
}