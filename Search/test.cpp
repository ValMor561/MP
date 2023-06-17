#include "pch.h"
#include "Search.h"
#include "test.h"

class SearchTest :public
	::testing::TestWithParam<std::tuple<searchMethod<int>, int*, std::vector<std::pair<int,int>>>> {};

TEST_P(SearchTest, Search)
{
	auto function = std::get<0>(GetParam());
	auto arr = std::get<1>(GetParam());
	auto indkeyArr = std::get<2>(GetParam());
	for (auto k : indkeyArr)
	{
		ASSERT_EQ(k.first, function(arr, k.second, size));
	}
}

INSTANTIATE_TEST_CASE_P(
	SearchTests,
	SearchTest,
	::testing::Values(
	/*	std::make_tuple(SimpleSearch<int>, GenerateData(), GenerateGoodPair()),
		std::make_tuple(SimpleSearch<int>, GenerateData(), GenerateBadPair()),*/
		std::make_tuple(BinSearch<int>, GenerateData(), GenerateGoodPair()),
		std::make_tuple(BinSearch<int>, GenerateData(), GenerateBadPair()),
		std::make_tuple(FibSearch<int>, GenerateData(), GenerateGoodPair()),
		std::make_tuple(FibSearch<int>, GenerateData(), GenerateBadPair()),
		std::make_tuple(InterpolSearch<int>, GenerateData(), GenerateGoodPair()),
		std::make_tuple(InterpolSearch<int>, GenerateData(), GenerateBadPair()),
		std::make_tuple(IndexSearch<int>, GenerateData(), GenerateGoodPair()),
		std::make_tuple(IndexSearch<int>, GenerateData(), GenerateBadPair())

		)
);

