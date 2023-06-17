#include "pch.h"
#include "Sorts.h"

#define size 10000

TEST(SortTest, LSDTest) {
	std::vector<std::string> vec(size);
	int strLen;
	std::string str;
	int charIndex = int('a');
	for (int i = 0; i < size; ++i)
	{
		if (i % 40000 == 0)
			--charIndex;
		strLen = rand() % 100 + 1;
		str.resize(strLen);
		for (int j = 0; j < strLen; ++j)
		{
			str[j] = (char)(rand() % 25 + 97);
		}
		vec[i] = str;
	}
	LSD(vec.begin(), vec.end());
	ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}


template<typename IterType>
using sortType = void(*)(IterType, IterType);

class SortParameterizedTestFixture :
	public ::testing::Test,
	public ::testing::WithParamInterface<sortType<std::vector<int>::iterator>>
{
protected: 
	std::vector<int> vec1;
	std::vector<int> vec2;
	std::vector<int> vec3;
	std::vector<int> vec4;
	void SetUp()
	{
		vec1.resize(size);
		vec2.resize(size);
		vec3.resize(size);
		vec4.resize(size);
		for (size_t i = 0; i < size; ++i)
		{
			vec1[i] = rand() % size;
			vec2[i] = rand() % 100;
			vec3[i] = i;
			vec4[i] = size - i;
		}
	}
	
};

TEST_P(SortParameterizedTestFixture, Rand1Test) {


	auto fun = GetParam();
	fun(vec1.begin(), vec1.end());
	ASSERT_TRUE(std::is_sorted(vec1.begin(), vec1.end()));
}

TEST_P(SortParameterizedTestFixture, Rand2Test) {


	auto fun = GetParam();
	fun(vec2.begin(), vec2.end());
	ASSERT_TRUE(std::is_sorted(vec2.begin(), vec2.end()));
}

TEST_P(SortParameterizedTestFixture, IncreaseTest) {


	auto fun = GetParam();
	fun(vec3.begin(), vec3.end());
	ASSERT_TRUE(std::is_sorted(vec3.begin(), vec3.end()));
}

TEST_P(SortParameterizedTestFixture, DecreaseTest) {


	auto fun = GetParam();
	fun(vec4.begin(), vec4.end());
	ASSERT_TRUE(std::is_sorted(vec4.begin(), vec4.end()));
}

INSTANTIATE_TEST_CASE_P(
	RandomTest,
	SortParameterizedTestFixture,
	::testing::Values(
		Sh1sort<std::vector<int>::iterator>,
		Sh2sort<std::vector<int>::iterator>,
		STLheap_sort<std::vector<int>::iterator>,
		HeapSort<std::vector<int>::iterator>,
		Qsort<std::vector<int>::iterator>,
		Hsort<std::vector<int>::iterator>,
		SVsort<std::vector<int>::iterator>,
		SNsort<std::vector<int>::iterator>
	)
);
