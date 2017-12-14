#include <iostream>
#include <vector>
#include <algorithm>



void bubble_sort(std::vector<int> &vec)
{
	for(int i = 1; i < vec.size(); i++)
	{
		bool sorted = true;

		for(int j = 0; j < vec.size() - i; j++ )
		{
			if(vec[j] > vec[j+1])
			{
				std::swap(vec[j],vec[j+1]);
				sorted = false;
			}
		}
		if(sorted)
			return ;
	}
}

int main()
{
	std::vector<int> vec;
	vec.push_back(50);
	vec.push_back(33);
	vec.push_back(60);
	vec.push_back(2);
	vec.push_back(100);
	vec.push_back(77);

	bubble_sort(vec);

	for(int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	return 0;
}