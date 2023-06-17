#include "pch.h"
using namespace std;
std::vector<int> Dijkstra(std::vector<std::vector<int>> C, int n, int x) 
{
	int i, j, k;

	std::vector<int> distance(n);

	std::vector<int> S(n);

	S[x] = 1;

	int count = 1;

	for (i = 0; i < n; ++i)
		distance[i] = C[x][i];
	while (count < n) {

		j = 1;
		while (S[j] && j < n - 1) 
			++j;
		k = j;
		for (i = j + 1; i < n; ++i)
			if (!S[i] && distance[k] > distance[i])
				k = i;

		S[k] = 1;
		++count;

		for (j = 1; j < n; ++j)
			if (!S[j])
				if (distance[j] > distance[k] + C[k][j])
					distance[j] = distance[k] + C[k][j];
	}
	return distance;
}
