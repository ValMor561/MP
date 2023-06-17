#include "pch.h"
#include "TrPerm.h"

std::vector<std::vector<int>> PermTr(int n) {
	std::vector<int> Permut(n + 2);
	std::vector<int> PermutIn(n + 1);
	std::vector<int> d(n + 1);	
	int i, j, k, m;
	std::vector<std::vector<int>> res;
	Permut[0] = n + 1;	
	Permut[n + 1] = n + 1;	
	for (i = 1; i < n + 1; ++i) {
		Permut[i] = i;
		PermutIn[i] = i;
		d[i] = -1;
	}
	d[1] = 0;
	for (; ; ) {
		res.push_back(Permut);
		m = n;
		while (Permut[PermutIn[m] + d[m]] > m) {
			d[m] = -d[m];
			--m;
			if (m == 1)
				return res;
		}
		j = Permut[PermutIn[m]];
		Permut[PermutIn[m]] = Permut[PermutIn[m] + d[m]];
		Permut[PermutIn[m] + d[m]] = j;

		j = PermutIn[Permut[PermutIn[m]]];
		PermutIn[Permut[PermutIn[m]]] = PermutIn[m];
		PermutIn[m] = j;
	}
	return res;
}
