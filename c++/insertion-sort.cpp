#include <iostream>
#include <vector>


void sort_insertion(std::vector<int> &vec)
{
	int sel, j;
	for(int i = 1; i < vec.size(); i++)
	{
		sel = vec[i];
		j = i -1;

		while((j >= 0) && (vec[j] > sel))
		{
			vec[j+1] = vec[j];
			j--;
		}
		vec[j + 1] = sel;
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

	sort_insertion(vec);

	for(int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	return 0;
}