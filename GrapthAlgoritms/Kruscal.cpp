#include "pch.h"
#include "DFS.h"

std::vector<TPare> Kruskal(int n, std::vector<TPare> edges) {
	std::vector<TPare> T;
	int m = edges.size();
	std::vector<int> components(n);
	for (int i = 0; i < n; ++i)
		components[i] = i;
	int currentedge = 0;
	int countcomp = n;
	while (currentedge < m && countcomp > 1) {
		TPare pare = edges[currentedge];
		if (components[pare.v1] != components[pare.v2])
		{ 
			int k = components[pare.v2];
			for (int i = 0; i < n; ++i)
				if (components[i] == k)
					components[i] = components[pare.v1];
			--countcomp;
			T.push_back(pare);
		}
		++currentedge;
	}
	return T;
} 