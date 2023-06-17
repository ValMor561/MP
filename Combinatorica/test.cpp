#include "pch.h"
#include "LexPerm.h"
#include "TrPerm.h"
#include "GreyCode.h"
#include "SGreyCode.h"
#define n 4
int fac(int a)
{
	int res = 1;
	while (a != 0)
	{
		res *= a;
		--a;
	}
	return res;
}
TEST(TestCaseName, TrTest) {
	std::vector<std::vector<int>> Permut = PermTr(n);
	int count = Permut.size();
	for (int i = 0; i < count; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			std::cout << Permut[i][j] << " ";
		}
		std::cout << std::endl;
	}
	ASSERT_EQ(count, fac(n));
}

TEST(TestCaseName, LexTest) {
	std::vector<std::vector<int>> Permut = LexPermute(n);
	int count = Permut.size();
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << Permut[i][j] << " ";
		}
		std::cout << std::endl;
	}
	ASSERT_EQ(count, fac(n));
}

TEST(TestCaseName, GreyTest) {
	bool** grey = CodåGrey(n);
	int N = pow(2, n);
	for (int i = 0; i < N; ++i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			std::cout << grey[i][j] << " ";
		}
		std::cout << std::endl;
	}
	ASSERT_TRUE(1 == 1);
}

TEST(TestCaseName, SGreyTest) {
	std::vector<std::vector<int>> grey = SCodåGrey(n);
	int count = grey.size();
	int N = pow(2, n);
	for (int i = 0; i < count; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			std::cout << grey[i][j] << " ";
		}
		std::cout << std::endl;
	}
	ASSERT_EQ(count, N);
}