#pragma once
#define size 100000
template <typename T>
using searchMethod = int(*)(T*, T, size_t);

int* GenerateData()
{
	int* arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i * 10;
	}
	return arr;
}

std::vector<std::pair<int, int>> GenerateGoodPair()
{
	std::vector<std::pair<int, int>> arr(size);
	for (int i = 0; i < 1; ++i)
	{
		arr[i].first = i;
		arr[i].second = i * 10;
	}
	return arr;
}

std::vector<std::pair<int, int>> GenerateBadPair()
{
	std::vector<std::pair<int, int>> arr(size);
	for (int i = 0; i < 1; ++i)
	{
		arr[i].first = -15;
		arr[i].second = i * 10 + 1;
	}
	return arr;
}