#include "pch.h"
#include "DFS.h"
#include "Dijkstra.h"
#include "Kruscal.h"
#define N 6

TEST(GraptAlgoritmsTests, DFSTest2)
{
	std::list<int> L[N];
	L[0].push_back(5);
	L[1].push_back(0);
	L[1].push_back(2);
	L[1].push_back(5);
	L[2].push_back(0);
	L[2].push_back(3);
	L[4].push_back(0);
	L[4].push_back(5);
	L[5].push_back(2);
	L[5].push_back(3);
	std::list<TPare> T[N];
	int k = RoundDFS(L, T, N);
	ASSERT_EQ(3, k);

	std::list<TPare>::iterator itt;
	for (int i = 1; i < k + 1; ++i) {
		std::cout << i << ": ";
		for (itt = T[i].begin(); itt != T[i].end(); ++itt) {
			std::cout << *itt << " ";
		}
		std::cout << std::endl;
	}
}

TEST(GraptAlgoritmsTests, DFSTest1)
{
	std::list<int> L[N];
	L[0].push_back(5);
	L[1].push_back(0);
	L[1].push_back(2);
	L[1].push_back(5);
	L[2].push_back(0);
	L[2].push_back(3);
	L[4].push_back(0);
	L[4].push_back(5);
	L[5].push_back(2);
	L[5].push_back(3);
	std::list<TPare> T[N];
	int k = RoundDFS(L, T, N);
	std::vector<TPare> test(3);
	test[0] = TPare(0,5);
	test[1] = TPare(5,2);
	test[2] = TPare(2,3);


	std::list<TPare>::iterator itt;
	int i = 0;
	for (itt = T[1].begin(); itt != T[1].end(); ++itt) {
		ASSERT_TRUE(test[i] == *itt);
		++i;
	}
}

TEST(GraptAlgoritmsTests, DijkstraTests)
{
	std::vector<std::vector<int>> C(N, std::vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			C[i][j] = 999;
	}
	for (int i = 0; i < N; ++i)
		C[i][i] = 0;
	C[0][1] = 20;
	C[0][3] = 40;
	C[0][4] = 10;
	C[1][5] = 10;
	C[3][2] = 20;
	C[4][3] = 15;
	C[5][2] = 1;

	std::vector<std::vector<int>> res;
	res.push_back({ 0, 20, 31, 25, 10, 30 });
	res.push_back({ 999, 0, 11, 999, 999, 10 });
	res.push_back({ 999, 999, 0, 999, 999, 999 });
	res.push_back({ 999, 999, 20, 0, 999, 999 });
	res.push_back({ 999, 999, 35, 15, 0, 999 });
	res.push_back({ 999, 999, 1, 999, 999, 0 });

	for (int i = 0; i < N; ++i)
	{
		std::vector<int> dist = Dijkstra(C, N, i);
		for (int j = 0; j < N; ++j)
		{
			ASSERT_EQ(res[i][j], dist[j]);
		}
	}
}

TEST(GraptAlgoritmsTests, KruscalTest)
{
	std::vector<TPare> edges(8);
	edges[0] = TPare(2, 5);
	edges[1] = TPare(1, 3);
	edges[2] = TPare(0, 4);
	edges[3] = TPare(1, 2);
	edges[4] = TPare(3, 5);
	edges[5] = TPare(0, 5);
	edges[6] = TPare(2, 4);
	edges[7] = TPare(0, 1);
	
	std::vector<TPare> test(5);
	test[0] = TPare(2, 5);
	test[1] = TPare(1, 3);
	test[2] = TPare(0, 4);
	test[3] = TPare(1, 2);
	test[4] = TPare(0, 5);

	std::vector<TPare> res = Kruskal(N, edges);
	for (int i = 0; i < N - 1; ++i)
		ASSERT_TRUE(test[i] == res[i]);
} 
