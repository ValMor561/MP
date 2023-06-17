#include "pch.h"
int HashStr(std::string str, int d, int q, int end, int start)
{
	int res = 0;
	for (int i = start; i < end + start; ++i)
	{
		res = (d * res + str[i]) % q;
	}
	return res;
}
int RKSearch(std::string text, std::string str)
{
	int d = 128;
	int q = 9973;
	int n = text.length();
	int m = str.length();
	if (m > n)
		return -15;
	int h = (int)pow(d, m - 1) % q;
	int f = HashStr(str, d, q, m, 0);
	int	t = HashStr(text, d, q, m, 0);
	
	for (int i = 0; i < n - m + 1;)
	{
		if (f == t)
		{
			for (int k = 0; k < m && text[i + k ] == str[k]; ++k)
				if (k == m - 1)
					return i;
		}
		++i;
		t = HashStr(text, d, q, m, i);
	}
	return -15;
}
