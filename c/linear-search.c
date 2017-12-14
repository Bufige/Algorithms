#include <stdio.h>


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
	

	int array[] = {1,2,4,8,16,32,64,128,256};
	

	int found = linear_search(array,0,9,256);
	printf("linear:");
	if(found != -1)
		printf("index:%d",found);
	else
		printf("not found");
	
	printf("\n");

	found = resursive_linear_search(array,0,9,256);
	printf("resursive:");
	if(found != -1)
		printf("index:%d",found);
	else
		printf("not found");
	printf("\n");
	return 0;
}