#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <locale>
#include <iomanip>

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

int my_binary_search_recursive(const int& elem, const std::vector<int>& data, int begin = 0, int back = 1)
{   
	if (back == 1) 
	{
		back = static_cast<int>(data.size()) - 1;
	}

	int find_idx = -1;

	if (begin > back)
	{
		return find_idx;
	}

	int mid = static_cast<int>((back + begin) / 2);
	int guess = data[mid];

	if (guess == elem)
	{
		return find_idx = mid;
	}
	if (guess < elem)
	{
		return my_binary_search_recursive(elem, data, mid + 1, back);
	}
    if (guess > elem)
	{
		return my_binary_search_recursive(elem, data, begin, mid - 1);
	}

	return find_idx;
}


int main()
{
	setlocale( LC_ALL, "Russian");
	
	std::vector<int> data = { 2,5,8,10,11,52,99,788 };
	auto start1 = std::chrono::high_resolution_clock::now();
	volatile int idx1 = my_line_search(788, data);
	auto end1 = std::chrono::high_resolution_clock::now();
	auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

	auto start2 = std::chrono::high_resolution_clock::now();
	volatile int idx2 = my_binary_search(788, data);
	auto end2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);

	auto start3 = std::chrono::high_resolution_clock::now();
	volatile int idx3 = my_binary_search_recursive(788, data);
	auto end3 = std::chrono::high_resolution_clock::now();
	auto duration3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3);

	auto start4 = std::chrono::high_resolution_clock::now();
	const auto it_1 = std::find(data.begin(), data.end(), 788);
	volatile int idx4 = std::distance(data.begin(), it_1);
	auto end4 = std::chrono::high_resolution_clock::now();
	auto duration4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - start4);

	auto start5 = std::chrono::high_resolution_clock::now();
	volatile bool found = std::binary_search(data.begin(), data.end(), 788);
	auto end5 = std::chrono::high_resolution_clock::now();
	auto duration5 = std::chrono::duration_cast<std::chrono::nanoseconds>(end5 - start5);

	// Вывод результатов
	std::cout << "Метод поиска            Индекс   Время (нс)\n";
	std::cout << "-------------------------------------------\n";
	std::cout << "Линейный поиск         " << std::setw(7) << idx1 << std::setw(10) << duration1.count() << "\n";
	std::cout << "Бинарный поиск         " << std::setw(7) << idx2 << std::setw(10) << duration2.count() << "\n";
	std::cout << "Рекурсивный бинарный   " << std::setw(7) << idx3 << std::setw(10) << duration3.count() << "\n";
	std::cout << "std::find              " << std::setw(7) << idx4 << std::setw(10) << duration4.count() << "\n";
	std::cout << "std::binary_search     " << std::setw(7) << (found ? "Да" : "Нет") << std::setw(10) << duration5.count() << "\n";

}
//ещё рекурсивно сделать, а потом сравнить время выполнения программы без вывода на консоль, потому что консоль занимает много времени, проверять в релизе, а не в дебаге