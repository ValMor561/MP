#include "pch.h"
#include "BMSearch.h"

int GetPosInABC(std::string alphabet, char c)
{
	int n = alphabet.length();
	for (int i = 0; i < n; ++i)
	{
		if (alphabet[i] == c)
			return i;
	}
}
std::vector<std::vector<int>> Trunsition(std::string alphabet, std::string str)
{
	int k = 0;
	int next = 1;
	int m = str.length();
	int power = alphabet.length();
	std::vector<std::vector<int>> delta;
	delta.assign(m + 1, std::vector<int>(power));
	int pos = GetPosInABC(alphabet, str[k]);
	for (int i = 0; i < m + 1; ++i)
		delta[i][pos] = 1;
	pos = GetPosInABC(alphabet, str[1]);
	delta[m][pos] = 2;
	for (int i = 0; i < m + 1; ++i)
	{
		pos = GetPosInABC(alphabet, str[k]);
		++k;
		delta[i][pos] = next;
		++next;
		if (k == m)
		{
			next = 1;
			k = 0;
		}
	}
	return delta;
}

int SearchAuto(std::vector<std::vector<int>> delta,std::string text, std::string alphabet)
{
	int m = delta.size();
	int n = text.length();
	int s = 0;
	for (int i = 1; i < n + 1; ++i) {
		int pos = GetPosInABC(alphabet, text[i - 1]);
		s = delta[s][pos];
		if (s == m - 1) {
			int r = i - m + 1;
			return r;
		}
	}
	return -15;
}

int AutoSearch(std::string text, std::string str)
{
	std::string alphabet = GetAlphabet(text);
	std::vector<std::vector<int>> delta = Trunsition(alphabet, str);
	return SearchAuto(delta, text, alphabet);
}
