#include "pch.h"
#include "SGreyCode.h"

std::vector<std::vector<int>> SCodåGrey(int n) {
	std::vector<std::vector<int>> res;
	std::vector<int> Stack(n);
	int top = -1;
	std::vector<int> G(n + 1);
	int i, j, k, m, temp;
	for (i = n - 1; i >= 0; --i) {
		G[i] = 0;
		Stack[++top] = i;
	}
	while (top >= 0) {
		res.push_back(G);
		i = Stack[top--];
		G[n - i] = (G[n - i] + 1) % 2;
		for (j = i - 1; j >= 0; --j)
			Stack[++top] = j;
	}
	res.push_back(G);
	return res;
}
