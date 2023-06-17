#include "pch.h"

std::vector<int> FPref(std::string str) 
{
	int m = str.length();
	std::vector<int> prefix(m);
	prefix[0] = 0;
	for (int i = 1; i < m; ++i) 
	{
		int j = prefix[i - 1];
		while (j > 0 && str[i] != str[j])
			j = prefix[j - 1];
		if (str[i] == str[j]) 
			++j;
		prefix[i] = j;
	}
	return prefix;
}

int KMP(std::string text, std::string str) 
{
	int n = text.length();
	int m = str.length();
	int q = 0, r;
	std::vector<int> prefix = FPref(str);
	for (int i = 1; i < n + 1; ++i) {
		while (q > 0 && str[q + 1] != text[i])
			q = prefix[q];
		if (str[q + 1] == text[i]) 
			++q;
		if (q == m) {
			r = i - m;
			return r;
			q = prefix[q];
		}
	}
	return -15;
}