#include <vector>
#include <iostream>
#include <algorithm>

int my_line_search(const int& elem, const std::vector<int>& data)
{
	int find_idx = -1;
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i] == elem)
		{
			find_idx = i;
			break;
		}

	}
	return find_idx;
}

int my_binary_search(const int& elem, const std::vector<int>& data)
{
	int find_idx = -1;

	int begin = 0;
	int back = data.size() - 1;
	int mid;
	int guess;

	while (begin <= back)
	{
		mid = static_cast<int>((back + begin) / 2);
		guess = data[mid];

		if (guess == elem)
		{
			return find_idx = mid;
		}
		if (guess < elem)
		{
			begin = mid + 1;
		}
		if (guess > elem)
		{
			back = mid - 1;
		}
	}

	return find_idx;
}

int my_binary_search_recursive(const int& elem, const std::vector<int>& data, int begin = 0, int back = - 1)
{   
	int find_idx = -1;

	int begin = 0;
	int back = data.size() - 1;
	int mid = static_cast<int>((back + begin) / 2);
	int guess = data[mid];

	if (guess == elem)
	{
		return find_idx = mid;
	}
	else
	{
		my_binary_search_recursive(elem, data);
	}

	return find_idx;
}


int main()
{
	
	std::vector<int> data = { 2,5,8,10,11,52,99,788 };

	//std::cout << my_line_search(90, data) << "\n";
	//std::cout << my_binary_search(90, data) << "\n";
	std::cout << my_binary_search_recursive(788, data);

	/*const auto it_1 = std::find(data.begin(), data.end(), 5);
	int index = std::distance(data.begin(), it_1);
	std::cout << index << "\n";*/

	//std::cout << std::binary_search(data.begin(), data.end(), 5) << "\n";

}
//ещё рекурсивно сделать, а потом сравнить время выполнения программы без вывода на консоль, потому что консоль занимает много времени, проверять в релизе, а не в дебаге