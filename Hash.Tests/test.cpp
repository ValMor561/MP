#include "pch.h"
#include "Hash.h"
#include "UniHash.h"

TEST(OpenHashTests, ConstructFromVector) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27};
	OpenHash<int> temp = OpenHash<int>(arr);
	std::vector<int> result = { 7, 3, 9, 10, 8, 1, 5, 6};
	for (int i = 0; i < 8; ++i)
	{
		ASSERT_EQ(result[i], temp.Search(arr[i]));
	}
}

TEST(OpenHashTests, InsertWithColusion) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27 };
	OpenHash<int> temp = OpenHash<int>(arr);
	temp.Insert(16);
	std::vector<int> result = { 7, 3, 9, 10, 8, 1, 5, 6, 0 };
	ASSERT_EQ(0, temp.Search(16));
}

TEST(OpenHashTests, InsertWithoutColusion) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27, 16 };
	OpenHash<int> temp = OpenHash<int>(arr);
	temp.Insert(13);
	ASSERT_EQ(2, temp.Search(13));
}

TEST(OpenHashTests, DeleteTest) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27, 16 };
	OpenHash<int> temp = OpenHash<int>(arr);
	temp.Delete(9);
	ASSERT_EQ(-15, temp.Search(9));
}

TEST(OpenHashTests, RehashTest) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27, 16, 13, 34, 52 };
	OpenHash<int> temp = OpenHash<int>(arr);
	std::vector<int> result = { 18, 14, 9, 20, 19, 12, 5, 6, 16, 13, 15, 8 };
	for (int i = 0; i < 11; ++i)
	{
		ASSERT_EQ(result[i], temp.Search(arr[i]));
	}
}

TEST(UniversalHashTests, VectorConstructTest) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27 };
	for (auto k : arr)
	{
		std::cout << k << " ";
	}
	std::cout << std::endl;
	UniversalHash<int> temp = UniversalHash<int>(arr);
	for (auto k : temp.__table)
	{
		if (k != 0)
			std::cout << k << " ";
	}
}

TEST(UniversalHashTests, DeleteTest) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27, 16 };
	UniversalHash<int> temp = UniversalHash<int>(arr);
	temp.Delete(9);
	ASSERT_EQ(-15, temp.Search(9));
}

TEST(UniversalHashTests, SearchTest) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27, 16 };
	UniversalHash<int> temp = UniversalHash<int>(arr);
	for (auto k : arr)
	{
		ASSERT_NE(-15, temp.Search(k));
	}
}

TEST(UniversalHashTests, InsertTest) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27 };
	for (auto k : arr)
	{
		std::cout << k << " ";
	}
	std::cout << std::endl;
	UniversalHash<int> temp = UniversalHash<int>(arr);
	for (auto k : temp.__table)
	{
		if (k != 0)
			std::cout << k << " ";
	}
	std::cout << std::endl;
	temp.Insert(65);
	for (auto k : temp.__table)
	{
		if (k != 0)
			std::cout << k << " ";
	}
}

TEST(UniversalHashTests, RehashTest) {
	std::vector<int> arr = { 18, 14, 9, 20, 19, 12, 5, 27, 13, 63, 93 };
	for (auto k : arr)
	{
		std::cout << k << " ";
	}
	std::cout << std::endl;
	UniversalHash<int> temp = UniversalHash<int>(arr);
	for (auto k : temp.__table)
	{
		if (k != 0)
			std::cout << k << " ";
	}
	std::cout << std::endl;
	temp.Insert(65);
	for (auto k : temp.__table)
	{
		if (k != 0)
			std::cout << k << " ";
	}
}

