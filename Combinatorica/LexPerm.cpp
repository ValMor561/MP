#include "LexPerm.h"
#include "pch.h"

std::vector<std::vector<int>> LexPermute(int n) {
	int i, j, temp, left, right;
	std::vector<int> Permut(n);	
	std::vector<std::vector<int>> res;
	for (j = 0; j < n; ++j)
		Permut[j] = j + 1;
	for (; ; ) {
		res.push_back(Permut);
		for (i = n - 2; i > -1; --i)
		{
			if (Permut[i] < Permut[i + 1])
				break;
		}
		if (i == -1) break;
		j = n - 1;
		while (Permut[i] > Permut[j]) 
			--j;
		std::swap(Permut[i], Permut[j]);
		left = i + 1;
		right = n - 1;
		while (right > left) {
			temp = Permut[right];
			Permut[right--] = Permut[left];
			Permut[left++] = temp;
		}
	}
	return res;
}
